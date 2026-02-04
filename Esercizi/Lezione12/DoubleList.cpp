#include <iostream>
#include <string>
using namespace std;

//definizione della struttura elem che rappresenta le liste
struct elem{
    char inf[51]; //campo che contiene i dati necessari
  
    elem* punt; //campo che punta all'elemento successivo
    elem* prec; //campo che punta all'elemento precedente
};

typedef elem *lista;    //Definizione della testa della lista, da fare al di fuori del main
   
char* head(lista l); //funzione che ritorna il valore testa della lista
lista tail(lista l); //funzione che ritorna il puntatore dell'elemento successivo
lista prev(lista l); //funzione che ritorna il puntatore dell'elemento precedente
lista insert_elem(lista l, elem* e); //funzione che permette di inserire un nuovo elemento all'interno della lista
lista delete_elem(lista l, elem* e); //funzione per cancellare un elemento dalla lista
void stampalista(lista p); //funzione che stampa tutti i valori degli elementi della lista
lista crealista(int n); //funzione che permette di creare una nuova lista lunga n elementi
void eliminalista(lista &testa); //funzione che cancella la liste interamente
elem* search(lista l, const string &v); //funzione che restituisce l'elemento v cercato nella lista
int conta(lista l, char* v); //funzione che conta il numero di volte in cui v appare nella lista
lista cancella(lista l, char* v); //funzione che cancella dalla lista gli elementi con valore v
void naviga(elem* e); //funzione che permette di navigare gli elementi della lista

int main(){
    int n;
    char v[51];
    int scelta;
    lista testa=NULL;
    elem* ris;

    do{
    		cout<< "Cosa vuoi fare?"<<endl;
    		cout<< "1: creare una lista"<<endl;
    		cout<<"2:cancellare valori dalla lista"<<endl;
    		cout<<"3: stampare la lista"<<endl;
    		cout<<"4:cercare valori nella lista"<<endl;
    		cout<<"5:esci"<<endl;
    		cin>>scelta;
    		switch(scelta){
                case 1: cout << "Inserire il numero di elementi da inserire nella lista" << endl;
                cin >> n;
                testa = crealista(n);
                break;
                case 2: cout<<"Inserire il valore da cancellare:"<<endl;
                cin>>v;
                testa=cancella(testa,v);
                break;
                case 3: stampalista(testa);
                break;

                case 4:
                cout << "Inserire il valore che si vuole cercare: ";
                cin>>v;
                ris=search(testa,v);
                if(ris!=NULL)
                    naviga(ris);

                else
                    cout<<"Valore non presente"<<endl;
                break;

                case 5: cout<<"Ciao, ciao!!"<<endl;
                break;

                default:
                cout << "Il valore inserito non è valido!" << endl;
                cout << "Inserire un valore che vada da 1 a 5" << endl;
            }
    	}while(scelta!=5);
    return 0;
}

//-----funzioni primitive che restituiscono il singolo campo dell'elemento----//
char* head(lista l){return l->inf;}       //si nota che la testa restituisce l'informazione
lista tail(lista l){return l->punt;}    //mentre la coda restituisce la lista a partire dall'elemento successivo a quello chiamato
lista prev(lista l){return l->prec;}


//------------------funzione di inserimento elem----------------//
lista insert_elem(lista l, elem* e){    //la funzione inserisce l'elemento in testa alla lista
    
    e->punt=l;

    if(l!=NULL)
        l->prec=e;
    
    e->prec=NULL;
    return e;
}


//-------------------funzione di cancellazione elem-----------------//
lista delete_elem(lista l, elem* e){
    if(l==e)
        l=tail(l); // e è la testa della lista
    else // e non è la testa della lista
        (e->prec)->punt = e->punt; //al puntatore del precedente di e mettiamo il punatore di e

    if(e->punt!=NULL)
        (e->punt)->prec=e->prec;   //se il successivo ad e esiste mettiamo che il suo precedente è il precedente di e 

    
    delete e;
    return l;
}


//------funzione di stampa-------------//
void stampalista(lista p){
     while (p != NULL) {
        cout << head(p) << " " ; // stampa valore in testa
        p = tail(p); // spostamento sulla coda di p
    }
    cout << endl ;
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


//------funzione di cancellamento lista--//
void eliminalista(lista &testa){

    while(testa != NULL){

        testa = delete_elem(testa, testa); //è necessario mettere testa = in quando delete_elem non lavora su lista tramite puntatori ma restituisce proprio l

    }

}


//------funzione di ricerca--------------//
elem* search(lista l, const string &v){
    while(l!=NULL){
        if(head(l) == v)
            return l;
        else
            l=tail(l);
    }

    return NULL;
}


//------funzione di conta valori---------//
int conta(lista l, char* v){
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
lista cancella(lista l, char* v){
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


//-----funzione di navigazione lista-----//
void naviga(elem* e){
    char scelta;
    cout << endl << "Trovato!";
    cout << endl << "L'URL su cui ti trovi è " << head(e) << endl;
    do{
        cout << "Cosa si vuole fare?" << endl;
        cout << "B se si vuole passare all'elemento precedente;" << endl;
        cout << "F se si vuole passare all'elemento successivo;" << endl;
        cout << "S se si vuole uscire dalla navigazione." << endl;
        cin >> scelta;

        switch(scelta){
            case 'B':
            case 'b': 
            e = prev(e);
            cout << "Sei passato all'URL precedente: " << head(e) << endl;
            break;

            case 'F':
            case 'f':
            e = tail(e);
            cout << "Sei passato all'URL successiva: " << head(e) << endl;
            break;

            case 'S':
            case 's':
            cout << "Stai uscendo dalla navigazione." << endl;
            break;

            default:
            cout << "La lettera inserita non rientra tra le possibili opzioni" << endl;
            cout << "Si prega di inserire: " << endl;
            cout << "B se si vuole passare all'elemento precedente;" << endl;
            cout << "F se si vuole passare all'elemento successivo;" << endl;
            cout << "S se si vuole uscire dalla navigazione." << endl;
        }

    }   while(scelta != 'S' or scelta != 's');
}