/*
  Scrivere un programma per la gestione di liste doppie.
  Il programma presenta un menù all'utente che può
  - creare una lista di n valori (volendo ordinata)
  - cancellare tutti tutti gli elementi contenente un valore dato dalla lista
  - stampare la lista
  - cercare valori nella lista
  Se la lista è ordinata la ricerca deve richiamare ord_search() altrimenti search().
*/

#include <iostream>
#include <cstring>

using namespace std ;

#include "tipo.h"


/*******************************/
/* DEFINIZIONE MODULO "tipo" */
/*******************************/

int compare(tipo_inf s1,tipo_inf s2){
	if(s1 == s2)
		return 0;
	else 
		return 1;
	
}


tipo_inf copy(tipo_inf s) {
    tipo_inf t = s;
    return t;
}

void print(tipo_inf s){
	cout << s;
}
