#include "tipo.h"

#include <iostream>
using namespace std;

/*******************************/
/* DEFINIZIONE MODULO "tipo" */
/*******************************/


int compare(tipo_inf s1, tipo_inf s2){
    if (s1.valore == s2.valore && s1.seme == s2.seme){
        return 0;
    }

    if (s1.valore == s2.valore){
        switch(s1.seme){
            case 'C': return 1;
            case 'F': if (s2.seme == 'C')
                            return -1;
                      else 
                            return 1;
            case 'P': if(s2.seme == 'C' || s2.seme == 'F')
                            return -1;
                      else 
                            return 1;
            case 'Q': return -1;
        }
    }

    if(s1.valore < s2.valore)
        return -1;
    else
        return 1;
}

void copy(tipo_inf& s1, tipo_inf s2){
    s1.seme = s2.seme;
    s1.valore = s2.valore;
}

void print(tipo_inf s){
    cout << "Valore: " << s.valore << " Seme: " << s.seme;
}