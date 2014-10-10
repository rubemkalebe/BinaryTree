#include <iostream>
#include "BinaryTree.hpp"

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

    BinaryTree binArv;

/*  binArv.insert(13);
    binArv.insert(10);
    binArv.insert(2);
    binArv.insert(12);
    binArv.insert(25);
    binArv.insert(20);
    binArv.insert(31);
    binArv.insert(29);*/
    binArv.insert(13);
    binArv.insert(10);
    binArv.insert(25);
    binArv.insert(2);
    binArv.insert(12);
    binArv.insert(20);
    binArv.insert(31);
    binArv.insert(29);

    std::cout << "Impressao da arvore em pre-ordem:" << std::endl;
    binArv.printInPreOrder();

    std::cout << "Impressao da arvore em ordem:" << std::endl;
    binArv.printInOrder();

    std::cout << "Impressao da arvore em pos-ordem:" << std::endl;
    binArv.printInPostOrder();

    std::cout << "Procurando nos..." << std::endl;
    if(binArv.search(31) != NULL) {
        std::cout << "O valor 31 esta na arvore" << std::endl;
    } else {
        std::cout << "O valor 31 nao esta na arvore" << std::endl;
    }
    if(binArv.search(99) != NULL) {
     std::cout << "O valor 99 esta na arvore" << std::endl;
    } else {
     std::cout << "O valor 99 nao esta na arvore" << std::endl;
    }

    std::cout << "Minimo: " << binArv.findMin() << std::endl;
    std::cout << "Maximo: " << binArv.findMax() << std::endl;

    return 0;
}
