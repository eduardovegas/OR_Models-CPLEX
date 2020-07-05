#include "../include/Data.hpp"
#include <stdio.h>
#include <iostream>
#include <ilcplex/ilocplex.h>

void solve(Data& data);

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Usage:\n./bin instance\n");
        return 0;
    }

    Data data(argv[1]);
    solve(data);

    return 0;
}

void solve(Data& data)
{
    IloEnv env;
    IloModel modelo(env);


    ///////////////////////////////////////////////////////
    //variavel Xij: Xij = 1, se o item i vai pra mochila j
    IloArray <IloBoolVarArray> x(env, data.getNItems());
    for(int i = 0; i < data.getNItems(); i++)
    {
        IloBoolVarArray vetor(env, data.getNBags());
        x[i] = vetor;
    }

    //adiciona a variavel x ao modelo
    for(int i = 0; i < data.getNItems(); i++)
    {
        for(int j = 0; j < data.getNBags(); j++)
        {
            char name[100];
            sprintf(name, "X(%d)(%d)", i, j);
            x[i][j].setName(name);
            modelo.add(x[i][j]);
        }

    }
    //fim das variaveis
    ///////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Criando a Função Objetivo (FO) 
    IloExpr sumBX(env);
    for(int j = 0; j < data.getNBags(); j++)
    {
        for(int i = 0; i < data.getNItems(); i++)
        {
            sumBX += data.getItemBenefit(i)*x[i][j];
        }

    }
    
    // Adicionando a FO
    modelo.add(IloMaximize(env, sumBX));
    //////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Restricoes
    
    //Restricoes (1): cada item deve estar no maximo em uma mochila
    for(int i = 0; i < data.getNItems(); i++) 
    {   
        IloExpr sumX(env);
        for(int j = 0; j < data.getNBags(); j++)
        {
            sumX += x[i][j];
        }

        IloRange r = (sumX - 1 <= 0);
        char name[100];
        sprintf(name, "COV(%d)", i);
        r.setName(name);
        modelo.add(r);

    }

    //Restricoes (2): capacidade das mochilas
    for(int j = 0; j < data.getNBags(); j++)
    {

        IloExpr sumWX(env);
        for(int i = 0; i < data.getNItems(); i++)
        {
            sumWX += data.getItemWeight(i)*x[i][j];
        }

        IloRange r = (sumWX - data.getBagCapacity(j) <= 0);
        char name[100];
        sprintf(name, "CAP(%d)", j);
        r.setName(name);
        modelo.add(r);

    }
    
    //fim das restricoes
    ////////////////////////////////////////////////////////

    //resolve o modelo
    IloCplex mkps(modelo);
    mkps.setParam(IloCplex::TiLim, 2*60*60);
    mkps.setParam(IloCplex::Threads, 1);
//    mkps.setParam(IloCplex::Param::MIP::Interval, 1);
//    mkps.setParam(IloCplex::Param::MIP::Display, 5);
    mkps.exportModel("modelo.lp");

    try
    {
        mkps.solve();
    }
    catch(IloException& e)
    {
        std::cout << e;
    }
    
    std::cout << "status:" << mkps.getStatus() << std::endl;
    std::cout << "beneficio maximo:" << mkps.getObjValue() << std::endl;
    for(int i = 0; i < data.getNItems(); i++) 
    {
        for(int j = 0; j < data.getNBags(); j++)
        {

            if(mkps.getValue(x[i][j]) > 0.9)
            {
                std::cout << "item " << i+1 << " na mochila " << j+1 << std::endl;
            }
        }
    }
}