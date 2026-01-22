#include <iostream>
using namespace std;

int main(){

    int a;
    int f = 1;

    cout << "Inserire il numero di cui si vuole il fattoriale:  ";
    cin >> a;

    for(int i = a; i>0; i--){
        f *= i;
    }

    cout << "Il fattoriale del numero " << a << " è " << f << endl;

    return 0;
}