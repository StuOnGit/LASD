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
            exit(0);
    }
}

void popolaBST(BST<int>& bst){
    for (int i = 0; i < menu.getSize(); ++i){
        bst.Insert((rand() % 1001) + 1);
    }
    if(bst.Size() != menu.getSize()){
        std::cout<<"There have been several repetitions of the same elements, the size entered is not the same";
    }
}
void popolaBST(BST<float>& bst){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> intDistr(-1000, 1000);
    std::uniform_int_distribution<int> decDistr(0, 99);
    for (int i = 0; i < menu.getSize(); ++i){
        int intVal = intDistr(gen);
        bst.Insert(intVal + (decDistr(gen) * ((intVal < 0)? (-0.01): (0.01)))) ;
    }
    if(bst.Size() != menu.getSize()){
        std::cout<<"There have been several repetitions of the same elements, the size entered is not the same";
    }
}
void popolaBST(BST<std::string>& bst){
    for (int i = 0; i < menu.getSize(); ++i){
        bst.Insert(random_string(rand()%12 + 1));
    }
    if(bst.Size() != menu.getSize()){
        std::cout<<"There have been several repetitions of the same elements, the size entered is not the same";
    }
}

void productMinorsOfN(const int& dat, const void* n, void* acc) {
    if(dat < *((int*) n)){
        *((int*) acc) *= dat;
    }
}

void stringConcatenate(const std::string& dat, const void* _, void* acc) {
    if(dat.size() < *((int*)_)){
        ((std::string*) acc)->append(dat);
    }
}

