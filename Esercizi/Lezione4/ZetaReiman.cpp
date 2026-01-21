#include <iostream>
#include <cmath>
using namespace std;

int main(){

    float z = 0;
    float zo = -1;
    float s = 0;
    cout << "Inserire il valore di s :"; 
    cin >> s;

    for(int n = 1; n<= 1000; n++){

        zo = z;
        z += 1/powf(n, s); 

        if((z - zo) <= 1e-6){
            cout << "Valore di z: " << z << endl;
            return 0;
        }

    }
    
    return 0;
}