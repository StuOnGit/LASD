#include "list.hpp"

namespace lasd {

/* ************************************************************************** */
//Costruttore obtained by linearContainer
template<typename Data>
List<Data>::List(const LinearContainer<Data>& lCon){
    unsigned long index = 0;
    while(index < lCon.Size()){
        InsertAtBack(lCon[index]);
        ++index;
    }
}

//Move constructor
template<typename Data>
List<Data>::List(List <Data> &&l) noexcept {
    std::swap(head, l.head);
    std::swap(size, l.size);
}
//Copy Constructor
template<typename Data>
List<Data>::List(const List<Data>& l){
    Node* tmp = l.head;
    while(tmp != nullptr){
        InsertAtBack(tmp->dato);
        tmp = tmp->next;
    }
}

//Destructor
template<typename Data>
List<Data>::~List(){
   Clear();
}
template<typename Data>
void List<Data>::InsertAtBack(Data&& dat) noexcept{
    Node* tmp = head;
    Node* new_node = new Node();
    ++size;
    if(tmp == nullptr){
        head = new_node;
        new_node->dato = std::move(dat);
        new_node->next = nullptr;
    }else {
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
        new_node->dato = std::move(dat);
        new_node->next = nullptr;
    }

}

template<typename Data>
void List<Data>::InsertAtFront(Data&& dat) noexcept{
    Node* new_node = new Node();
    new_node->dato = std::move(dat);
    new_node->next = head;
    head = new_node;
    ++size;
}

template<typename Data>
void List<Data>::InsertAtFront(const Data& val){
    Node* new_node = new Node();
    new_node->dato = val;
    new_node->next = head;
    head = new_node;
    ++size;
}

template<typename Data>
Data& List<Data>::Back() const{
    if (head == nullptr){
        throw std::length_error("Access to an Empty List (back)");
    }else{
        Node* tmp = head;
        while(tmp->next != nullptr){
                tmp = tmp->next;
        }
        return tmp->dato;
    }
}


template<typename Data>
Data& List<Data>::Front() const{
    if (head == nullptr){
        throw std::length_error("Access to an Empty List (front)");
    }else{
        return head->dato;
    }
}
template<typename Data>
void List<Data>::Clear(){
    while(head != nullptr){
        RemoveFromFront();
    }
}
template<typename Data>
void List<Data>::RemoveFromFront() {
    if(head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        --size;
    }else{
        throw std::length_error("Access to an Empty List (rmvFromfront)");
    }
}

template<typename Data>
Data List<Data>::FrontNRemove() {
    if(head != nullptr) {
        Data value = std::move(head->dato);
        Node* tmp = head;
        head = head->next;
        delete tmp;
        --size;
        return value;
    }else{
        throw std::length_error("Access to an Empty List(frntRmv)");
    }
}
template<typename Data>
Data& List<Data>::operator[](const unsigned long siz) const{
    unsigned long index = 0;
    Node* tmp = head;
    if(siz >= size){
        throw std::out_of_range("Out of range access");
    }else{
        while(index != siz){
            tmp = tmp->next;
            ++index;
        }
        return tmp->dato;
    }
}


template<typename Data>
List<Data>& List<Data>::operator=(const List <Data>& l) {
    Clear();
    Node* tmp = l.head;
    while(tmp != nullptr){
        InsertAtBack(tmp->dato);
        tmp = tmp->next;
    }
    return *this;
}

template<typename Data>
List<Data>& List<Data>::operator=(List <Data>&& lst) noexcept {
    std::swap(head, lst.head);
    std::swap(size, lst.size);
    return *this;
}


template<typename Data>
bool List<Data>::operator==(const List& lst) const noexcept{
    Node* tmp1 = head;
    Node* tmp2 = lst.head;
    if(size == lst.Size()) {
        while (tmp1 != nullptr && tmp2 != nullptr) {
            if (tmp1->dato != tmp2->dato) {
                return false;
            } else {
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
        }
        if (tmp1 == nullptr && tmp2 == nullptr) {
            return true;
        } else {
            return false;
        }
    }else{
        return false;
    }
}


template<typename Data>
bool List<Data>::operator!=(const List& lst) const noexcept{
    return !(*this == lst);
}


template<typename Data>
void List<Data>::InsertAtBack(const Data& val) {
    Node* current = head;
    Node* new_node = new Node();
    if(current == nullptr){
        head = new_node;
        new_node->dato = val;
        new_node->next = nullptr;
    }else {
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
        new_node->dato = val;
        new_node->next = nullptr;
    }
    ++size;
}


// Funzione di map pre-order
    template<typename Data>
    void List<Data>::MapPreOrder(const MapFunctor map, void* support){
        Node *tmp = head;
        while(tmp != nullptr){
            map(tmp->dato, support);
            tmp = tmp->next;
        }
    }

// Funzione di map post-order
    template<typename Data>
    void List<Data>::MapPostOrder(const MapFunctor map, void* support){
        for(int i = size; i > 0; i--){
            map((*this)[i - 1], support);
        }
    }

// Funzione di fold pre-order
    template<typename Data>
    void List<Data>::FoldPreOrder(const FoldFunctor fold, const void* accum, void* support) const{
        Node *tmp = head;
        while(tmp != nullptr){
            fold(tmp->dato, accum, support);
            tmp = tmp->next;
        }
    }

// Funzione di fold post-order
    template<typename Data>
    void List<Data>::FoldPostOrder(const FoldFunctor fold, const void* accum, void* support) const{
        for(unsigned long i = size; i > 0; i--){
            fold((*this)[i - 1], accum, support);
        }
    }
/* ************************************************************************** */

}
