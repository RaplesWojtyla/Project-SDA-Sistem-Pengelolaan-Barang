/*
    !! Created at 30/04/2024 -> Patra Rafles Wostyla Sinaga
    !! Updated at 12/05/2024 -> Patra Rafles Wostyla Sinaga

    Nama file: main.cpp
    Deskripsi: Ini adalah program sederhana untuk mengelola barang pada suatu gudang
*/

#include <windows.h>
#include "print.hpp"
#include "sort.hpp"
#include "create.hpp"
#include "read.hpp"
#include "update.hpp"


int main()
{
    while(true)
    {
        system("cls");

        Create create;
        Read read;
        UpdateFile update;
        char c;

        cout << "\n1. Create file data barang." << '\n';
        cout << "2. Read file data barang." << '\n';
        cout << "3. Update file data barang." << '\n';
        cout << "q. Exit." << '\n';
        cout << "Pilihan: ";

        cin >> c;

        switch(c)
        {
            case '1':
                create.createFile();
                system("pause");
                break;
            case '2':
                read.readFile();
                system("pause");
                break;
            case '3':
                update.updateOption();
                break;
            case 'q':
                system("cls");
                exit(0);
            default:
                cout << "Input tidak valid." << '\n';
                break;
        }
    }

    return 0;
}
