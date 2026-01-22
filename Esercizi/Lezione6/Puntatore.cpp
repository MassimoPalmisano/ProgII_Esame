#include <iostream>
using namespace std;

void scambia(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int main(){

    int x = 7, y = 10;
    scambia(&x, &y);
    cout << "x: " << x << "\t y: " << y << endl;

    return 0;
}