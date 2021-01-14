#include <iostream>

using namespace std;

float readHeight(float height)
{
    cout<<"Podaj wzrost w metrach"<<endl;
    cin>>height;
    return height;
}

int readMass(float mass)
{
    cout<<"Podaj wage w kilogramach"<<endl;
    cin>>mass;
    return mass;
}

typedef float( * BMI)(height, mass)
{
    height = readHeight()
    BMI = (mass/(height*height));
    cout<< BMI;
}


int main()
{
    BMI();
    return 0;
}

