
#include "binarytree.hpp"

namespace lasd {

/********************************* Node ****************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{
        bool areEqual = true;
        if (Element() != node.Element()) {
            areEqual = false;
        } else {
            if ((!HasLeftChild() && node.HasLeftChild()) || (HasLeftChild() && !node.HasLeftChild())) {
                areEqual = false;
            } else {
                if (HasLeftChild() && node.HasLeftChild()) {
                    areEqual = (LeftChild() == node.LeftChild());
                }
            }
            if (areEqual) {
                if ((!HasRightChild() && node.HasRightChild()) || (HasRightChild() && !node.HasRightChild())) {
                    areEqual = false;
                } else {
                    if (HasRightChild() && node.HasRightChild()) {
                        areEqual = (RightChild() == node.RightChild());
                    }
                }
            }
        }
        return areEqual;
}

template<typename Data>
bool BinaryTree<Data>::Node::operator!=(const BinaryTree::Node& node) const noexcept {
    return !(*this == node);
}

template<typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept {
    return !(HasRightChild() || HasLeftChild());
}


/*********************************  Binary Tree  ****************************************** */
template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& binaryTree) const noexcept {
    if(size != 0 && binaryTree.Size() != 0) {
        return Root() == binaryTree.Root();
    }else if(size == 0 && binaryTree.Size() == 0){
        return true;
    }else{
        return false;
    }
}


template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& binaryTree) const noexcept {
    return !(*this == binaryTree);
}


template <typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor map, void * support) {
        if(!(this->Empty()))
            MapPreOrderAux(map, support, Root());
}
template <typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor map, void *support) {
    if(!(this->Empty()))
        MapPostOrderAux(map, support, Root());
}
template <typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor map, void *support) {
    if(!(this->Empty()))
        MapInOrderAux(map, support, Root());
}
template <typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor map, void *support) {
    if(!(this->Empty()))
        MapBreadthAux(map, support, Root());
}
template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fold, const void *acc, void *support) const {
    if(!this->Empty())
        FoldPreOrderAux(fold, acc, support, Root());
}
template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fold, const void *acc, void *support) const {
    if(!(this->Empty()))
        FoldPostOrderAux(fold, acc, support, Root());
}
template <typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fold, const void * acc, void * support) const {
    if(!(this->Empty()))
        FoldBreadthAux(fold, acc, support, Root());
}
template <typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fold, const void * acc, void * support) const {
    if(!(this->Empty()))
        FoldInOrderAux(fold, acc, support, Root());
}

