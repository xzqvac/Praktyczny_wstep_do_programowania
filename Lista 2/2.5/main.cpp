#include <iostream>

using namespace std;

int main()
{
    for(int i=30;i<=107;i++)
        {
        cout<<"\x1b[0m Numer kodu ANSI:"<<i<<" "<<"\x1b["<<i<<"m"<<" Hello World";
        cout<<"\x1b[0m"<<endl;
        }
}
