//Zadanie 3 i 4
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int maximum=100;
    int wygrywa=0;
    int counter=0;
    int dec, losowana, p;
    losowana = (rand() %100+1);
    //cout<<losowana<<endl;
    cout<<"Witaj w grze pod tytluem Zgadywanka. Twoim zadaniem jest odgadniecie liczby z przedzialu"<<endl;
    cout<<"POWODZENIA!"<<endl;
    while(bool x = true)
    {   if(counter==0)
            cout<<"Zakres przedzialu: "<<"["<<1<<":"<<maximum<<"]"<<endl;
        cout<<"Podaj liczbe"<<endl;
        cin>>wygrywa;
        if(losowana>wygrywa)
        {
            cout<<"\x1b[105m Podana liczba jest za mala \x1b[40m"<<endl;
            cout<<endl;
        }
        if(losowana<wygrywa)
        {
            cout<<"\x1b[101m Podana liczba jest za duza \x1b[40m"<<endl;
        }
        ++counter;

        if(losowana==wygrywa)
        {
            cout<<"\x1b[43m BINGO! \x1b[40m"<<endl;
            cout<<"Udalo Ci sie za "<<counter<<"-razem"<<endl;
            cout<<"Czy chcesz zagrac ponownie? (0 - NIE/1 - TAK)"<<endl;
            cin>>dec;
            if(dec == 0)
            {
                break;
            }
            else if(dec == 1)
            {
                cin.clear();
                counter=0;
                cout<<"Czy chcesz zwiekszyc przedzial? (0 - NIE/1 - TAK)"<<endl;
                cin>>p;
                if(p==1)
                {
                    cout<<"Podaj gorny przedzial zakresu: "<<endl;
                    cin>>maximum;
                    losowana = (rand() %maximum+1);
                }
                else if(p==0)
                    losowana = (rand() %maximum+1);
            }
        }
    }
}

