#include <iostream>
using namespace std;

int main(){

    int a, b, sum = 0;

    cout << "Inserire 2 numeri per fare una moltiplicazione tra di essi" << endl;
    cout << "Numero 1: ";
    cin >> a;
    cout << "Numero 2: ";
    cin >> b;

    for(int i = 0; i<b; i++){
        sum += a;
    }

    cout << "La moltiplicazione dei 2 numeri inseriti da come risultato: " << sum<< endl;

    return 0;
}