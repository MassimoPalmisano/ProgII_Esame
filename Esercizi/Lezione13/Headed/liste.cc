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


#include "liste.h"



/*******************************/
/* DEFINIZIONE MODULO "liste" */
/*******************************/

tipo_inf head(lista p){return p->inf;}
lista tail(lista p){return p->punt;}
lista prev(lista p){return p->prec;}

lista insert_elem(lista l, elem* e){
	e->punt=l;
	if(l!=NULL)
		l->prec=e;
	e->prec=NULL;
	return e;
}

lista delete_elem(lista l, elem* e){

		if(l==e)
			l=e->punt; // e è la testa della lista
		else // e non è la testa della lista
			(e->prec)->punt = e->punt;
		if(e->punt!=NULL)
			(e->punt)->prec=e->prec;
		delete e;
		return l;
}

elem* new_elem(tipo_inf inf){
	elem* p = new elem;
	p->inf = copy(inf);
	p->punt = p->prec = NULL;
	
	return p;
}

elem* search(lista p, tipo_inf v){
	while(p != NULL){
		if(compare(p->inf, v) == 0)
			return p;
		else 
			p = tail(p);
	}
	return NULL;
}