//PROTECTED
template <typename Data>
void BinaryTree<Data>::MapPreOrderAux(const MapFunctor map, void * support, Node& node) {

        map(node.Element(), support);
        if (node.HasLeftChild()) {
            MapPreOrderAux(map, support,node.LeftChild());
        }
        if (node.HasRightChild()) {
            MapPreOrderAux(map, support, node.RightChild());
        }

}
template <typename Data>
void BinaryTree<Data>::MapPostOrderAux(const MapFunctor map, void * support, Node& node) {

        if (node.HasLeftChild()) {
            MapPostOrderAux(map, support, node.LeftChild());
        }
        if (node.HasRightChild()) {
            MapPostOrderAux(map, support, node.RightChild());
        }
        map(node.Element(), support);

}
template <typename Data>
void BinaryTree<Data>::MapInOrderAux(const MapFunctor map, void * support, Node& node) {

    if (node.HasLeftChild()) {
        MapInOrderAux(map, support, node.LeftChild());
    }
    map(node.Element(), support);
    if (node.HasRightChild()) {
        MapInOrderAux(map, support, node.RightChild());
    }

}
template <typename Data>
void BinaryTree<Data>::MapBreadthAux(const MapFunctor map, void * support, Node& node) {

    map(node.Element(), support);
    QueueLst<Node*> queueLst;
    if (node.HasLeftChild()) {
        queueLst.Enqueue(&node.LeftChild());
    }
    if (node.HasRightChild()) {
        queueLst.Enqueue(&node.RightChild());
    }
    Node* tmp;
    while (!queueLst.Empty()) {
        tmp = queueLst.HeadNDequeue();
        if (tmp->HasLeftChild()) {
            queueLst.Enqueue(&tmp->LeftChild());
        }
        if (tmp->HasRightChild()) {
            queueLst.Enqueue(&tmp->RightChild());
        }
        map(tmp->Element(), support);
    }

}
template <typename Data>
void BinaryTree<Data>::FoldPreOrderAux(const FoldFunctor fold, const void * acc, void * support, Node& node) const {

        fold(node.Element(), acc, support);
        if (node.HasLeftChild()) {
            FoldPreOrderAux(fold, acc, support, node.LeftChild());
        }
        if (node.HasRightChild()) {
            FoldPreOrderAux(fold, acc, support, node.RightChild());
        }

}
template <typename Data>
void BinaryTree<Data>::FoldPostOrderAux(const FoldFunctor fold, const void * acc, void * support, Node& node) const {

        if (node.HasLeftChild()) {
            FoldPostOrderAux(fold, acc, support, node.LeftChild());
        }
        if (node.HasRightChild()) {
            FoldPostOrderAux(fold, acc, support, node.RightChild());
        }
        fold(node.Element(), acc, support);

}
template <typename Data>
void BinaryTree<Data>::FoldBreadthAux(const FoldFunctor fold, const void * acc, void * support, Node& node) const {

        fold(node.Element(), acc, support);
        QueueLst<Node*> queueLst;
        if (node.HasLeftChild()) {
            queueLst.Enqueue(&node.LeftChild());
        }
        if (node.HasRightChild()) {
            queueLst.Enqueue(&node.RightChild());
        }
        Node* tmp;
        while (!queueLst.Empty()) {
            tmp = queueLst.HeadNDequeue();
            if (tmp->HasLeftChild()) {
                queueLst.Enqueue(&tmp->LeftChild());
            }
            if (tmp->HasRightChild()) {
                queueLst.Enqueue(&tmp->RightChild());
            }
            fold(tmp->Element(), acc, support);
        }

}
template <typename Data>
void BinaryTree<Data>::FoldInOrderAux(const FoldFunctor fold, const void * acc, void * support, Node& node) const {

        if (node.HasLeftChild()) {
            FoldInOrderAux(fold, acc, support, node.LeftChild());
        }
        fold(node.Element(), acc, support);
        if (node.HasRightChild()) {
            FoldInOrderAux(fold, acc, support, node.RightChild());
        }

}
/*********************************      BTPreOrderIterator     ****************************************** */
//Specific Constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree <Data>& binaryTree) {

        if (!binaryTree.Empty()) {
            iterator = &binaryTree.Root();
            if (iterator->HasRightChild()) {
                stackLst.Push(&iterator->RightChild());
            }
            if (iterator->HasLeftChild()) {
                stackLst.Push(&iterator->LeftChild());
            }
        }
}
//Copy Constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator <Data> & btPreOrderIterator) {
    iterator = btPreOrderIterator.iterator;
    stackLst = btPreOrderIterator.stackLst;
}
//Move Constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator <Data> && btPreOrderIterator) noexcept {
        iterator = std::move(btPreOrderIterator.iterator);
        stackLst = std::move(btPreOrderIterator.stackLst);
}
template <typename Data>
BTPreOrderIterator<Data> & BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator <Data>& btPreOrderIterator) {
    iterator = btPreOrderIterator.iterator;
    stackLst = btPreOrderIterator.stackLst;
    return *this;
}
template <typename Data>
BTPreOrderIterator<Data> & BTPreOrderIterator<Data>::operator=(BTPreOrderIterator <Data>&& btPreOrderIterator) noexcept {
    iterator = std::move(btPreOrderIterator.iterator);
    stackLst = std::move(btPreOrderIterator.stackLst);
    return *this;
}
template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator <Data>& btPreOrderIterator) const noexcept {
    if(btPreOrderIterator.iterator == iterator && btPreOrderIterator.stackLst == stackLst){
        return true;
    }else{
        return false;
    }
}
template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator <Data>& btPreOrderIterator) const noexcept {
    return !(*this == btPreOrderIterator);
}
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if(!Terminated()) {
        if (!stackLst.Empty()){
            iterator = stackLst.TopNPop();
            if (iterator->HasRightChild()) {
                stackLst.Push(&iterator->RightChild());
            }
            if (iterator->HasLeftChild()) {
                stackLst.Push(&iterator->LeftChild());
            }
        }else{
            iterator = nullptr;
        }
    }else{
        throw std::out_of_range("Out of range error");
    }
    return *this;
}
template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() const {
    if(Terminated()){
        throw std::out_of_range("Out of range access");
    }else {
        return iterator->Element();
    }
}
template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return iterator == nullptr && stackLst.Empty();
}

