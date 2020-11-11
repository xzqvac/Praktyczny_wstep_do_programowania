#include <iostream>
#include <windows.h>

using namespace std;

void ani(char a[100])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        for(int j = 0; j <RAND_MAX; j++);
        {
            Sleep(100);
            cout<<a[i];
        }
    }
}

int main()
{
    ani("Animacja wyswietlania tekstu");
    cout<<endl;
    ani("Korzystajac z wiedzy na temat kodow ANSI oraz funkcji Sleep/usleep (w zaleznosci Windows/Linux) napisz prosta animacje w konsoli (podobnie do zadania 9, ale albo generujac funkcyjnie kolejne klatki albo wyswietlajac kilka klatek w petli).");
    return 0;
}
