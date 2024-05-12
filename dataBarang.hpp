/*
    !! Created at 30/04/2024 -> Patra Rafles Wostyla Sinaga
    !! Updateed at 12/05/2024 -> Patra Rafles Wostyla Sinaga

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
        time_t currTime;
        struct tm *ct;
        struct tm exp;
        string dataBarang[MAX_SIZE][3];
        string currentTime;
        int n;
    
    public:
        DataBarang();
        void print(int);
        ~DataBarang() {}
};

DataBarang::DataBarang()
{
    currTime = time(nullptr);
    ct = localtime(&currTime);
    exp = {0};
    currentTime = to_string(mktime(ct)); 
    n = 0;
}

void DataBarang::print(int i)
{
    cout << "Barang ke-" << i + 1 << ":\n";
    cout << "\tNama barang: " << dataBarang[i][0] << '\n';
    cout << "\tBanyak barang: " << dataBarang[i][1] << '\n';

    char buff[80];
    time_t t = stol(dataBarang[i][2]);
    tm *convert = localtime(&t);
    strftime(buff, 80, "%A, %d %B %Y", convert);

    cout << "\tTanggal kadaluarsa: " << buff << '\n'; 
}