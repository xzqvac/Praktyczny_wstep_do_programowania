#include <iostream>

using namespace std;

int main()
{
    int N;
    int wynik=1;
    cout<<"Podaj liczbe N: "<<endl;
    cin>>N;
    for (int i=N;i>1;i--)
    {
        wynik *= i;

    }
    cout<<N<<"!= "<<wynik<<endl;
    return 0;
}
