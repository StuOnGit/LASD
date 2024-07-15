
namespace lasd {

/* ************************************************************************** */
//Copy of the value
template <typename Data>
void BST<Data>::Insert(const Data& dato){
    NodeLnk*& pointer = FindPointerTo(root, dato);
    if(pointer == nullptr){
        pointer = new NodeLnk();
        pointer->element = dato;
        ++size;
    }
}
//Move of the value
template <typename Data>
void BST<Data>::Insert(Data&& dato) noexcept{
        NodeLnk*& pointer = FindPointerTo(root, dato);
        if(pointer == nullptr){
            (pointer) = new NodeLnk();
            (pointer)->Element() = std::move(dato);
            ++size;
        }
}

template <typename Data>
void BST<Data>::Remove(const Data & dato) {
    delete Detach(FindPointerTo(root, dato));
}
//Constructor obtained by a linearContainer
template <typename Data>
BST<Data>::BST(const LinearContainer<Data>& linearContainer){
    int i = 0;
    int linSize = linearContainer.Size();
    while(i < linSize){
        Insert(linearContainer[i]);
        ++i;
    }
}
//Copy Constructor
template <typename Data>
BST<Data>::BST(const BST& bst) : BinaryTreeLnk<Data>(bst){}
//Move Constructor
template <typename Data>
BST<Data>::BST(BST&& bst) noexcept : BinaryTreeLnk<Data> (std::move(bst)) {};

template <typename Data>
const Data & BST<Data>::Min() const {
    if (root != nullptr){
        return FindPointerToMin(root)->Element();
    }else{
        throw std::length_error("Access to an empty tree");
    }
}

template <typename Data>
Data BST<Data>::MinNRemove() {
    if(root != nullptr){
        return DataNDelete(DetachMin(root));
    }else{
        throw std::length_error("Access to an empty tree");
    }
}

template <typename Data>
void BST<Data>::RemoveMin() {
    if(root != nullptr){
        delete DetachMin(root);
    }else{
        throw std::length_error("Access to an empty tree");
    }
}

template <typename Data>
const Data & BST<Data>::Max() const {
    if (root != nullptr){
        return FindPointerToMax(root)->Element();
    }else{
        throw std::length_error("Access to an empty tree");
    }
}

template <typename Data>
Data BST<Data>::MaxNRemove() {
    if(root != nullptr){
        return DataNDelete(DetachMax(root));
    }else{
        throw std::length_error("Access to an empty tree");
    }
}

template <typename Data>
void BST<Data>::RemoveMax() {
    if(root != nullptr){
        delete DetachMax(root);
    }else{
        throw std::length_error("Access to an empty tree");
    }
}
template <typename Data>
const Data& BST<Data>::Predecessor(const Data & dato) const {
    NodeLnk* const& pointer = FindPointerToPredecessor(root, dato);
    if(pointer != nullptr){
        return (pointer)->Element();
    }else{
        throw std::length_error("There's not predecessor");
    }
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data & dato) {
    NodeLnk*& pointer = FindPointerToPredecessor(root, dato);
    if(pointer != nullptr){
        return DataNDelete(Detach(pointer));
    }else{
        throw std::length_error("There's not predecessor");
    }
}

template <typename Data>
void BST<Data>::RemovePredecessor(const Data & dato) {
    NodeLnk*& pointer = FindPointerToPredecessor(root, dato);
    if(pointer != nullptr){
        delete Detach(pointer);
    }else{
        throw std::length_error("There's not predecessor");
    }
}

template <typename Data>
const Data & BST<Data>::Successor(const Data & dato) const {
    NodeLnk* const& pointer = FindPointerToSuccessor(root, dato);
    if(pointer != nullptr){
        return (pointer)->element;
    }else{
        throw std::length_error("There's not successor");
    }
}
template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data & dato) {
    NodeLnk*& pointer = FindPointerToSuccessor(root, dato);
    if(root != nullptr){
        return DataNDelete(Detach(pointer));
    }else{
        throw std::length_error("There's not successor");
    }
}

template<typename Data>
void BST<Data>::RemoveSuccessor(const Data & dato) {
    NodeLnk*& pointer = FindPointerToSuccessor(root, dato);
    if(pointer != nullptr){
        delete Detach(pointer);
    }else{
        throw std::length_error("There's not successor");
    }
}
template <typename Data>
bool BST<Data>::Exists(const Data & dato) const noexcept {
    return (FindPointerTo(root, dato) != nullptr);
}
/* ******************************** PROTECTED ****************************************** */
template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* nodeLnk) {
    Data dato;
    std::swap(dato, nodeLnk->element);
    delete nodeLnk;
    return dato;
}

