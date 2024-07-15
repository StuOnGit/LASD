
namespace lasd {

/* ************************************************************************** */
bool Container::Empty() const noexcept{
    return size == 0;
}

unsigned long Container::Size() const noexcept{
    return size;
}

template <typename Data>
void AuxFoldExists(const Data& dat, const void* val, void* exists){
    if (dat == *((Data*) val)){
        *((bool*) exists) = true;
    }
}

template <typename Data>
bool FoldableContainer<Data>::Exists(const Data& dat) const noexcept{
    bool exists = false;
    FoldPreOrder(&AuxFoldExists<Data>, &dat, &exists);
    return exists;
}

// ...

/* ************************************************************************** */

}
