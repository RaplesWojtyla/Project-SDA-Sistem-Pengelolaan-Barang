/*
    !! Created At 02/05/2024 -> Syuja Aqilsyah
    !! Updated At 07/05/2024 -> Patra Rafles Wostyla Sinaga
    !! Updated At 12/05/2024 -> Patra Rafles Wostyla Sinaga
    !! Updated At 14/05/2024 -> Patra Rafles Wostyla Sinaga

    Nama file: sort.hpp
    Deskripsi: Ini merupakan header file untuk mengurutkan data barang
*/

#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#define MAX_SIZE 100
using namespace std;

class Sort : protected PrintArr
{
    public:
        Sort() {}
        void ascSort(string arr[MAX_SIZE][3], int);
        void descSort(string arr[MAX_SIZE][3], int);
        void sortByExp(string arr[MAX_SIZE][3], int);
        void filterByExp(string arr[MAX_SIZE][3], string, int);
        void filterByNotExp(string arr[MAX_SIZE][3], string, int);
        ~Sort() {}
};

void Sort::ascSort(string arr[MAX_SIZE][3], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int pos = i;

        while (pos > 0 && arr[pos][0] < arr[pos - 1][0])
        {
            string t1 = arr[pos][0];
            string t2 = arr[pos][1];
            string t3 = arr[pos][2];

            arr[pos][0] = arr[pos - 1][0];
            arr[pos][1] = arr[pos - 1][1];
            arr[pos][2] = arr[pos - 1][2];

            arr[pos - 1][0] = t1;
            arr[pos - 1][1] = t2;
            arr[--pos][2] = t3;
        }
    }
}

void Sort::descSort(string arr[MAX_SIZE][3], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int pos = i;

        while (pos > 0 && arr[pos][0] > arr[pos - 1][0])
        {
            string t1 = arr[pos][0];
            string t2 = arr[pos][1];
            string t3 = arr[pos][2];

            arr[pos][0] = arr[pos - 1][0];
            arr[pos][1] = arr[pos - 1][1];
            arr[pos][2] = arr[pos - 1][2];

            arr[pos - 1][0] = t1;
            arr[pos - 1][1] = t2;
            arr[--pos][2] = t3;
        }
    }
}

void Sort::sortByExp(string arr[MAX_SIZE][3], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int pos = i;

        while (pos > 0 && stol(arr[pos][2]) < stol(arr[pos - 1][2]))
        {
            string t1 = arr[pos][0];
            string t2 = arr[pos][1];
            string t3 = arr[pos][2];

            arr[pos][0] = arr[pos - 1][0];
            arr[pos][1] = arr[pos - 1][1];
            arr[pos][2] = arr[pos - 1][2];

            arr[pos - 1][0] = t1;
            arr[pos - 1][1] = t2;
            arr[--pos][2] = t3;
        }
    }
}

void Sort::filterByExp(string arr[MAX_SIZE][3], string currentTime, int n)
{
    int j = 1;
    
    cout << "Daftar barang yang telah kadaluarsa:\n";
    for (int i = 0; i < n; ++i)
        if (stol(arr[i][2]) < stol(currentTime)) printArr(arr, i);
}

void Sort::filterByNotExp(string arr[MAX_SIZE][3], string currentTime, int n)
{
    int j = 1;

    cout << "Daftar barang yang belum kadaluarsa:\n";
    for (int i = 0; i < n; ++i)
        if (stol(arr[i][2]) > stol(currentTime)) printArr(arr, i);
}


