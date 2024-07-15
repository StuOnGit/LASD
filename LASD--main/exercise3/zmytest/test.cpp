
#include "../zlasdtest/test.hpp"
#include "test.hpp"
#include <random>
#include <ctime>


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

std::string random_string(unsigned long length){

    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string random_string;
    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[rand() % CHARACTERS.size()];
    }
    return random_string;
}

template<typename Data>
void printElement(const Data& dato, void * _){
    std::cout<<dato<<" ";
}

void productMinorsOfN(const int& dat, const void* n, void* acc) {
    if(dat < *((int*) n)){
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

void func_3n(int& dato, void * _){
    dato *= 3;
}

void raisedToThird(float& dato, void * _){
    dato = dato*dato*dato;
}

void stringConc(std::string& dat, void* acc) {
    dat = (*(std::string*)acc) + dat;
}


void testMappable(BinaryTree<int>& binaryTree){
    if(!binaryTree.Empty()) {
        std::cout<<"The function is the product of 3 and the integer numbers in the tree!"<<std::endl;
        binaryTree.MapInOrder(&func_3n, nullptr);
        std::cout<<"\nApplied!"<<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}
void testMappable(BinaryTree<float>& binaryTree){
    if(!binaryTree.Empty()){
        std::cout<<"The function is the raise to Third of the float numbers in the tree!"<<std::endl;
        binaryTree.MapInOrder(&raisedToThird, nullptr);
        std::cout<<"\nApplied!"<<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}
void testMappable(BinaryTree<std::string>& binaryTree){
    if(!binaryTree.Empty()){
        std::string strng;
        std::cout<<"The function is the concatenation of the strings in the tree and your string!"<<std::endl;
        std::cout<<"Insert the string that you want to add in front"<<std::endl;
        std::cout<<">>>>";
        std::cin>>strng;
        binaryTree.MapInOrder(&stringConc, &strng);
        std::cout<<"\nApplied!"<<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}

void testFoldable(BinaryTree<int>& binaryTree){
    if(!binaryTree.Empty()){
        int n;
        int prod = 1;
        std::cout<<"The function is the product of the integer numbers  < of you n-value!"<<std::endl;
        std::cout<<"Insert n-value: "<<std::endl;
        std::cin>> n;
        binaryTree.FoldInOrder(&productMinorsOfN, &n, &prod);
        std::cout<<"Your result:"<<std::endl;
        std::cout<< prod<<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}

void testFoldable(BinaryTree<std::string>& binaryTree){
    if(!binaryTree.Empty()){
        int n;
        std::string strng;
        std::cout<<"The function is the concatenation of the strings with length < of your n-value!"<<std::endl;
        std::cout<<"Insert n-value: "<<std::endl;
        std::cin>> n;
        binaryTree.FoldInOrder(&stringConcatenate, &n, &strng);
        std::cout<<"Your result:"<<std::endl;
        std::cout<< strng <<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }

}
void testFoldable(BinaryTree<float>& binaryTree){
    if(!binaryTree.Empty()){
        float n;
        float sum = 0;
        std::cout<<"The function is the the sum of the float numbers > of your n-value!"<<std::endl;
        std::cout<<"Insert n-value: "<<std::endl;
        std::cin>>n;
        binaryTree.FoldInOrder(&sumMajors, &n, &sum);
        std::cout<<"Your result:"<<std::endl;
        std::cout<<sum<<std::endl;
    }else{
        std::cout<<"The struct is Empty.."<<std::endl;
    }
}

void popolaVector(Vector<int>& s){
    for (int i = 0; i < menu.getSize(); ++i) {
        s[i] = (rand() % 101);
    }
}
void popolaVector(Vector<float>& s){

    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> intDistr(-1000, 1000);
    std::uniform_int_distribution<int> decDistr(0, 99);
    for (unsigned long i = 0; i < s.Size(); i++) {
        int intVal = intDistr(gen);
        s[i] = intVal + (decDistr(gen) * ((intVal < 0)? (-0.01): (0.01)));
    }
}

void popolaVector(Vector<std::string>& s){
    for(int i = 0; i <menu.getSize(); ++i){
        s[i] = (random_string((rand() % 12)+ 1));
    }
}


void chooseClass(){
    coutAst(30);
    coutRighe(2);
    std::cout<<"Choose: "<<std::endl<<"[0]Quit"<<std::endl<<"[1]Vector Or [2]Pointers"<<std::endl;
    unsigned long scelta;
    std::cin>> scelta;

    char classe;
    switch (scelta) {
        case 0: //Exit
            std::cout<<"Goodbye!";
            exit(0);
        case 1: //Vector
            std::cout<<"You choosed Vector"<<std::endl;
            classe = 1;
            break;
        case 2: //Pointers
            std::cout<<"You choosed Pointers"<<std::endl;
            classe = 2;
            break;
        default:
            std::cout<<"Oooops, u pressed a wrong key";
            exit(0);
    }
    menu.setClasse(classe);

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
            exit(0);
    }
}
template <typename Data>
void usePostOrderIterator(BinaryTree<Data>& binaryTree){
    if(!binaryTree.Empty()) {
        BTPostOrderIterator<Data> btPostOrderIterator(binaryTree);
        int scelta;
        while (scelta != 0) {
            std::cout << "[0]Quit" << std::endl << "[1]Go next(++)" << std::endl << "[2]See the element" << std::endl;
            std::cin >> scelta;
            switch (scelta) {
                case 0:
                    std::cout << "Bye" << std::endl;
                    break;
                case 1:
                    ++btPostOrderIterator;
                    break;
                case 2:
                    std::cout << *btPostOrderIterator<<std::endl;
                    break;
                default:
                    std::cout << "Oops.." << std::endl;
                    break;
            }
        }
    }else{
        std::cout<<"The binary tree is Empty"<<std::endl;
    }
}
template <typename Data>
void usePreOrderIterator(BinaryTree<Data>& binaryTree){
    if(!binaryTree.Empty()) {
        BTPreOrderIterator<Data> btPreOrderIterator(binaryTree);
        int scelta;
        while(scelta != 0){
            std::cout<<"[0]Quit"<<std::endl<<"[1]Go next(++)"<<std::endl<<"[2]See the element"<<std::endl;
            std::cin>>scelta;
            switch(scelta){
                case 0:
                    std::cout<<"Bye"<<std::endl;
                    break;
                case 1:
                    ++btPreOrderIterator;
                    break;
                case 2:
                    std::cout<<*btPreOrderIterator<<std::endl;
                    break;
                default:
                    std::cout<<"Oops.."<<std::endl;
                    break;
            }
        }
    }else{
        std::cout<<"The binary tree is Empty"<<std::endl;
    }
}

template <typename Data>
void useBreadthOrderIterator(BinaryTree<Data>& binaryTree){
    if(!binaryTree.Empty()) {
        BTBreadthIterator<Data> btBreadthIterator(binaryTree);
        int scelta;
        while(scelta != 0){
            std::cout<<"[0]Quit"<<std::endl<<"[1]Go next(++)"<<std::endl<<"[2]See the element"<<std::endl;
            std::cin>>scelta;
            switch(scelta){
                case 0:
                    std::cout<<"Bye"<<std::endl;
                    break;
                case 1:
                    ++btBreadthIterator;
                    break;
                case 2:
                    std::cout<<*btBreadthIterator<<std::endl;
                    break;
                default:
                    std::cout<<"Oops.."<<std::endl;
                    break;
            }
        }
    }else{
        std::cout<<"The binary tree is Empty"<<std::endl;
    }
}
template <typename Data>
void useInOrderIterator(BinaryTree<Data>& binaryTree){
    if(!binaryTree.Empty()) {
        BTInOrderIterator<Data> btInOrderIterator(binaryTree);
        int scelta;
        while(scelta != 0){
            std::cout<<"[0]Quit"<<std::endl<<"[1]Go next(++)"<<std::endl<<"[2]See the element"<<std::endl;
            std::cin>>scelta;
            switch(scelta){
                case 0:
                    std::cout<<"Bye"<<std::endl;
                    break;
                case 1:
                    ++btInOrderIterator;
                    break;
                case 2:
                    std::cout<<*btInOrderIterator<<std::endl;
                    break;
                default:
                    std::cout<<"Oops.."<<std::endl;
                    break;
            }
        }
    }else{
        std::cout<<"The binary tree is Empty"<<std::endl;
    }
}

template <typename Data>
void navigateTheTree(BinaryTree<Data>& binaryTree){
    if(!binaryTree.Empty()) {
        int scelta = -1;
        Data tmp;
        typename BinaryTree<Data>::Node *node = &binaryTree.Root();
        while (scelta != 0) {
            std::cout << "[0]Quit" << std::endl << "[1]See the Element" << std::endl << "[2]Modify the Element" << std::endl
                      << "[3]Access to children" << std::endl << "[4]Navigate with iterators" << std::endl;
            std::cin >> scelta;
            switch (scelta) {
                case 0:
                    std::cout << "Bye" << std::endl;
                    break;
                case 1:
                    std::cout << node->Element() << std::endl;
                    break;
                case 2:
                    std::cout << "Insert the new value of the element:" << std::endl;
                    std::cout << ">>>>";
                    std::cin >> tmp;
                    node->Element() = tmp;
                    break;
                case 3:
                    std::cout << "[0]To go back.." << std::endl;
                    std::cout << (node->HasLeftChild() ? "[1]Access to left Child" : "No left Child..")<<std::endl;
                    std::cout << (node->HasRightChild() ? "[2]Access to right Child" : "No right Child..")<<std::endl;

                    int chooseChild;
                    std::cin >> chooseChild;
                    switch (chooseChild) {
                        case 0:
                            std::cout << "Bye";
                            break;
                        case 1:
                            if (node->HasLeftChild()) {
                                node = &node->LeftChild();
                            }
                            break;
                        case 2:
                            if (node->HasRightChild()) {
                                node = &node->RightChild();
                            }
                            break;
                        default:
                            std::cout << "Oops..";
                            break;
                    }
                    break;
                case 4:
                    std::cout << "[0]Quit" << std::endl << "Choose an Iterator:" << std::endl << "[1]PreOrder"
                              << std::endl << "[2]PostOrder"
                              << std::endl << "[3]BreadthOrder" << std::endl << "[4]InOrder" << std::endl;
                    int choose;
                    std::cin>>choose;
                    switch (choose) {
                        case 0:
                            std::cout<<"Bye"<<std::endl;
                            break;
                        case 1:
                            usePreOrderIterator(binaryTree);
                            break;
                        case 2:
                            usePostOrderIterator(binaryTree);
                            break;
                        case 3:
                            useBreadthOrderIterator(binaryTree);
                            break;
                        case 4:
                            useInOrderIterator(binaryTree);
                            break;
                    }
                    break;
            }
        }
    }else{
        std::cout<<"Binary tree is empty.."<<std::endl;
    }
}

template <typename Data>
void startPointer(){
    srand(time(nullptr));
    Vector<Data> vector(menu.getSize());
    popolaVector(vector);
    BinaryTreeLnk<Data> binaryTreeLnk(vector);
    int scelta = -1;
    Data element;
    while(scelta != 0){
        std::cout << "\n[0]Quit" << std::endl << "[1]View the entire struct" << std::endl
                  << "[2]See if an element exists inside the struct"
                  << std::endl << "[3]Calculate function" << std::endl << "[4]Apply functions" << std::endl
                  << "[5]Specific operations.." << std::endl;
        std::cin>>scelta;
        switch (scelta) {
            case 0:
                std::cout<<"Bye bye!"<<std::endl;
                break;
            case 1:
                if(!binaryTreeLnk.Empty()) {
                std::cout << "Choose a type of function for your visualization(Using Map):" << std::endl
                          << "[0]Quit" << std::endl << "[1]PreOrder" << std::endl << "[2]PostOrder" << std::endl
                          << "[3]BreadthOrder" << std::endl
                          << "[4]InOrder" << std::endl;
                int typeMap;
                std::cin>>typeMap;
                    switch (typeMap) {
                        case 0:
                            std::cout << "Bye!";
                            break;
                        case 1:
                            binaryTreeLnk.MapPreOrder(&printElement<Data>, nullptr);
                            break;
                        case 2:
                            binaryTreeLnk.MapPostOrder(&printElement<Data>, nullptr);
                            break;
                        case 3:
                            binaryTreeLnk.MapBreadth(&printElement<Data>, nullptr);
                            break;
                        case 4:
                            binaryTreeLnk.MapInOrder(&printElement<Data>, nullptr);
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
                std::cout<<"Type an element"<<std::endl;
                std::cout<<">>>>";
                std::cin>>element;
                std::cout<<((binaryTreeLnk.Exists(element))  ? "Yes, the element exists" : "No,the element doesn't exists ");
                std::cout<<std::endl;
                break;
            case 3:
                testFoldable(binaryTreeLnk);
                break;
            case 4:
                testMappable(binaryTreeLnk);
                break;
            case 5:
                navigateTheTree(binaryTreeLnk);
                break;
            default:
                std::cout<<"Ooops..";
                break;
        }
    }
}

template <typename Data>
void startVec() {
    srand(time(nullptr));
    Vector<Data> vector(menu.getSize());
    popolaVector(vector);
    BinaryTreeVec<Data> binaryTreeVec(vector);
    int scelta = -1;
    Data element;
    while (scelta != 0) {
        std::cout << "\n[0]Quit" << std::endl << "[1]View the entire struct" << std::endl
                  << "[2]See if an element exists inside the struct"
                  << std::endl << "[3]Calculate function" << std::endl << "[4]Apply functions" << std::endl
                  << "[5]Specific operations.." << std::endl;
        std::cin >> scelta;
        switch (scelta) {
            case 0:
                std::cout << "Bye bye!" << std::endl;
                break;
            case 1:
                if(!binaryTreeVec.Empty()) {
                    std::cout << "Choose a type of function for your visualization(Using Map):" << std::endl
                              << "[0]Quit" << std::endl << "[1]PreOrder" << std::endl << "[2]PostOrder" << std::endl
                              << "[3]BreadthOrder" << std::endl
                              << "[4]InOrder" << std::endl;
                    int typeMap;
                    std::cin >> typeMap;
                    switch (typeMap) {
                        case 0:
                            std::cout << "Bye!";
                            break;
                        case 1:
                            binaryTreeVec.MapPreOrder(&printElement<Data>, nullptr);
                            break;
                        case 2:
                            binaryTreeVec.MapPostOrder(&printElement<Data>, nullptr);
                            break;
                        case 3:
                            binaryTreeVec.MapBreadth(&printElement<Data>, nullptr);
                            break;
                        case 4:
                            binaryTreeVec.MapInOrder(&printElement<Data>, nullptr);
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
                std::cout << ((binaryTreeVec.Exists(element)) ? "Yes, the element exists"
                                                              : "No,the element doesn't exists ");
                std::cout << std::endl;
                break;
            case 3:
                testFoldable(binaryTreeVec);
                break;
            case 4:
                testMappable(binaryTreeVec);
                break;
            case 5:
                navigateTheTree(binaryTreeVec);
                break;
        }
    }
}
void launchMenu() {
        unsigned long menuChoosing;
        unsigned long exitMenu;
        coutRighe(3);
        coutAst(10);
        std::cout << " ~Welcome to the Menu of Francesco De Stasio~ ";
        coutAst(10);
        coutRighe(3);
        unsigned long strutt_size;
        while (menuChoosing != 0) {
            std::cout << "\nChoose an option:" << std::endl << "[0]Quit" << std::endl << "[1]Start Test" << std::endl
                      << "[2]Choose Struct BinaryTree(Pointers or Vector)" << std::endl;
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
                    chooseClass();
                    switch (menu.getClasse()) {
                        case 1: //Vettore
                            std::cout << "Your struct(Vector) will be populated with random elements, choose a size."
                                      << std::endl << "Size: (digit a number > 0! not characters!)" << std::endl;
                            std::cin >> strutt_size;
                            menu.setSize(strutt_size);
                            if (menu.getTipo() == 1) {
                                startVec<int>();
                            } else if(menu.getTipo() == 2){
                              startVec<float>();
                            }else if(menu.getTipo() == 3) {
                                startVec<std::string>();
                            }
                            break;
                        case 2: //Pointers
                            std::cout << "Your struct(Pointers) will be populated with random elements, choose a size." << std::endl
                                      << "Size: (digit a number > 0! not characters!)" << std::endl;
                            std::cin >> strutt_size;
                            menu.setSize(strutt_size);
                            if (menu.getTipo() == 1) {
                               startPointer<int>();
                            } else if(menu.getTipo() == 2){
                              startPointer<float>();
                            }else if(menu.getTipo() == 3){
                             startPointer<std::string>();
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
    }
