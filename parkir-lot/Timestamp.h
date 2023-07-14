#include <iostream>
using namespace std;
//library utk rekap waktu
class Timestamp
{
    public :
        int jIn, mIn, dIn; //masuk parkir
        int jOut, mOut, dOut;//keluar parkir
        int jm, mn, dt; //selang waktu


       //default constructor
        Timestamp()
        {
            jIn = 0;
            mIn = 0;
            dIn = 0;

            jOut = 0;
            mOut = 0;
            dOut= 0;
        }


        //rekap jam masuk
        void jamMasuk()
          {
              int j, m, d;

              cout << "input jam : ";
              cin >> j;


              //validasi inputan jam
              if(j<0 || j >= 24){
                cout << "input jam dari 00 ... 23" << endl;
                return jamMasuk();
              }
              cout << "input menit : ";
              cin >> m;

              //validasi menit
              if(m < 0 || m >= 60){
                cout << "input menit dari 00 ... 59" << endl;
                return jamMasuk();
              }

                cout << "input detik : ";
                cin >> d;

              //validasi detik
              if(d < 0 || d >= 60){
                cout << "input detik dari 00 ... 59" << endl;
                return jamMasuk();
              }

            //setelah lolos validasi
            //assign variabel lokal ke variabel global
            jIn = j;
            mIn = m;
            dIn = d;
          }

        //tampil jam

         void displayWaktu(int &j, int &m, int &d)
          {
            cout << j << " : " << m<< " : " << d << endl;
          }

        //rekap jam keluar
        void jamKeluar()
        {

            int jO, mO, dO;

            cout << "input jam : ";
              cin >> jO;


              //validasi inputan jam
              if(jO<0 || jO >= 24){
                cout << "input jam dari 00 ... 23" << endl;
                return jamKeluar();
              }

              cout << "input menit : ";
              cin >> mO;

              //validasi menit
              if(mO < 0 || mO >= 60){
                cout << "input menit dari 00 ... 59" << endl;
                return jamKeluar();
              }

                cout << "input detik : ";
                cin >> dO;

              //validasi detik
              if(dO < 0 || dO >= 60){
                cout << "input detik dari 00 ... 59" << endl;
                return jamKeluar();
              }

            //setelah lolos validasi
            //assign variabel lokal ke variabel global

            jOut = jO;
            mOut = mO;
            dOut = dO;
        }

        //mengkonversi semua satuan waktu menjadi detik saat masuk
        int ke_detik(int jam, int menit, int detik)
        {
            return (jam*3600) + (menit * 60) + detik;
        }

        int konversi_jam(int detik)
        {
            return detik/3600;
        }

        int konversi_menit(int detik)
        {
            //jam = detik/3600
            //menit = detik - jam*3600
            //detik/3600
            return (detik%3600)/60;

        }

        int konversi_detik(int detik)
        {
            return (detik%3600)%60;
        }


};