/******************************** BTPostOrderIterator ******************************************* */
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& binaryTree) {
    if(!binaryTree.Empty()){
        iterator = &binaryTree.Root();
        while(!iterator->IsLeaf()){
           stackLst.Push(iterator);
           if(iterator->HasLeftChild()){
               iterator = &iterator->LeftChild();
           }else{
               iterator = &iterator->RightChild();
           }
       }
    }
}
//Copy Constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& btPostOrderIterator) {
        iterator = btPostOrderIterator.iterator;
        stackLst = btPostOrderIterator.stackLst;
}
//Move Constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& btPostOrderIterator ) noexcept {
        iterator = std::move(btPostOrderIterator.iterator);
        stackLst = std::move(btPostOrderIterator.stackLst);
}
template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& btPostOrderIterator) const noexcept {
    if(btPostOrderIterator.iterator == iterator && btPostOrderIterator.stackLst == stackLst){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& btPostOrderIterator) const noexcept {
    return !(*this == btPostOrderIterator);
}
template <typename Data>
BTPostOrderIterator<Data> & BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data> & btPostOrderIterator) {
    iterator = btPostOrderIterator.iterator;
    stackLst = btPostOrderIterator.stackLst;
    return *this;
}

template <typename Data>
BTPostOrderIterator<Data> & BTPostOrderIterator<Data>::operator=( BTPostOrderIterator<Data> && btPostOrderIterator) noexcept{
    iterator = std::move(btPostOrderIterator.iterator);
    stackLst = std::move(btPostOrderIterator.stackLst);
    return *this;
}
template <typename Data>
Data & BTPostOrderIterator<Data>::operator*() const {
    if(Terminated()){
        throw std::out_of_range("Out of range access");
    }else {
        return iterator->Element();
    }
}
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if(!Terminated()){
        if(!stackLst.Empty()) {
            if(stackLst.Top()->HasRightChild()){
                if(iterator != &stackLst.Top()->RightChild()) {
                    iterator = &stackLst.Top()->RightChild();
                    while (!iterator->IsLeaf()) {
                        stackLst.Push(iterator);
                        if(iterator->HasLeftChild()) {
                            iterator = &iterator->LeftChild();
                        }else{
                            iterator = &iterator->RightChild();
                        }
                    }
                }else{
                    iterator = stackLst.TopNPop();
                }
            }else{
                iterator = stackLst.TopNPop();
            }
        }else{
            iterator = nullptr;
        }
        return *this;
    }else{
        throw std::out_of_range("Out of range error");
    }
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return iterator == nullptr && stackLst.Empty();
}
/******************************** BTInOrderIterator ******************************************* */
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& binaryTree) {
    iterator = &binaryTree.Root();
    while(iterator->HasLeftChild()){
        stackLst.Push(iterator);
        iterator = &iterator->LeftChild();
    }
}
//Copy Constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& btInOrderIterator) {
        iterator = btInOrderIterator.iterator;
        stackLst = btInOrderIterator.stackLst;
}
//Move Constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& btInOrderIterator) noexcept {
        iterator = std::move(btInOrderIterator.iterator);
        stackLst = std::move(btInOrderIterator.stackLst);
}
template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data> & btInOrderIterator) const noexcept {
    if(btInOrderIterator.iterator == iterator && btInOrderIterator.stackLst == stackLst){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data> & btInOrderIterator) const noexcept {
    return !(*this == btInOrderIterator);
}
template <typename Data>
BTInOrderIterator<Data> & BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data> & btInOrderIterator) {
    iterator = btInOrderIterator.iterator;
    stackLst = btInOrderIterator.stackLst;
    return *this;
}

