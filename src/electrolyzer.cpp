#include <iostream>
#include <iomanip>
using namespace std;
const double ETA_ELECTROLYZER=0.75;

double hydrogen_mass(double Q){
    double N;
    N=(Q*ETA_ELECTROLYZER)/39.7;

    return N;
}

int main(){
    cout<<"Q - kWh going into the electrolyzer:\n";
    double Q;
    if(!(cin>>Q))return 0;

    cout<<fixed<<setprecision(3);
    cout<<"Estimated Hydrogen Mass: "<<hydrogen_mass(Q)<<" KG";

    cout<<"\n";
    return 0;
}