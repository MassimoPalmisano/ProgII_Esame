#include <iostream>
using namespace std;

void trova_max(int *rmax, int *values, unsigned size);
void trova_minmax(int *rmin, int *rmax, int *values, unsigned size);
void compute_mean_variance(float *rmean, float *rvariance, float *values, unsigned size);


int main(){

    int max, min;
    float *values, mean, variance;
    unsigned size = 10;

    values = (float*)malloc(sizeof(float) * size);

    cout << "inserire i valori all'interno dell'array" << endl;
    for(unsigned i = 0; i<size; i++){
        cin >> values[i];
    }

    //trova_minmax(&min, &max, &values[0], size);
    
    //cout << "Il valore massimo dentro l'array è: " << max << endl;
    //out << "Il valore minimo dentro l'array è: " << min << endl;
    
    compute_mean_variance(&mean, &variance, &values[0], size);

    cout << "La media dei valori inseriti è: " << mean << endl;
    cout << "La varianza dei valori dell'array è: " << variance << endl;

    free(values);
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
void trova_minmax(int *rmin, int *rmax, int *values, unsigned size){

    *rmax = values[0];
    *rmin = values[0];
    for(unsigned i = 0; i < size; i++){
        if(*rmax < values[i]){
            *rmax = values[i];
        }

        if(*rmin > values[i]){
            *rmin = values[i];
        }
    }
}

void compute_mean_variance(float *rmean, float *rvariance, float *values, unsigned size){

    *rmean = 0;
    *rvariance = 0;

    for(unsigned i = 0; i< size; i++){
        *rmean += values[i];
    }

    *rmean = *rmean/size;

    for(unsigned i = 0; i< size; i++){
        *rvariance = *rvariance + ((values[i] - *rmean) * (values[i] - *rmean));
    }

    *rvariance = *rvariance/size;

}
