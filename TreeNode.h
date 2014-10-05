#ifndef TREENODE_H
#define TREENODE_H

struct Node {

    // Informacao a ser armazenada
    int info;

    // Apontador para a subarvore a esquerda
    Node *esq;

    // Apontador para a subarvore a direita
    Node *dir;

};

#endif // TREENODE_H
