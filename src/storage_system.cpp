#include <iostream>
#include <iomanip>
using namespace std;

double new_level(double current_level, double amount, double max_capacity){
    double nw_lvl;
    if(current_level+amount>max_capacity){
        nw_lvl=max_capacity;
    }else if(current_level+amount<0){
        nw_lvl=0;
    }else{
        nw_lvl=current_level+amount; 
    }

    return nw_lvl;
}

int main(){
    cout<<"1) Current Level (KG);\n2) Max Capacity (KG);\n";
    double current_level, max_capacity;
    if(!(cin>>current_level>>max_capacity))return 0;

    while(true){
        double amount;
        cout<<"Amount of H2 + or - :\n";
        cin>>amount;

        double cur_lvl=new_level(current_level, amount, max_capacity);
        current_level=cur_lvl;

        cout<<"Current Tank Level: "<<cur_lvl<<"\n"<<"Continue? [y] or [n]:\n";
        
        char validator;
        cin>>validator;
        if(validator=='n')break;
        
    }


    cout<<"\n";
    return 0;
}