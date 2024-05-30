/*
    !! Created at 30/04/2024 -> Patra Rafles Wostyla Sinaga
    !! Updated at 14/05/2024 -> Patra Rafles Wostyla Sinaga

    Nama file: read.hpp
    Deskripsi: Header file untuk membaca file
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#define MAX_SIZE 100
using namespace std;

class Read : protected Sort
{
    private:
        ifstream ifile;
        struct tm exp;
        time_t currTime;
        long currentTime;
        string filename;
        string dataBarang[MAX_SIZE][3];
        int n;

    public: 
        Read();
        void displayOption();
        void readFile();
        void updateItem();
        ~Read() {ifile.close();}
};

Read::Read() 
{
    currTime = time(nullptr); // Waktu saat ini
    currentTime = currTime;
    exp = {0};
    n = 0;
}

void Read::displayOption()
{
   while (true)
    {
        char c;

        cout << "\nDisplay barang berdasarkan:\n";
        cout << "1. Default" << '\n';
        cout << "2. Abjad (asc)." << '\n';
        cout << "3. Abjad (desc)." << '\n';
        cout << "4. Tanggal Kadaluarsa." << '\n';
        cout << "5. Barang sudah kadaluarsa." << '\n';
        cout << "6. Barang belum Kadaluarsa." << '\n';
        cout << "q. Home" << '\n';
        cout << "Pilihan: ";
        cin >> c;

        switch (c)
        {
            case '1':
                displayAllArr(dataBarang, n);
                break;
            case '2':
                ascSort(dataBarang, n);
                displayAllArr(dataBarang, n);
                break;
            case '3':
                descSort(dataBarang, n);
                displayAllArr(dataBarang, n);
                break;
            case '4':
                sortByExp(dataBarang, n);
                displayAllArr(dataBarang, n);
                break;
            case '5':
                system("cls");
                filterByExp(dataBarang, currentTime, n);
                break;
            case '6':
                system("cls");
                filterByNotExp(dataBarang, currentTime, n);
                break;
            case 'q':
                return;
            default:
                cout << "Input tidak valid." << '\n';
                break;
        }
    } 
}

void Read::readFile()
{
    cout << "Masukkan nama file: ";
    cin >> filename;
    filename += ".txt";

    ifile.open(filename);
    if (ifile.fail())
    {
        cout << "Gagal membuka file: " << filename << '\n';
        return;
    }

    int i = 0;
    while (!ifile.eof())
    {
        getline(ifile, dataBarang[i][0], ',');
        getline(ifile, dataBarang[i][1], ',');
        getline(ifile, dataBarang[i++][2], '\n');
    }
    n = i - 1;

    displayOption();
}
