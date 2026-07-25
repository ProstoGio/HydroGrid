#include <iostream>
#include <iomanip>
#include <vector>
#define pb push_back
using namespace std;

double cabin_daily_need, tank_max_capacity, area, tank_level = 0.0;
int days;
vector<double> REAL_IRRADIANCE; // kWh/m^2/day, real historical data (e.g. from PVGIS)

const double ETA_SOLAR_PANEL = 0.20;
const double ETA_ELECTROLYZER = 0.75;
const double ETA_FC = 0.55;

// solar_energy_real() : Energy Solar Panels Produce, using REAL measured irradiance
// (no altitude adjustment needed -- real data already reflects actual site conditions)

double solar_energy_real(double daily_irradiance, double S) {
    double N;
    N = daily_irradiance * S * ETA_SOLAR_PANEL;
    return N;
}

// hydrogen_mass() : Kilograms of Hydrogen Produced by Electrolyzer

double hydrogen_mass(double Q) {
    double N;
    N = (Q * ETA_ELECTROLYZER) / 39.7;
    return N;
}

// energy_from_fc() : Energy Produced by Fuel Cell Using M mass Hydrogen

double energy_from_fc(double mass) {
    double N;
    N = mass * 39.7 * ETA_FC;
    return N;
}

// H2_mass_for_deficit() : Mass of H2 Needed to Fill Deficit

double H2_mass_for_deficit(double Q) {
    double mass;
    mass = Q / (39.7 * ETA_FC);
    return mass;
}

// upd_level() : Updates Level Of Hydrogen In Tank

double upd_level(double current_level, double amount, double max_capacity) {
    double nw_lvl;
    if (current_level + amount > max_capacity) {
        nw_lvl = max_capacity;
    } else if (current_level + amount < 0) {
        nw_lvl = 0;
    } else {
        nw_lvl = current_level + amount;
    }
    return nw_lvl;
}

int main() {
    cout << fixed << setprecision(3);

    cout << "Input Data in Next Order:\n";
    cout << "Number of Days in Data File (DAYS)\n";
    cout << "Area of Solar Panels (M^2)\n";
    cout << "Cabin's Daily Need (kWh)\n";
    cout << "Tank's Max Capacity (KG)\n\n";

    cin >> days;
    cin >> area;
    cin >> cabin_daily_need;
    cin >> tank_max_capacity;

    cout << "\n\nInput Real Daily Irradiance Values (kWh/m^2/day)\n";
    cout << "[ i1 i2 i3 i4 ..... idays ]\n\n";

    for (int i = 0; i < days; i++) {
        double val;
        cin >> val;
        REAL_IRRADIANCE.pb(val);
    }

    bool ind = true;

    for (int i = 0; i < days; i++) {
        double irr = REAL_IRRADIANCE[i]; // real measured kWh/m^2/day
        double E1 = solar_energy_real(irr, area); // Energy produced by SP, real data

        if (E1 > cabin_daily_need) {
            double surplus = E1 - cabin_daily_need;
            double m = hydrogen_mass(surplus);
            tank_level = upd_level(tank_level, m, tank_max_capacity);
        } else if (E1 < cabin_daily_need) {
            double deficit = cabin_daily_need - E1;
            double needed_mass_of_H2 = H2_mass_for_deficit(deficit);
            if ((tank_level - needed_mass_of_H2) < 0) {
                double energy_tank_couldve_given = energy_from_fc(tank_level);

                cout << "\n\nHydroGrid Failed to Provide Enough Energy!\n";
                cout << "Day: " << i + 1 << " th\n";
                cout << "Real Irradiance That Day: " << irr << " kWh/m^2\n";
                cout << "Produced Energy on This Day: " << E1 << " kWh\n";
                cout << "Necessary Energy Amount: " << cabin_daily_need << " kWh\n";
                cout << "Tank Level: " << tank_level << " KG\n";
                cout << "Energy Remaining Tank Could Provide: " << energy_tank_couldve_given << " kWh\n";
                cout << "Tank's Maximum Capacity: " << tank_max_capacity << " KG\n";
                ind = false;
                break;
            } else {
                tank_level = upd_level(tank_level, -needed_mass_of_H2, tank_max_capacity);
            }
        }
    }

    if (ind) {
        cout << "\n\nHydroGrid Provided Enough Energy Successfully! (validated against real historical data)";
    }

    cout << "\n";
    return 0;
}
