
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: public virtual Queue<Data>, private virtual Vector<Data>{ // Must extend Queue<Data> and Vector<Data>

private:

  // ...

protected:

   using Vector<Data>::size;
   using Vector<Data>::Elements;
   unsigned long testa = 0;
   unsigned long coda = 0;
   unsigned long realSize = 0;
public:

  // Default constructor
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
   QueueVec(LinearContainer<Data>&); // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
   QueueVec(const QueueVec&);

  // Move constructor
   QueueVec(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
   virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
   QueueVec& operator=(const QueueVec&);

  // Move assignment
   QueueVec& operator=(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec&) const noexcept;
  bool operator!=(const QueueVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  void Enqueue(Data&&) noexcept override; // Override Queue member (move of the value)
  Data& Head() override; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override; // Override Container member

  unsigned long Size() const noexcept override; // Override Container member

  void Clear(); // Override Container member

protected:

  // Auxiliary member functions

  //void Expand();
  //void Reduce() ;
  void SwapVectors(unsigned long) ;

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
