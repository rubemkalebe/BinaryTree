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
    // Chama o metodo para liberar toda a memoria alocada para a arvore
    destroy_tree();
}

void BinaryTree::insert(int chave) {
    if(raiz != NULL) {
        insert(chave, raiz);
    } else {
        raiz = createNode(chave);
        raiz->pai = NULL;
    }
}

bool BinaryTree::isEmpty() {
    return raiz == NULL;
}

bool BinaryTree::search(int chave) {
    return search(chave, raiz) != NULL;
}

void BinaryTree::destroy_tree() {
    destroy_tree(raiz);
}

void BinaryTree::printInPreOrder() {
    printInPreOrder(raiz);
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

int BinaryTree::findMin() {
    if(raiz == NULL) {
        return -1;
    } else {
        TreeNode *tmp = findMin(raiz);
        return tmp->info;
    }
}

int BinaryTree::findMax() {
    if(raiz == NULL) {
        return -1;
    } else {
        TreeNode *tmp = findMax(raiz);
        return tmp->info;
    }
}

int BinaryTree::sucessor(int chave) {
    TreeNode *tmp = search(chave, raiz);
    if(tmp != NULL) {
        if((tmp = sucessor(tmp)) != NULL) {
            return tmp->info;
        }
    }
    return -1;
}

int BinaryTree::predecessor(int chave) {
    TreeNode *tmp = search(chave, raiz);
    if(tmp != NULL) {
        if((tmp = predecessor(tmp)) != NULL) {
            return tmp->info;
        }
    }
    return -1;
}

/****************************
 * Metodos privados *
*****************************/

void BinaryTree::destroy_tree(TreeNode *node) {
    // Metodo recursivo para desalocar memoria
    if(node != NULL) {
        destroy_tree(node->esq);
        destroy_tree(node->dir);
        delete node;
    }
}

TreeNode *BinaryTree::createNode(int chave) {
    TreeNode *tmp = new TreeNode;
    tmp->info = chave;
    tmp->esq = NULL;
    tmp->dir = NULL;
    return tmp;
}

bool BinaryTree::isLeaf(TreeNode *node) {
    return (node->esq == NULL) && (node->dir == NULL);
}

void BinaryTree::insert(int chave, TreeNode *node) {
    /*
     * Versao recursiva
     *
    if(chave == node->info) {
        std::cout << "O valor " << chave << " ja foi inserido na BST!" << std::endl;
        return;
    } else if(chave < node->info) {
        if(node->esq != NULL) {
            insert(chave, node->esq);
        } else {
            node->esq = createNode(chave);
        }
    } else if(chave > node->info) {
        if(node->dir != NULL) {
            insert(chave, node->dir);
        } else {
            node->dir = createNode(chave);
        }
    }
    */

    /*
     * Versao iterativa
     */
    TreeNode *tmp = node;
    while(tmp != NULL) {
        if(chave == tmp->info) {
            std::cout << "O valor " << chave << " ja foi inserido na BST!" << std::endl;
            return;
        } else if(chave > tmp->info) {
            if(tmp->dir != NULL) {
                tmp = tmp->dir;
            } else {
                tmp->dir = createNode(chave);
                tmp->dir->pai = tmp;
                break;
            }
        } else if(chave < tmp->info){
            if(tmp->esq != NULL) {
                tmp = tmp->esq;
            } else {
                tmp->esq = createNode(chave);
                tmp->esq->pai = tmp;
                break;
            }
        }
    }
}

TreeNode *BinaryTree::search(int chave, TreeNode *node) {
    /*
     *  Versao recursiva
     *
    if(node != NULL) {
        if(chave == node->info) {
            return node;
        } else if(chave < node->info) {
            return search(chave, node->esq);
        } else {
            return search(chave, node->dir);
        }
    } else {
        return NULL;
    }
    */

    /*
     * Versao iterativa
     */
    TreeNode *tmp = node;
    while(tmp != NULL) {
        if(chave == tmp->info) {
            return tmp;
        } else if(chave > tmp->info) {
            tmp = tmp->dir;
        } else {
            tmp = tmp->esq;
        }
    }
    return NULL;
}

void BinaryTree::printNode(TreeNode *node) {
    if(node != NULL) {
        std::cout << node->info << std::endl;
    }
}

void BinaryTree::printInPreOrder(TreeNode *node) {
    // Percurso em pre-ordem -> Versao recursiva
    /*if(node != NULL) {
        std::cout << node->info << std::endl;
        printInPreOrder(node->esq);
        printInPreOrder(node->dir);
    }*/

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

void BinaryTree::printInOrder(TreeNode *node) {
    // Percurso em ordem -> Versao recursiva
    if(node != NULL) {
        printInOrder(node->esq);
        std::cout << node->info << std::endl;
        printInOrder(node->dir);
    }

    /*
     * Versao iterativa
    if(node != NULL) {
        std::stack<TreeNode*> pilha;
        TreeNode *atual = raiz;
        bool done = false;
        while (!done) {
            if (atual) {
                pilha.push(atual);
                atual = atual->esq;
            } else {
                if (pilha.empty()) {
                    done = true;
                } else {
                    atual = pilha.top();
                    pilha.pop();
                    std::cout << atual->info << std::endl;
                    atual = atual->dir;
                }
            }
        }
    }
    */
}

void BinaryTree::printInPostOrder(TreeNode *node) {
    // Percurso em pos-ordem -> Versao recursiva
    /*if(node != NULL) {
        printInPostOrder(node->esq);
        printInPostOrder(node->dir);
        std::cout << node->info << std::endl;
    }*/

    /* Versao iterativa */
    if(node != NULL) {
        std::stack<TreeNode*> pilha;
        TreeNode *ant = NULL;   // armazena o no anterior da arvore
        pilha.push(node);
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

TreeNode *BinaryTree::findMin(TreeNode *node) {
    /*
     * Versao recursiva
     *
    if(node->esq != NULL) {
        findMin(node->esq);
    } else {
        return node->info;
    }
    */

    /*
     * Versao iterativa
     *
     */
    TreeNode *tmp = node;
    while(tmp->esq != NULL) {
        tmp = tmp->esq;
    }
    return tmp;
}

TreeNode *BinaryTree::findMax(TreeNode *node) {
    /*
     * Versao recursiva
     *
    if(node->dir != NULL) {
        findMax(node->dir);
    } else {
        return node->info;
    }
    */

    /*
     * Versao iterativa
     *
     */
    TreeNode *tmp = node;
    while(tmp->dir != NULL) {
        tmp = tmp->dir;
    }
    return tmp;
}

TreeNode *BinaryTree::sucessor(TreeNode *node) {
    if(node->dir != NULL) {
        return findMin(node->dir);
    } else {
        TreeNode *p;
        TreeNode *t;
        p = node->pai;
        t = node;
        while((p != NULL) && (t == p->dir)) {
            // vai subindo na arvore
            t = p;
            p = t->pai;
        }
        if(p == NULL) {
            // nao tem sucessor
            return NULL;
        } else {
            return p;
        }
    }
}

TreeNode *BinaryTree::predecessor(TreeNode *node) {
    if(node->esq != NULL) {
        return findMax(node->esq);
    } else {
        TreeNode *p;
        TreeNode *t;
        p = node->pai;
        t = node;
        while((p != NULL) && (t == p->esq)) {
            // vai subindo na arvore
            t = p;
            p = t->pai;
        }
        if(p == NULL) {
            // nao tem predecessor
            return NULL;
        } else {
            return p;
        }
    }
}
