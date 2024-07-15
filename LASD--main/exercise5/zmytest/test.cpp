#include "../zlasdtest/test.hpp"
#include "test.hpp"

static Menu menu;

using namespace lasd;

void coutAst(unsigned long ast){
    for(unsigned long index = 0; index < ast; ++index){
        std::cout<<"*";
    }
}

void coutRighe(unsigned long rig){
    for(unsigned long index = 0; index < rig; ++index){
        std::cout<<std::endl;
    }
}

template<typename Data>
void printElement(const Data& dato, void * _){
    std::cout<<dato<<" | ";
}

std::string random_string(unsigned long length){

    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string random_string;
    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[rand() % CHARACTERS.size()];
    }
    return random_string;
}

void productMinorsOfN(const int& dat, const void* n, void* acc) {
    if((dat < *((int*) n) && dat != 0)){
        *((int*) acc) *= dat;
    }
}

void stringConcatenate(const std::string& dat, const void* _, void* acc) {
    if(dat.size() <= *((int*)_)){
        ((std::string*) acc)->append(dat);
    }
}

void sumMajors(const float& dat, const void* _, void* acc) {
    if(dat > *((float*) _)){
        *((float*) acc) += dat;
    }
}


void func_2n(int& dato, void * _){
    dato *= 2;
}

void NegativeAndRaisedToThird(float& dato, void * _){
    if(dato != 0){
        dato = -dato;
        dato = dato*dato*dato;
    }
}

void stringConc(std::string& dat, void* acc) {
    dat = (*(std::string*)acc) + dat;
}

void chooseType(){
    unsigned long type;
    std::cout<<"Choose the type of the struct"<<std::endl;
    std::cout<<"[1]Int [2]float [3]string"<<std::endl;
    std::cin>>type;

    switch (type) {
        case 1: //interi
            std::cout<<"You choosed int"<<std::endl;
            menu.setType(type);
            break;
        case 2: //float
            std::cout<<"You choosed float"<<std::endl;
            menu.setType(type);
            break;
        case 3://string
            std::cout<<"You choosed string"<<std::endl;
            menu.setType(type);
            break;
        default:
            std::cout<<"Oooops, u pressed a wrong key";
    }
}

void chooseStruct(){
    unsigned long strutt;
    std::cout<<"Choose the type of the struct"<<std::endl;
    std::cout<<"[1]MatrixCSR(Compressed Sparse Row)"<<std::endl<<"[2]MatrixVec"<<std::endl;
    std::cin>>strutt;

    switch (strutt) {
        case 1:
            std::cout<<"You choosed MatrixCSR(Compressed Sparse Row)"<<std::endl;
            menu.setStruttura(strutt);
            break;
        case 2:
            std::cout<<"You choosed MatrixVec"<<std::endl;
            menu.setStruttura(strutt);
            break;
        default:
            std::cout<<"Oooops, u pressed a wrong key";
    }
}


void popolaMatrix(Matrix<int>& matrix){
    srand(time(nullptr));
    for (int i = 0; i < (matrix.RowNumber()*matrix.ColumnNumber())*2; ++i) {
        matrix(rand()%matrix.RowNumber(), rand()%matrix.ColumnNumber()) = rand()%1001;
    }
}

void popolaMatrix(Matrix<float>& matrix){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> intDistr(-1000, 1000);
    std::uniform_int_distribution<int> decDistr(0, 99);
    for (int i = 0; i < (matrix.RowNumber()*matrix.ColumnNumber())*2; ++i){
        int intVal = intDistr(gen);
        matrix(rand()%matrix.RowNumber(), rand()%matrix.ColumnNumber()) = intVal + (decDistr(gen) * ((intVal < 0)? (-0.01): (0.01))) ;
    }
}

void popolaMatrix(Matrix<std::string>& matrix){
    for (int i = 0; i < (matrix.RowNumber()*matrix.ColumnNumber())*2; ++i){
        matrix(rand()%matrix.RowNumber(), rand()%matrix.ColumnNumber()) = (random_string(rand()%12 + 1));
    }
}

