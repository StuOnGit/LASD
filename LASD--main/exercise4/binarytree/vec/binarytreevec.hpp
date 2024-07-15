
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec: public virtual BinaryTree<Data>{ // Must extend BinaryTree<Data>

private:

  // ...

protected:

   using BinaryTree<Data>::size;

  // ...

  struct NodeVec: public virtual BinaryTree<Data>::Node{ // Must extend Node

  private:

      //...

  protected:

    // ...

  public:

      Data element;

      unsigned int index;

      Vector<NodeVec*>* veccPtr = nullptr;

      friend class BinaryTree<Data>;

      /* ********************************************************************** */

      //Destructor
      ~NodeVec() = default;

      // Specific member functions

       Data& Element() noexcept ; // Mutable access to the element (concrete function should not throw exceptions)
       const Data& Element() const noexcept ; // Immutable access to the element (concrete function should not throw exceptions)


      bool HasLeftChild() const noexcept ; // (concrete function should not throw exceptions)
      bool HasRightChild() const noexcept ; // (concrete function should not throw exceptions)

      NodeVec& LeftChild() const ; // (concrete function must throw std::out_of_range when not existent)
      NodeVec& RightChild() const ; // (concrete function must throw std::out_of_range when not existent)

  };

    Vector<NodeVec*> vecc;

public:

  // Default constructor
   BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
   BinaryTreeVec(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
   BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
   BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
   ~BinaryTreeVec() ;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec&) const noexcept;
  bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeVec& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
