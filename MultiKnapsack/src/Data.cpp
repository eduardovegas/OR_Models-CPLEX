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

    if(fscanf(f, "%d", &n_items) != 1)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    if(fscanf(f, "%d", &n_bags) != 1)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    //reading capacities
    capacities = std::vector<int>(n_bags, 0);
    for(int i = 0; i < n_bags; i++)
    {
        if(fscanf(f, "%d", &capacities[i]) != 1)
        {
            printf("Problem while reading instance.\n");
            exit(1);
        }

    }

    //reading weights and benefits
    weights = std::vector<int>(n_items, 0);
    benefits = std::vector<int>(n_items, 0);
    for(int i = 0; i < n_items; i++)
    {
        if(fscanf(f, "%d %d", &benefits[i], &weights[i]) != 2)
        {
            printf("Problem while reading instance.\n");
            exit(1);
        }
    }

    fclose(f);
}

int Data::getNItems()
{
    return n_items;
}

int Data::getNBags()
{
    return n_bags;
}

int Data::getItemWeight(int item)
{
    return weights[item]; 
}

int Data::getItemBenefit(int item)
{
    return benefits[item]; 
}

int Data::getBagCapacity(int bag)
{
    return capacities[bag];
}
