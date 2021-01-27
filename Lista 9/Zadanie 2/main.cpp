#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

ofstream MyFile("filename.txt");

const int W = 1920;
const int H = 1080;

int R[W][H];
int G[W][H];
int B[W][H];

void  gradient()
{
    for(int i=0;i<W;i++)
        for(int j=0;j<H/2;j++)
    {
        R[i][j] = 255;
        G[i][j] = 255;
        B[i][j] = 255;
}
    for(int i=0;i<W;i++)
        for(int j=H/2;j<H;j++)
    {
        R[i][j] = 255;
        G[i][j] = 0;
        B[i][j] = 0;
}
}


void saveppm()
{
    MyFile<<"P3"<< endl << "# komentarz" << endl << W << " "<< H << endl << " "<< "255" <<endl;
    for(int j=0;j<H;j++)
    {
        for(int i=0;i<W;i++)
        {
        MyFile<<R[i][j]<<" "<< G[i][j] <<" "<< B[i][j] << " ";
        }
    MyFile<<endl;
    }
    MyFile.close();

}

int main()
{

    gradient();
    saveppm();
    return 0;
}