template <typename Data>
void specificOperations(Matrix<Data>& matrix){
    int scelta = -1;
    Data element;
    while(scelta != 0) {
        std::cout << "Choose what you want to do:"
            << std::endl << "[0]Quit"
            << std::endl << "[1]Columns Resize"
            << std::endl << "[2]Rows Resize"
            << std::endl << "[3]Specific cell" << std::endl;
        std::cin >> scelta;
        switch (scelta) {
            case 0:
                std::cout << "Bye" << std::endl;
                break;
            case 1:
                int sizeColumn;
                std::cout<<"Current size of the Columns is: "<< matrix.ColumnNumber() <<
                std::endl<<"Choose a new Size(COLUMNS):"<< std::endl;
                    std::cin>>sizeColumn;
                    matrix.ColumnResize(sizeColumn);
                std::cout<<"Column Resize Applied"<<
                std::endl<<"New Size:"<<matrix.ColumnNumber()<<std::endl;
                break;
            case 2:
                int sizeRow;
                std::cout<<"Current size of the Rows is: "<< matrix.RowNumber() <<
                std::endl<<"Choose a new Size(ROWS):"<< std::endl;
                     std::cin>>sizeRow;
                     matrix.RowResize(sizeColumn);
                std::cout<<"Column Resize Applied"<<
                std::endl<<"New Size:"<<matrix.RowNumber()<<std::endl;
                break;
            case 3:
                int cellRow;
                int cellColumn;
                std::cout<<"Enter the Row:"<<std::endl;
                std::cin>>cellRow;
                std::cout<<"Enter the Column:"<<std::endl;
                std::cin>>cellColumn;
                    int cellChoose;
                    std::cout<<"Choose what you want to do:"
                        <<std::endl<<"[0]Quit"
                        <<std::endl<<"[1]Read the value"
                        <<std::endl<<"[2]Insert a new value"
                        <<std::endl<<"[3]Exists cell"
                        <<std::endl;
                    std::cin>>cellChoose;
                    switch (cellChoose) {
                        case 0:
                            std::cout << "Bye" << std::endl;
                            break;
                        case 1:
                            std::cout << "Reading the value" << std::endl << std::endl;
                            try {
                                std::cout << "The value is -->" << const_cast<Data &>(matrix(cellRow, cellColumn))
                                          << std::endl;
                            } catch (std::length_error e) {
                                std::cout << "Exception throwed: Length error" << std::endl;
                            } catch (std::out_of_range e) {
                                std::cout << "Exception throwed: Out of range error" << std::endl;
                            }
                            break;
                        case 2:
                            if(matrix.ExistsCell(cellRow, cellColumn)){
                                std::cout << "Insert the new value:" << std::endl;
                                std::cin >> element;
                                matrix(cellRow, cellColumn) = element;
                                std::cout << "Value (" << element << ") inserted!" << std::endl;
                            }else{
                                std::cout<<"Out of range!"<<std::endl;
                            }
                            break;
                        case 3:
                            std::cout<<"The cell "<<(matrix.ExistsCell(cellRow,cellColumn) ? "exists" : "doesnt' exists")<<std::endl;
                            break;
                        default:
                            std::cout << "Ooops" << std::endl;
                            break;
                    }
                break;
            default:
                std::cout<<"Ooops"<<std::endl;
                break;
        }
    }
}


