/*
    !! Created at 30/04/2024 -> Patra Rafles Wostyla Sinaga

    Nama file: dataBarang.hpp
    Ini merupakan header file yang berfungsi untuk menyimpan data barang di dalam array 2d
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#define MAX_SIZE 100
using namespace std;


class DataBarang
{
    protected:
        string dataBarang[MAX_SIZE][3];
        int n;
};
