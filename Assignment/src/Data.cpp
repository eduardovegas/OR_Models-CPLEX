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

    if(fscanf(f, "%d", &n_people) != 1)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    if(fscanf(f, "%d", &n_tasks) != 1)
    {
        printf("Problem while reading instance %s.\n", filePath);
        exit(1);
    }

    //reading assigned cost
    cost = std::vector< std::vector<int> >(n_people, std::vector<int>(n_tasks, 0));

    for(int i = 0; i < n_people; i++)
    {
        for(int j = 0; j < n_tasks; j++)
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

int Data::getNPeople()
{
    return n_people;
}

int Data::getNTasks()
{
    return n_tasks;
}

int Data::getAssignedCost(int person, int task)
{
    return cost[person][task]; 
}