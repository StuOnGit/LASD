
namespace lasd {
/* ****************************DESTRUCTOR AND CONSTRUCTORS********************************************** */
template <typename Data>
MatrixCSR<Data>::MatrixCSR() {
    RowVec.Resize(1);
    RowVec[0] = &head;
}

template <typename Data>
MatrixCSR<Data>::MatrixCSR(const int & m_row, const int & m_column) {
     RowVec.Resize(m_row + 1);
     row = m_row;
     column = m_column;
     for (int i = 0; i <= row; ++i) {
            RowVec[i] = &head;
     }
}

template <typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR <Data> & matrixCsr) : MatrixCSR(matrixCsr.row, matrixCsr.column) {
    Node** pointer;
    for(int i = 0; i < row; ++i){
       for(pointer = matrixCsr.RowVec[i]; pointer != matrixCsr.RowVec[i+1]; pointer = &((*pointer)->next)){
           Node& node = **pointer;
           (*this)(i, node.dato.second) = node.dato.first;
       }
   }
}

template <typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR<Data>&& matrixCsr) noexcept : MatrixCSR() {
    operator=(std::move(matrixCsr));
}

template <typename Data>
MatrixCSR<Data>::~MatrixCSR() {
    Clear();
}

/* ***************************** MEMBER FUNCTIONS ********************************************* */
template <typename Data>
void MatrixCSR<Data>::RowResize(const int & m_row) {
            if(m_row < row){
                Node* tmp = *RowVec[m_row];
                Node* del;
                while(tmp != nullptr){
                    del = tmp;
                    tmp = tmp->next;
                    delete del;
                    size--;
                }
                RowVec.Resize(m_row + 1);
                *RowVec.Back() = nullptr;
            }else if(m_row == 0){
                int oldCol = column;
                Clear();
                column = oldCol;
            }else{
                RowVec.Resize(m_row + 1);
                for(unsigned long i = row; i < m_row; i++) {
                    RowVec[i+1] = RowVec[i];
                }
            }
            row = m_row;
}

template <typename Data>
void MatrixCSR<Data>::ColumnResize(const int & m_column) {
    if(m_column == 0){
        List<std::pair<Data,ulong>>::Clear();
        for(int i = 0; i < RowVec.Size(); ++i){
            RowVec[i] = &head;
        }
        size = 0;
    } else if(m_column < column){
        for (unsigned long i = 0; i < row; ++i) {
            Node** tmp = RowVec[i];
            while (tmp != RowVec[i+1]){
                if ((*tmp)->dato.second >= m_column){
                    Node* del = *tmp;
                    *tmp = del->next;
                    if (&(del->next) == RowVec[i+1]){
                        for(unsigned long j = i+1; j < RowVec.Size() && *RowVec[j] == del->next; ++j){
                            RowVec[j] = tmp;
                        }
                    }
                    delete del;
                    size--;
                } else tmp = &((*tmp)->next);
            }
        }
    }
    column = m_column;
}

template <typename Data>
bool MatrixCSR<Data>::ExistsCell(const int & m_row, const int & m_column) const noexcept {
    if(m_row < row && m_column < column){
        Node** pointer = RowVec[m_row];
        while(pointer != RowVec[m_row + 1]){
            Node& node = **pointer;
            if(node.dato.second == m_column){
                return true;
            }
            pointer = &(node.next);
        }
    }
    return false;
}
template <typename Data>
void MatrixCSR<Data>::Clear() {
    RowVec.Resize(1);
    List<std::pair<Data,ulong>>::Clear();
    row = 0;
    column = 0;
}
/* ***************************** OPERATORS  ********************************************* */
template <typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR <Data> & matrixCsr) const noexcept {
    if(row == matrixCsr.row && column == matrixCsr.column){
        Node** pointer1 = RowVec[0];
        Node** pointer2 = matrixCsr.RowVec[0];
        for (int i = 0; i < RowVec.Size()-1 ; ++i) {
                while(pointer1 != RowVec[i + 1] && pointer2 != matrixCsr.RowVec[i + 1]){
                    if((*pointer1)->dato != (*pointer2)->dato){
                        return false;
                    }
                    pointer1 = &((*pointer1)->next);
                    pointer2 = &((*pointer2)->next);
                }
                if(((pointer1 != RowVec[i+1]) && (pointer2 == matrixCsr.RowVec[i+1])) || ((pointer1 == RowVec[i+1]) && (pointer2 != matrixCsr.RowVec[i+1]))){
                    return false;
                }
            }
    }else{
        return false;
    }
        return true;
}
template <typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR <Data> & matrixCsr) const noexcept {
    return !(*this == matrixCsr);
}
template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR <Data> & matrixCsr) {
    Clear();
    RowVec.Resize(matrixCsr.row + 1);
    row = matrixCsr.row;
    column = matrixCsr.column;
    for (int i = 0; i <= row; ++i) {
        RowVec[i] = &head;
    }
    Node** pointer;
    for(int i = 0; i < row; ++i){
        for(pointer = matrixCsr.RowVec[i]; pointer != matrixCsr.RowVec[i+1]; pointer = &((*pointer)->next)){
            Node& node = **pointer;
            (*this)(i, node.dato.second) = node.dato.first;
        }
    }
    return *this;
}

