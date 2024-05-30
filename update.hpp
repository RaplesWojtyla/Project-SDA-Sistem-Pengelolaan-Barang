/*
    !! Created at 30/04/2024 -> Patra Rafles Wostyla Sinaga
    !! Updated At 03/05/2024 -> Ashnel Muhammad
    !! Updated at 14/05/2024 -> Patra Rafles Wostyla Sinaga

    Nama file: update.hpp
    Deskripsi: Header file untuk melakukan perubahan pada file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#define MAX_SIZE 100
using namespace std;

class UpdateFile : protected Sort
{   
    private:
        fstream file;
        struct tm exp;
        time_t currTime;
        long currentTime;
        string filename;
        string dataBarang[MAX_SIZE][3];
        int n;

    public:
        UpdateFile();
        void updateOption(); 
        void addItem();
        void updateItem();
        void deleteItem();
        void updateFile();
        int searchItem(string);
        ~UpdateFile() {file.close();}
};

UpdateFile::UpdateFile() 
{
    currTime = time(nullptr); // Waktu saat ini
    currentTime = currTime; // Menyimpan currTime ke dalam variable dengan tipe data long
    exp = {0};
    n = 0;
}

void UpdateFile::updateOption()
{
    cout << "Masukkan nama file: ";
    cin.ignore();
    getline(cin, filename);
    filename += ".txt";

    file.open(filename, ios::in);
    if(file.fail())
    {
        cout << "Gagal membuka file: " << filename << '\n';
        return;
    }

    int i = 0;
    while (!file.eof())
    {
        getline(file, dataBarang[i][0], ',');
        getline(file, dataBarang[i][1], ',');
        getline(file, dataBarang[i++][2], '\n');
    }
    file.close();
    n = i - 1;

    while (true)
    {
        system("cls");
        char c;

        cout << "\nMenu:\n";
        cout << "1. Tambah data barang." << '\n';
        cout << "2. Update data barang" << '\n';
        cout << "3. Hapus data barang." << '\n';
        cout << "4. Save" << '\n';
        cout << "q. Home" << '\n';
        cout << "Pilihan: ";
        cin >> c;

        switch(c)
        {
            case '1':
                addItem();
                break;
            case '2':
                updateItem();
                break;
            case '3':
                deleteItem();
                break;
            case '4':
                displayAllArr(dataBarang, n);
                char c;
                cout << "\nSimpan ke dalam file?[y/n] ";
                cin >> c;

                if (tolower(c) != 'y') break;
                updateFile();
                system("pause");
                return;
            case 'q':
                system("pause");
                return;
            default:
                cout << "Input tidak valid." << '\n';
                break;
        }
    }
}

void UpdateFile::addItem()
{
    int addon;
    cout << "\nBanyak barang yang ingin ditambahkan: ";
    cin >> addon;

    if (n + addon > MAX_SIZE) 
    {
        cerr << "Maksimum data yang dapat ditambahkan: " << MAX_SIZE << '\n';
        return;
    }
    
    int day, month, year;

    for (int i = n; i < n + addon; ++i)
    {
        cout << "Barang ke-" << i + 1 << ":\n";
        cout << "\tNama barang: ";
        cin.ignore();
        getline(cin, dataBarang[i][0]);

        cout << "\tBanyak barang (pcs): ";
        cin >> dataBarang[i][1];

        cout << "\tMasukkan tanggal kadaluarsa (DD MM YYYY): ";
        cin >> day >> month >> year;
        exp.tm_mday = day;
        exp.tm_mon = month - 1;
        exp.tm_year = year - 1900;
        dataBarang[i][2] = to_string(mktime(&exp));
    }
    n += addon;
}

void UpdateFile::updateItem()
{
    displayAllArr(dataBarang, n);

    int day, month, year;
    string itemName;

    cout << "\nMasukkan nama barang: ";
    cin.ignore();
    getline(cin, itemName);

    int idx = searchItem(tolowerCase(itemName));

    if (idx == -1)
    {
        cout << "Barang tersebut tidak ditemukan." << '\n';
        system("pause");
        return;
    }

    while(true)
    {
        system("cls");
        fflush(stdin);

        char c;

        cout << "Pilih nomor yang akan diupdate." << '\n';
        cout << "\t1. Nama barang: " << dataBarang[idx][0] << '\n';
        cout << "\t2. Banyak barang: " << dataBarang[idx][1] << '\n';

        char buff[80];
        time_t t = stol(dataBarang[idx][2]);
        tm *convert = localtime(&t);
        strftime(buff, 80, "%A, %d %B %Y", convert);

        cout << "\t3. Tanggal kadaluarsa: " << buff << '\n';
        cout << "\t4. Update semua." << '\n';
        cout << "\tq. Back." << '\n';
        cout << "Pilihan: ";

        cin >> c;

        switch(c)
        {
            case '1':
                cout << "Nama barang: ";
                cin.ignore();
                getline(cin, dataBarang[idx][0]);
                break;
            case '2':
                cout << "Banyak barang (pcs): ";
                cin >> dataBarang[idx][1];
                break;
            case '3':
                cout << "Tanggal kadaluarsa (DD MM YYYY): ";
                cin >> day >> month >> year;

                exp.tm_mday = day;
                exp.tm_mon = month - 1;
                exp.tm_year = year - 1900;
                dataBarang[idx][2] = to_string(mktime(&exp));
                break;
            case '4':
                cout << "\tNama barang: ";
                cin.ignore();
                getline(cin, dataBarang[idx][0]);

                cout << "\tBanyak barang (pcs): ";
                cin >> dataBarang[idx][1];

                cout << "\tMasukkan tanggal kadaluarsa (DD MM YYYY): ";
                cin >> day >> month >> year;

                exp.tm_mday = day;
                exp.tm_mon = month - 1;
                exp.tm_year = year - 1900;
                dataBarang[idx][2] = to_string(mktime(&exp));
                break;
            case 'q':
                system("cls");
                return;
            default:
                cout << "Input tidak valid." << '\n';
                system("pause");
                break;
        }
    }
}

void UpdateFile::deleteItem()
{
    displayAllArr(dataBarang, n);

    char c;
    string itemName;

    cout << "\nMasukkan nama barang: ";
    cin.ignore();
    getline(cin, itemName);

    int idx = searchItem(tolowerCase(itemName));

    if (idx == -1)
    {
        cout << "Barang tersebut tidak ditemukan." << '\n';
        system("pause");
        return;
    }

    printArr(dataBarang, idx);

    cout << "\nYakin akan menghapus barang tersebut?[y/n] ";
    cin >> c;

    if (tolower(c) == 'y')
    {
        --n;
        for (int i = idx; i < n; ++i)
        {
            dataBarang[i][0] = dataBarang[i + 1][0];
            dataBarang[i][1] = dataBarang[i + 1][1];
            dataBarang[i][2] = dataBarang[i + 1][2];
        }
    }
}

void UpdateFile::updateFile()
{
    file.open(filename, ios::out);

    for(int i = 0; i < n; ++i)
        file << dataBarang[i][0] << ',' << dataBarang[i][1] << ',' << dataBarang[i][2] << '\n';

    if (file.good()) cout << "\nBerhasil mengupdate file " << filename << '\n';
    else cout << "\nGagal mengupdate file " << filename << '\n';
}

int UpdateFile::searchItem(string target)
{
    ascSort(dataBarang, n);
    int l = 0, m, r = n - 1;

    while (l <= r)
    {
        m = l + (r - l) / 2;

        if (tolowerCase(dataBarang[m][0]) < target) l = m + 1;
        else if (tolowerCase(dataBarang[m][0]) > target) r = m - 1;
        else return m;
    }

    return -1;
}
