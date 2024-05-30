/*
    !! Created at 30/04/2024 -> Patra Rafles Wostyla Sinaga
    !! Updated at 14/05/2024 -> Patra Rafles Wostyla Sinaga

    Nama file: create.hpp
    Deskripsi: Header file untuk membuat file baru untuk menyimpan data barang
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#define MAX_SIZE 100
using namespace std;


class Create
{
    private:
        struct tm exp;
        ofstream ofile;
        string filename;
        int n;
    
    public:
        Create() {n = 0, exp = {0};}
        void createFile();
        ~Create() {ofile.close();}
};

void Create::createFile()
{
    cout << "Masukkan nama file: ";
    cin.ignore();
    getline(cin, filename);
    filename += ".txt";

    ofile.open(filename);
    if(ofile.fail())
    {
        cout << "Gagal membuka file: " << filename << '\n';
        return;
    }

    cout << "\nBanyak barang yang akan ditambahkan: ";
    cin >> n;

    if (n > MAX_SIZE) 
    {
        cerr << "Maksimum data yang dapat ditambahkan: " << MAX_SIZE << '\n';
        return;
    }

    int day, month, year, quantity;
    string itemName, expDate;

    for (int i = 0; i < n; ++i)
    {
        cout << "Barang ke-" << i + 1 << ":\n";
        cout << "\tNama barang: ";
        cin.ignore();
        getline(cin, itemName);

        cout << "\tBanyak barang (pcs): ";
        cin >> quantity;

        cout << "\tMasukkan tanggal kadaluarsa (DD MM YYYY): ";
        cin >> day >> month >> year;
        exp.tm_mday = day;
        exp.tm_mon = month - 1;
        exp.tm_year = year - 1900; // Epoch Time
        expDate = to_string(mktime(&exp));

        ofile << itemName << ',' << quantity << ',' << expDate << '\n';
    }

    if(ofile.good()) cout << "\nBerhasil membuat file data barang" << '\n';
    else cout << "Gagal menulis data barang" << '\n';
}