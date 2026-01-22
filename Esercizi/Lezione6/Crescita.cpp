#include <iostream>
using namespace std;

int f(float x, float r, float N){
    return r * x * (1-x/N);
}

int main(){

    int n = 15;
    float r = 1.2, N = 1000, x = 300;

    cout << "La popolazione iniziale è " << x << endl;

    for(int t = 1; t <= n; ++t){
        x = f(x, r, N);
        cout << "Popolazione al passo " << t << ": " << x << endl;
    }

    return 0;
}