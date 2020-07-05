#ifndef _DATA_H_
#define _DATA_H_

#include <vector>
#include <stdio.h>

class Data
{
    private:

        int n_nos;
        int n_arcos;
        std::vector<int> demanda;
        std::vector<int> custo;
        std::vector<int> lim_min;
        std::vector<int> lim_max;
        std::vector<std::vector<int>> arcos;

    public:

        Data(char* filePath);
        
        int getNNos();
        int getNArcos();
        int getDemandaNo(int no);
        int getCustoArco(int arco);
        int getLimMinArco(int arco);
        int getLimMaxArco(int arco);
        int getNoArco(int arco, int no);

};

#endif

