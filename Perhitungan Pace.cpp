#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    int pilihan;
    do {
        cout << "=== Program Penghitung Pace Lari ===" << endl;
        cout << "1. Input data lari" << endl;
        cout << "2. Tampilkan hasil perhitungan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                
                cout << "" << endl;
                break;
            }
            case 2: {
                
                cout << "" << endl;
                break;
            }
            case 3:
                cout << "aplikasi keluar" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 3);

    return 0;
}