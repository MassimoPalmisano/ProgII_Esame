
/*********************/
/* DEFINIZIONE TIPO  */
/*********************/

#include <iostream>
#include <cstring>
using namespace std;

#include "tipo.h"

int compare(tipo_inf s1, tipo_inf s2){
    return strcmp(s1,s2);
}

tipo_inf copy(tipo_inf s){
    tipo_inf t = new char[strlen(s) + 1];
    strcpy(t, s);
    return t;
}

void print(tipo_inf s){
    cout << s;
}

