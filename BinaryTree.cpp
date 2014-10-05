#include <iostream>
#include "BinaryTree.hpp"

/****************************
 * Metodos publicos *
*****************************/

BinaryTree::BinaryTree() {
    // Como uma arvore eh representada pelo endereço do no raiz
    // uma arvore vazia tem que ser representada pelo valor NULL.
    raiz = NULL;
}

BinaryTree::~BinaryTree() {
    destroy_tree();
}

void BinaryTree::insert(int chave) {
    if(raiz != NULL) {
        insert(chave, raiz);
    } else {
        raiz = new TreeNode;
        raiz->info = chave;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }
}

TreeNode *BinaryTree::search(int chave) {
    return search(chave, raiz);
}

void BinaryTree::destroy_tree() {
    destroy_tree(raiz);
}

void BinaryTree::printInPreOrder() {
    /* Versao recursiva - usa um metodo auxiliar */
    //printInPreOrder(raiz);

    /* Versao iterativa */
    TreeNode *tmp;
    std::stack<TreeNode*> pilha;
    if(raiz != NULL) {
        pilha.push(raiz);
        while(!pilha.empty()) {
            tmp = pilha.top();
            pilha.pop();
            printNode(tmp);
            // Tenta empilhar filho direito
            if(tmp->dir != NULL) {
                pilha.push(tmp->dir);
            }
            // Tenta empilhar filho esquerda
            if(tmp->esq != NULL) {
                pilha.push(tmp->esq);
            }
        }
    }
}

void BinaryTree::printInOrder() {
    printInOrder(raiz->esq);
    printNode(raiz);
    printInOrder(raiz->dir);
}

void BinaryTree::printInPostOrder() {
    printInPostOrder(raiz->esq);
    printInPostOrder(raiz->dir);
    printNode(raiz);
}

/****************************
 * Metodos privados *
*****************************/

void BinaryTree::destroy_tree(TreeNode *folha) {
    if(folha != NULL) {
        destroy_tree(folha->esq);
        destroy_tree(folha->dir);
        delete folha;
    }
}

void BinaryTree::insert(int chave, TreeNode *folha) {
    if(chave < folha->info) {
        if(folha->esq != NULL) {
            insert(chave, folha->esq);
        } else {
            folha->esq = new TreeNode;
            folha->esq->info = chave;
            folha->esq->esq = NULL;
            folha->esq->dir = NULL;
        }
    } else if(chave >= folha->info) {
        if(folha->dir != NULL) {
            insert(chave, folha->dir);
        } else {
            folha->dir = new TreeNode;
            folha->dir->info = chave;
            folha->dir->esq = NULL;
            folha->dir->dir = NULL;
        }
    }
}

TreeNode *BinaryTree::search(int chave, TreeNode *folha) {
    if(folha != NULL) {
        if(chave == folha->info) {
            return folha;
        } else if(chave < folha->info) {
            return search(chave, folha->esq);
        } else {
            return search(chave, folha->dir);
        }
    } else {
        return NULL;
    }
}

void BinaryTree::printNode(TreeNode *folha) {
    if(folha != NULL) {
        std::cout << folha->info << std::endl;
    }
}

void BinaryTree::printInPreOrder(TreeNode *folha) {
    // Percurso em pre-ordem -> Versao recursiva
    if(folha != NULL) {
        std::cout << folha->info << std::endl;
        printInPreOrder(folha->esq);
        printInPreOrder(folha->dir);
    }
}

void BinaryTree::printInOrder(TreeNode *folha) {
    // Percurso em ordem -> Versao recursiva
    if(folha != NULL) {
        printInOrder(folha->esq);
        std::cout << folha->info << std::endl;
        printInOrder(folha->dir);
    }

    /* Versao iterativa */
    /*if(folha != NULL) {
        std::stack<TreeNode*> pilha;
        pilha.push(folha);
        TreeNode *ant = NULL;
        while (!pilha.empty()) {
          TreeNode *atual = pilha.top();
          if (!ant || ant->esq == atual || ant->dir == atual) {
            if (atual->esq)
              pilha.push(atual->esq);
            else if (atual->dir)
              pilha.push(atual->dir);
          } else if (atual->esq == ant) {
            if (atual->dir)
              pilha.push(atual->dir);
          } else {
            std::cout << atual->info << std::endl;
            pilha.pop();
          }
          ant = atual;
        }
    }*/

}

void BinaryTree::printInPostOrder(TreeNode *folha) {
    // Percurso em pos-ordem -> Versao recursiva
    /*if(folha != NULL) {
        printInPostOrder(folha->esq);
        printInPostOrder(folha->dir);
        std::cout << folha->info << std::endl;
    }*/

    /* Versao iterativa */
    if(folha != NULL) {
        std::stack<TreeNode*> pilha;
        TreeNode *ant = NULL;   // armazena o no anterior da arvore
        pilha.push(folha);
        while (!pilha.empty()) {
          TreeNode *atual = pilha.top();    // armazena o no atual
          // Quando ant eh pai de atual vamos descer na arvore
          if (!ant || ant->esq == atual || ant->dir == atual) {
            if (atual->esq)
              pilha.push(atual->esq);
            else if (atual->dir)
              pilha.push(atual->dir);
          // Quando ant eh filho esq de atual vamos percorrer a arvore da esq
          } else if (atual->esq == ant) {
            if (atual->dir)
              pilha.push(atual->dir);
          } else {
            std::cout << atual->info << std::endl;
            pilha.pop();
          }
          ant = atual;
        }
    }
}
