/*
    !! Created At 30/04/2024 -> Patra Rafles Wostyla Sinaga
    !! Updated At 03/05/2024 -> Ashnel Muhammad
    !! Updated at 12/05/2024 -> Patra Rafles Wostyla Sinaga

    Nama file: gudang.hpp
    Ini merupakan header file yang berfungsi untuk menyimpan metode yang perlukan untuk mengelola barang
*/

#include "sort.hpp"

class Gudang : public Sort
{
    public:
        Gudang() {}
        void displayOption();
        void filterOption();
        void createItem();
        void addItem();
        void updateItem();
        void deleteItem();
        int searchItem(string);
        string tolowerCase(string);
        void display();
        ~Gudang(){};
};

void Gudang::displayOption()
{
    char c;

    do
    {
        fflush(stdin);

        cout << "\nDisplay barang berdasarkan:\n";
        cout << "1. Default" << '\n';
        cout << "2. Abjad (asc)." << '\n';
        cout << "3. Abjad (desc)." << '\n';
        cout << "4. Tanggal Kadaluarsa." << '\n';
        cout << "q. Home" << '\n';
        cout << "Pilihan: ";
        
        cin.get(c);

        switch (c)
        {
            case '1':
                display();
                break;
            case '2':
                ascSort();
                display();
                break;
            case '3':
                descSort();
                display();
                break;
            case '4':
                sortByExp();
                display();
                break;
            case 'q':
                system("cls");
                break;
            default:
                cout << "Input tidak valid." << '\n';
                break;
        }
    } while (tolower(c) != 'q');
}

void Gudang::filterOption()
{
    char c;

    do
    {
        fflush(stdin);

        cout << "\nFilter barang:\n";
        cout << "1. Telah kadaluarsa." << '\n';
        cout << "2. Belum kadaluarsa." << '\n';
        cout << "q. Home" << '\n';
        cout << "Pilihan: ";
        
        cin.get(c);

        switch (c)
        {
            case '1':
                system("cls");
                filterByExp();
                break;
            case '2':
                system("cls");
                filterByNotExp();
                break;
            case 'q':
                system("cls");
                break;
            default:
                cout << "Input tidak valid." << '\n';
                break;
        }
    } while (tolower(c) != 'q');
}

void Gudang::createItem()
{
    if (n > 0)
    {
        cerr << "Data barang telah ada." << '\n';
        return;
    }

    cout << "\nBanyak barang yang akan ditambahkan: ";
    cin >> n;

    if (n > MAX_SIZE) 
    {
        cerr << "Maksimum data yang dapat ditambahkan: " << MAX_SIZE << '\n';
        return;
    }

    int day, month, year;

    for (int i = 0; i < n; ++i)
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
}

void Gudang::updateItem()
{
    display();

    char c;
    int day, month, year;
    string itemName;

    cout << "\nMasukkan nama barang: ";
    cin.ignore();
    getline(cin, itemName);

    int idx = searchItem(tolowerCase(itemName));

    if (idx == -1)
    {
        cout << "Barang tersebut tidak ditemukan." << '\n';
        return;
    }

    do
    {
        system("cls");
        fflush(stdin);

        cout << "Pilih nomor yang akan diupdate." << '\n';
        cout << "\t1. Nama barang: " << dataBarang[idx][0] << '\n';
        cout << "\t2. Banyak barang: " << dataBarang[idx][1] << '\n';

        char buff[80];
        time_t t = stol(dataBarang[idx][2]);
        tm *convert = localtime(&t);
        strftime(buff, 80, "%A, %d %B %Y", convert);

        cout << "\t3. Tanggal kadaluarsa: " << buff << '\n';
        cout << "\t4. Update semua." << '\n';
        cout << "\tq. Home." << '\n';
        cout << "Pilihan: ";

        cin.get(c);

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
                break;
            default:
                cout << "Input tidak valid." << '\n';
                break;
        }
    } while (tolower(c) != 'q');
}

void Gudang::addItem()
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

void Gudang::deleteItem()
{
    display();

    char c;
    string itemName;

    cout << "\nMasukkan nama barang: ";
    cin.ignore();
    getline(cin, itemName);

    int idx = searchItem(tolowerCase(itemName));

    if (idx == -1)
    {
        cout << "Barang tersebut tidak ditemukan." << '\n';
        return;
    }

    print(idx);

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

int Gudang::searchItem(string target)
{
    ascSort();
    int l = 0, m, r = n - 1;

    while (l <= r)
    {
        m = l + (r - l) / 2;

        if (tolowerCase(dataBarang[m][0]) > target) r = m - 1;
        else if (tolowerCase(dataBarang[m][0]) < target) l = m + 1;
        else return m;
    }

    return -1;
}

string Gudang::tolowerCase(string str)
{
    string ret = "";
    for (int i = 0; i < str.length(); ++i) ret += tolower(str[i]);

    return ret;
}   

void Gudang::display()
{
    system("cls");
    cout << "\nDaftar Barang:\n";

    for (int i = 0; i < n; ++i) print(i);
}

