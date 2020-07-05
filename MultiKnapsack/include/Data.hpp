#ifndef _DATA_H_
#define _DATA_H_

#include <vector>
#include <stdio.h>

class Data
{
    private:

        int n_items;
        int n_bags;
        std::vector<int> weights;
        std::vector<int> benefits;
        std::vector<int> capacities;

    public:

        Data(char* filePath);
        
        int getNItems();
        int getNBags();
        int getItemWeight(int item);
        int getItemBenefit(int item);
        int getBagCapacity(int item);
};

#endif