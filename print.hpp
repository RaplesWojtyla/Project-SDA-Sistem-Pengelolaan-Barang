/*
    !! Created at 30/04/2024 -> Patra Rafles Wostyla Sinaga
    !! Updated At 03/05/2024 -> Ashnel Muhammad
    !! Updated at 14/05/2024 -> Patra Rafles Wostyla Sinaga

    Nama file: update.hpp
    Deskripsi: Header file untuk menampilkan data ke user
*/

#include <iostream>
#include <string>
#include <ctime>
#define MAX_SIZE 100
using namespace std;

class PrintArr
{
    public:
        void printArr(string arr[MAX_SIZE][3], int);
        void displayAllArr(string arr[MAX_SIZE][3], int);
};

void PrintArr::printArr(string arr[MAX_SIZE][3], int i)
{
    cout << "Barang ke-" << i + 1 << ":\n";
    cout << "\tNama barang: " << arr[i][0] << '\n';
    cout << "\tBanyak barang: " << arr[i][1] << '\n';

    char buff[80];
    time_t t = stol(arr[i][2]);
    tm *convert = localtime(&t);
    strftime(buff, 80, "%A, %d %B %Y", convert);

    cout << "\tTanggal kadaluarsa: " << buff << '\n';
}

void PrintArr::displayAllArr(string arr[MAX_SIZE][3], int n)
{
    system("cls");

    cout << "\nDaftar Barang:\n";
    for (int i = 0; i < n; ++i) printArr(arr, i);
}
