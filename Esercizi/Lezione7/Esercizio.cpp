#include <iostream>
using namespace std;

void trova_max(int *rmax, int *values, unsigned size);

int main(){

    int max, *values;
    unsigned size = 10;

    values = (int*)malloc(sizeof(int) * size);

    cout << "inserire i valori all'interno dell'array" << endl;
    for(unsigned i = 0; i<size; i++){
        cin >> values[i];
    }

    trova_max(&max, &values[0], size);

    cout << "Il valore massimo dentro l'array è: " << max << endl;

    return 0;
}

void trova_max(int *rmax, int *values, unsigned size){

    *rmax = 0;
    for(unsigned i = 0; i < size; i++){
        if(*rmax < values[i]){
            *rmax = values[i];
        }
    }

}