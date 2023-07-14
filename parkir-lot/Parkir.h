#include <iostream>

#ifndef PARKIR_H
#define PARKIR_H
#include "Timestamp.h"

using namespace std;
class Parkir{

public:
    //property

    //lokasi parkir
    char kolom;
    int baris,
        rateHour,
        rateTotal;
    //bool kosong; //T or F
    bool isPark = false; // define kendaraan sudah masuk parkir atau blm ?
    bool hasParking = false, hasExit = false;
    Timestamp T; //acces library waktu

    //method

    // masuk method
    void masuk();
    void set_location();
    //void reset_location();
    void keluar();
    int countTotal(int &jam, int &rate);

};

void Parkir::masuk()
{
        //atur lokasi <huruf, angka>

        //catat jam masuk

        cout << "masuk : " << endl;
        T.jamMasuk();
        cout << "Selamat datang : " ; T.displayWaktu(T.jIn, T.mIn, T.dIn) ;
        cout<< endl;
        Parkir::set_location();
        hasParking = true;
        isPark = true; //mobil sedang parkir
}

void Parkir::keluar()
{
     //catat jam keluar
        cout << "\n keluar : \n" ;
        T.jamKeluar();
        //mengecek apakah waktu masuk lebih awal dari waktu keluar ?
        //if awal - akhir negatif atau 0
        //<=0
        if(T.ke_detik(T.jIn, T.mIn, T.dIn) - T.ke_detik(T.jOut, T.mOut, T.dOut)>0)
        {
           cout << "input tidak valid \n";
            return keluar();
        }


        int dura = T.ke_detik(T.jOut, T.mOut, T.dOut) - T.ke_detik(T.jIn, T.mIn, T.dIn);
        //set koversi waktu
        //jam
        T.jm = T.konversi_jam(dura);
        //menit
        T.mn = T.konversi_menit(dura);
        T.dt = T.konversi_detik(dura);
        cout << "anda parkir selama " << T.jm << " jam " << T.mn << " menit " << T.dt << " detik "<<endl;

        cout << "anda keluar pukul : ";

        T.displayWaktu(T.jOut, T.mOut, T.dOut);

        rateTotal = countTotal(T.jm, rateHour);
        cout << "\n biaya parkir : " << rateTotal << endl;
        //Parkir::reset_location();

        hasExit = true;
        isPark = false; //mobil tidak parkir
}

void Parkir::set_location()
{
    int rw;
    char clm;

    cout << "silahkan pilih lokasi parkir anda \n";
    cout << "pilih kolom [A .... Z] : ";cin >> clm;

    cout << "masukkan baris : ";cin >> rw;
    if(rw <= 0){
        cout <<endl<< "harus lebih dari 0" <<endl;
        return Parkir::set_location();
    }
    kolom = clm;
    baris = rw;
    return;
}

/*void Parkir::reset_location()
{
    //mereset nilai kolom dan baris
    //variabel kosong


    //assign dgn variabel kosong
    kolom = 0;
    baris = '#';
}
*/

int Parkir::countTotal(int &jam, int &rate)
{
    if(jam <=1 )
    {
        return rate;
    } else {

    return rate * jam;
    }
}

#endif //PARKIR_H
