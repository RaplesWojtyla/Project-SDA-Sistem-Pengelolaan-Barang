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
        cout << "4. Tambah data barang." << '\n';
        cout << "5. Delete data barang." << '\n';
        cout << "6. Filter data barang" << '\n';
        cout << "7. Cari data barang" << '\n';
        cout << "q. Exit." << '\n';
        cout << "Pilihan: ";

        cin.get(c);

        switch(c)
        {
            case '1':
                gudangBarang.createItem();
                break;
            case '2':
                gudangBarang.displayOption();
                break;
            case '3':
                gudangBarang.updateItem();
                break;
            case '4':
                gudangBarang.addItem();
                break;
            case '5':
                gudangBarang.deleteItem();
                break;
            case '6':
                gudangBarang.filterOption();
                break;
            case '7':
                gudangBarang.searchItem();
                system("pause");
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