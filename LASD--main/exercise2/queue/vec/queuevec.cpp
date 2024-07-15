#define costante 2
namespace lasd {

/* ************************************************************************** */

//Constructor
template <typename Data>
QueueVec<Data>::QueueVec() {
    Vector<Data>::Resize(1);
}
//Copy Constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec <Data> & queueVec) {
        size = queueVec.size;
        realSize = queueVec.realSize;
        Elements = new Data[queueVec.size];
        for(int i = 0; i < size; ++i){
            Elements[i] = queueVec[i];
        }
        coda = queueVec.coda;
        testa = queueVec.testa;
}
//Move Constructor
template<typename Data>
QueueVec<Data>::QueueVec(QueueVec <Data> && queueVec) noexcept{
    std::swap(Elements, queueVec.Elements);
    std::swap(testa, queueVec.testa);
    std::swap(coda, queueVec.coda);
    std::swap(realSize, queueVec.realSize);
}
//Constructor Obtained by a LinearContainer
template<typename Data>
QueueVec<Data>::QueueVec(LinearContainer <Data> & container) : Vector<Data>::Vector(container){
    Vector<Data>::Resize(size+1);
    realSize = container.Size();
    coda = container.Size();
}


//Member functions
template <typename Data>
void QueueVec<Data>::Enqueue(Data && dat) noexcept {
        if (Size() >= size-1) {
            SwapVectors(size*costante);
        }
        Elements[coda] = std::move(dat);
        coda = (coda+1)%size;
        ++realSize;
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data & dat) {
    if (Size() >= size-1) {
        SwapVectors(size*costante);
    }
    Elements[coda] = dat;
    coda = (coda+1)%size;
    ++realSize;
}

template <typename Data>
Data & QueueVec<Data>::Head() {
    if(Empty() == true){
        throw std::length_error("Access to an Empty Queue");
    }else{
        return Elements[testa];
    }
}

template <typename Data>
void QueueVec<Data>::Dequeue() {
    if(Empty() == true){
        throw std::length_error("Access to an Empty Queue");
    }else{
        testa = (testa+1)%size;
        --realSize;
        if(Size() == (1/4)*size && size>= costante) {
            SwapVectors(size/costante);
        }
    }
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    Data dat = Head();
    Dequeue();
    return dat;
}

template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    return realSize == 0;
}

template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept {
    return realSize;
}

template <typename Data>
void QueueVec<Data>::Clear() {
    Vector<Data>::Clear();
    Vector<Data>::Resize(1);
    realSize = 0;
    testa = 0;
    coda = 0;
}

template <typename Data>
void QueueVec<Data>::SwapVectors(unsigned  long newSize) {
    Data* TmpElements = new Data[newSize] {};
    unsigned long start = testa;
    for(int i = 0; i < realSize; ++i) {
        std::swap(TmpElements[i], Elements[start]);
        start = (start + 1) % size;
    }
    std::swap(TmpElements, Elements);
    testa = 0;
    coda = realSize;
    size = newSize;
    delete[] TmpElements;
}

//Operators
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec <Data> & queueVec) const noexcept {
    if(realSize == queueVec.realSize){
            unsigned long index1 = queueVec.testa;
            unsigned long index = testa;
            for(int i = 0; i < realSize; ++i){
                if(Elements[index] != queueVec[index1]){
                    return false;
                }
                index = (index+1)%size;
                index1 = (index1+1)%queueVec.size;
            }
        return true;
    }else{
        return false;
    }
}
template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec <Data> & queueVec) const noexcept {
    return !(*this == queueVec);
}

template <typename Data>
QueueVec<Data> & QueueVec<Data>::operator=(QueueVec <Data> && queueVec) {
    std::swap(Elements, queueVec.Elements);
    std::swap(testa, queueVec.testa);
    std::swap(coda, queueVec.coda);
    std::swap(realSize, queueVec.realSize);
    return *this;
}
template <typename Data>
QueueVec<Data> & QueueVec<Data>::operator=(const QueueVec <Data> & queueVec) {
    size = queueVec.size;
    realSize = queueVec.realSize;
    Elements = new Data[queueVec.size];
    for(int i = 0; i < size; ++i){
        Elements[i] = queueVec[i];
    }
    coda = queueVec.coda;
    testa = queueVec.testa;
    return *this;
}
/* ************************************************************************** */

}
