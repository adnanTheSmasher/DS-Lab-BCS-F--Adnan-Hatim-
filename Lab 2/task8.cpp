#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter number of readings per day: ";
    cin >> m;


    double** temps = new double*[n];
    for (int i = 0; i < n; i++) {
        temps[i] = new double[m];
    }


    for (int i = 0; i < n; i++) {
        cout << "\nDay " << i + 1 << ":\n";
        for (int j = 0; j < m; j++) {
            cout << "  Enter temperature at time " << j + 1 << ": ";
            cin >> temps[i][j];
        }
    }

    double* averages = new double[n];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum += temps[i][j];
        }
        averages[i] = sum / m;
    }

    cout << "\nDaily Average Temperatures:\n";
    for (int i = 0; i < n; i++) {
        cout << "Day " << i + 1 << ": " << fixed << setprecision(2) 
             << averages[i] << "°C\n";
    }


    int hottestDay = 0, coldestDay = 0;
    for (int i = 1; i < n; i++) {
        if (averages[i] > averages[hottestDay]) {
            hottestDay = i;
        }
        if (averages[i] < averages[coldestDay]) {
            coldestDay = i;
        }
    }

    cout << "\nHottest Day: Day " << hottestDay + 1 
         << " with avg " << averages[hottestDay] << "°C\n";
    cout << "Coldest Day: Day " << coldestDay + 1 
         << " with avg " << averages[coldestDay] << "°C\n";

    for (int i = 0; i < n; i++) {
        delete[] temps[i];
    }
    delete[] temps;
    delete[] averages;

    return 0;
}
