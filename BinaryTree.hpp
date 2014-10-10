#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "TreeNode.hpp"
#include <stack>

typedef struct Node TreeNode;

class BinaryTree {

    // Raiz da arvore
    TreeNode *raiz;

    void destroy_tree(TreeNode *node);
    void insert(int chave, TreeNode *node);
    TreeNode *createNode(int chave);
    void printNode(TreeNode *node);

    /* Metodos de impressao com percursos diferentes */
    void printInPreOrder(TreeNode *node);
    void printInOrder(TreeNode *node);
    void printInPostOrder(TreeNode *node);

    /* Metodos de busca */
    int findMin(TreeNode *node);
    int findMax(TreeNode *node);
    TreeNode *search(int chave, TreeNode *node);

public:

    BinaryTree();
    ~BinaryTree();

    void insert(int chave);
    void destroy_tree();

    /* Metodos de impressao com percursos diferentes */
    void printInPreOrder();
    void printInOrder();
    void printInPostOrder();

    /* Metodos de busca */
    int findMin();
    int findMax();
    TreeNode *search(int chave);

};

#endif // BINARYTREE_HPP
