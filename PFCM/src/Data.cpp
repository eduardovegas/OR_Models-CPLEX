#include "../include/Data.hpp"
#include <stdlib.h>

Data::Data(char* filePath)
{
    FILE* f = fopen(filePath, "r");

    if(!f)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    if(fscanf(f, "%d", &n_nos) != 1)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    if(fscanf(f, "%d", &n_arcos) != 1)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    //lendo demanda
    demanda = std::vector<int>(n_nos, 0);
    for(int i = 0; i < n_nos; i++)
    {
        if(fscanf(f, "%d", &demanda[i]) != 1)
        {
            printf("Problem while reading instance.\n");
            exit(1);
        }
    }

    //lendo arcos
    custo = std::vector<int>(n_arcos, 0);
    lim_min = std::vector<int>(n_arcos, 0);
    lim_max = std::vector<int>(n_arcos, 0);

    for(int i = 0; i < n_arcos; i++)
    {
        std::vector<int> vecAux(2);

        for(int j = 0; j < 2; j++)
        {
            if(fscanf(f, "%d", &vecAux[j]) != 1)
            {
                printf("Problem while reading instance.\n");
                exit(1);
            }
        }

        arcos.push_back(vecAux);

        //lendo custos
        if(fscanf(f, "%d", &custo[i]) != 1)
        {
            printf("Problem while reading instance.\n");
            exit(1);
        }

        //lendo limites
        if(fscanf(f, "%d", &lim_min[i]) != 1)
        {
            printf("Problem while reading instance.\n");
            exit(1);
        }

        if(fscanf(f, "%d", &lim_max[i]) != 1)
        {
            printf("Problem while reading instance.\n");
            exit(1);
        }

    }
    

    /*printf("leu\n");

    for(int i = 0; i < n_nos; i++)
    {
        printf("%d ", demanda[i]);
    }
    puts("");

    for(int i = 0; i < n_arcos; i++)
    {
        printf("%d %d %d\n", custo[i], lim_min[i], lim_max[i]);
    }

    for(int i = 0; i < n_arcos; i++)
    {

        for(int j = 0; j < arcos[i].size(); j++){

            printf("%d ", arcos[i][j]);
        }

        puts("");
    }*/


    fclose(f);
}

int Data::getNNos()
{
    return n_nos;
}

int Data::getNArcos()
{
    return n_arcos;
}

int Data::getDemandaNo(int no)
{
    return demanda[no];
}

int Data::getCustoArco(int arco)
{
    return custo[arco];
}

int Data::getLimMinArco(int arco)
{
    return lim_min[arco];
}

int Data::getLimMaxArco(int arco)
{
    return lim_max[arco];
}

int Data::getNoArco(int arco, int no)
{
    return arcos[arco][no];
}