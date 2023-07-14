#include <iostream>
#include <vector>
#include "Kendaraan.h" // Anggaplah kelas Kendaraan didefinisikan dalam Kendaraan.h
#include "utility.h" // Anggaplah fungsi update didefinisikan dalam utility.h

void menu_update(std::vector<Kendaraan>& var)
{
    int n = var.size();

    if (n > 0) {
        update(var);
    }
    else {
        cout << "data tidak ada \n";
        return;
    }
}

int main() {
    // Contoh penggunaan
    std::vector<Kendaraan> kendaraanVector;
    // Anggap kendaraanVector sudah diisi dengan objek-objek Kendaraan
    isi(kendaraanVector);
    menu_update(kendaraanVector);
}
