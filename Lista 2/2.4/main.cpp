#include <iostream>

using namespace std;

int main()
{
    for (int i = -5; i <= 5; i++)
    {
        for (int j = -5; j <=5; j++)
        {
            cout << j*i << "\t";
        }
        cout << endl;
    }
    return 0;
}
