
/*********************/
/* DEFINIZIONE TIPO  */
/*********************/

#include <iostream>
#include <cstring>
using namespace std;

#include "tipo.h"

int compare(tipo_inf s1,tipo_inf s2){
	return strcmp(s1,s2);
}

tipo_inf copy(tipo_inf source){
	tipo_inf dest=new char[strlen(source)];
	strcpy(dest,source);

	return dest;
}

void print(tipo_inf inf){
	cout<<inf;
}