template <typename Data>
typename BST<Data>::NodeLnk * BST<Data>::Detach(NodeLnk *& nodeLnk) noexcept{
    if(nodeLnk != nullptr){
        if(nodeLnk->left == nullptr){
            return SkipOnRight(nodeLnk);
        }else if(nodeLnk->right == nullptr){
            return SkipOnLeft(nodeLnk);
        }else{
            NodeLnk* nodeLnkMax = DetachMax(nodeLnk->left);
            std::swap(nodeLnk->element, nodeLnkMax->element);
            return nodeLnkMax;
        }
    }else{
        return nullptr;
    }
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk *& nodeLnk) noexcept{
    return SkipOnRight(FindPointerToMin(nodeLnk));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk *& nodeLnk) noexcept{
    return SkipOnLeft(FindPointerToMax(nodeLnk));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnRight(NodeLnk *& nodeLnk) {
    NodeLnk* nodeRight = nullptr;
    if(nodeLnk != nullptr){
        std::swap(nodeRight, nodeLnk->right);
        std::swap(nodeRight, nodeLnk);
        size--;
    }
    return nodeRight;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnLeft(NodeLnk *& nodeLnk) {
    NodeLnk* nodeLeft = nullptr;
    if(nodeLnk != nullptr){
        std::swap(nodeLeft, nodeLnk->left);
        std::swap(nodeLeft, nodeLnk);
        size--;
    }
    return nodeLeft;
}
/* **************************************** FIND POINTER **************************************/

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk *& nodeLnk, const Data& dato) {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerTo(nodeLnk, dato));
}
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(NodeLnk *& nodeLnk, const Data& dato) {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(nodeLnk, dato));
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(NodeLnk *& nodeLnk, const Data& dato) {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(nodeLnk, dato));
}
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& nodeLnk) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(nodeLnk));
}
template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& nodeLnk) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(nodeLnk));
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(NodeLnk * const& nodeLnk, const Data & dato) const noexcept{
    if (nodeLnk != nullptr){
        if(dato != nodeLnk->element){
            if(dato < nodeLnk->element){
                return FindPointerTo(nodeLnk->left, dato);
            }else{
                return FindPointerTo(nodeLnk->right, dato);
            }
        }
    }
    return nodeLnk;
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(NodeLnk *const & nodeLnk, const Data & dato) const noexcept {
    if(nodeLnk != nullptr){
        if(nodeLnk->element == dato){
            return FindPointerToMax(nodeLnk->left);
        }else if(nodeLnk->element > dato){
            return FindPointerToPredecessor(nodeLnk->left, dato);
        }else{
            NodeLnk* const& pre = FindPointerToPredecessor(nodeLnk->right, dato);
            if(pre != nullptr){
                return pre;
            }
        }
    }
    return nodeLnk;
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk *const & nodeLnk, const Data & dato) const noexcept {
    if(nodeLnk != nullptr){
        if(nodeLnk->element == dato){
            return FindPointerToMin(nodeLnk->right);
        }else if(nodeLnk->element < dato){
            return FindPointerToSuccessor(nodeLnk->right, dato);
        }else{
            NodeLnk* const& succ = FindPointerToSuccessor(nodeLnk->left, dato);
            if(succ != nullptr){
                return succ;
            }
        }
    }
    return nodeLnk;
}


template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk * const&  nodeLnk) const noexcept{
    NodeLnk* const* pointer = &nodeLnk;
    NodeLnk* current = nodeLnk;
    if(current != nullptr){
        while(current->left != nullptr){
            pointer = &current->left;
            current = current->left;
        }
    }
    return *pointer;
}



template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk * const&  nodeLnk) const noexcept{
    NodeLnk* const* pointer = &nodeLnk;
    NodeLnk* current = nodeLnk;
    if(current != nullptr){
        while(current->right != nullptr){
            pointer = &current->right;
            current = current->right;
        }
    }
    return *pointer;
}

/* ************************************************************************************* */


//Copy Assignment
template <typename Data>
BST<Data> & BST<Data>::operator=(const BST <Data> & bst) {
    BinaryTreeLnk<Data>::operator=(bst);
    return *this;
}
//Move Assignment
template <typename Data>
BST<Data> & BST<Data>::operator=(BST <Data> && bst) noexcept {
    BinaryTreeLnk<Data>::operator=(std::move(bst));
    return *this;
}

template <typename Data>
bool BST<Data>::operator==(const BST <Data> & bst) const noexcept {
    if(size == bst.Size()){
        BTInOrderIterator<Data> btInOrderIterator0(*this);
        BTInOrderIterator<Data> btInOrderIterator1(bst);
        while(!btInOrderIterator0.Terminated()){
            if(*btInOrderIterator0 != *btInOrderIterator1){
                return false;
            }else{
                ++btInOrderIterator0;
                ++btInOrderIterator1;
            }
        }
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool BST<Data>::operator!=(const BST <Data> & bst) const noexcept {
    return !(*this == bst);
}


/* ************************************************************************** */

}
