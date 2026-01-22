#include <iostream>
using namespace std;

void step(double *H, double *P, double r, double N, double s, double u, double v) {
    double H_prev = *H;
    double P_prev = *P;

    // formula prede
    *H = r * H_prev * (1 - H_prev / N) - s * H_prev * P_prev;

    // formula predatori
    *P = u * P_prev + v * (s * H_prev * P_prev);
}

int main() {
    // parametri
    double r = 2.0;
    double N = 1000.0;
    double s = 0.01;
    double u = 0.05;
    double v = 0.3;

    // valori iniziali
    double H = 500.0;
    double P = 30.0;

    cout << "t\tH\t\tP" << endl;
    cout << "0\t" << H << "\t" << P << endl;

    for(int t = 1; t <= 10; t++) {
        step(&H, &P, r, N, s, u, v);
        cout << t << "\t" << H << "\t" << P << endl;
    }

    return 0;
}