template <typename Data>
void startMatrixCSR(){
    srand(time(nullptr));
    MatrixCSR<Data> matrixCsr(menu.getRiga(), menu.getColonna());
    popolaMatrix(matrixCsr);
    int scelta = -1;
    Data element;
    while(scelta != 0){
        std::cout << "\n[0]Quit"
                  << std::endl << "[1]View the entire struct"
                  << std::endl << "[2]See if an element exists inside the struct"
                  << std::endl << "[3]Calculate function"
                  << std::endl << "[4]Apply function"
                  << std::endl << "[5]Specific Operations"
                  << std::endl;
        std::cin>>scelta;
        switch (scelta) {
            case 0:
                std::cout<<"Bye"<<std::endl;
                break;
            case 1:
                if(!matrixCsr.Empty()) {
                    std::cout << "Choose a type of function for your visualization(Using Map):" << std::endl
                              << "[0]Quit" << std::endl << "[1]PreOrder" << std::endl << "[2]PostOrder" << std::endl;
                    int typeMap;
                    std::cin >> typeMap;
                    switch (typeMap) {
                        case 0:
                            std::cout << "Bye!";
                            break;
                        case 1:
                            matrixCsr.MapPreOrder(&printElement<Data>, nullptr);
                            break;
                        case 2:
                            matrixCsr.MapPostOrder(&printElement<Data>, nullptr);
                            break;
                        default:
                            std::cout << "Ooops..";
                            break;
                    }
                }else{
                    std::cout<<"The struct is Empty.."<<std::endl;
                }
                break;
            case 2:
                std::cout << "Type an element" << std::endl;
                std::cout << ">>>>";
                std::cin >> element;
                std::cout << ((matrixCsr.Exists(element)) ? "Yes, the element exists"
                                                          : "No,the element doesn't exists ");
                std::cout << std::endl;
                break;
            case 3:
                  testFoldable(matrixCsr);
                break;
            case 4:
                testMappable(matrixCsr);
                break;
            case 5:
                specificOperations(matrixCsr);
                break;
            default:
                std::cout<<"Ooops..";
                break;
        }
    }
}

template <typename Data>
void startMatrixVec(){
    srand(time(nullptr));
    MatrixVec<Data> matrixVec(menu.getRiga(), menu.getColonna());
    popolaMatrix(matrixVec);
    int scelta = -1;
    Data element;
    while(scelta != 0){
        std::cout << "\n[0]Quit"
                  << std::endl << "[1]View the entire struct"
                  << std::endl << "[2]See if an element exists inside the struct"
                  << std::endl << "[3]Calculate function"
                  << std::endl << "[4]Apply function"
                  << std::endl << "[5]Specific Operations"
                  << std::endl;
        std::cin>>scelta;
        switch (scelta) {
            case 0:
                std::cout<<"Bye"<<std::endl;
                break;
            case 1:
                if(!matrixVec.Empty()) {
                    std::cout << "Choose a type of function for your visualization(Using Map):" << std::endl
                              << "[0]Quit" << std::endl << "[1]PreOrder" << std::endl << "[2]PostOrder" << std::endl;
                    int typeMap;
                    std::cin >> typeMap;
                    switch (typeMap) {
                        case 0:
                            std::cout << "Bye!";
                            break;
                        case 1:
                            matrixVec.MapPreOrder(&printElement<Data>, nullptr);
                            break;
                        case 2:
                            matrixVec.MapPostOrder(&printElement<Data>, nullptr);
                            break;
                        default:
                            std::cout << "Ooops..";
                            break;
                    }
                }else{
                    std::cout<<"The struct is Empty.."<<std::endl;
                }
                break;
            case 2:
                std::cout << "Type an element" << std::endl;
                std::cout << ">>>>";
                std::cin >> element;
                std::cout << ((matrixVec.Exists(element)) ? "Yes, the element exists"
                                                    : "No,the element doesn't exists ");
                std::cout << std::endl;
                break;
            case 3:
                testFoldable(matrixVec);
                break;
            case 4:
                testMappable(matrixVec);
                break;
            case 5:
                 specificOperations(matrixVec);
                break;
            default:
                std::cout<<"Ooops..";
                break;
        }
    }
}

