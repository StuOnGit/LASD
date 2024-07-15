
namespace lasd {

/* ************************************************************************** */
//Distruttore
template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    if(left != nullptr) {
        delete left;
    }
    if(right != nullptr) {
        delete right;
    }
}

template <typename Data>
Data & BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
        return element;
}

template <typename Data>
const Data & BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
        return element;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    if(right != nullptr){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    if(left != nullptr){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if(HasLeftChild() == true){
        return *left;
    }else{
        throw std::out_of_range("Out of range error");
    }
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if(HasRightChild() == true){
        return *right;
    }else{
        throw std::out_of_range("Out of range error");
    }
}


/* ************************************************************************** */
//Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk<Data>() {
        Clear();
}
//Specific Constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& linearContainer) {
        root = AuxFunCopyLCont(root, 0, linearContainer);
        size = linearContainer.Size();
}
//Copy Constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& binaryTreeLnk) {
        if(binaryTreeLnk.size > 0){
            root = AuxFunAssignment(binaryTreeLnk.Root());
            size = binaryTreeLnk.size;
        }
}

//Move constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& binaryTreeLnk) noexcept {
    std::swap(root, binaryTreeLnk.root);
    std::swap(size, binaryTreeLnk.size);
}


template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    if(size != 0) {
        delete root;
        root = nullptr;
        size = 0;
    }
}

//Copy Assignment
template <typename Data>
BinaryTreeLnk<Data> & BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk <Data>& binaryTreeLnk) {
        Clear();
        root = AuxFunAssignment(binaryTreeLnk.Root());
        size = binaryTreeLnk.size;
        return *this;
}
//Move Assignment
template <typename Data>
BinaryTreeLnk<Data> & BinaryTreeLnk<Data>::operator=( BinaryTreeLnk <Data>&& binaryTreeLnk) noexcept{
    std::swap(root, binaryTreeLnk.root);
    std::swap(size, binaryTreeLnk.size);
    return *this;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::Root() const {
    if(root != nullptr) {
        return *root;
    }else{
        throw std::length_error("Length error");
    }
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk <Data>& binaryTreeLnk) const noexcept {
    return BinaryTree<Data>::operator==(binaryTreeLnk);
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk <Data>& binaryTreeLnk) const noexcept {
    return !(*this == binaryTreeLnk);
}


//AUX FUNCTIONS
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::AuxFunCopyLCont(NodeLnk* node, unsigned int index,const LinearContainer<Data>& linearContainer) {
    if (index < linearContainer.Size()){
        node = new NodeLnk();
        node->element = linearContainer[index];
        node -> left =  AuxFunCopyLCont(node->left, (index*2)+1, linearContainer);
        node -> right = AuxFunCopyLCont(node->right, (index*2)+2, linearContainer);
    }
        return node;
}
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::AuxFunAssignment(NodeLnk& root){
    NodeLnk *tmp = new NodeLnk();
    tmp->element = root.Element();
    if(root.HasLeftChild()){
        tmp->left = AuxFunAssignment(root.LeftChild());
    }
    if(root.HasRightChild()) {
        tmp->right = AuxFunAssignment(root.RightChild());
    }
    return tmp;
}
/* ************************************************************************** */

}
