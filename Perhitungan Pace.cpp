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
// Fungsi untuk menentukan intensitas berdasarkan kecepatan
string tentukanIntensitas(double kecepatanDetik) {
    double kecepatanMph = kecepatanDetik * 0.0372823; 
    double paceMenit = 3600 / (kecepatanDetik * 60); 

    if (kecepatanMph < 3) {
        return "Intensitas Ringan: Pace lebih dari 20 menit per mil";
    } else if (kecepatanMph >= 3 && kecepatanMph < 4) {
        return "Intensitas Sedang: Pace antara 16 dan 20 menit per mil";
    } else if (kecepatanMph >= 4 && kecepatanMph < 5) {
        return "Intensitas Menengah: Pace antara 12 dan 15 menit per mil";
    } else {
        return "Intensitas Tinggi: Pace kurang dari 12 menit per mil";
    }
}
// Fungsi untuk menentukan rekomendasi berdasarkan umur dan jenis kelamin
string rekomendasi(string jenisKelamin, int umur) {
    if (jenisKelamin == "pria") {
        if (umur <= 30)
            return "Pace yang sangat bagus.";
        else if (umur <= 45)
            return "Pace yang baik.";
        else
            return "Pace yang lumayan.";
    } else if (jenisKelamin == "wanita") {
        if (umur <= 30)
            return "Pace yang sangat bagus.";
        else if (umur <= 45)
            return "Pace yang baik.";
        else
            return "Pace yang lumayan.";
    }
    return "";


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