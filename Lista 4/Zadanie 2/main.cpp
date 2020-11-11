#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int main()
{
    float liczba;
    float suma;
    float srednia=0;
    ofstream wyniki;
    wyniki.open("srednia.dat.txt");
    srand(time(NULL));
    for(int n = 10; n <= 5000; n++ )
    {
        suma=0;
        for(int i=1; i<=n;i++)
        {
        liczba=(float(rand())/RAND_MAX);
        suma+=liczba;
        }
        srednia=suma/n;
        cout<<"Srednia dla N = "<<n<<" "<<srednia<<endl;
        wyniki<<n<<" "<<srednia<<endl;

    }
}
