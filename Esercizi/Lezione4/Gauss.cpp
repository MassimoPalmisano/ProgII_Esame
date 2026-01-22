#include <iostream>
using namespace std;

int main(){

    float n = 10, gauss, sum = 0;

    for(float i = 1; i<= n; i++){
    sum += i;
    }

    gauss = (n * (n+1))/2;

    cout << "il valore della sommatoria è " << sum << " mentre quello della formula di gauss è " << gauss <<  endl;


    return 0;
}