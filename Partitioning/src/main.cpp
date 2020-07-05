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
    //variavel Yj: Yj = 1, se o subconjunto Yj é selecionado
    IloBoolVarArray y(env, data.getNSubsets());
    
    //adiciona a variavel y ao modelo
    for(int j = 0; j < data.getNSubsets(); j++)
    {

        char name[100];
        sprintf(name, "Y(%d)", j);
        y[j].setName(name);
        modelo.add(y[j]);
        
    }
    //fim das variaveis
    ///////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Criando a Função Objetivo (FO) 
    IloExpr sumCY(env);
    for(int j = 0; j < data.getNSubsets(); j++)
    {
        sumCY += data.getSubsetCost(j)*y[j];
    }

    // Adicionando a FO
    modelo.add(IloMinimize(env, sumCY));
    //////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Restricoes

    //Restricoes (1): cada elemento deve estar contido em EXATAMENTE um subconjunto
    for(int i = 0; i < data.getNElements(); i++) 
    {   

        IloExpr sumSY(env);

        for(int j = 0; j < data.getNSubsets(); j++)
        {
            for(int n = 0; n < data.getSubsetSize(j); n++)
            {
                if(data.getSubsetElement(j, n) == i+1)
                {
                    sumSY += y[j];
                    break;
                }
            }
        }

        IloRange r = (sumSY - 1 == 0);
        char name[100];
        sprintf(name, "PAR(%d)", i);
        r.setName(name);
        modelo.add(r);
    }

    //fim das restricoes
    ////////////////////////////////////////////////////////

    //resolve o modelo
    IloCplex par(modelo);
    par.setParam(IloCplex::TiLim, 2*60*60);
    par.setParam(IloCplex::Threads, 1);
//    par.setParam(IloCplex::Param::MIP::Interval, 1);
//    par.setParam(IloCplex::Param::MIP::Display, 5);
    par.exportModel("modelo.lp");

    try
    {
        par.solve();
    }
    catch(IloException& e)
    {
        std::cout << e;
    }

    std::cout << "\nstatus:" << par.getStatus() << std::endl;
    std::cout << "custo minimo de particionamento:" << par.getObjValue() << std::endl;
    for(int j = 0; j < data.getNSubsets(); j++) 
    {

        if(par.getValue(y[j]) > 0.9)
            printf("Subconjunto %d foi selecionado\n", j+1);
        
    }

}

