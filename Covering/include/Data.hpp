#ifndef _DATA_H_
#define _DATA_H_

#include <vector>
#include <stdio.h>

class Data
{
    private:

        int n_elements;
        int n_subsets;
        std::vector<int> cost;
        std::vector<std::vector<int>> subsets;

    public:

        Data(char* filePath);
        
        int getNElements();
        int getNSubsets();
        int getSubsetCost(int subset);
        int getSubsetSize(int subset);
        int getSubsetElement(int subset, int element);

};

#endif

