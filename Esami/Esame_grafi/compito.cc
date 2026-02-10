#include <iostream>
#include <fstream>
#include <cstring>
#include "tipo.h"
#include "grafo.h"

using namespace std;

/**
 * Rimuove spazi, tabulazioni e ritorni a capo (come \r o \n) 
 * dalla fine della stringa per garantire che strcmp funzioni.
 */
void trim(char* s) {
    int l = strlen(s);
    while (l > 0 && isspace(s[l - 1])) {
        s[l - 1] = '\0';
        l--;
    }
}

// Punto 1: Caricamento nodi con pulizia stringhe
tipo_inf* creaNodi(int& n) {
    ifstream f("nodi.txt");
    if (!f) return NULL;
    
    f >> n;
    f.ignore(1000, '\n'); 

    tipo_inf* v = new tipo_inf[n];
    for (int i = 0; i < n; i++) {
        f.getline(v[i].descrizione, 21);
        trim(v[i].descrizione); // <--- PULIZIA FONDAMENTALE

        f >> v[i].tipo;
        f.ignore(1000, '\n'); 
    }
    f.close();
    return v;
}

/**
 * @brief Cerca l'indice (1-based) di un nodo data la sua descrizione.
 * @return L'ID del nodo (1...dim) oppure -1 se non trovato.
 */
int cercaID(const char* nome, tipo_inf* nodi, int dim) {
    for (int i = 0; i < dim; i++) {
        if (strcmp(nodi[i].descrizione, nome) == 0) {
            return i + 1; // Le primitive del grafo usano indici 1-based
        }
    }
    return -1;
}

/**
 * @brief Punto 1: Stampa valutazioni utenti
 */
void stampa(graph g, tipo_inf* nodi) {
    for (int i = 1; i <= get_dim(g); i++) {
        if (nodi[i-1].tipo == 'U') {
            adj_list l = get_adjlist(g, i);
            while (l != NULL) {
                int prod_id = get_adjnode(l);
                cout << nodi[i-1].descrizione << " valuta " 
                     << get_adjweight(l) << " " << nodi[prod_id-1].descrizione << endl;
                l = get_nextadj(l);
            }
        }
    }
}

/**
 * @brief Punto 2.a: Media valutazioni di un utente
 */
float media_utente(char* account, graph g, tipo_inf* n, int dim) {
    int id_utente = -1;
    for (int i = 0; i < dim; i++) {
        if (strcmp(n[i].descrizione, account) == 0 && n[i].tipo == 'U')
            id_utente = i + 1;
    }
    if (id_utente == -1) return 0;

    float somma = 0;
    int cont = 0;
    adj_list l = get_adjlist(g, id_utente);
    while (l != NULL) {
        somma += get_adjweight(l);
        cont++;
        l = get_nextadj(l);
    }
    return (cont > 0) ? somma / cont : 0;
}

/**
 * @brief Punto 0: Media valutazioni di un prodotto
 */
float media_prod(char* prod, graph g, tipo_inf* n, int dim) {
    int id_prod = -1;
    for (int i = 0; i < dim; i++) {
        if (strcmp(n[i].descrizione, prod) == 0 && n[i].tipo == 'P')
            id_prod = i + 1;
    }
    if (id_prod == -1) return 0;

    float somma = 0;
    int cont = 0;
    for (int i = 1; i <= dim; i++) {
        adj_list l = get_adjlist(g, i);
        while (l != NULL) {
            if (get_adjnode(l) == id_prod) {
                somma += get_adjweight(l);
                cont++;
            }
            l = get_nextadj(l);
        }
    }
    return (cont > 0) ? somma / cont : 0;
}

/**
 * @brief Punto 2.b: Algoritmo di suggerimento
 */
void suggerisci(char* account, char* prod, graph g, tipo_inf* n, int dim) {
    // 1. Troviamo gli ID numerici dei nomi in input
    int u_id = cercaID(account, n, dim);
    int p_id = cercaID(prod, n, dim);

    if (u_id == -1 || p_id == -1) {
        cout << "Utente o Prodotto non trovato." << endl;
        return;
    }

    // 2. Troviamo che voto (v_target) ha dato l'utente al prodotto
    float v_target = -1;
    adj_list l = get_adjlist(g, u_id);
    while (l != NULL) {
        if (get_adjnode(l) == p_id) {
            v_target = get_adjweight(l);
            break;
        }
        l = get_nextadj(l);
    }

    if (v_target == -1) {
        cout << account << " non ha valutato " << prod << endl;
        return;
    }

    // 3. Analizziamo ogni possibile prodotto X come candidato suggerimento
    for (int x = 1; x <= dim; x++) {
        // Deve essere un prodotto e non quello di partenza
        if (n[x-1].tipo == 'P' && x != p_id) {
            
            bool ogni_altro_utente_ok = true;
            bool trovato_almeno_un_comparo = false;

            // 4. Cerchiamo ogni ALTRO utente K
            for (int k = 1; k <= dim; k++) {
                if (n[k-1].tipo == 'U' && k != u_id) {
                    
                    float voto_k_su_p = -1;
                    float voto_k_su_x = -1;

                    // Controlliamo i voti dell'utente K
                    adj_list l_k = get_adjlist(g, k);
                    while (l_k != NULL) {
                        if (get_adjnode(l_k) == p_id) voto_k_su_p = get_adjweight(l_k);
                        if (get_adjnode(l_k) == x) voto_k_su_x = get_adjweight(l_k);
                        l_k = get_nextadj(l_k);
                    }

                    // Se l'utente K ha dato lo stesso voto v_target al prodotto P
                    if (voto_k_su_p == v_target) {
                        trovato_almeno_un_comparo = true;
                        // Regola: deve aver valutato X con almeno 3 stelle
                        if (voto_k_su_x < 3) { 
                            ogni_altro_utente_ok = false;
                        }
                    }
                }
            }

            // Se abbiamo trovato utenti simili e tutti hanno promosso X
            if (trovato_almeno_un_comparo && ogni_altro_utente_ok) {
                cout << "Suggerimento: " << n[x-1].descrizione << endl;
            }
        }
    }
}


int main() {
    int dim;
    tipo_inf* nodi = creaNodi(dim);
    if (!nodi) return -1;

    graph g = new_graph(dim);
    ifstream fv("valutazioni.txt");
    
    if (!fv) {
        cout << "Errore: valutazioni.txt non trovato!" << endl;
    } else {
        char nome_u[21], nome_p[21];
        float stelle;
        int conteggio_archi = 0;

        // Leggiamo: NomeUtente NomeProdotto Voto
        while (fv >> nome_u >> nome_p >> stelle) {
            int id_u = cercaID(nome_u, nodi, dim);
            int id_p = cercaID(nome_p, nodi, dim);

            if (id_u != -1 && id_p != -1) {
                add_arc(g, id_u, id_p, stelle);
                conteggio_archi++;
            } 
        }
        fv.close();
    }

    cout << "\n--- PUNTO 1: STAMPA ---" << endl;
    stampa(g, nodi);

    // Punto 2.a: Media Utente
    char account[21];
    cout << "\nInserire account per media: ";
    cin >> account;
    cout << "Media: " << media_utente(account, g, nodi, dim) << endl;

    // Punto 0: Media Prodotto
    char prod[21];
    cout << "\nInserire prodotto per media: ";
    cin >> prod;
    cout << "Media Prodotto: " << media_prod(prod, g, nodi, dim) << endl;

    cout << "\n--- Suggerimenti ---" << endl;
    suggerisci(account, prod, g, nodi, dim);

    return 0;

    delete[] nodi;
    return 0;
}