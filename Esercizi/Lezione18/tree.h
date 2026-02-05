/*******************/
/*   HEADER TREE   */
/*******************/

#include "tipo.h"

struct node{
    tipo_inf inf;
    node* parent;
    node* firstChild;
    node* nextSibling;
};

typedef node* tree;

tipo_inf head(tree);
tree parent(tree);
tree firstC(tree);
tree nextS(tree);

node* new_node(tipo_inf);
void insert_child(tree, tree);
void insert_sibling(node*, tree);