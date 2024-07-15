
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk: public virtual BinaryTree<Data>{ // Must extend BinaryTree<Data>

private:

  // ...

protected:

    using BinaryTree<Data>::size;

  // ...

struct NodeLnk: public virtual BinaryTree<Data>::Node{ // Must extend Node

  private:

    //...

  protected:


  public:

    Data element;
    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    ~NodeLnk();

    /* ********************************************************************** */

    // Specific member functions

    Data& Element() noexcept ; // Mutable access to the element (concrete function should not throw exceptions)
    const Data& Element() const noexcept ; // Immutable access to the element (concrete function should not throw exceptions)


    bool HasLeftChild() const noexcept ; // (concrete function should not throw exceptions)
    bool HasRightChild() const noexcept ; // (concrete function should not throw exceptions)

    NodeLnk& LeftChild() const ; // (concrete function must throw std::out_of_range when not existent)
    NodeLnk& RightChild() const ; // (concrete function must throw std::out_of_range when not existent)


};

    NodeLnk* root = nullptr;

    NodeLnk* AuxFunAssignment(NodeLnk& root);

    NodeLnk* AuxFunCopyLCont(NodeLnk *, unsigned int,const LinearContainer<Data>&);

public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
   BinaryTreeLnk(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
   BinaryTreeLnk(const BinaryTreeLnk<Data>&) ;

  // Move constructor
   BinaryTreeLnk(BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
   ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk& operator=(const BinaryTreeLnk<Data>&);

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk<Data>&) const noexcept;
  bool operator!=(const BinaryTreeLnk<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeLnk& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member


};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
