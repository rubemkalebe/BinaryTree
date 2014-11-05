#include <iostream>
#include "BinaryTree.hpp"
#include "BinaryTree.cpp"

/*
    Arvore inserida
             13
           /    \
         10      25
        /  \    /  \
       2    12 20   31
                    /
                   29
*/

int main() {

    BinarySearchTree<int> bst;

    bst.insert(13);
    bst.insert(10);
    bst.insert(25);
    bst.insert(2);
    bst.insert(12);
    bst.insert(20);
    bst.insert(31);
    bst.insert(29);
/*
    std::cout << "Impressao da arvore em pre-ordem:" << std::endl;
    bst.printInPreOrder();

    std::cout << "Impressao da arvore em ordem:" << std::endl;
    bst.printInOrder();

    bst.remove(25);

    std::cout << "Impressao da arvore em ordem:" << std::endl;
    bst.printInOrder();

    std::cout << "Impressao da arvore em pos-ordem:" << std::endl;
    bst.printInPostOrder();

    std::cout << "Procurando nos..." << std::endl;
    if(bst.search(31)) {
        std::cout << "O valor 31 esta na arvore" << std::endl;
    } else {
        std::cout << "O valor 31 nao esta na arvore" << std::endl;
    }
    if(bst.search(99)) {
     std::cout << "O valor 99 esta na arvore" << std::endl;
    } else {
     std::cout << "O valor 99 nao esta na arvore" << std::endl;
    }

    std::cout << "Minimo: " << bst.findMin() << std::endl;
    std::cout << "Maximo: " << bst.findMax() << std::endl;
*/

    std::cout << bst.toString() << std::endl;

    return 0;
}
