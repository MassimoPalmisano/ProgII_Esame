#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int a,b,c,d;
    int r;
    a = 3 * 4;
    b = -(2 * 2);
    c = 7 + 4;
    d = 10 % 4;
    r = powf(d, 3);

    cout << a << " " << b << " " << c << " " << d << endl;

    cout << "il valore " << d << " alla potenza di 3 è " << r << endl;

    

    return 0;
}