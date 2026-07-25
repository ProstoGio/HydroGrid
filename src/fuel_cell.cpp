#include <iostream>
#include <iomanip>
using namespace std;
const double ETA_FC = 0.55;

double energy_from_fc(double mass){
    double N;
    N=mass*39.7*ETA_FC;

    return N;
}

int main(){
    cout<<"Mass of H2 drawn from tank (KG):\n";
    double mass;
    if(!(cin>>mass))return 0;

    double E=energy_from_fc(mass);
    
    cout<<fixed<<setprecision(3);
    cout<<"Estimated Energy: "<<E<<" KWh";

    cout<<"\n";
    return 0;
}
