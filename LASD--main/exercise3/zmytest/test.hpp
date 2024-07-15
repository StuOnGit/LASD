
/* ************************************************************************** */
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
void launchMenu();
void chooseClass();
template <typename Data>
void printElement(const Data& dato, void * _);
std::string random_string(unsigned long length);
void popolaStack(Stack<std::string>& s);
void popolaStack(Stack<int>& s);
void popolaStack(Stack<float>& s);
template <typename Data>
void startPointer();
void startVec();
void testFoldable(BinaryTree<float>& binaryTree);
void testFoldable(BinaryTree<std::string>& binaryTree);
void testFoldable(BinaryTree<int>& binaryTree);
void testMappable(BinaryTree<std::string>& binaryTree);
void testMappable(BinaryTree<int>& binaryTree);
void testMappable(BinaryTree<float>& binaryTree);
void stringConc(std::string& dat, void* acc);
void raisedToThird(float& dato, void * _);
void func_3n(int& dato, void * _);
void sumMajors(const float& dat, const void* _, void* acc);
void stringConcatenate(const std::string& dat, const void* _, void* acc);
void productMinorsOfN(const int& dat, const void* n, void* acc);
template <typename Data>
void usePostOrderIterator(BinaryTree<Data>& binaryTree);
template <typename Data>
void usePreOrderIterator(BinaryTree<Data>& binaryTree);
template <typename Data>
void useBreadthOrderIterator(BinaryTree<Data>& binaryTree);
template <typename Data>
void useInOrderIterator(BinaryTree<Data>& binaryTree);
template <typename Data>
void navigateTheTree(BinaryTree<Data>& binaryTree);
/* ************************************************************************** */

#endif
