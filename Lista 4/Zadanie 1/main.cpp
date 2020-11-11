#include <iostream>

using namespace std;

int a(void)
{
    cout<<"Hello world"<<endl;
    return 0;
}

float b(float a)
{
    cout<<"Zwrocona liczba: "<<a<<endl;
}

int c(int x, int y)
{
    int suma;
    suma = x+y;
    cout<<"Suma argumentow: "<<suma<<endl;
}

int d(int a, float b, float c)
{
    int iloczyn;
    iloczyn = a*b*c;
    return iloczyn;
}

float e(int tab[],int i)
{
    int ilt=1;
    for(int j=0; j<i; j++)
    {
      ilt *= tab[i];
    }
    return ilt;
}
int main()
{
    a();
    b(0.7);
    c(1,2);
    cout<<"D) "<<d(9,7.9,7.8)<<endl;
    int i=5;
    int tab[i] = {1, 2, 3, 4, 5};
    cout<<"E) "<<e(tab,5);
    return 0;
}
