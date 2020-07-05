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

    if(fscanf(f, "%d", &n_plants) != 1)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    if(fscanf(f, "%d", &n_clients) != 1)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    int aux;
    //reading capacities
    capacities = std::vector<int>(n_plants, 0);
    for(int i = 0; i < n_plants; i++)
    {
        if(fscanf(f, "%d", &capacities[i]) != 1)
        {
            printf("Problem while reading instance.\n");
            exit(1);
        }
    }
    
    //reading demands
    demands = std::vector<int>(n_clients, 0);
    for(int i = 0; i < n_clients; i++)
    {
        if(fscanf(f, "%d", &demands[i]) != 1)
        {
            printf("Problem while reading instance.\n");
            exit(1);
        }
    }

    //reading per-unit transportation cost
    cost = std::vector< std::vector<int> >(n_plants, std::vector<int>(n_clients, 0));

    for(int i = 0; i < n_plants; i++)
    {
        for(int j = 0; j < n_clients; j++)
        {
            if(fscanf(f, "%d", &cost[i][j]) != 1)
            {
                printf("Problem while reading instance.\n");
                exit(1);
            }
        }
    }


    fclose(f);
}

int Data::getNPlants()
{
    return n_plants;
}

int Data::getNClients()
{
    return n_clients;
}

int Data::getPlantCapacity(int plant)
{
    return capacities[plant];
}

int Data::getClientDemand(int client)
{
    return demands[client];
}

int Data::getTransportationCost(int person, int task)
{
    return cost[person][task]; 
}