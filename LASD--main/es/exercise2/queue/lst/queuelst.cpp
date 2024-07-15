
#include "queuelst.hpp"

namespace lasd {

/* ************************************************************************** */
//Queue obtained by LinearContainer<Data>
template <typename Data>
QueueLst<Data>::QueueLst(LinearContainer<Data>& linearContainer) : List<Data>(linearContainer) {}

//Copy Constructor
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst& queueLst) : List<Data>(queueLst){}

//Move Constructor
template<typename Data>
QueueLst<Data>::QueueLst(QueueLst <Data> && queueLst) noexcept : List<Data>(std::move(queueLst)) {}

//Destructor
template <typename Data>
QueueLst<Data>::~QueueLst<Data>() {
    Clear();
}

template <typename Data>
void QueueLst<Data>::Enqueue(const Data & data) {
    List<Data>::InsertAtBack(data);
}

template <typename Data>
void QueueLst<Data>::Enqueue(Data && data) {
    List<Data>::InsertAtBack(std::move(data));
}

template<typename Data>
void QueueLst<Data>::Dequeue() {
    List<Data>::RemoveFromFront();
}

template<typename Data>
Data QueueLst<Data>::HeadNDequeue() {
    return List<Data>::FrontNRemove();
}

template <typename Data>
Data& QueueLst<Data>::Head(){
    return List<Data>::Front();
}

template<typename Data>
void QueueLst<Data>::Clear() {
    List<Data>::Clear();
}

template<typename Data>
bool QueueLst<Data>::operator!=(const QueueLst & queueLst) const noexcept {
    return !(*this == queueLst);
}

template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst & queueLst) const noexcept {
    return List<Data>::operator==(queueLst);
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst & queueLst){
    List<Data>::operator=(queueLst);
    return *this;
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst && queueLst) noexcept {
    List<Data>::operator=(std::move(queueLst));
    return *this;
}


/* ************************************************************************** */

}
