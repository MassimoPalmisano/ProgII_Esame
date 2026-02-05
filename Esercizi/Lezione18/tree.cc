#include <iostream>
using namespace std;

#include "tree.h"

/************************/
/*   DEFINIZIONE TREE   */
/************************/

tipo_inf head(tree t){return t->inf;}
tree parent(tree t){return t->parent;}
tree firstC(tree t){return t->firstChild;}
tree nextS(tree t){return t->nextSibling;}

node* new_node(tipo_inf inf){
    tree t = new node;
    t->inf = copy(inf);
    t->parent = t->firstChild = t->nextSibling = NULL;
    return t;
}

void insert_child(tree p, tree c){
    if(p->firstChild != NULL)
        c->nextSibling = p->firstChild;
    
    c->parent = p;

    p->firstChild = c;
}

void insert_sibling(node* n, tree t){

    if(n->nextSibling != NULL)
        t->nextSibling = n->nextSibling;

    if(n->parent != NULL)
        t->parent = n->parent;

    n->nextSibling = t;
}