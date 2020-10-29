#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
    fstream plik;
    plik.open("wynik.dat", ios::app);

    for(float x=0; x<2*3.1415; x+=0.15)
    {
        cout << x << "\t" << cos(x) << "\t" << cos(x)*cos(x) << endl;
        plik << x << "\t" << cos(x) << "\t" << cos(x)*cos(x) << endl;
    }


}


