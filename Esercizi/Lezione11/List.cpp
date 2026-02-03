#include <iostream>
using namespace std;

//definizione della struttura elem che rappresenta le liste
struct elem{
    int inf;    //campo che contiene i dati necessari
    elem* punt; //campo che punta all'elemento successivo
};

typedef elem *lista;    //Definizione della testa della lista, da fare al di fuori del main
   
int head(lista l); //funzione che ritorna il valore testa della lista
lista tail(lista l); //funzione che ritorna la lista a partire dall'elemento successivo rispetto a quello dato
void stampalista(lista p); //funzione che stampa tutti i valori degli elementi della lista
lista insert_elem(lista l, elem* e); //funzione che permette di inserire un nuovo elemento all'interno della lista
lista crealista(int n); //funzione che permette di creare una nuova lista lunga n elementi
lista delete_elem(lista l, elem* e); //funzione per cancellare un elemento dalla lista
void eliminalista(lista &testa); //funzione che cancella la liste interamente
elem* search(lista l, int v); //funzione che restituisce l'elemento v cercato nella lista
int conta(lista l, int v); //funzione che conta il numero di volte in cui v appare nella lista
lista cancella(lista l, int v); //funzione che cancella dalla lista gli elementi con valore v
lista copy(lista l1); //funzione che prende una lista e ne crea una nuova copiando gli elementi dell'originale

int main(){

    //--------------test di inserimento e stampa lista--------------------------//
    /*lista p = new elem;     //questo comando crea un elemento dinamico di tipo elem*
                            //solo dopo questo comando si può accedere ai suoi campi
    p->inf = 3;


    lista p1 = new elem;

    p1->inf = 7;


    p->punt = p1;
    p1->punt = NULL;


    stampalista(p);

    elem * p2 = new elem;
    p2->inf = 4;
    p2->punt = NULL;

    insert_elem(p, p2);

    stampalista(p2);

    cout << endl << endl << endl;*/


    //----------test di creazione lista e cancellazione della lista-----------//
    /*int n; 
    cout << "Inserire il numero di elementi da inserire nella lista: ";
    cin >> n; 
    lista testa = crealista(n);
    stampalista(testa);
    eliminalista(testa);
    cout << testa << endl; */

    //---------test del contatore dei valori---------------------------------//
    /*int n, v = 1, l = 6, count; 
    cout << "Inserire il numero di elementi da inserire nella lista: ";
    cin >> n; 
    lista testa = crealista(n);
    stampalista(testa);
    
    count = conta(testa, v);
    cout << "Il numero " << v << " appare " << count << " volte nella lista" << endl;

    count = conta(testa, l);
    cout << "Il numero " << l << " appare " << count << " volte nella lista" << endl;*/

    //-----------test cancellazione degli elementi con valore v---------------//
    int n, v = 1; 
    cout << "Inserire il numero di elementi da inserire nella lista: ";
    cin >> n; 
    lista testa = crealista(n);
    stampalista(testa);
    
    testa = cancella(testa, v);
    stampalista(testa);

    return 0;
}

//------funzioni di testa e coda-------//
int head(lista l){return l->inf;}       //si nota che la testa restituisce l'informazione
lista tail(lista l){return l->punt;}    //mentre la coda restituisce la lista a partire dall'elemento successivo a quello chiamato


//------funzione di stampa-------------//
void stampalista(lista p){
     while (p != NULL) {
        cout << head(p) << " " ; // stampa valore in testa
        p = tail(p); // spostamento sulla coda di p
    }
    cout << endl ;
}

//------funzione di inserimento--------//
lista insert_elem(lista l, elem* e){    //la funzione inserisce l'elemento in testa alla lista
e->punt=l;  //questo elemento deve essere dinamico e inizializzato prima di poter essere inserito
return e;
}


//------funzione di creazione lista----//
lista crealista(int n){

    lista testa = NULL;

    for(int i = 0; i< n; i++){
        elem * n = new elem;
        cout << "Inserire il valore nell'elemento " << i+1 << ": ";
        cin >> n->inf;
        n->punt = NULL;
        testa = insert_elem(testa, n);
    }

    return testa;
}


//------funzione di cancellamento elem---//
lista delete_elem(lista l, elem* e){

    if (l==e)       //caso in cui l'elemento da rimuovere è la testa
        l=tail(l);
    else{           //caso in cui l'elemento da rimuovere sia diverso dalla testa

        lista l1=l;             //utilizziamo una seconda lista temporanea (l1) per muoverci all'interno della lista
        while (tail(l1)!=e)     //senza perdere gli elementi precedenti
                l1=tail(l1);
        
        l1->punt=tail(e);
    }

    delete e;      //deallochiamo la memoria usata per l'elemento e

    return l;
}

//------funzione di cancellamento lista--//
void eliminalista(lista &testa){

    while(testa != NULL){

        testa = delete_elem(testa, testa); //è necessario mettere testa = in quando delete_elem non lavora su lista tramite puntatori ma restituisce proprio l

    }

}


//------funzione di ricerca--------------//
elem* search(lista l, int v){
    while(l!=NULL){
        if(head(l)==v)
            return l;
        else
            l=tail(l);
    }

    return NULL;
}

//------funzione di conta valori---------//
int conta(lista l, int v){
    int conta;

    while(l != NULL){
        if (head(l) == v){
            conta++; 
            l = tail(l);
        }
        else 
            l = tail(l);
    }

    return conta;
}

//------funzione di cancellamento specifica--//
lista cancella(lista l, int v){
    lista l1 = l;
    while(l1 != NULL){
        
        if(search(tail(l1), v)){
            delete_elem(l, search(tail(l1), v));
            l1 = tail(l1);
        }
        else
            l1 = tail(l1);

    }

    //nel caso in cui ci siano diversi valori v di fila capita che un singolo controllo non basti, per risolvere il problema possiamo semplicemente fare ciclare di nuovo la lista
    l1 = l;
    while(l1 != NULL){
        
        if(search(tail(l1), v)){
            delete_elem(l, search(tail(l1), v));
            l1 = tail(l1);
        }
        else
            l1 = tail(l1);

    }

    return l;
}

//------funzione di copia una lista------//
lista copy(lista l1){
    //dichiaro i vari elementi necessari
    lista l=NULL;
    elem* curr;
    elem* prev=NULL;

    while(l1!=NULL){
        curr = new elem;
        curr->inf = head(l1);   //creo l'elemento corrente su cui sto lavorando
        curr->punt=NULL;
        if(prev==NULL)          //creo la testa della lista
            l=curr;
        else
            prev->punt=curr;    //accodo l'elemento al suo predecessore

            prev=curr;          //aggiorno i dati per il prossimo elemento
            l1=tail(l1);

    }

    return l;
}