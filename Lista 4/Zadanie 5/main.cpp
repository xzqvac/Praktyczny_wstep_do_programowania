#include <iostream>
#include <fstream>
using namespace std;

int fibb(int a)
{
    if(a==0)
    {
        return 0;
    }
    else if(a==1)
    {
        return 1;
    }
    else
        return fibb(a-2) + fibb(a-1);
}

int main()
{
    int a;
    ofstream wynik;
    wynik.open("fib.dat.txt");
    cout << "Ile wyrazow ciagu Fibbonaciego chcesz zobaczyc?: "<<endl;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cout<<"Numer wyrazu "<<i<<" :"<<fibb(i)<<endl;
        wynik<<i<<" "<<fibb(i)<<endl;
    }
}
