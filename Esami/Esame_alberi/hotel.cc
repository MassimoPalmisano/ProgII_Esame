#include <iostream>
#include <cstring>
#include "hotel.h"

using namespace std;

void copy(tipo_inf& dest, tipo_inf source) {
    dest.stelle = source.stelle;
    strcpy(dest.nome, source.nome);
    strcpy(dest.luogo, source.luogo);
}

void print(tipo_inf h) {
    cout << h.stelle << " stelle " << h.nome << " " << h.luogo << endl;
}