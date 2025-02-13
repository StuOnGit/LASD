
#include <iostream>

/* ************************************************************************** */

#include "../../container/container.hpp"

/* ************************************************************************** */

// Container member functions!

void Empty(unsigned int & testnum, unsigned int & testerr, const lasd::Container& con, bool chk) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " The container is " << ((tst = con.Empty()) ? "" : "not ") << "empty: ";
  std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (unsigned int ) tst);
}

void Size(unsigned int & testnum, unsigned int & testerr, const lasd::Container& con, bool chk, unsigned long siz) {
  bool tst;
  testnum++;
  std::cout << " " << testnum << " The container has size " << con.Size() << ": ";
  std::cout << ((tst = ((con.Size() == siz) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  testerr += (1 - (unsigned int ) tst);
}

/* ************************************************************************** */

// Auxiliary functions for MappableContainer!

void MapStringAppend(std::string& dat, void* par) {
  dat.append(*((std::string*) par));
}

/* ************************************************************************** */

// Auxiliary functions for FoldableContainer!

void FoldParity(const int& dat, const void* _, void* acc) {
  *((int*) acc) += dat;
  *((int*) acc) %= 2;
}

void FoldStringConcatenate(const std::string& dat, const void* _, void* acc) {
  ((std::string*) acc)->append(dat);
}

/* ************************************************************************** */
