
#ifndef MYTEST_HPP
#define MYTEST_HPP

/* ************************************************************************** */

#include <iostream>
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/stack.hpp"
#include "../queue/queue.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"


using namespace lasd;

class Menu {

public:
    Menu() : classe(0), type(0), size(0){}
    virtual ~Menu() = default;

    void setClasse(char cl) {
        classe = cl;
    }
    unsigned long getClasse(){
        return classe;
    }

    void setType(unsigned long tipo){
        type = tipo;
    }
    unsigned long getTipo(){
        return type;
    }
    void setSize(unsigned long siz){
        size = siz;
    }
    unsigned long getSize(){
        return size;
    }

    unsigned long getStruttura() const {
        return struttura;
    }

    void setStruttura(unsigned long struttura) {
        Menu::struttura = struttura;
    }

private:
    unsigned long classe; // se 1 e' Vector se 2 e' List
    unsigned long type; // se 1 int, 2 float, 3 stringhe
    unsigned long struttura; //se 1 pila, se 2 coda
    unsigned long size;
};

//Inserisce asterischi
void coutAst(unsigned long);
void coutRighe(unsigned long);
std::string random_string(unsigned long );
void launchMenu();
void chooseType();
template <typename Data>
void specificOperations(BST<Data>&);
template<typename Data>
void printElement(const Data& , void * );
void testFoldable(BinaryTree<float>& );
void testFoldable(BinaryTree<std::string>& );
void testFoldable(BinaryTree<int>& );
void sumMajors(const float& , const void* , void* );
void stringConcatenate(const std::string& , const void* , void* );
void productMinorsOfN(const int& , const void* , void* );
void popolaBST(BST<std::string>& );
void popolaBST(BST<float>& );
void popolaBST(BST<int>& );
void startBST();
/* ************************************************************************** */

#endif
