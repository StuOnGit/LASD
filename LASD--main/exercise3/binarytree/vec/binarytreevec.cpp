
namespace lasd {

/* ************************************************************************** */
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{
        return element;
}

template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element()const noexcept{
    return element;
}


template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    if((index*2 + 2) >= veccPtr->Size()){
    return false;
    }else{
        return true;
    }
}
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    if((index*2 + 1) >= veccPtr->Size()){
        return false;
    }else{
        return true;
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(HasRightChild()) {
        return *((*veccPtr)[(index * 2) + 2]);
    }else{
        throw std::out_of_range("Out of range error");
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(HasLeftChild()) {
        return *((*veccPtr)[(index * 2) + 1]);
    }else{
        throw std::out_of_range("Out of range error");
    }
}


/* ************************************************************************** */
//Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {
    Clear();
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data> & linearContainer) {
    vecc.Resize(linearContainer.Size());
    for(unsigned int i = 0; i < linearContainer.Size(); ++i){
        vecc[i] = new NodeVec();
        vecc[i]->veccPtr = &vecc;
        vecc[i]->element = linearContainer[i];
        vecc[i]->index = i;
    }
    size = linearContainer.Size();
}

//Copy Constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec <Data>& binaryTreeVec) {
        vecc.Resize(binaryTreeVec.Size());
        for(unsigned int i = 0; i < binaryTreeVec.Size(); ++i){
            vecc[i] = new NodeVec();
            vecc[i]->veccPtr = &vecc;
            vecc[i]->element = binaryTreeVec.vecc[i]->element;
            vecc[i]->index = binaryTreeVec.vecc[i]->index;
        }
        size = binaryTreeVec.Size();
}
//Move Constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& binaryTreeVec)noexcept {
  std::swap(size, binaryTreeVec.size);
  std::swap(vecc, binaryTreeVec.vecc);
}

//Copy Assignment
template <typename Data>
BinaryTreeVec<Data> & BinaryTreeVec<Data>::operator=(const BinaryTreeVec <Data> & binaryTreeVec) {
        vecc.Resize(binaryTreeVec.Size());
        for(unsigned int i = 0; i < binaryTreeVec.Size(); ++i){
            vecc[i] = new NodeVec();
            vecc[i]->veccPtr = &vecc;
            vecc[i]->element = binaryTreeVec.vecc[i]->element;
            vecc[i]->index = binaryTreeVec.vecc[i]->index;
        }
        size = binaryTreeVec.Size();
        return *this;
}
//Move Assignment
template <typename Data>
BinaryTreeVec<Data> & BinaryTreeVec<Data>::operator=( BinaryTreeVec <Data> && binaryTreeVec) noexcept {
       std::swap(vecc, binaryTreeVec.vecc);
       std::swap(size, binaryTreeVec.size);
       return *this;
}
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec <Data> & binaryTreeVec) const noexcept {
     return BinaryTree<Data>::operator==(binaryTreeVec);
}
template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec <Data> & binaryTreeVec) const noexcept {
    return !(*this == binaryTreeVec);
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const {
    if(vecc.Size() > 0) {
        return *(vecc[0]);
    }else{
        throw std::length_error("Lenght error[vec]");
    }
}

template <typename Data>
void BinaryTreeVec<Data>::Clear() {
    for(unsigned int i = 0; i < vecc.Size(); ++i){
        delete vecc[i];
    }
    vecc.Clear();
    size = 0;
}
/* ************************************************************************** */

}
