#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
    const int W = 256;
    const int H = 200;
    for(int j=0; j<H; j++)
        {
        for(int i=0; i<W; i++)
            {
            int r = (i/float(W))*100;
            int g = (i/float(H))*255;
            int b = (i/float(W))*200;

            cout << "\x1b[48;2;" << r << ";" << g << ";" << b << "m" <<"  \x1b[0m";
            }
        cout << endl;
        }
    return 0;
}
