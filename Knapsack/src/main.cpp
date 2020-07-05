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
    //variavel Xi: Xi = 1, se o item i esta na mochila
    IloBoolVarArray x(env, data.getNItems());
    
    //adiciona a variavel x ao modelo
    for(int i = 0; i < data.getNItems(); i++)
    {
        char name[100];
        sprintf(name, "X(%d)", i);
        x[i].setName(name);
        modelo.add(x[i]);
        
    }
    //fim das variaveis
    ///////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Criando a Função Objetivo (FO) 
    IloExpr sumBX(env);
    for(int i = 0; i < data.getNItems(); i++)
    {
        sumBX += data.getItemBenefit(i)*x[i];
    }
    // Adicionando a FO
    modelo.add(IloMaximize(env, sumBX));
    //////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Restricoes

    //Restricoes (1): cada item deve estar em um bin
    IloExpr sumWX(env);
    for(int i = 0; i < data.getNItems(); i++) 
    {
        sumWX += data.getItemWeight(i)*x[i];
    }

    IloRange r = (sumWX - data.getCapacity() <= 0);
    char name[100] = "CAP";
    r.setName(name);
    modelo.add(r);

    //fim das restricoes
    ////////////////////////////////////////////////////////

    //resolve o modelo
    IloCplex knps(modelo);
    knps.setParam(IloCplex::TiLim, 2*60*60);
    knps.setParam(IloCplex::Threads, 1);
//    knps.setParam(IloCplex::Param::MIP::Interval, 1);
//    knps.setParam(IloCplex::Param::MIP::Display, 5);
    knps.exportModel("modelo.lp");

    try
    {
        knps.solve();
    }
    catch(IloException& e)
    {
        std::cout << e;
    }

    std::cout << "status:" << knps.getStatus() << std::endl;
    std::cout << "beneficio maximo:" << knps.getObjValue() << std::endl;
    for(int i = 0; i < data.getNItems(); i++) 
    {

        if(knps.getValue(x[i]) > 0.9)
            printf("item %d entra\n", i+1);
        
    }
}

