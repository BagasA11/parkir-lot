#include <iostream>
#include <fstream>
#include "Kendaraan.h"
#include "utility.h"
#include <vector>

using namespace std;

//package fitur2 jadi konsol

//fungsi cari data
void menu_cari(vector<Kendaraan>& var);

//cari data

void menu_update(vector<Kendaraan>& var);

//menampilkan semua data

void menu_tampil(vector<Kendaraan>& var);

//menu masuk
int menu_masuk(vector <Kendaraan> &var);

int menu_keluar(vector<Kendaraan>& var);

void konsol(vector <Kendaraan> &var, int &width);

//save data
void save(vector<Kendaraan>& var);
void saving(vector<Kendaraan>& var, int i);
void saveLine(int &n, vector<Kendaraan>& var);
int rekapPendapatan(vector<Kendaraan>& var);

//===========================================================

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


void menu_update(vector<Kendaraan>& var)
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


void menu_tampil(vector<Kendaraan>& var)
{
    int i = var.size();
    if(i == 0)
    {
        cout << "\n tambahkan data terlebih dahulu \n";
        return;
    }

    tampil(var, 0);
}

int menu_masuk(vector <Kendaraan> &var)
{
//local
int i;
bool status;

if(var.size() == 0)
{
    cout << "tambahkan data kendaraan lebih dulu \n";
    //return 0;
} else
{
    cout << "input index kendaraan yg akan masuk parkir [0 ... " << var.size() - 1<< "] : \n";
    cin >> i;

    if(i >= var.size())
    {
        cout <<"nilai tidak boleh melebihi batas maksimum \n";
        return menu_masuk(var);
    }

    status = var[i].isPark;

    if(status == true)
    {
        cout << "status" <<status <<endl;
        cout << "kendaraan ini sudah parkir. Silahkan pilih index yang lain !" <<endl;
        return menu_masuk(var);
    }


    rateGetter(var[i]);
    var[i].masuk();
    return i+1;
}

return 0;
}


int menu_keluar(vector<Kendaraan>& var)
{
    //local variable
    int i, n;
    bool status;

    if (var.size() == 0)
    {
        cout << "data tidak boleh kosong \n";
            //return;
    }
    else
    {
        cout << "pilih indeks kendaraan yang akan keluar: \n";
        n = var.size();
        cout << "[0"  << " ... " << n-1 <<"]" <<endl;
        cin >> i;

        if (i >= n)
        {
            cout << "dilarang melebihi atau menyamai index maksimum \n";
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
            return i+1;
        }
    }


    return 0;
}

void konsol(vector <Kendaraan> &var, int &width)
{
    /*
    1. tambah
    2. cari
    3. update
    4. lihat semua data
    5. masuk
    6. keluar
    7. exit

    */

    int pil;
    cout << "\n============================================  \n";
    cout << "   pilih menu  "<<endl;
    cout <<"1. tambah data\n 2. cari\n 3. update\n 4. lihat semua data \n 5. masuk parkir\n 6. keluar parkir\n 7. exit\n";
    cout << "============================================  \n";
    cout << "input pilihan : ";cin >> pil;

    if(pil == 1)
    {
        cout << "\n halaman tambah data\n";
            isi(var);
    } else if (pil == 2)
    {
        cout << "\n halaman cari data \n";
        menu_cari(var);
    } else if (pil == 3)
    {
         cout << "\n halaman update data \n";
        menu_update(var);
    } else if (pil == 4)
    {
        cout << "\n halaman lihat data \n \n \n";
        menu_tampil(var);
    } else if (pil == 5)
    {
        cout << "\n halaman menu masuk parkir\n";

        if(width == 0)
        {
            cout << "\n parkir penuh !!! \n";
            return konsol(var, width);
        }

        int x = menu_masuk(var);
        if(x > 0)
        {
            width -= var[x-1].width;
        }

    } else if (pil == 6)
    {
        cout << "\n halaman menu keluar parkir";
        int key = menu_keluar(var);

        if(key > 0){
            width += var[key-1].width;
        }

    } else
    {
        cout << "\n exit \n";
        return;
    }

    cout << "\n \n \n";
    return konsol(var, width);
}


void save(vector<Kendaraan>& var, int &width)
{
    //validasi
    if(var.size() == 0)
    {
        cout<<endl << "silahkan tambah data terlebih dahulu \n";
        konsol(var, width);
    }
    cout << "menyimpan data\n";
    saveLine(width, var);
    saving(var, 0);

}


void saving(vector<Kendaraan>& var, int i)
{
    ofstream myFile; //file stream instance
    myFile.open("data.txt", ios::app);

    if(i == var.size())
    {
        cout << endl << "proses save selesai" << endl;
        return;
    }

    cout << "data ke-"<<i+1<<endl;
    myFile << "plat nomor : " << var[i].platId;
    myFile << "\n jumlah roda : " << var[i].jmlRoda << endl;

    if(var[i].hasParking == true)
        {
            myFile << "\n waktu masuk: \n";
            myFile << "jam : " <<var[i].T.jIn <<" menit : "<< var[i].T.mIn<<" detik : "<<var[i].T.dIn << endl;
            myFile << "lokasi : "<< var[i].kolom <<" - "<<var[i].baris <<endl;

        } else {
             myFile << "\n waktu masuk: \n";
             myFile << "jam : - " <<" menit : - "<<" detik : - "<< endl;
             myFile << "lokasi : xx"<<endl;
        }

    if(var[i].hasExit == true)
    {
        myFile << "waktu keluar: \n";
        myFile << "jam: "<<var[i].T.jOut << " menit: "<<var[i].T.mOut<<" detik: " <<var[i].T.dOut<<endl;
        myFile << "\n durasi: \n";
        myFile << var[i].T.jm <<" jam "<<var[i].T.mn << " menit "<< var[i].T.dt <<" detik \n";
    } else {
        myFile << "waktu keluar: \n";
        myFile << "jam : - " <<" menit : - "<<" detik : - "<< endl;
        myFile << "\n durasi: \n";
        myFile <<" 0 jam "<<0 << " menit "<< 0 <<" detik \n";

    }

    myFile << "\n============================================  \n";
    myFile<<"\n \n";
    myFile.close();

    return saving(var, i+1);
}

void saveLine(int &n, vector<Kendaraan>& var)
{
    ofstream myFile; //file stream instance
    myFile.open("data.txt", ios::app);
    myFile << "\n============================================  \n";
    myFile << "total pendapatan hari ini : " << rekapPendapatan(var) << endl;
    myFile << "kapasitas tersedia : " << n << "\n";
    myFile << "\n============================================  \n \n";
    myFile.close();
}

int rekapPendapatan(vector<Kendaraan>& var)
{
    //local
    int n;

    for(int i = 0; i < var.size();i++)
    {
        if(var[i].rateTotal > 0){
            n += var[i].rateTotal;
        }

    }

    return n;
}
