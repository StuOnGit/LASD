
#ifndef MYTEST_HPP
#define MYTEST_HPP

/* ************************************************************************** */

enum class vecOrList;

#include <iostream>
#include "../vector/vector.hpp"
#include "../list/list.hpp"
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
private:
    unsigned long classe; // se 1 e' Vector se 2 e' List
    unsigned long type; // se 1 int, 2 float, 3 stringhe
    unsigned long size;
};


//Inserisce asterischi
void coutAst(unsigned long);
void coutRighe(unsigned long);
char to_upper(char&);
void toUpper(std::string& strg, void* _);
// ...

template<typename Data>
void sumMinors(const Data& dat, const void* _, void* acc);

template<typename Data>
void func_2n(Data& , void * );

template<typename Data>
void raisedToSecond(Data& , void * );

template<typename Data>
void printElement(const Data& , void * );

template<typename Data>
void productMinors(const Data& , const void* , void* );

std::string random_string(unsigned long );
void stringConcatenate(const std::string& , const void* , void* );
void launchMenu();
void chooseStruct();
void startTheStruct();
void strngStruct();
/* ************************************************************************** */

#endif
