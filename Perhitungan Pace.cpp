#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definisi struct untuk menyimpan data lari
struct DataLari {
    string nama;
    string jenisKelamin;
    double totalWaktuMenit;
    double totalWaktuDetik;
    double totalJarak;

    // Fungsi untuk menghitung pace
double hitungPace(double totalWaktuMenit, double totalWaktuDetik, double totalJarak) {
    double totalWaktu = totalWaktuMenit + (totalWaktuDetik / 60.0);
    return totalWaktu / totalJarak;
}

// Fungsi untuk menghitung kecepatan (speed) dalam satuan detik
double hitungKecepatanDetik(double totalWaktuMenit, double totalWaktuDetik, double totalJarak) {
    double totalWaktuDetikTotal = (totalWaktuMenit * 60) + totalWaktuDetik;
    return totalJarak / totalWaktuDetikTotal; // dalam detik per kilometer
}
}


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