void testMappable(Matrix<int>& matrix){
    if(!matrix.Empty()) {
        std::cout<<"The function is the product of 2 and the integer numbers in the struct!"<<std::endl;
        matrix.MapPreOrder(&func_2n, nullptr);
        std::cout<<"\nApplied!"<<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}
void testMappable(Matrix<float>& matrix){
    if(!matrix.Empty()){
        std::cout<<"The function is the negative and the raise to Third of the float numbers in the struct!"<<std::endl;
        matrix.MapPreOrder(&NegativeAndRaisedToThird, nullptr);
        std::cout<<"\nApplied!"<<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}
void testMappable(Matrix<std::string>& matrix){
    if(!matrix.Empty()){
        std::string strng;
        std::cout<<"The function is the concatenation of the strings in the tree and your string!"<<std::endl;
        std::cout<<"Insert the string that you want to add in front"<<std::endl;
        std::cout<<">>>>";
        std::cin>>strng;
        matrix.MapPreOrder(&stringConc, &strng);
        std::cout<<"\nApplied!"<<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}

void testFoldable(Matrix<int>& matrix){
    if(!matrix.Empty()){
        int n;
        int prod = 1;
        std::cout<<"The function is the product of the integer numbers  < of you n-value!"<<std::endl;
        std::cout<<"Insert n-value: "<<std::endl;
        std::cin>> n;
        matrix.FoldPreOrder(&productMinorsOfN, &n, &prod);
        std::cout<<"Your result:"<<std::endl;
        std::cout<< prod<<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}

void testFoldable(Matrix<std::string>& matrix){
    if(!matrix.Empty()){
        int n;
        std::string strng;
        std::cout<<"The function is the concatenation of the strings with length <= of your n-value!"<<std::endl;
        std::cout<<"Insert n-value: "<<std::endl;
        std::cin>> n;
        matrix.FoldPreOrder(&stringConcatenate, &n, &strng);
        std::cout<<"Your result:"<<std::endl;
        std::cout<< strng <<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}

void testFoldable(Matrix<float>& matrix){
    if(!matrix.Empty()){
        float n;
        float sum = 0;
        std::cout<<"The function is the the sum of the float numbers > of your n-value!"<<std::endl;
        std::cout<<"Insert n-value: "<<std::endl;
        std::cin>>n;
        matrix.FoldPreOrder(&sumMajors, &n, &sum);
        std::cout<<"Your result:"<<std::endl;
        std::cout<<sum<<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}

void launchMenu() {
    unsigned long menuChoosing = -1;
    unsigned long exitMenu;
    coutRighe(3);
    coutAst(10);
    std::cout << " ~Welcome to the Menu of Francesco De Stasio~ ";
    coutAst(10);
    coutRighe(3);
    unsigned long column_size;
    unsigned long row_size;
    while (menuChoosing != 0) {
        std::cout << "\nChoose an option:" << std::endl << "[0]Quit" << std::endl << "[1]Start Test" << std::endl
                  << "[2]Choose type BinarySearchTree(int, string or float)" << std::endl;
        std::cin >> menuChoosing;
        switch (menuChoosing) {
            case 0:
                std::cout << "GoodBye";
                exitMenu = 2;
                break;
            case 1:
                lasdtest();
                break;
            case 2:
                chooseStruct();
                chooseType();
                std::cout << "Your struct will be populated with random elements, choose a size for the Columns and the Rows"
                << std::endl << "Rows: (digit a number > 0! not characters!)" << std::endl;
                std::cin >> row_size;
                std::cout << "Columns: (digit a number > 0! not characters!)" << std::endl;
                std::cin >> column_size;

                menu.setRiga(row_size);
                menu.setColonna(column_size);

            if(menu.getStruttura() == 1){
                if(menu.getTipo() == 1){
                     startMatrixCSR<int>();
                }else if(menu.getTipo() == 2){
                    startMatrixCSR<float>();
                }else if(menu.getTipo() == 3){
                    startMatrixCSR<std::string>();
                }
            }else if(menu.getStruttura() == 2){ //MatrixVec
                if(menu.getTipo() == 1){
                    startMatrixVec<int>();
                }else if(menu.getTipo() == 2){
                    startMatrixVec<float>();
                }else if(menu.getTipo() == 3){
                    startMatrixVec<std::string>();
                }
            }else{
                std::cout<<"Is not choosed a struct"<<std::endl;
            }
                break;
            default:
                std::cout
                        << "Ooops, you pressed a wrong key, you want go back? [1]Yes, sorry.. [2]No, let me quit"
                        << std::endl;
                std::cin >> exitMenu;
                switch (exitMenu) {
                    case 1:
                        break;
                    case 2:
                        std::cout << "GoodBye!!";
                        menuChoosing = 0;
                        break;
                    default:
                        std::cout << "Pay Attention next time!";
                        menuChoosing = 0;
                        break;
                }
        }
    }
}