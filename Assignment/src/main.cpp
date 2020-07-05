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
    //variavel Xij: Xij = 1, se a pessoa i foi designada para a tarefa j
    IloArray <IloBoolVarArray> x(env, data.getNPeople());
    for(int i = 0; i < data.getNPeople(); i++)
    {
        IloBoolVarArray vetor(env, data.getNTasks());
        x[i] = vetor;
    }
    
    //adiciona a variavel x ao modelo
    for(int i = 0; i < data.getNPeople(); i++)
    {
        for(int j = 0; j < data.getNTasks(); j++)
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
    IloExpr sumCX(env);
    for(int i = 0; i < data.getNPeople(); i++)
    {   
        for(int j = 0; j < data.getNTasks(); j++)
        {
            sumCX += data.getAssignedCost(i,j)*x[i][j];
        }

    }
    // Adicionando a FO
    modelo.add(IloMinimize(env, sumCX));
    //////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Restricoes

    //Restricoes (1): cada pessoa deve estar atribuida em uma tarefa
    for(int i = 0; i < data.getNPeople(); i++) 
    {   
        IloExpr sumX(env);

        for(int j = 0; j < data.getNTasks(); j++)
        {
            sumX += x[i][j];
        }

        IloRange r = (sumX - 1 == 0);
        char name[100];
        sprintf(name, "ASSIGN(%d)", i);
        r.setName(name);
        modelo.add(r);
    }

    //Restricoes (2): cada tarefa deve ter uma pessoa atribuida
    for(int j = 0; j < data.getNTasks(); j++) 
    {   
        IloExpr sumX(env);

        for(int i = 0; i < data.getNPeople(); i++)
        {
            sumX += x[i][j];
        }

        IloRange r = (sumX - 1 == 0);
        char name[100];
        sprintf(name, "ALOC(%d)", j);
        r.setName(name);
        modelo.add(r);
    }

    //fim das restricoes
    ////////////////////////////////////////////////////////

    //resolve o modelo
    IloCplex assig(modelo);
    assig.setParam(IloCplex::TiLim, 2*60*60);
    assig.setParam(IloCplex::Threads, 1);
//    assig.setParam(IloCplex::Param::MIP::Interval, 1);
//    assig.setParam(IloCplex::Param::MIP::Display, 5);
    assig.exportModel("modelo.lp");

    try
    {
        assig.solve();
    }
    catch(IloException& e)
    {
        std::cout << e;
    }

    std::cout << "status:" << assig.getStatus() << std::endl;
    std::cout << "custo minimo:" << assig.getObjValue() << std::endl;
    for(int i = 0; i < data.getNPeople(); i++) 
    {
        for(int j = 0; j < data.getNTasks(); j++)
        {
            if(assig.getValue(x[i][j]) > 0.9)
                printf("pessoa %d atribuida a tarefa %d\n", i+1, j+1);
        }
        
    }
}

