#include <iostream>
#include <cstring>
#include "tipo.h"

using namespace std;

int compare(tipo_inf s1, tipo_inf s2) {
    return strcmp(s1.descrizione, s2.descrizione);
}

void copy(tipo_inf& dest, tipo_inf source) {
    strcpy(dest.descrizione, source.descrizione);
    dest.tipo = source.tipo;
}

void print(tipo_inf p) {
    cout << p.descrizione << " (" << p.tipo << ")";
}