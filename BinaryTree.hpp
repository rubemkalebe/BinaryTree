#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "TreeNode.hpp"
#include <stack>
#include <queue>
#include <sstream>

template <class Type>
class BinarySearchTree {

    // Raiz da arvore
    TreeNode<Type> *raiz;

    void destroy_tree(TreeNode<Type> *node);
    void insert(Type chave, TreeNode<Type> *node);
    TreeNode<Type> *createNode(Type chave);
    void printNode(TreeNode<Type> *node);
    bool isLeaf(TreeNode<Type> *node);
    void remove(Type chave, TreeNode<Type> *node);

    /* Metodos de impressao com percursos diferentes */
    void printInPreOrder(TreeNode<Type> *node);
    void printInOrder(TreeNode<Type> *node);
    void printInPostOrder(TreeNode<Type> *node);
    std::string percorreEmNivel(TreeNode<Type> *node);

    /* Metodos de busca */
    TreeNode<Type> *findMin(TreeNode<Type> *node);
    TreeNode<Type> *findMax(TreeNode<Type> *node);
    TreeNode<Type> *search(Type chave, TreeNode<Type> *node);
    TreeNode<Type> *sucessor(TreeNode<Type> *node);
    TreeNode<Type> *predecessor(TreeNode<Type> *node);

public:

    BinarySearchTree();
    ~BinarySearchTree();

    void insert(Type chave);
    void remove(Type chave);
    void destroy_tree();
    bool isEmpty();

    /* Metodos de impressao com percursos diferentes */
    void printInPreOrder();
    void printInOrder();
    void printInPostOrder();
    std::string toString();

    /* Metodos de busca */
    Type findMin();
    Type findMax();
    bool search(Type chave);
    Type sucessor(Type chave);
    Type predecessor(Type chave);

};

#endif // BINARYTREE_HPP
