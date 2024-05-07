/*
    !! Created at 30/04/2005 -> Patra Rafles Wostyla Sinaga

    Nama file: gudang.hpp
    File ini berfungsi untuk menyimpan metode yang perlukan untuk mengelola barang
*/

#include "sort.hpp"

class Gudang : public Sort
{
    private:
        struct tm exp;

    public:
        Gudang() {exp = {0};}
        void displayOption();
        void addItem();
        void updateItem();
        void deleteItem();
        void tolowerCase(string &);
        int bSearch(string);
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

void Gudang::addItem()
{
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
    int idx;

    cout << "\nMasukkan nomor barang: ";
    cin >> idx;

    do
    {
        system("cls");
        fflush(stdin);

        cout << "Pilih nomor yang akan diupdate." << '\n';
        cout << "\t1. Nama barang: " << dataBarang[idx - 1][0] << '\n';
        cout << "\t2. Banyak barang: " << dataBarang[idx - 1][1] << '\n';

        char buff[80];
        time_t t = stol(dataBarang[idx - 1][2]);
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
                getline(cin, dataBarang[idx - 1][0]);
                break;
            case '2':
                cout << "Banyak barang (pcs): ";
                cin >> dataBarang[idx - 1][1];
                break;
            case '3':
                cout << "Tanggal kadaluarsa: ";
                cin >> day >> month >> year;

                exp.tm_mday = day;
                exp.tm_mon = month - 1;
                exp.tm_year = year - 1900;
                dataBarang[idx - 1][2] = to_string(mktime(&exp));
                break;
            case '4':
                cout << "\tNama barang: ";
                cin.ignore();
                getline(cin, dataBarang[idx - 1][0]);

                cout << "\tBanyak barang (pcs): ";
                cin >> dataBarang[idx - 1][1];

                cout << "\tMasukkan tanggal kadaluarsa (DD MM YYYY): ";
                cin >> day >> month >> year;

                exp.tm_mday = day;
                exp.tm_mon = month - 1;
                exp.tm_year = year - 1900;
                dataBarang[idx - 1][2] = to_string(mktime(&exp));
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

void Gudang::display()
{
    system("cls");
    cout << "\nDaftar Barang:\n";

    for (int i = 0; i < n; ++i)
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
}

void Gudang::tolowerCase(string &str)
{
    for (int i = 0; i < str.length(); ++i) str[i] = tolower(str[i]);
}
