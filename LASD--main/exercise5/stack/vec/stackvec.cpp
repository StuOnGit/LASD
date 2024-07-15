#define costante 2

namespace lasd {

/* ************************************************************************** */

//Copy Constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stkVec) : Vector<Data>(stkVec) {
    testa = stkVec.Size();
}
//Constructor obtained by a Linear Container
template <typename Data>
StackVec<Data>::StackVec(LinearContainer<Data>& contain) : Vector<Data>::Vector(contain) {
    if (contain.Size() == 0) Vector<Data>::Resize(1);
    testa = contain.Size();
}

//Move Constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stackVec) noexcept {
        std::swap(Elements, stackVec.Elements);
        std::swap(size, stackVec.size);
        std::swap(testa, stackVec.testa);
}

//Constructor
template <typename Data>
StackVec<Data>::StackVec() {
    Vector<Data>::Resize(1);
}

template <typename Data>
bool inline StackVec<Data>::Empty() const noexcept {
    if (Size() == 0){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
void StackVec<Data>::Clear() {
    Vector<Data>::Clear();
    Vector<Data>::Resize(1);
    testa = 0;
}
template <typename Data>
unsigned long StackVec<Data>::Size() const noexcept {
    return testa;
}

template <typename Data>
void StackVec<Data>::Push(const Data& dat) {
    if (testa >= size-1){
        Vector<Data>::Resize(costante*size);
    }
    Elements[testa] = dat;
    ++testa;
}

template <typename Data>
void StackVec<Data>::Pop() {
    if(Empty() == true){
        throw std::length_error("Stack is Empty!");
    }else{
        if(testa <= (size/(4)) && size/costante > 1 && size/costante > Size()){
            Vector<Data>::Resize(size/2);
        }
        --testa;
    }
}

template <typename Data>
Data& StackVec<Data>::Top() const {
    if(Empty() == true){
        throw std::length_error("Stack is Empty!");
    }else{
        return Elements[testa -1];
    }
}

template <typename Data>
Data StackVec<Data>::TopNPop() {
    Data tmp = Top();
    Pop();
    return tmp;
}

template <typename Data>
void StackVec<Data>::Push(Data&& dat) {
    if (testa >= size-1){
        Vector<Data>::Resize(costante*size);
    }
    Elements[testa] = std::move(dat);
    ++testa;
}
template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stackVec) const noexcept {
    if(Size() == stackVec.Size()){
        for(int i = 0; i < Size(); ++i){
            if(Elements[i] != stackVec[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& stackVec) const noexcept {
    return !(*this == stackVec);
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stackVec) {
  Vector<Data>::operator=(stackVec);
  testa = stackVec.Size();
    return *this;
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec <Data> && stackVec) noexcept {
    std::swap(Elements, stackVec.Elements);
    std::swap(size, stackVec.size);
    std::swap(testa, stackVec.testa);
    return *this;
}
/* ************************************************************************** */

}
