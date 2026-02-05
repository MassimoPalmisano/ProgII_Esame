/*******************************/
/* HEADER MODULO "liste" */
/*******************************/

#include <iostream>
#include "tipo.h"

struct elem {
    tipo_inf inf;
    elem* punt;
    elem* prec;
};

typedef elem* lista;

tipo_inf head(lista);
elem* new_elem(tipo_inf);
elem* search(lista, tipo_inf);

lista tail(lista);
lista prev(lista);
lista insert_elem(lista, elem*);
lista delete_elem(lista, elem*);


