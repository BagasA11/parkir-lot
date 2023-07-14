#include <iostream>

#include "Kendaraan.h"
#include "utility.h"
#include <vector>

using namespace std;

void menu_masuk(vector <Kendaraan> &var);
int main()
{

vector <Kendaraan> x;
isi(x);
//isi(x);

cout << x[0].isPark <<endl;
cout << endl;

menu_masuk(x);
cout << endl;
cout << x[0].isPark<<endl;


return 0;
}

void menu_masuk(vector <Kendaraan> &var)
{
//local
int i;
bool status;

if(var.size() == 0)
{
    cout << "tambahkan data kendaraan lebih dulu \n";
    return;
}

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

var[i].masuk();
return;
}
