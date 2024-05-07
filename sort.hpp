/*
    !!CREATED AT 02/05/2024 -> SYUJA AQILSYAH
    !! UPDATED AT 07/05/2024 -> Patra Rafles Wostyla Sinaga

    Nama file: sort.hpp
    Ini merupakan header file yang berisi method untuk mengurutkan data barang
*/

#include "dataBarang.hpp"

class Sort : protected DataBarang
{
    public:
        Sort() {}
        void ascSort();
        void descSort();
        void sortByExp();
        void swapp(int, int);
        ~Sort() {}
};

void Sort::ascSort()
{
    for (int i = 1; i < n; ++i)
    {
        int pos = i;

        while (pos > 0 && dataBarang[pos][0] < dataBarang[pos - 1][0])
            swapp(pos, pos - 1), --pos;
    }
}

void Sort::descSort()
{
    for (int i = 1; i < n; ++i)
    {
        int pos = i;

        while (pos > 0 && dataBarang[pos][0] > dataBarang[pos - 1][0])
            swapp(pos, pos - 1), --pos;
    }
}

void Sort::sortByExp()
{
    for (int i = 1; i < n; ++i)
    {
        int pos = i;

        while (pos > 0 && dataBarang[pos][2] < dataBarang[pos - 1][2])
            swapp(pos, pos - 1), --pos;
    }
}

void Sort::swapp(int i, int j)
{
    string t1 = dataBarang[i][0];
    string t2 = dataBarang[i][1];
    string t3 = dataBarang[i][2];

    dataBarang[i][0] = dataBarang[j][0];
    dataBarang[i][1] = dataBarang[j][1];
    dataBarang[i][2] = dataBarang[j][2];

    dataBarang[j][0] = t1;
    dataBarang[j][1] = t2;
    dataBarang[j][2] = t3;
}