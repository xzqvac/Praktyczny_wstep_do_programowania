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
    cout<<"Najwyzsza wartoscia dla jakiej otrzymuje poprawne wartosci to N=12."<<endl;
    cout<<"Dla N = 13 zmienna typu int nie przechowuje wartosci, poniewaz jest powyzej 2'147'483'647"<<endl;
    return 0;
}
