#include <iostream>
#include <cstdlib>
#include <time.h>
#include "windows.h"
using namespace std;

int main()
{
    srand (time(NULL));
    bool quest1_zlecony = false;
    bool quest1_wykonany = false;
    bool quest1_odebrano_nagrode = false;

    int zloto = 20;
    int zycie = 100;
    int mikstury = 0;
    int wegiel = 0;

    bool gratrwa = true;

    while(gratrwa == true)
    {
        cout<<"Witaj w swiecie Erthos"<<endl;
        cout<<"Zycie = "<<zycie<<endl;
        cout<<"Zloto = "<<zloto<<endl;
        if(mikstury >0)
            cout<<"Mikstury lecznicze = "<<endl;
        if(wegiel>0)
            cout<<"Wegiel ="<<wegiel<<endl;
        cout<<endl;
        cout<<"Gdzie chcesz pojsc?"<<endl;
        cout<<"1. Tawerna"<<endl;
        cout<<"2. Sklep"<<endl;
        cout<<"3. Kopalnia"<<endl;
        cout<<"0. Opusc Erthos"<<endl;

        int wybor = 0;
        cout<<"Twoj wybor: "<<endl;
        cin>>wybor;

        if(wybor == 0)
        {
            cout<<"Zegnaj..."<<endl;
            gratrwa = false;
        }

        if(wybor == 1)
        {
        {
            cout<<"Wchodzisz do tawerny"<<endl;
            system("pause");
            cout<<"Co robisz?"<<endl;
            cout<<"1. Wypij drinka (koszt: 5 zlota)"<<endl;
            cout<<"2. Postaw wszystkim kolejke (koszt 40 zlota)"<<endl;

            if(quest1_zlecony == true)
            {
                if(quest1_odebrano_nagrode == false)
                    cout<<"3. Porozmawiaj z tajemnicznym mezczyzna"<<endl;
                else
                    cout<<"Porozmawiaj z krolem"<<endl;
            }
        }
        wybor = 0;
        cout<<"Twoj wybor to: "<<endl;
        cin>>wybor;

        if(wybor==1)
        {
            if(zloto >= 5)
            {
                cout<<"Wypijasz orzezwiajacego drinka!"<<endl;
                if(zycie < 100)
                {
                    zycie = 100;
                    zloto -= 5;
                }
            }
            else
                cout<<"Niestety, nie stac Cie nawet na drinka..."<<endl;
        }
        else if(wybor==2)
        {
            if(zloto>=40)
            {
                cout<<"Stawiasz kolejke wszystkim w tawernie!"<<endl;
                system("pause");
                if(quest1_zlecony == false)
                {
                    cout<<"Wnet slyszysz krzyk: Rowny z ciebie gosc!"<<endl;
                    system("pause");
                    cout<<"(tajemniczy mezczyzna) Sluchaj, mam dla Ciebie zadanie. Slyszales moze o pobliskiej kopalni?"<<endl;
                    system("pause");
                    cout<<"(tajemniczy mezczyzna) Ostatnimi czasy coraz wiecej naszych ludzi przepada bezpowrotnie..."<<endl;
                    system("pause");
                    cout<<"(tajemniczy mezczyzna) Sprawdze, co sie tam dzieje, a sowicie Ci to wynagrodze."<<endl;
                    system("pause");
                    cout<<"(tajemniczy mezczyzna) Bede tu na Ciebie czekal."<<endl;
                    quest1_zlecony = true;
                }
            }
            else
                cout<<"Niestety, nie masz wystarczajacej ilosci zlota... "<<endl;
        }
        else if(wybor==3)
        {
            if(quest1_wykonany == false && quest1_odebrano_nagrode == false)
                cout<<"(tajemniczy mezczyzna) Zlo czai sie w ciemnosciach..."<<endl;
            if(quest1_wykonany == true)
            {
                if(quest1_odebrano_nagrode == false)
                {
                    cout<<"(tajemniczy mezczyzna) Gratulacje, udalo ci siê!"<<endl;
                    system("pause");
                    cout<<"(tajemniczy mezczyzna) Przyjmij ode mnie ten oto skromny podarunek w postaci sakwy zlota."<<endl;
                    system("pause");
                    zloto += 1000;

                    cout<<"(tajemniczy mezczyzna zdejmuje kaptur)"<<endl;
                    system("pause");
                    cout<<"(czlowiek z tlumu) Ludzie spojrzcie, to krol!"<<endl;
                    system("pause");
                    cout<<"(wszyscy zebrani) Niech zyje król!"<<endl;
                    system("pause");
                    cout<<"(król) Przyjacielu, w podziece nadaje ci równiez tytul szlachecki!"<<endl;

                    quest1_odebrano_nagrode = true;
                }
                else
                    cout<<"Ach witaj przyjacielu!"<<endl;
            }

        }
        }
        else if(wybor == 2)
        {
            cout<<"Wchodzisz do sklepu"<<endl;
            system("pause");
            cout<<"Co robisz?"<<endl;
            cout<<"1. Kup miksture leczniczą (koszt: 50 zlota)"<<endl;
            cout<<"2. Sprzedaj wegiel"<<endl;

            wybor = 0;
            cout<<"Twoj wybor: "<<endl;
            cin>>wybor;
            if(wybor==1)
            {
                if(zloto >=50)
                {
                    cout<<"(sprzedawca) Oto Twoja mikstura"<<endl;
                    mikstury += 1;
                    zloto -= 50;
                }
                else
                    cout<<"(sprzedawca) 50 sztuk zlota i ani grosza mniej!"<<endl;
            }
            else if(wybor ==2)
            {
                if(wegiel > 0)
                {
                    int cena = 0;
                    int cena_za_sztuke = 0;
                    cena_za_sztuke = rand()%10 + 5;
                    cena = wegiel * cena_za_sztuke;

                    cout<<"Sprzedales "<<wegiel<<"Jednostek wegla za "<<cena<<" sztuk zlota"<<endl;

                    zloto += cena;
                    wegiel = 0;
                }
                else
                    cout<<"Nie masz przy sobie wegla... "<<endl;
            }
        }
        else if(wybor ==3)
        {
            cout<<"Udajesz sie do kopalni"<<endl;
            system("pause");
            cout<<"Co robisz?"<<endl;
            cout<<"1. Idz wydobyc wegiel"<<endl;
            if(quest1_zlecony == true && quest1_wykonany == false)
                cout<<"2. Zejdz na nizszy poziom"<<endl;

            wybor = 0;
            cout<<"Twoj wybor:"<<endl;
            cin>>wybor;

            if(wybor == 1)
            {
                int los = 0;
                int ile_tur = 0;
                los = rand()%100+1;

                if(los>10)
                {
                    int ile_wegla = 0;
                    cout<<"Rozpocznij wydobycie"<<endl;
                    ile_tur = rand()%10+5;
                    while(ile_tur >0)
                    {
                        cout<<"Kopiesz..."<<endl;
                        Sleep(1000);
                        ile_tur -= 1;
                    }
                    ile_wegla = rand()%150+50;
                    cout<<"Wydobyles "<<ile_wegla<<" wegla"<<endl;
                    wegiel += ile_wegla;
                }
                else
                {
                    cout<<"Potykasz sie o wlasne nogi i spadasz w przepasc..."<<endl;
                    gratrwa = false;
                }
            }
            else if(wybor ==2)
            {
                if(quest1_zlecony == true && quest1_wykonany == false)
                {
                    cout<<"Przemierzasz nizsze poziomy kopalni..."<<endl;
                    system("pause");
                    cout<<"Na kazdym kroku widzisz ciala gornikow..."<<endl;
                    system("pause");
                    cout<<"W pewnym momencie nastaje niepokojaca cisza..."<<endl;
                    system("pause");
                    cout<<"Z ciemnosci wylania się zakrwawiony szkielet trzymajacy tasak i tarcze!"<<endl;
                    system("pause");

                    wybor = 0;
                    while(wybor != 1 && wybor != 2)
                    {
                        cout<<"Co robisz?"<<endl;
                        cout<<"1. Uciekasz"<<endl;
                        cout<<"2. Podejmujesz walke"<<endl;
                        cout<<"Twoj wybor to: "<<endl;
                        cin>>wybor;

                        if(wybor == 1)
                        {
                            cout<<"Probujesz uciec"<<endl;
                            system("pause");
                            cout<<"Biegniesz nie ogladajac sie za siebie..."<<endl;
                            system("pause");

                            int los = 0;
                            los = rand()*100+1;

                            if(los<10)
                            {
                                cout<<"W pewnym momencie czujesz przeszywajacy bol..."<<endl;
                                system("pause");
                                cout<<"Ogladajac sie za siebie widzisz szkieleta i tasak wbity w Twoje plecy..."<<endl;
                                system("pause");
                                cout<<"Umierasz"<<endl;
                                gratrwa = false;
                            }
                            else
                                cout<<"Na szczescie udalo Ci sie uciec!"<<endl;
                        }
                        else
                        {
                            cout<<"Rozpoczyna sie walka"<<endl;
                            bool walka_trwa;
                            int zycie_wroga = 100;
                            walka_trwa = true;

                            while(walka_trwa = true)
                            {
                                cout<<"Zycie gracza= "<< zycie<<endl;
                                cout<<"Zycie wroga= "<<zycie_wroga<<endl;
                                cout<<"Co robisz?"<<endl;
                                cout<<"1. Atakauj"<<endl;
                                cout<<"2. Wypij miksture"<<endl;
                                wybor = 0;
                                cin>>wybor;

                                if(wybor==1)
                                {
                                    int obrazenia_gracza = 0;
                                    obrazenia_gracza = rand()%15+5;
                                    cout<<"Zadajesz "<<obrazenia_gracza<<" obrazen!"<<endl;
                                    system("pause");
                                    zycie_wroga -= obrazenia_gracza;

                                    if(zycie_wroga <= 0)
                                    {
                                        cout<<"Gratulacje, zabiles szkieleta!"<<endl;
                                        walka_trwa = false;
                                        quest1_wykonany = true;
                                    }
                                    else
                                    {
                                        cout<<"Tura szkieleta"<<endl;
                                        system("pause");
                                        int obrazenia_szkieleta = 0;
                                        obrazenia_szkieleta = rand()%28+3;
                                        cout<<"Szkielet atakuje i zadaje"<<obrazenia_szkieleta<<" obrazen!"<<endl;
                                        system("pause");
                                        zycie -= obrazenia_szkieleta;
                                        if(zycie <=0)
                                        {
                                            cout<<"Umierasz..."<<endl;
                                            walka_trwa = false;
                                            gratrwa = false;
                                        }

                                    }
                                }
                                else if(wybor == 2)
                                {
                                    if(mikstury > 0)
                                    {
                                        cout<<"Wypijasz miksture i odzyskujesz cale zdrowie!"<<endl;
                                        zycie = 100;

                                        mikstury -= 1;
                                    }
                                    else
                                        cout<<"Niestety nie posiadasz mikstury..."<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }

    }
}


