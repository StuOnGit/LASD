
namespace lasd {

/* ************************************************************************** */
template<typename Data>
Vector<Data>::Vector(const unsigned long newSize){
    Elements = new Data[newSize] {};
    size = newSize;
}
// ...
template<typename Data>
Vector<Data>::Vector(const LinearContainer<Data>& contain){
    size = contain.Size();
    Elements = new Data[size];
    for(unsigned long i = 0; i < size; ++i){
        Elements[i] = contain[i];
    }
}

//Copy Constructor
template<typename Data>
Vector<Data>::Vector(const Vector<Data>& vett){
    Elements = new Data[vett.size];
    std::copy(vett.Elements, vett.Elements + vett.size, Elements);
    size = vett.size;
}

//Move Constructor
template<typename Data>
Vector<Data>::Vector(Vector<Data>&& vett) noexcept {
    std::swap(Elements, vett.Elements);
    std::swap(size, vett.size);
}

//Destructor
template<typename Data>
Vector<Data>::~Vector(){
    delete[] Elements;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vett){
    Vector<Data>* tmpVett = new Vector<Data>(vett);
    std::swap(*tmpVett, *this);
    delete tmpVett;
    return *this;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vett) noexcept {
    std::swap(Elements, vett.Elements);
    std::swap(size, vett.size);
    return *this;
}

template<typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vett) const noexcept{
    if(size == vett.size){
        for(unsigned long i = 0; i < size; ++i){
            if (Elements[i] != vett.Elements[i]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}
template <typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& vett) const noexcept {
    return !(*this == vett);
}

template<typename Data>
void Vector<Data>::Resize(const unsigned long newSize){
    if(newSize == 0){
        Clear();
    }else if(size != newSize){
        unsigned long limit = (size < newSize) ? size : newSize;
        Data* TmpElements = new Data[newSize] {};
        for(unsigned long i = 0; i < limit; ++i){
            std::swap(Elements[i], TmpElements[i]);
        }
        std::swap(Elements,TmpElements);
        size = newSize;
        delete[] TmpElements;
    }
}

template<typename Data>
void Vector<Data>::Clear(){
    delete[] Elements;
    Elements = nullptr;
    size = 0;
}

template<typename Data>
Data& Vector<Data>::Front() const{
    if(size != 0){
        return Elements[0];
    }else{
        throw std::length_error("Accesso a un vettore vuoto");
    }
}
template<typename Data>
Data& Vector<Data>::Back() const{
   if(size != 0){
        return Elements[size - 1];
    }else{
        throw std::length_error("Accesso a un vettore vuoto");
    }
}

template<typename Data>
Data& Vector<Data>::operator[](const unsigned long i) const {
    if (i < size){
        return Elements[i];
    }else{
        throw std::out_of_range("Accesso ad un indice non coerente");
    }
}

template<typename Data>
void Vector<Data>::MapPreOrder(const MapFunctor fun, void* par){
    for(unsigned long i = 0; i < size; ++i){
        fun(Elements[i], par);
    }
}

template<typename Data>
void Vector<Data>::MapPostOrder(const MapFunctor fun, void* par){
    unsigned long i = size;
    while(i > 0){
        fun(Elements[--i],par);
    }
}

template<typename Data>
void Vector<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const {
    for(unsigned  long i = 0; i < size; ++i){
        fun(Elements[i], par, acc);
    }
}

template<typename Data>
void Vector<Data>::FoldPostOrder(const FoldFunctor fun,const void* par, void* acc) const{
    unsigned long i = size;
    while(i > 0){
        fun(Elements[--i],par, acc);
    }
}
/* ************************************************************************** */

}
