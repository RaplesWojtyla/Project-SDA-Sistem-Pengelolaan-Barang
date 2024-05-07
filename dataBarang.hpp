/*
    !! Created at 30/04/2005 -> Patra Rafles Wostyla Sinaga

    Nama file: sort.hpp
    File ini berfungsi untuk mendeklarasikan array yang menyimpan data barang
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
