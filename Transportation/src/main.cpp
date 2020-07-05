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
    //variavel Xij: Xij = 1, 1 unidade transportada da fabrica i para o cliente j
    IloArray <IloNumVarArray> x(env, data.getNPlants());
    for(int i = 0; i < data.getNPlants(); i++)
    {
        IloNumVarArray vetor(env, data.getNClients(), 0, IloInfinity);
        x[i] = vetor;
    }
    
    //adiciona a variavel x ao modelo
    for(int i = 0; i < data.getNPlants(); i++)
    {
        for(int j = 0; j < data.getNClients(); j++)
        {
            char name[100];
            sprintf(name, "X(%d,%d)", i, j);
            x[i][j].setName(name);
            modelo.add(x[i][j]);
        }

    }
    //fim das variaveis
    ///////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Criando a Função Objetivo (FO) 
    IloExpr sumCX(env);
    for(int i = 0; i < data.getNPlants(); i++)
    {   
        for(int j = 0; j < data.getNClients(); j++)
        {
            sumCX += data.getTransportationCost(i,j)*x[i][j];
        }

    }
    // Adicionando a FO
    modelo.add(IloMinimize(env, sumCX));
    //////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Restricoes

    //Restricoes (1): a oferta de cada origem deve ser satisfeita
    for(int i = 0; i < data.getNPlants(); i++) 
    {   
        IloExpr sumX(env);

        for(int j = 0; j < data.getNClients(); j++)
        {
            sumX += x[i][j];
        }

        IloRange r = (sumX - data.getPlantCapacity(i) == 0);
        char name[100];
        sprintf(name, "CAP(%d)", i);
        r.setName(name);
        modelo.add(r);
    }

    //Restricoes (2): a demanda de cada cliente deve ser satisfeita
    for(int j = 0; j < data.getNClients(); j++) 
    {   
        IloExpr sumX(env);

        for(int i = 0; i < data.getNPlants(); i++)
        {
            sumX += x[i][j];
        }

        IloRange r = (sumX - data.getClientDemand(j) == 0);
        char name[100];
        sprintf(name, "DEM(%d)", j);
        r.setName(name);
        modelo.add(r);
    }

    /*//restricoes (3): restricao de nao-negatividade
    for(int i = 0; i < data.getNPlants(); i++)
    {
        for(int j = 0; j < data.getNClients(); j++)
        {
            IloRange r = (x[i][j] >= 0);
            char name[100];
            sprintf(name, "X(%d)(%d)", i, j);
            r.setName(name);
            modelo.add(r);
        }

    }*/

    //fim das restricoes
    ////////////////////////////////////////////////////////

    //resolve o modelo
    IloCplex tnp(modelo);
    tnp.setParam(IloCplex::TiLim, 2*60*60);
    tnp.setParam(IloCplex::Threads, 1);
//    tnp.setParam(IloCplex::Param::MIP::Interval, 1);
//    tnp.setParam(IloCplex::Param::MIP::Display, 5);
    tnp.exportModel("modelo.lp");

    try
    {
        tnp.solve();
    }
    catch(IloException& e)
    {
        std::cout << e;
    }

    std::cout << "\nstatus:" << tnp.getStatus() << std::endl;
    std::cout << "custo minimo de transporte:" << tnp.getObjValue() << std::endl;
    for(int i = 0; i < data.getNPlants(); i++) 
    {
        for(int j = 0; j < data.getNClients(); j++)
        {
            if(tnp.getValue(x[i][j]) == 0.0)
                continue;

            std::cout << "fabrica " << i+1 << " transporta " << tnp.getValue(x[i][j]) << " unit. para o cliente " << j+1 << std::endl;
        
        }

        puts("");
        
    }
}

