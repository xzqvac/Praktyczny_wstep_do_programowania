#include <iostream>
#include <string>

using namespace std;

bool isDivisibleByThree(int number)
{
   int wynik = (number / 3);
   if(wynik * 3 == number)
    return true;

    return false;
}

int main()
{
    int a;

    cout << "Podaj liczbe" << endl;
    cin >> a;

    if(isDivisibleByThree(a))
        cout << "Liczba jest podzielna przez 3" << endl;
    else
        cout << "Liczba nie jest podzielna przez 3" << endl;

    return 0;
}
