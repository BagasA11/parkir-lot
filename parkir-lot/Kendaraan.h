#include <iostream>
#ifndef KENDARAAN_H
#define KENDARAAN_H

#include "Parkir.h"
using namespace std;
class Kendaraan: public Parkir
{
    public :
        string platId; // plat nomer
        int jmlRoda; //jml roda
        int width; //lebar kendaraan

        Kendaraan(string plat, int roda)
        {
            platId = plat;
            jmlRoda = roda;

            if(roda <= 2){
                width = 1;
            } else {
                width = 3;
            }
        }

};
#endif //KENDARAAN_H
