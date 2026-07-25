#include <iostream>
#include <iomanip>
using namespace std;
const double I0=1000.0;
const double K=0.08;
const double ETA_SOLAR_PANEL=0.20; 

double solar_energy(double S, double t, double h){
    double N;
    t=t*3600;
    N=(I0*(1+((K*h)/1000))*S*t*ETA_SOLAR_PANEL)/3600000;

    return N;
}

int main(){
    cout<<"1) Area(S) _ m^2; \n2) Time(t) _ hrs; \n3) Atlitude(h) _ m;\n";
    double S, t, h;
    if(!(cin>>S>>t>>h))return 0;

    cout<<fixed<<setprecision(3);
    cout<<"Estimated Solar Energy: "<<solar_energy(S, t, h)<<" kWh";
    
    cout<<"\n";
    return 0;
}
