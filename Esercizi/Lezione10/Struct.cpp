#include <iostream>
#include <string>
using namespace std;

struct persona{
    char nome[64];
    char cognome[64];
};

void stampa_persona(struct persona p);
void leggi_persona(struct persona *p);

int main(){

    struct persona p1;

    leggi_persona(&p1);

    cout << p1.nome;

    stampa_persona(p1);


    return 0;
}

void stampa_persona(struct persona p){
    cout << "Il nome della persona data è: " << p.nome << " " << p.cognome << endl;;
}

void leggi_persona(struct persona *p){
    cout << "Inserire il nome desiderato: ";
    cin >> p->nome;
    cout << endl << "Inserire il cognome desiderato: ";
    cin >> p->cognome;
}