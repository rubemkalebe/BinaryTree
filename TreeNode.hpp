#ifndef TREENODE_HPP
#define TREENODE_HPP

struct Node {

    // Informacao a ser armazenada (depois sera um campo para a chave e outro para o dado)
    int info;

    // Apontador para a subarvore a esquerda
    Node *esq;

    // Apontador para a subarvore a direita
    Node *dir;

    // Apontador para o pai do no
    Node *pai;

};

#endif // TREENODE_HPP
