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
    //variavel Xi: Xi = 1, 1 unidade sendo transportada no arco i
    IloNumVarArray x(env, data.getNArcos(), 0, IloInfinity);

    //adiciona a variavel x ao modelo
    for(int i = 0; i < data.getNArcos(); i++)
    {
        x[i].setBounds(data.getLimMinArco(i), data.getLimMaxArco(i));
        char name[100];
        sprintf(name, "X(%d)", i);
        x[i].setName(name);
        modelo.add(x[i]);
    }
    //fim das variaveis
    ///////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Criando a Função Objetivo (FO) 
    IloExpr sumCX(env);
    for(int i = 0; i < data.getNArcos(); i++)
    {
        sumCX += data.getCustoArco(i)*x[i];
    }

    // Adicionando a FO
    modelo.add(IloMinimize(env, sumCX));
    //////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //Restricoes

    //Restricoes (1): o que entra em um no menos o que sai deve ser igual a demanda do mesmo
    for(int i = 0; i < data.getNNos(); i++) 
    {   

        IloExpr sumEX(env);
        IloExpr sumSX(env);

        for(int j = 0; j < data.getNArcos(); j++)
        {
            for(int n = 0; n < 2; n++)
            {
                if(data.getNoArco(j, n) == i+1)
                {
                    if(n == 0)
                    {
                        sumSX += x[j];
                    }
                    else
                    {
                        sumEX += x[j];
                    }       
                }
            }
        }

        IloRange r = (sumEX - sumSX - data.getDemandaNo(i) == 0);
        char name[100];
        sprintf(name, "DEM(%d)", i);
        r.setName(name);
        modelo.add(r);
    }

    //fim das restricoes
    ////////////////////////////////////////////////////////

    //resolve o modelo
    IloCplex fcm(modelo);
    fcm.setParam(IloCplex::TiLim, 2*60*60);
    fcm.setParam(IloCplex::Threads, 1);
//    fcm.setParam(IloCplex::Param::MIP::Interval, 1);
//    fcm.setParam(IloCplex::Param::MIP::Display, 5);
    fcm.exportModel("modelo.lp");

    try
    {
        fcm.solve();
    }
    catch(IloException& e)
    {
        std::cout << e;
    }

    std::cout << "\nstatus:" << fcm.getStatus() << std::endl;
    std::cout << "custo minimo de transporte:" << fcm.getObjValue() << std::endl;
    for(int i = 0; i < data.getNArcos(); i++) 
    {

        printf("Unit. transportada do no #%d para o no #%d: ", data.getNoArco(i,0), data.getNoArco(i,1));

        std::cout << fcm.getValue(x[i]) << std::endl;
        
    }

}

