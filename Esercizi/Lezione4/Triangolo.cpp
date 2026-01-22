#include <iostream>
using namespace std;

int main(){

    float a, b, c;
    bool equi, iso, scal, triangolo;

    cout << "Inserire i valori dei 3 segmenti" << endl;
    cout << "Segmento 1: ";
    cin >> a;
    cout << "Segmento 2: ";
    cin >> b;
    cout << "Segmento 3: ";
    cin >> c;

    if(c > (a + b)){
        cout << "I 3 segmenti dati non possono formare un triangolo" << endl;
        triangolo = equi = iso = scal = false;
    }
    else if(a == b && b == c){
        //cout << "I 3 segmenti dati formano un triangolo equilatero" << endl;
        triangolo = equi = true;
        scal = iso = false;
    }
    else if(a == b || b == c || a == c){
        //cout << "I 3 segmenti dati formano un triangolo isoscele" << endl;
        triangolo = iso = true;
        scal = equi = false;
    }
    else {
        //cout << "I 3 segmenti dati formano un triangolo scaleno" << endl;
        triangolo = scal = true;
        iso = equi = false;
    }

    cout << "Dati i 3 segmenti il risultato dei controlli è: "<< endl;
    cout << "Equilatero: " << equi <<   "\tIsoscele: " << iso <<  "    Scaleno: " << scal <<  endl;

    return 0;
}