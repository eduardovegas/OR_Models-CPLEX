#ifndef _DATA_H_
#define _DATA_H_

#include <vector>
#include <stdio.h>

class Data
{
    private:

        int n_plants;
        int n_clients;
        std::vector<int> capacities;
        std::vector<int> demands;
        std::vector<std::vector<int>> cost;

    public:

        Data(char* filePath);
        
        int getNPlants();
        int getNClients();
        int getPlantCapacity(int plant);
        int getClientDemand(int client);
        int getTransportationCost(int plant, int client);

};

#endif

