
namespace lasd {

/* ************************************************************************** */
//Stack Obtained from a LinearContainer
template<typename Data>
StackLst<Data>::StackLst(LinearContainer<Data>& container) {
        for(int i = 0; i < container.Size(); ++i) {
            List<Data>::InsertAtBack(container[i]);
        }
}
//Copy Constructor
template<typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& stackLst) : List<Data>::List(stackLst) {}

//Move Constructor
template<typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& stackLst) noexcept :  List<Data>::List(std::move(stackLst)){}


template <typename Data>
void StackLst<Data>::Push(Data&& data) {
    List<Data>::InsertAtFront(std::move(data));
}

template <typename Data>
void StackLst<Data>::Push(const Data& data) {
    List<Data>::InsertAtFront(data);
}
template <typename Data>
Data& StackLst<Data>::Top() const {
   return List<Data>::Front();
}
template <typename Data>
void StackLst<Data>::Pop() {
    List<Data>::RemoveFromFront();
}

template<typename Data>
Data StackLst<Data>::TopNPop() {
    Data dat = Top();
    Pop();
    return dat;
}
template <typename Data>
void StackLst<Data>::Clear() {
    List<Data>::Clear();
}

template <typename Data>
bool StackLst<Data>::operator==(const StackLst <Data> & stackLst) const noexcept {
    return List<Data>::operator==(stackLst);
}

template <typename Data>
bool StackLst<Data>::operator!=(const StackLst <Data>& stackLst) const noexcept {
    return !(*this == stackLst);
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst <Data> & stackLst) {
  List<Data>::operator=(stackLst);
  return *this;
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst <Data> && stackLst) noexcept {
   List<Data>::operator=(std::move(stackLst));
   return *this;
}

/* ************************************************************************** */

}
