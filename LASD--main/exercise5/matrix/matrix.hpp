
#ifndef MATRIX_HPP
#define MATRIX_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Matrix: public virtual MappableContainer<Data>, public virtual FoldableContainer<Data>{ // Must extend MappableContainer<Data> and FoldableContainer<Data>

private:

  // ...

protected:

  int row = 0;
  int column = 0;

public:

  // Destructor
   virtual ~Matrix() = default;

  /* ************************************************************************ */

  // Copy assignment
   Matrix<Data>& operator=(const Matrix<Data>&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
   Matrix<Data>& operator=(Matrix<Data>&&) noexcept  = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Matrix<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Matrix<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  int RowNumber() const; // (concrete function should not throw exceptions)
  int ColumnNumber() const; // (concrete function should not throw exceptions)

  virtual void RowResize(const int&) = 0;
  virtual void ColumnResize(const int&) = 0;

  virtual bool ExistsCell(const int&, const int&) const noexcept = 0; // (concrete function should not throw exceptions)

  virtual Data& operator()(const int&, const int&) = 0; // Mutable access to the element (concrete function should throw exceptions only when out of range)
  virtual const Data& operator()(const int&, const int&) const = 0; // Immutable access to the element (concrete function should throw exceptions when not present)


};

/* ************************************************************************** */

}

#include "matrix.cpp"

#endif
