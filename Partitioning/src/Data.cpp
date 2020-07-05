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

    if(fscanf(f, "%d", &n_elements) != 1)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    if(fscanf(f, "%d", &n_subsets) != 1)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    //reading costs
    cost = std::vector<int>(n_subsets, 0);
    for(int i = 0; i < n_subsets; i++)
    {
        if(fscanf(f, "%d", &cost[i]) != 1)
        {
            printf("Problem while reading instance.\n");
            exit(1);
        }
    }
    
    int tam = 0;
    //reading subsets
    for(int i = 0; i < n_subsets; i++)
    {

        if(fscanf(f, "%d", &tam) != 1)
        {
            printf("Problem while reading instance.\n");
            exit(1);
        }

        std::vector<int> vecAux(tam);

        for(int j = 0; j < tam; j++)
        {

            int aux = 0;
            if(fscanf(f, "%d", &aux) != 1)
            {
                printf("Problem while reading instance.\n");
                exit(1);
            }

            vecAux[j] = aux;

        }

        subsets.push_back(vecAux);

    }

    /*printf("leu\n");

    for(int i = 0; i < n_subsets; i++)
    {

        for(int j = 0; j < getSubsetSize(i); j++){

            printf("%d ", subsets[i][j]);
        }

        puts("");
    }*/


    fclose(f);
}

int Data::getNElements()
{
    return n_elements;
}

int Data::getNSubsets()
{
    return n_subsets;
}

int Data::getSubsetCost(int subset)
{
    return cost[subset];
}

int Data::getSubsetSize(int subset)
{
    return subsets[subset].size();
}

int Data::getSubsetElement(int subset, int element)
{
    return subsets[subset][element];
}