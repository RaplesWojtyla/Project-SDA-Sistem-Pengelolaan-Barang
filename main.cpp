/*
    !! Created at 30/04/2024 -> Patra Rafles Wostyla Sinaga

    Nama file: main.cpp
    File ini sebagai file utama yang akan dijalankan
*/

#include "gudang.hpp"


int main()
{
    Gudang gudangBarang;
    char c;

    do
    {
        system("cls");
        fflush(stdin);

        cout << "\n1. Create data barang." << '\n';
        cout << "2. Show data barang." << '\n';
        cout << "3. Update data barang." << '\n';
        cout << "4. Delete data barang." << '\n';
        cout << "5. Filter barang" << '\n';
        cout << "q. Exit." << '\n';
        cout << "Pilihan: ";

        cin.get(c);

        switch(c)
        {
            case '1':
                gudangBarang.addItem();
                break;
            case '2':
                gudangBarang.displayOption();
                break;
            case '3':
                gudangBarang.updateItem();
                break;
            case '4':
                break;
            case '5':
                break;
            case 'q': 
                system("cls");
                break;
            default: 
                cout << "Input tidak valid." << '\n';
                break;
        }
    } while (tolower(c) != 'q');


    return 0;
}