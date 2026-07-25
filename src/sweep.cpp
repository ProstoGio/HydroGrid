#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

const double ETA_SOLAR_PANEL = 0.20;
const double ETA_ELECTROLYZER = 0.75;
const double ETA_FC = 0.55;
const double H2_ENERGY = 39.7;

// -- Same physics functions as before --

double solar_energy_real(double daily_irradiance, double S) {
    return daily_irradiance * S * ETA_SOLAR_PANEL;
}

double hydrogen_mass(double Q) {
    return (Q * ETA_ELECTROLYZER) / H2_ENERGY;
}

double energy_from_fc(double mass) {
    return mass * H2_ENERGY * ETA_FC;
}

double H2_mass_for_deficit(double Q) {
    return Q / (H2_ENERGY * ETA_FC);
}

double upd_level(double current_level, double amount, double max_capacity) {
    double nw = current_level + amount;
    if (nw > max_capacity) return max_capacity;
    if (nw < 0) return 0;
    return nw;
}

// Runs the full simulation silently; returns true if it survives the whole dataset
bool simulate(const vector<double>& irradiance, double area, double cabin_need, double tank_max) {
    double tank_level = 0.0;
    for (double irr : irradiance) {
        double E1 = solar_energy_real(irr, area);
        if (E1 > cabin_need) {
            double surplus = E1 - cabin_need;
            double m = hydrogen_mass(surplus);
            tank_level = upd_level(tank_level, m, tank_max);
        } else if (E1 < cabin_need) {
            double deficit = cabin_need - E1;
            double needed = H2_mass_for_deficit(deficit);
            if (tank_level - needed < 0) return false; // failed
            tank_level = upd_level(tank_level, -needed, tank_max);
        }
    }
    return true;
}

vector<double> load_irradiance(const string& path) {
    ifstream f(path);
    int n;
    f >> n;
    vector<double> vals(n);
    for (int i = 0; i < n; i++) f >> vals[i];
    return vals;
}

int main() {
    cout << fixed << setprecision(2);

    double cabin_need;
    double panel_cost_per_m2, hydride_cost_per_kg_H2;
    double area_min, area_max, area_step;
    double tank_min, tank_max_range, tank_step;
    string real_file, stressed_file;

    cout << "Cabin Daily Need (kWh): ";
    cin >> cabin_need;

    cout << "Panel Cost ($/m^2): ";
    cin >> panel_cost_per_m2;
    cout << "Hydride Storage Cost ($ per kg of H2 CAPACITY, alloy included): ";
    cin >> hydride_cost_per_kg_H2;

    cout << "Panel Area Sweep -- min max step (m^2): ";
    cin >> area_min >> area_max >> area_step;
    cout << "Tank Capacity Sweep -- min max step (kg): ";
    cin >> tank_min >> tank_max_range >> tank_step;

    cout << "Real data file path: ";
    cin >> real_file;
    cout << "Stressed data file path: ";
    cin >> stressed_file;

    vector<double> real_data = load_irradiance(real_file);
    vector<double> stressed_data = load_irradiance(stressed_file);

    cout << "\n\nSearching combos (must survive BOTH real and stressed data)...\n\n";
    cout << "Area(m^2)\tTank(kg)\tCost($)\t\tReal?\tStressed?\n";

    double best_cost = -1;
    double best_area = 0, best_tank = 0;

    for (double area = area_min; area <= area_max + 1e-9; area += area_step) {
        for (double tank = tank_min; tank <= tank_max_range + 1e-9; tank += tank_step) {
            bool ok_real = simulate(real_data, area, cabin_need, tank);
            bool ok_stressed = simulate(stressed_data, area, cabin_need, tank);
            double cost = area * panel_cost_per_m2 + tank * hydride_cost_per_kg_H2;

            if (ok_real && ok_stressed) {
                cout << area << "\t\t" << tank << "\t\t" << cost
                     << "\t\tYES\tYES\n";
                if (best_cost < 0 || cost < best_cost) {
                    best_cost = cost;
                    best_area = area;
                    best_tank = tank;
                }
            }
        }
    }

    if (best_cost >= 0) {
        cout << "\n\nCHEAPEST COMBO THAT SURVIVES BOTH:\n";
        cout << "Panel Area: " << best_area << " m^2\n";
        cout << "Tank Capacity: " << best_tank << " kg\n";
        cout << "Estimated Cost: $" << best_cost << "\n";
    } else {
        cout << "\n\nNo combo in the tested range survived both datasets. Widen the sweep range.\n";
    }

    return 0;
}
