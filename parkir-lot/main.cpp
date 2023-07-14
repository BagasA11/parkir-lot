#include <iostream>
#include "konsol.h"
//#include "utility.h" // input output cari
#include "Kendaraan.h"
#include <vector>
using namespace std;



int main()
{

vector <Kendaraan> obj;
int maxWidth = 50;
//isi(obj);
//isi(obj);

konsol(obj, maxWidth);

cout <<endl<< rekapPendapatan(obj) << endl;
save(obj, maxWidth);
return 0;
}
