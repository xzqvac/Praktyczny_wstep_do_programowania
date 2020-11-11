#include <iostream>

using namespace std;

int main()
{
    for(int i=30;i<=47;i++)
        {
        cout<<"\x1b[0m Numer kodu ANSI:"<<i<<" "<<"\x1b["<<i<<"m"<<" Hello World";
        cout<<"\x1b[0m"<<endl;
        }
    for(int j=90;j<=107;j++)
        {
        cout<<"\x1b[0m Numer kodu ANSI:"<<j<<" "<<"\x1b["<<j<<"m"<<" Hello World";
        cout<<"\x1b[0m"<<endl;
        }
}