template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR <Data> && matrixCsr) noexcept {
    std::swap(RowVec, matrixCsr.RowVec);
    std::swap(row, matrixCsr.row);
    std::swap(column, matrixCsr.column);
    std::swap(size, matrixCsr.size);
    std::swap(head, matrixCsr.head);

    for (int i = 0; i < RowVec.Size() && RowVec[i] == &matrixCsr.head; ++i) {
        RowVec[i] = &head;
    }

    for (int i = 0; i < matrixCsr.Size() && matrixCsr.RowVec[i] == &head; ++i) {
        matrixCsr.RowVec[i] = &matrixCsr.head;
    }

    return *this;
}
template <typename Data>
Data & MatrixCSR<Data>::operator()(const int & m_row , const int & m_column) {
    if((m_row < row) && (m_column < column)){
        Node** pointer = RowVec[m_row];
        Node** ext = RowVec[m_row+1];
        while((pointer != ext)  && (*pointer)->dato.second <= m_column){
            Node& node = **pointer;
            if(node.dato.second == m_column){
                return node.dato.first;
            }
            pointer = &(node.next);
        }
        Node* nodo = new Node();
        Node* tmp = (*pointer);
        *pointer = nodo;
        (*pointer)->next = tmp;
        nodo->dato.second = m_column;
        size++;
        int i = m_row+1;
        if(pointer == ext){
            for(; i < row && RowVec[i] == RowVec[i+1]; ++i){
                RowVec[i] = &((*pointer)->next);
            }
            RowVec[i] = &((*pointer)->next);
        }
        return nodo->dato.first;
    }else{
        throw std::out_of_range("Out of range error [operator ()]");
    }
}

template <typename Data>
const Data & MatrixCSR<Data>::operator()(const int & m_row, const int & m_column) const {
       if((m_row < row) && (m_column < column)){
           Node** pointer = RowVec[m_row];
           while((pointer != RowVec[m_row + 1]) && (*pointer)->dato.second <= m_column){
                Node& node = **pointer;
                if(node.dato.second == m_column){
                    return node.dato.first;
                }
               pointer = &(node.next);
           }
           throw std::length_error("Length error");
       }else{
           throw std::out_of_range("Out of range error [operator const ()]");
       }
}

/* ***************************** MAP E FOLD ********************************************* */

template <typename Data>
void MatrixCSR<Data>::FoldPostOrder(const FoldFunctor fold, const void * par, void *acc) const {
    List<std::pair<Data,ulong>>::FoldPostOrder(
            [&fold] (const std::pair<Data,ulong>& dati,const void* par1,void* acc1) { fold(dati.first, par1,acc1); }
            ,par,acc);
}
template <typename Data>
void MatrixCSR<Data>::FoldPreOrder(const FoldFunctor fold, const void * par, void *acc) const {
    List<std::pair<Data,ulong>>::FoldPreOrder(
            [&fold] (const std::pair<Data,ulong>& dati,const void* par1,void* acc1) { fold(dati.first, par1,acc1); }
            ,par,acc);
}
template <typename Data>
void MatrixCSR<Data>::MapPreOrder(MapFunctor map, void *par) {
    List<std::pair<Data,ulong>>::MapPreOrder(
            [&map] (std::pair<Data,ulong>& dati, void* par1) { map(dati.first, par1); }
            ,par);
}
template <typename Data>
void MatrixCSR<Data>::MapPostOrder(MapFunctor map, void *par) {
    List<std::pair<Data,ulong>>::MapPostOrder(
            [&map] (std::pair<Data,ulong>& dati, void* par1) { map(dati.first, par1); }
            ,par);
}
/* ************************************************************************** */
}
