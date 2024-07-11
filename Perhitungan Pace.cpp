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
};

// Fungsi untuk menghitung pace
double hitungPace(double totalWaktuMenit, double totalWaktuDetik, double totalJarak) {
    double totalWaktu = totalWaktuMenit + (totalWaktuDetik / 60.0);
    return totalWaktu / totalJarak;
}

// Fungsi untuk menghitung kecepatan (speed) dalam satuan detik
double hitungKecepatanDetik(double totalWaktuMenit, double totalWaktuDetik, double totalJarak) {
    double totalWaktuDetikTotal = (totalWaktuMenit * 60) + totalWaktuDetik;
    return totalJarak / totalWaktuDetikTotal; // dalam kilometer per detik
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
    vector<DataLari> dataLariArray;
    const int MAX_SIMPANAN = 5;

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
                if (dataLariArray.size() >= MAX_SIMPANAN) {
                    dataLariArray.erase(dataLariArray.begin());
                }

                DataLari data;
                cout << "Masukkan nama Anda: ";
                cin >> data.nama;
                cout << "Masukkan jenis kelamin (pria/wanita): ";
                cin >> data.jenisKelamin;
                cout << "Masukkan total waktu lari (menit): ";
                cin >> data.totalWaktuMenit;
                cout << "Masukkan total waktu lari (detik): ";
                cin >> data.totalWaktuDetik;
                cout << "Masukkan total jarak lari (kilometer): ";
                cin >> data.totalJarak;

                dataLariArray.push_back(data);
                cout << "Data lari berhasil disimpan." << endl;
                break;
            }

            case 2: {
                if (dataLariArray.empty()) {
                    cout << "Belum ada data lari yang dimasukkan." << endl;
                } else {
                    for (int i = 0; i < dataLariArray.size(); ++i) {
                        DataLari data = dataLariArray[i];
                        double pace = hitungPace(data.totalWaktuMenit, data.totalWaktuDetik, data.totalJarak);
                        double kecepatanDetik = hitungKecepatanDetik(data.totalWaktuMenit, data.totalWaktuDetik, data.totalJarak);

                        cout << "=== Data Lari " << i + 1 << " ===" << endl;
                        cout << "Nama: " << data.nama << endl;
                        cout << "Jenis Kelamin: " << data.jenisKelamin << endl;
                        cout << "Total Waktu (menit): " << data.totalWaktuMenit << endl;
                        cout << "Total Waktu (detik): " << data.totalWaktuDetik << endl;
                        cout << "Total Jarak (kilometer): " << data.totalJarak << endl;

                        // Periksa jika waktu terlalu lama dan kecepatan terlalu lambat
                        if (pace > 20 || kecepatanDetik < 0.00027778) {
                            cout << "Maaf, kami tidak bisa menghitung pace lari Anda dikarenakan waktu tempuh yang lama dan kecepatan Anda terlalu lambat." << endl;
                        } else {
                            cout << "Pace: " << pace << " menit per kilometer" << endl;
                            cout << "Kecepatan (dalam detik per kilometer): " << kecepatanDetik << " detik per kilometer" << endl;
                            cout << "Intensitas: " << tentukanIntensitas(kecepatanDetik) << endl;

                            int umur;
                            cout << "Masukkan umur Anda: ";
                            cin >> umur;
                            cout << "Rekomendasi: " << rekomendasi(data.jenisKelamin, umur) << endl;
                        }

                        cout << endl;
                    }
                }
                break;
            }
            case 3:
                cout << "Aplikasi keluar" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 3);

    return 0;
}
