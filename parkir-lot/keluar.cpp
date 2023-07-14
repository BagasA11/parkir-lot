#include <iostream>
#include <vector>
#include "Kendaraan.h"
#include "utility.h"

using namespace std;

void menu_keluar(std::vector<Kendaraan>& var);

int main() {

    vector<Kendaraan> kendaraanVector;

    isi(kendaraanVector);
    int i = kendaraanVector.size();
    cout << endl << "N : " << i << endl;
    kendaraanVector[0].isPark = true;
    menu_keluar(kendaraanVector);
    //menu_keluar(kendaraanVector);
    //cout << endl << kendaraanVector[i].isPark << endl;

    return 0;
}


void menu_keluar(std::vector<Kendaraan>& var)
{
    if (var.size() == 0)
        {
            cout << "data tidak boleh kosong \n";
            return;
        }


    int i, n;
    bool status;

    cout << "pilih indeks kendaraan yang akan keluar: \n";
    cout << "[0"  << " ... " << n <<"]" <<endl;
    n = var.size();
    cin >> i;

    if (i >= n)
        {
            cout << "dilarang melebihi index maksimum \n";
            return menu_keluar(var);
        }


    status = var[i].isPark;
    //cout << endl << status << endl;
    //

    if (status == false) {
        cout << "pilih kendaraan lain ! \n";
        menu_keluar(var);
    }

    else {
        var[i].keluar();
        return;
    }
    //var[i].keluar();
    /*
    }*/
}
