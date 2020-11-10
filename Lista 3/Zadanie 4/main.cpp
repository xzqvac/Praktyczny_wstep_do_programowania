#include <iostream>

using namespace std;

int main()
{
    float x;
    float y;
    int dec;
    int operation;
    bool b = true;
    float wynik;

    while(b == true)
    {
        cout<<"Podaj pierwsza liczbe: "<<endl;
        cin>>x;
        cout<<"Podaj druga liczbe: "<<endl;
        cin>>y;
        cout<<"Podaj dzialanie jakie chcesz wykonac (0-dodawanie, 1-mnozenie):"<<endl;
        while ( !(cin>>operation) )
        {
            cout << "Wprowadz poprawna operacje" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        if(operation == 0)
        {
            wynik = x + y;
            cout<<"Twoj wynik to: "<<wynik<<endl;
            cout<<"Czy chcesz sprobowac jeszcze raz? (0/1)"<<endl;
            cin>>dec;
            if (dec==1)
            {
                b = true;
                cin.clear();
            }
            else
                b = false;
        }

        else if(operation == 1)
        {
            wynik = x * y;
            cout<<"Twoj wynik to: "<<wynik<<endl;
            cout<<"Czy chcesz sprobowac jeszcze raz? (0/1)"<<endl;
            cin>>dec;
            if (dec==1)
            {
                b = true;
                cin.clear();
            }
            else
                b = false;
        }
    }
}
