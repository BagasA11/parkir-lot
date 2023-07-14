#include <iostream>
#include <vector>
#include "utility.h" // File header yang berisi definisi fungsi cari

using namespace std;

void menu_cari(vector<Kendaraan>& var)
{
    int n = var.size();

    if (n == 0) {
        cout << "Tidak ada kendaraan dalam daftar." << endl;
        return;
    }

    string plat;
    cout << "Masukkan nomor plat kendaraan: ";
    cin >> plat;

    if (plat.size() >= 7 && plat.size() <= 8) {
        int pos = cari(var, n, plat); // Memanggil fungsi cari dari utility.h
        cout << "Posisi kendaraan: " << pos << endl;
    } else {
        cout << "Jumlah karakter plat kendaraan harus di antara 7-8 karakter." << endl;
        menu_cari(var); // Memanggil kembali fungsi menu_cari untuk mengisi ulang
    }
}

int main() {
    // Contoh penggunaan fungsi menu_cari
    vector<Kendaraan> kendaraanList; // Vector kendaraan
    // Isi vector kendaraanList dengan data kendaraan
    isi(kendaraanList);
    menu_cari(kendaraanList);

    return 0;
}
