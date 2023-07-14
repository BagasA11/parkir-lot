//library untuk melakukan utilitas
//input plat nomor dan roda
//cari plat nomor
//output
//-----------------------------------------------------------------------

#include <iostream>

#include "Kendaraan.h"
#include <vector>
using namespace std;


string capslock(string &txt, int i);

void isi(vector <Kendaraan> &var);


int cari(vector <Kendaraan> &var, int num, string key);

void tampil(vector <Kendaraan> &var, int num);

void update(vector <Kendaraan> &var);

void rateGetter(Kendaraan &var);
//-----------------------------------------------------
//-----------------------------------------------------





//konversi huruf kecil ke besar
string capslock(string &txt, int i)
{
        if(txt[i] == 'a')
        {
            txt[i] = 'A';
        }
        //b
        if(txt[i] == 'b')
        {
            txt[i] = 'B';
        }
        //c
        if(txt[i] == 'c')
        {
            txt[i] = 'C';
        }
        //d
        if(txt[i] == 'd')
        {
            txt[i] = 'D';
        }
        //e
        if(txt[i] == 'e')
        {
            txt[i] = 'E';
        }
        //f
        if(txt[i] == 'f')
        {
            txt[i] = 'F';
        }
        //g
        if(txt[i] == 'g')
        {
            txt[i] = 'G';
        }
        //h
        if(txt[i] == 'h')
        {
            txt[i] = 'H';
        }
        //i
        if(txt[i] == 'i')
        {
            txt[i] = 'I';
        }
        //j
        if(txt[i] == 'j')
        {
            txt[i] = 'J';
        }
        //k
        if(txt[i] == 'k')
        {
            txt[i] = 'K';
        }
        //l
        if(txt[i] == 'l')
        {
            txt[i] = 'L';
        }
        //m
        if(txt[i] == 'm')
        {
            txt[i] = 'M';
        }
        //n
        if(txt[i] == 'n')
        {
            txt[i] = 'N';
        }
        //o
        if(txt[i] == 'o')
        {
            txt[i] = 'O';
        }
        //p
        if(txt[i] == 'p')
        {
            txt[i] = 'P';
        }
        //q
        if(txt[i] == 'q')
        {
            txt[i] = 'Q';
        }
        //r
        if(txt[i] == 'r')
        {
            txt[i] = 'R';
        }
        //s
        if(txt[i] == 's')
        {
            txt[i] = 'S';
        }
        //t
        if(txt[i] == 't')
        {
            txt[i] = 'T';
        }
        //u
        if(txt[i] == 'u')
        {
            txt[i] = 'U';
        }
        //v
        if(txt[i] == 'v')
        {
            txt[i] = 'V';
        }
        //w
        if(txt[i] == 'w')
        {
            txt[i] = 'W';
        }
        //x
        if(txt[i] == 'x')
        {
            txt[i] = 'X';
        }
        //y
        if(txt[i] == 'y')
        {
            txt[i] = 'Y';
        }
        //z
        if(txt[i] == 'z')
        {
            txt[i] = 'Z';
        }

    if(i<txt.size())
    {
        return capslock(txt, i+1);
    } else
    {
        return txt;
    }

}

//melakukan insert element dari paling belakang
void isi(vector <Kendaraan> &var)
{
    //local variabel
    int roda;
    string plat;

    cout << "input plat nomer : ";
    cin >> plat;

    cout << "input jumlah roda : ";
    cin >> roda;

    if(roda >=2 && roda <= 6)
    {

        if(plat.size()>=7 && plat.size()<=8){
            cout << "input berhasil \n";
            Kendaraan input_field(capslock(plat, 0), roda);
            var.push_back(input_field);
        } else {

            cout << "jumlah karakter harus antara 7/8\n" ;
            return isi(var);
        }

    }
    else {
        cout << "inputan salah \n";
        return isi(var);
    }
}

//mencari plat id
int cari(vector <Kendaraan> &var, int num, string key)
{
     if(num < 0)
    {
        return -1;
    }

    //descending
    //if ketemu
    if(capslock(key, 0) == var[num-1].platId)
    {
        return num;
    }
    else {
        return cari(var, num-1, key);
    }


}

void tampil(vector <Kendaraan> &var, int i)
{
    //batas akhir indeks
      if(i == var.size())
        {

            return;

        }

    cout << "data ke " << i+1 <<endl;
    cout << "plat : " << var[i].platId << endl;
    cout << "roda : " << var[i].jmlRoda << endl;
    cout << endl;


    return tampil(var, i+1);

}

void update(vector <Kendaraan> &var)
{
    int i, roda;
    string plat;
    cout << "pilih indeks yang ingin diupdate [0 ... "<<var.size()-1<<"] : ";
    cin >> i;
    if(i >= var.size()){
            cout << "indeks harus lebih kecil dari nilai maksimum \n";
        return update(var);

    }

     cout << "input plat nomer : ";
    cin >> plat;

    cout << "input jumlah roda : ";
    cin >> roda;

    if(roda >=2 && roda <= 6)
    {

        if(plat.size()>=7 && plat.size()<=8){
            cout << "update berhasil \n";
            var[i].platId = capslock(plat, 0);
            var[i].jmlRoda = roda;

        } else {

            cout << "jumlah karakter harus antara 7/8\n" ;
            update(var);
        }

    }
    else {
        cout << "inputan salah \n";
        update(var);
    }

    return;
}

void rateGetter(Kendaraan &var)
{
    if(var.jmlRoda <=2){
        var.rateHour = 1000;
    } else {
        var.rateHour = 3000;
    }
}
