#ifndef _DATA_H_
#define _DATA_H_

#include <vector>
#include <stdio.h>

class Data
{
    private:

        int n_items;
        int capacity;
        std::vector<int> weights;
        std::vector<int> benefits;

    public:

        Data(char* filePath);
        
        int getNItems();
        int getCapacity();
        int getItemWeight(int item);
        int getItemBenefit(int item);
};

#endif