void sumMajors(const float& dat, const void* _, void* acc) {
    if(dat > *((float*) _)){
        *((float*) acc) += dat;
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

template <typename Data>
void specificOperations(BST<Data>& bst){
    int scelta = -1;
    Data element;
    while(scelta != 0) {
        std::cout << "Choose what you want to do:" << std::endl << "[0]Quit" << std::endl << "[1]Insert an element"
                  << std::endl << "[2]Remove an element" << std::endl << "[3]See an Element" << std::endl;
        std::cin >> scelta;
        switch (scelta) {
            case 0:
                std::cout << "Bye" << std::endl;
                break;
            case 1:
                std::cout << "Type an element:" << std::endl << ">>>>";
                std::cin >> element;
                bst.Insert(element);
                std::cout<<"\nDone!"<<std::endl;
                break;
            case 2:
                std::cout << "[0]Quit"<<std::endl << "[1]Remove a specific element" << std::endl << "[2]Remove min" << std::endl
                          << "[3]Remove max" << std::endl << "[4]Remove predecessor" << std::endl
                          << "[5]Remove successor" << std::endl;
                int choose;
                std::cin>>choose;
                switch (choose) {
                    case 0:
                        std::cout<<"Bye"<<std::endl;
                        break;
                    case 1:
                        std::cout << "Type an element:" << std::endl <<
                        ">>>>";
                        std::cin >> element;
                        bst.Remove(element);
                        std::cout<<"\nDone!"<<std::endl;
                        break;
                    case 2:
                        std::cout<<"[1]See and remove min"<<std::endl<<"[2]Just Remove"<<std::endl;
                        int rmvMinChooser;
                        std::cin>>rmvMinChooser;
                        switch (rmvMinChooser) {
                            case 1:
                                try {
                                    std::cout<<bst.MinNRemove()<<std::endl;
                                }catch(std::length_error error){
                                    std::cout<< error.what()<< std::endl;
                                }
                                break;
                            case 2:
                                try {
                                    bst.RemoveMin();
                                }catch(std::length_error error){
                                    std::cout<< error.what()<< std::endl;
                                }
                                break;
                            default:
                                std::cout<<"Ooops"<<std::endl;
                                break;
                        }
                        break;
                    case 3:
                        std::cout<<"[1]See and remove max"<<std::endl<<"[2]Just Remove"<<std::endl;
                        int rmvMaxChooser;
                        std::cin>>rmvMaxChooser;
                        switch (rmvMaxChooser) {
                            case 1:
                                try {
                                    std::cout << bst.MaxNRemove() << std::endl;
                                }catch(std::length_error error){
                                   std::cout<< error.what()<< std::endl;
                                }
                                break;
                            case 2:
                                try {
                                    std::cout << bst.MaxNRemove() << std::endl;
                                bst.RemoveMax();
                                }catch(std::length_error error){
                                    std::cout<< error.what()<< std::endl;
                                }
                                break;
                            default:
                                std::cout<<"Ooops"<<std::endl;
                                break;
                        }
                        break;
                    case 4:
                        std::cout<<"Predecessor of:"<<std::endl<<">>>>";
                        std::cin>>element;
                        std::cout<<"[1]See and remove predecessor of"<<std::endl<<"[2]Just Remove"<<std::endl;
                        int rmvPredecessorChooser;
                        std::cin>>rmvPredecessorChooser;
                        switch (rmvPredecessorChooser) {
                            case 1:
                                try{
                                    std::cout<<bst.PredecessorNRemove(element)<<std::endl;
                                }catch(std::length_error error){
                                    std::cout<< error.what()<< std::endl;
                                }
                                break;
                            case 2:
                                try{
                                    bst.RemovePredecessor(element);
                                }catch(std::length_error error){
                                    std::cout<< error.what()<< std::endl;
                                }
                                break;
                            default:
                                std::cout<<"Ooops"<<std::endl;
                                break;
                        }
                        break;
                    case 5:
                        std::cout<<"Successor of:"<<std::endl<<">>>>";
                        std::cin>>element;
                        std::cout<<"[1]See and remove successor of"<<std::endl<<"[2]Just Remove"<<std::endl;
                        int rmvSuccessorChooser;
                        std::cin>>rmvSuccessorChooser;
                        switch (rmvSuccessorChooser) {
                            case 1:
                                try{
                                    std::cout<<bst.SuccessorNRemove(element)<<std::endl;
                                }catch(std::length_error error){
                                    std::cout<< error.what()<< std::endl;
                                }
                                break;
                            case 2:
                                try{
                                    bst.RemoveSuccessor(element);
                                }catch(std::length_error error){
                                    std::cout<< error.what()<< std::endl;
                                }
                                break;
                            default:
                                std::cout<<"Ooops"<<std::endl;
                                break;
                        }
                        break;
                }
                break;
            case 3:
                std::cout<<"Which element do you want to see:"<<std::endl<<"[1]Min"<<std::endl<<"[2]Max"<<std::endl<<"[3]Predecessor"<< std::endl<<"[4]Successor"<<std::endl;
                int seeChoose;
                std::cin>>seeChoose;
                switch (seeChoose) {
                    case 1:
                        try{
                            std::cout<<bst.Min()<<std::endl;
                        }catch(std::length_error error){
                            std::cout<< error.what()<< std::endl;
                        }
                        break;
                    case 2:
                        try{
                            std::cout<<bst.Max()<<std::endl;
                        }catch(std::length_error error){
                            std::cout<< error.what()<< std::endl;
                        }
                        break;
                    case 3:
                        std::cout<<"Predecessor of:"<<std::endl<<">>>>";
                        std::cin>>element;
                        try{
                            std::cout<<bst.Predecessor(element)<<std::endl;
                        }catch(std::length_error error){
                            std::cout<< error.what() << std::endl;
                        }
                        break;
                    case 4:
                        std::cout<<"Successor of:"<<std::endl<<">>>>";
                        std::cin>>element;
                        try{
                            std::cout<<bst.Successor(element)<<std::endl;
                        }catch(std::length_error error){
                            std::cout<< error.what()<< std::endl;
                        }
                        break;
                    default:
                        std::cout<<"Ooops"<<std::endl;
                        break;
                }
                break;
        }
    }
}

template <typename Data>
void startBST(){
    srand(time(nullptr));
    BST<Data> bst;
    popolaBST(bst);
    int scelta = -1;
    Data element;
    while(scelta != 0){
        std::cout << "\n[0]Quit" << std::endl << "[1]View the entire struct" << std::endl
                  << "[2]See if an element exists inside the struct"
                  << std::endl << "[3]Calculate function" << std::endl
                  << "[4]Specific operations.." << std::endl;
        std::cin>>scelta;
        switch (scelta) {
            case 0:
                std::cout<<"Bye"<<std::endl;
                break;
            case 1:
                if(!bst.Empty()) {
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
                            bst.MapPreOrder(&printElement<Data>, nullptr);
                            break;
                        case 2:
                            bst.MapPostOrder(&printElement<Data>, nullptr);
                            break;
                        case 3:
                            bst.MapBreadth(&printElement<Data>, nullptr);
                            break;
                        case 4:
                            bst.MapInOrder(&printElement<Data>, nullptr);
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
                std::cout << ((bst.Exists(element)) ? "Yes, the element exists"
                                                              : "No,the element doesn't exists ");
                std::cout << std::endl;
                break;
            case 3:
                testFoldable(bst);
                break;
            case 4:
                specificOperations(bst);
                break;
            default:
                std::cout<<"Ooops..";
                break;
        }
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
    unsigned long strutt_size;
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
                chooseType();
                std::cout << "Your struct will be populated with random elements, choose a size."
                          << std::endl << "Size: (digit a number > 0! not characters!)" << std::endl;
                std::cin >> strutt_size;
                menu.setSize(strutt_size);

                if(menu.getTipo() == 1){
                    startBST<int>();
                }else if(menu.getTipo() == 2){
                    startBST<float>();
                }else if(menu.getTipo() == 3){
                    startBST<std::string>();
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