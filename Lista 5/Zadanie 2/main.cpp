#include <iostream>

using namespace std;

float readHeight(float h)
{
    float height;
    cout<<"Podaj wzrost w metrach"<<endl;
    cin>>height;
    return height;
}

int readMass(float m)
{
    float mass;
    cout<<"Podaj wage w kilogramach"<<endl;
    cin>>mass;
    return mass;
}

float BMI(readHeight(),readMass())
{
    float BMI;
    BMI = (m/(h*h));
    return BMI;
}
int main()
{
    cout<<BMI( readHeight(), readMass()));
}
