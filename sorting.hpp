/* !!CREATED AT 02/05/2024 -> SYUJA AQILSYAH

    Nama File : sorting.hpp
    Deskripsi : File ini berfungsi untuk mensorting data array berdasarkan alfabeth, menggunakan quick sort
*/

#include <iostream>
#include <string>
using namespace std;

class AlfabethSorting {
public:
    // Fungsi untuk menukar dua string
    void swap(string& a, string& b) {
        string temp = a;
        a = b;
        b = temp;
    }
    // Fungsi untuk melakukan Quick Sort pada array string
    void quickSort(string arr[], int low, int high){
        if (low < high)
        {
            // Memilih elemen pivot
            string pivot = arr[high];           
            int i = low -1;

            // Langkah pembagian
            for (int j = low; j < high; j++)    
            {
                if (arr[j] < pivot)
                {
                    i++;
                    swap(arr[i], arr[j]);
                }    
            }
            swap(arr[i + 1], arr[high]);

            // Memanggil quickSort secara rekursif pada partisi
            int pi = i + 1;
            quickSort(arr, low, pi - 1);
            quickSort(arr,pi + 1,high);
        }
    }
};


// <--CARA PENGGUNAAN-->
// int main() {
//     string arr[] = {"apel", "jeruk", "pisang", "anggur", "kiwi", "nanas", "semangka", "stroberi", "mangga", "pir", "ceri", "blueberry", "lemon", "peach", "plum", "raspberry", "blackberry", "aprikot", "delima", "buah tin"};    
//     int n = sizeof(arr)/sizeof(arr[0]);

//     AlfabethSorting sort1;
//     sort1.quickSort(arr, 0, n-1);

//     cout << "Hasil Sorting Array: ";
//     for (int i=0; i < n; i++)
//         cout << arr[i] << " "<<"\n";
//     return 0;
// }