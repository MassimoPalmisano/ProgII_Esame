#include <iostream>
#include <fstream>
#include <cstring>
#include "hotel.h"
#include "bst.h"

using namespace std;

// Punto 2.a: Ricerca sfruttando le proprietà del BST (Decrescente)
// Ricorda: Left > Root > Right
void ricerca(bst b, int stelle, bool maggiore) {
    if (b == NULL) return;

    if (maggiore) {
        // Stampiamo quelli con stelle > input
        ricerca(b->left, stelle, maggiore); // Sinistra sono sicuramente maggiori
        if (b->key > stelle) {
            print(b->inf);
            ricerca(b->right, stelle, maggiore); // Anche a destra potrebbero essercene
        }
    } else {
        // Stampiamo quelli con stelle <= input
        if (b->key <= stelle) {
            ricerca(b->left, stelle, maggiore); // A sinistra potrebbero essercene di <=
            print(b->inf);
            ricerca(b->right, stelle, maggiore); // A destra sono sicuramente minori
        } else {
            ricerca(b->right, stelle, maggiore);
        }
    }
}

// Punto 2.b: Media (Conteggio hotel in luogo con stelle > soglia)
int media(bst b, int soglia, char* luogo) {
    if (b == NULL) return 0;
    
    int count = 0;
    if (strcmp(b->inf.luogo, luogo) == 0 && b->key > soglia) {
        count = 1;
    }

    // Poiché cerchiamo per luogo (non ordinato nel BST), dobbiamo visitare tutto il sottoalbero 
    // se le stelle sono potenzialmente sopra la soglia.
    if (b->key > soglia) {
        return count + media(b->left, soglia, luogo) + media(b->right, soglia, luogo);
    } else {
        // Se siamo <= soglia, a destra sono tutti più piccoli, cerchiamo solo a sinistra
        return count + media(b->left, soglia, luogo);
    }
}

// Punto 3: Stampa per luogo
void per_luogo(bst b, char* luogo) {
    if (b == NULL) return;
    per_luogo(b->left, luogo);
    if (strcmp(b->inf.luogo, luogo) == 0) {
        print(b->inf);
    }
    per_luogo(b->right, luogo);
}

void stampa(bst b) {
    if (b != NULL) {
        stampa(get_left(b));
        print(get_value(b));
        stampa(get_right(b));
    }
}

int main() {
    bst tree = NULL;
    ifstream f("hotel.txt");
    if (!f) {
        cout << "Errore apertura file hotel.txt" << endl;
        return -1;
    }

    int n;
    f >> n;
    for (int i = 0; i < n; i++) {
        tipo_inf h;
        f >> h.stelle;
        f.ignore(); // Salta newline
        f.getline(h.nome, 21);
        f.getline(h.luogo, 21);
        bst_insert(tree, bst_newNode(h.stelle, h));
    }
    f.close();

    cout << "--- Punto 1: Stampa BST Decrescente ---" << endl;
    stampa(tree);

    cout << "\n--- Punto 2.a: Ricerca (3, true) ---" << endl;
    ricerca(tree, 3, true);

    cout << "\n--- Punto 2.a: Ricerca (3, false) ---" << endl;
    ricerca(tree, 3, false);

    cout << "\n--- Punto 2.b: Hotel a Bologna con stelle > 2 ---" << endl;
    char loc[] = "Bologna";
    cout << "Risultato: " << media(tree, 2, loc) << endl;

    cout << "\n--- Punto 3: Hotel a Firenze ---" << endl;
    char loc2[] = "Firenze";
    per_luogo(tree, loc2);

    return 0;
}