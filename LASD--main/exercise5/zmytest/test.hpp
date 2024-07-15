
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
#include "../matrix/matrix.hpp"
#include "../matrix/csr/matrixcsr.hpp"
#include "../matrix/vec/matrixvec.hpp"
#include <random>
#include <ctime>

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

    void setStruttura(unsigned long strutt) {
        struttura = strutt;
    }

    unsigned long getColonna() const {
        return colonna;
    }

    void setColonna(unsigned long colonna) {
        Menu::colonna = colonna;
    }

    unsigned long getRiga() const {
        return riga;
    }

    void setRiga(unsigned long riga) {
        Menu::riga = riga;
    }

private:
    unsigned long classe; // se 1 e' Vector se 2 e' List
    unsigned long type; // se 1 int, 2 float, 3 stringhe
    unsigned long struttura; //se 1 MatrixCsr, se 2 MatrixVec
    unsigned long size;
    unsigned long colonna;
    unsigned long riga;
};


void coutAst(unsigned long);
void coutRighe(unsigned long);
std::string random_string(unsigned long );
void launchMenu();
void chooseType();
void chooseStruct();
template <typename Data>
void startMatrixCSR();
template <typename Data>
void startMatrixVec();
void productMinorsOfN(const int& , const void* , void* );
void stringConcatenate(const std::string& , const void* , void* );
void sumMajors(const float& , const void* , void* );
void stringConc(std::string& , void* );
void NegativeAndRaisedToThird(float& dato, void * );
void testFoldable(Matrix<int>& );
void testFoldable(Matrix<float>& );
void testFoldable(Matrix<std::string>& );
void testMappable(Matrix<int>& );
void testMappable(Matrix<float>& );
void testMappable(Matrix<std::string>& );
/* ************************************************************************** */

#endif