template <typename Data>
BTInOrderIterator<Data> & BTInOrderIterator<Data>::operator=( BTInOrderIterator<Data> && btInOrderIterator) noexcept{
    iterator = std::move(btInOrderIterator.iterator);
    stackLst = std::move(btInOrderIterator.stackLst);
    return *this;
}
template <typename Data>
Data & BTInOrderIterator<Data>::operator*() const {
    if(Terminated()){
        throw std::out_of_range("Out of range access");
    }else {
        return iterator->Element();
    }
}
template <typename Data>
BTInOrderIterator<Data> & BTInOrderIterator<Data>::operator++() {
    if(!Terminated()){
        if(iterator->IsLeaf()){
            if(!stackLst.Empty()) {
                iterator = stackLst.TopNPop();
            }else{
                iterator = nullptr;
            }
        }else{
        if(iterator->HasRightChild()){
            iterator = &iterator->RightChild();
                while(iterator->HasLeftChild()){
                    stackLst.Push(iterator);
                    iterator = &iterator->LeftChild();
                }
            }else{
            if(!stackLst.Empty()) {
                iterator = stackLst.TopNPop();
            }else{
                iterator = nullptr;
            }
        }
        }
    }else{
        throw std::out_of_range("Out of range error");
    }
    return *this;
}
template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
       return iterator == nullptr && stackLst.Empty();
}

/******************************** BTBreadthIterator ******************************************* */

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& binaryTree) {
    if(!binaryTree.Empty()){
        iterator = &binaryTree.Root();
    }
}
//Copy Constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& btBreadthIterator) {
    iterator = btBreadthIterator.iterator;
    queueLst = btBreadthIterator.queueLst;
}
//Move Constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& btBreadthIterator) noexcept {
        iterator = std::move(btBreadthIterator.iterator);
        queueLst = std::move(btBreadthIterator.stackLst);
}
template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data> & btBreadthIterator) const noexcept {
        if(iterator == btBreadthIterator.iterator && queueLst == btBreadthIterator.queueLst){
            return true;
        }else{
            return false;
        }
}

template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& btBreadthIterator) const noexcept {
    return !(*this == btBreadthIterator);
}
template <typename Data>
BTBreadthIterator<Data> & BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data> & btBreadthIterator) {
    iterator = btBreadthIterator.iterator;
    queueLst = btBreadthIterator.queueLst;
    return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data> && btBreadthIterator) noexcept{
    iterator = std::move(btBreadthIterator.iterator);
    queueLst = std::move(btBreadthIterator.stackLst);
    return *this;
}
template <typename Data>
Data & BTBreadthIterator<Data>::operator*() const {
    if(Terminated()){
        throw std::out_of_range("Out of range access");
    }else {
        return iterator->Element();
    }
}
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if(iterator->HasLeftChild()){
        queueLst.Enqueue(&iterator->LeftChild());
    }
    if(iterator->HasRightChild()){
        queueLst.Enqueue(&iterator->RightChild());
    }
    if(!queueLst.Empty()) {
        iterator = queueLst.HeadNDequeue();
    }else{
        iterator = nullptr;
    }
    return *this;
}
template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return iterator == nullptr && queueLst.Empty();
}

}
