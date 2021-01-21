#include <iostream>
#include <fstream>

using namespace std;

int fibonacci(int a)
{
    if(a == 0)
    {
        return 0;
    }
    else if(a==1)
    {
        return 1;
    }
    else
        return fibonacci(a-2) + fibonacci(a-1);
}

int liczbyGnomiczne(int b)
{
    return 2*b+1 + b*b;
}

int main()
{
    int a;
    int b;
    ofstream wynikfibonacci,wynikliczbyGnomiczne;
    wynikfibonacci.open("fib.dat.txt");
    wynikliczbyGnomiczne.open("lgn.dat.txt");
    cout << "Ile wyrazow ciagu Fibbonaciego chcesz zobaczyc?: "<<endl;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cout<<"Numer wyrazu "<<i<<" :"<<fibonacci(i)<<endl;
        wynikfibonacci<<i<<" "<<fibonacci(i)<<endl;
    }

    cout << "Liczby gnomiczne to liczby postaci 2n+1, ktore dodane do kwadratu liczby n daja kwadrat nastepnej liczby"<<endl;
    cout << "Ile wyrazow ciagu liczb gnomicznych chcesz zobaczyc?: "<<endl;
    cin>>b;

    for(int i=1;i<b;i++)
    {
        cout<<"Numer wyrazu "<<i<<" :"<<liczbyGnomiczne(i)<< endl;
        wynikliczbyGnomiczne<<i<<" "<<liczbyGnomiczne(i)<<endl;
    }

}
