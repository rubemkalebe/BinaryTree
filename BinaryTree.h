#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <stack>

typedef struct Node TreeNode;

class BinaryTree {

    // Raiz da arvore
    TreeNode *raiz;

    void destroy_tree(TreeNode *folha);
    void insert(int chave, TreeNode *folha);
    TreeNode *search(int chave, TreeNode *folha);
    void printNode(TreeNode *folha);

    /* Metodos de impressao com percursos diferentes */
    void printInPreOrder(TreeNode *folha);
    void printInOrder(TreeNode *folha);
    void printInPostOrder(TreeNode *folha);

public:

    BinaryTree();
    ~BinaryTree();

    void insert(int chave);
    TreeNode *search(int chave);
    void destroy_tree();

    /* Metodos de impressao com percursos diferentes */
    void printInPreOrder();
    void printInOrder();
    void printInPostOrder();

};

#endif // BINARYTREE_H
