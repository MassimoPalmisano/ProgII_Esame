#include <iostream>
#include <fstream>
using namespace std;

#include "liste.h"

void pesca(lista& g, int v, char s){

    elem* c = new elem;
    tipo_inf card;
    card.valore = v;
    card.seme = s;

    c = new_elem(card);
    g = insert_elem(g, c);
}

void stampa(lista g1,lista g2){

    //per evitare di scrivere per tre volte il codice di stampa creiamo una stringa dove salviamo il risultato del compare e la usiamo per la stampa
    const char* comp; 

    while(g1 != NULL && g2 != NULL){

        int ris = compare(g1->inf, g2->inf);

        switch(ris){

            case 0:
                comp = " é uguale a ";
                break;
            case 1:
                comp = " è maggiore di ";
                break;
            case -1:
                comp = " è minore di ";
                break;
        }    

        cout << head(g1).valore << " " << head(g1).seme << comp << head(g2).valore << " " << head(g2).seme << endl;
        g1 = tail(g1);
        g2 = tail(g2);
    }

    //se in uno dei file ci fosse un valore in più rispetto all'altro lo stampiamo singolarmente
    if(g1 != NULL){
        cout << head(g1).valore << " " << head(g1).seme << endl;
    }
    if(g2 != NULL){
        cout << head(g2).valore << " " << head(g2).seme << endl;
    }

}

int* tris(lista carte){
    int* tris;
    tris = (int*)malloc(sizeof(int)*13); //allocazione di memoria dell'array
    lista temp = new elem; //nonostante si tratti di una lista doppia che permette di muoversi verso la testa della lista
    int conta;             //alla fine del check, conviene di più usare una lista temporanea e settarla alla testa per ogni ciclo del for

    for(int i = 0; i<13; i++){
        temp = carte;
        conta = 0;
        while(temp != NULL){
            if(head(temp).valore == i + 1){
                conta ++;
            }

            temp = tail(temp);
        }
        if (conta >= 3){
            tris[i] += 1;
        }
    }
    
    return tris;
}

int cala(lista& carte){

    int punteggio = 0;
    int* array_tris = tris(carte);

    for(int i = 0; i<13; i++){

        if(array_tris[i] >= 1){
            lista temp = carte;
            int cont = 0;


            while(temp != NULL && cont < 3){
                
                lista next = tail(temp);

                if(head(temp).valore == i +1){
                    cout << head(temp).valore << head(temp).seme;
                    punteggio += i+1;
                    carte = delete_elem(carte, temp);
                    cont++;
                    cout << " ";
                }
                temp = next;
            }
            cout << ", ";
        }
    }
    return punteggio;
}

int main(){

    lista g1 = NULL;
    lista g2 = NULL;

    int n;
    cout << "Numero di carte per giocatore: ";
    cin >> n;

    ifstream f1("g1.txt");
    ifstream f2("g2.txt");

    if(!f1 || !f2){
        cout << "Errore apertura file" << endl;
        return 1;
    }

    int v;
    char s;
    lista temp = NULL;

    //Quando in pesca() viene introdotta una nuova carta essa viene sempre messa in testa alla lista
    for(int i = 0; i < n; i++){
        //utilizziamo una lista temporanea per garantire che le carte siano inserite nella lista nello stesso ordine del documento
        f1 >> v >> s;
        pesca(temp, v, s);
    }
    
    while(temp != NULL){
        tipo_inf x = head(temp);
        pesca(g1, x.valore, x.seme);
        temp = tail(temp);
    }

    for(int i = 0; i < n; i++){
        f2 >> v >> s;
        pesca(temp, v, s);
    }

    while(temp != NULL){
        tipo_inf x = head(temp);
        pesca(g2, x.valore, x.seme);
        temp = tail(temp);
    }

    cout << endl << "Punto 1" << endl;

    stampa(g1, g2);

    cout << endl << "Punto 2.a" << endl;

    int* array_tris;

    array_tris = tris(g1);

    cout << "Giocatore 1: ";
    for(int i = 0; i < 13; i++){
        cout << array_tris[i] << " ";
    }
    cout << endl;

    array_tris = tris(g2);

    cout << "Giocatore 2: ";
    for(int i = 0; i < 13; i++){
        cout << array_tris[i] << " ";
    }
    cout << endl;
    
    cout << endl << "Punto 2.b" << endl;
    
    int score1, score2;
    cout << "Giocatore 1:" << endl << "Inserire i valori della carta pescata: " << endl;
    cout << "Valore: ";
    cin >> v;
    cout << "Seme: ";
    cin >> s; 

    pesca(g1, v, s);

    cout << "Giocatore 2:" << endl << "Inserire i valori della carta pescata: " << endl;
    cout << "Valore: ";
    cin >> v;
    cout << "Seme: ";
    cin >> s;

    pesca(g2, v, s);

    cout << endl << endl << "Giocatore 1: Pesca " << head(g1).valore << head(g1).seme << ", cala ";

    score1 = cala(g1);

    cout << "punteggio: " << score1 << endl;

    cout << endl << endl << "Giocatore 2: Pesca " << head(g2).valore << head(g2).seme << ", cala ";

    score2 = cala(g2);

    cout << "punteggio: " << score2 << endl;

    if(score1 - score2 < 0){
        cout << endl << "Il vincitore è Giocatore 2" << endl;
    }
    else if(score1 - score2 > 0){
        cout << endl << "Il vincitore è Giocatore 1" << endl;
    }
    else
        cout << endl << "è un pareggio!" << endl;

    return 0;
}
