#ifndef _DATA_H_
#define _DATA_H_

#include <vector>
#include <stdio.h>

class Data
{
    private:

        int n_people;
        int n_tasks;
        std::vector<std::vector<int>> cost;

    public:

        Data(char* filePath);
        
        int getNPeople();
        int getNTasks();
        int getAssignedCost(int person, int task);
};

#endif

