namespace lasd {

/* ************************************************************************** */
template <typename Data>
MatrixVec<Data>::MatrixVec(const int & my_row, const int & my_column) {
    Vector<Data>::Resize(my_row * my_column);
    row = my_row;
    column = my_column;
}

template <typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec <Data> & matrixVec) : Vector<Data>(matrixVec) {
    row = matrixVec.row;
    column = matrixVec.column;
}

template <typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec <Data> && matrixVec) noexcept{
    std::swap(row, matrixVec.row);
    std::swap(column, matrixVec.column);
    Vector<Data>::operator=(std::move(matrixVec));
}

template <typename Data>
MatrixVec<Data>::~MatrixVec() {
    Clear();
}

template <typename Data>
MatrixVec<Data> & MatrixVec<Data>::operator=(const MatrixVec <Data> & matrixVec) {
    row = matrixVec.row;
    column = matrixVec.column;
    Vector<Data>::operator=(matrixVec);
    return *this;
}
template <typename Data>
MatrixVec<Data> & MatrixVec<Data>::operator=(MatrixVec <Data> && matrixVec) noexcept {
    std::swap(row, matrixVec.row);
    std::swap(column, matrixVec.column);
    Vector<Data>::operator=(std::move(matrixVec));
    return *this;
}

template <typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec <Data> & matrixVec) const noexcept {
    if(row == matrixVec.row && column == matrixVec.column) {
        return Vector<Data>::operator==(matrixVec);
    }else{
        return false;
    }
}

template <typename Data>
bool MatrixVec<Data>::operator!=(const MatrixVec <Data> & matrixVec) const noexcept {
    return !(*this == matrixVec);
}
/* *********************** MEMBER FUNCTIONS *************************************************** */

template <typename Data>
void MatrixVec<Data>::Clear() {
    Vector<Data>::Clear();
    row = 0;
    column = 0;
}

template <typename Data>
void MatrixVec<Data>::RowResize(const int & m_row) {
    int oldColumn = column;
    Vector<Data>::Resize(m_row*column);
    column = oldColumn;
    row = m_row;
}

template <typename Data>
void MatrixVec<Data>::ColumnResize(const int & m_column) {
    if(m_column == 0){
        int oldRow = row;
        Clear();
        row = oldRow;
    }else if(column != m_column){
        int limit = (column < m_column) ? column : m_column;
        Data* TmpElements = new Data[m_column * row] {};
        for(int i = 0; i < row ; ++i){
            for(int j = 0; j < limit ; ++j){
                std::swap(Elements[i*column + j], TmpElements[i*m_column + j]);
            }
        }
        std::swap(Elements,TmpElements);
        size = m_column * row;
        column = m_column;
        delete[] TmpElements;
    }
}

template <typename Data>
bool MatrixVec<Data>::ExistsCell(const int & my_row, const int & my_column) const noexcept {
    return my_row < row && my_column < column;
}

template <typename Data>
Data & MatrixVec<Data>::operator()(const int & my_row, const int & my_column) {
    return const_cast<Data&>(static_cast<const MatrixVec<Data>*>(this)->operator()(my_row, my_column));
}
template <typename Data>
const Data & MatrixVec<Data>::operator()(const int & my_row, const int & my_column) const {
    if(ExistsCell(my_row, my_column)){
        return Elements[my_row * column + my_column];
    }else{
        throw std::out_of_range("Out of range error");
    }
}
/* ************************************* MAP E FOLD ************************************************* */
template <typename Data>
void MatrixVec<Data>::FoldPreOrder(const FoldFunctor foldFunctor, const void *  acc, void * supp) const {
    Vector<Data>::FoldPreOrder(foldFunctor, acc, supp);
}

template <typename Data>
void MatrixVec<Data>::FoldPostOrder(const FoldFunctor foldFunctor, const void * acc, void * supp) const {
    Vector<Data>::FoldPostOrder(foldFunctor, acc, supp);
}

template <typename Data>
void MatrixVec<Data>::MapPostOrder(const MapFunctor mapFunctor, void * supp) {
    Vector<Data>::MapPostOrder(mapFunctor, supp);
}
template <typename Data>
void MatrixVec<Data>::MapPreOrder(const MapFunctor mapFunctor, void * supp) {
    Vector<Data>::MapPreOrder(mapFunctor, supp);
}
/* ************************************************************************** */
}