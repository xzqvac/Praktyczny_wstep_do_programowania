#include <iostream>

using namespace std;

float readHeight()
{
    float height;
    cout<<"Podaj wzrost w metrach"<<endl;
    cin>>height;
    return height;
}

int readMass()
{
    int mass;
    cout<<"Podaj wage w kilogramach"<<endl;
    cin>>mass;
    return mass;
}

float BMI(float height, int mass)
{
    float BMI;
    BMI = (mass/(height*height));
    return BMI;
}

void BMIprint(float BMI)
{
    cout<<"Twoje BMI to: "<<BMI;
}


int main()
{
    BMIprint(BMI(readHeight(),readMass()));
    return 0;
}

