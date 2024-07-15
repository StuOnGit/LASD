#include "../zlasdtest/test.hpp"
#include "test.hpp"
#include <random>
#include <ctime>

using namespace lasd;

static Menu menu;

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

void chooseClass(){
    coutAst(30);
    coutRighe(2);
    std::cout<<"Choose: "<<std::endl<<"[1]Vector Or [2]List"<<std::endl;
    std::cout<<"[0]Quit"<<std::endl;
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
        case 2: //List
            std::cout<<"You choosed List"<<std::endl;
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

void chooseStruct(){
    coutAst(30);
    coutRighe(2);
    std::cout<<"Choose: "<<std::endl<<"[1]Stack Or [2]Queue"<<std::endl;
    std::cout<<"[0]Quit"<<std::endl;
    unsigned long scelta;
    std::cin>> scelta;

    char struttura;
    switch (scelta) {
        case 0: //Exit
            std::cout<<"Goodbye!";
            exit(0);
        case 1: //Stack
            std::cout<<"You choosed Stack"<<std::endl;
            struttura = 1;
            break;
        case 2: //Queue
            std::cout<<"You choosed Queue"<<std::endl;
            struttura = 2;
            break;
        default:
            std::cout<<"Oooops, u pressed a wrong key";
            exit(0);
    }
    menu.setStruttura(struttura);
}

template <typename Data>
void startQueueLst(){
    srand(time(nullptr));
    QueueLst<Data> queueLst;
    popolaQueue(queueLst);
    int scelta = -1;
    Data element;
    while(scelta != 0) {
        std::cout << "\n[0]Cancel" << std::endl << "[1]Add Element to the tail" << std::endl << "[2]Remove an Element from the front" << std::endl
                  << "[3]See the Front of the Queue"<< std::endl << "[4]Size" << std::endl
                  << "[5]Clear All" << std::endl << "[6]is Empty?" << std::endl;
        std::cin >> scelta;
        switch (scelta) {
            case 0:
                std::cout<<"Bye";
                break;
            case 1:
                std::cout<<"Element to add:"<<std::endl;

                std::cin>>element;
                queueLst.Enqueue(element);
                break;
            case 2:
                std::cout<<"[1]Just Remove"<<std::endl<<"[2]Remove and see"<<std::endl;
                int rmv;
                std::cin>>rmv;
                switch (rmv) {
                    case 1:
                        queueLst.Dequeue();
                        break;
                    case 2:
                        std::cout<<"This is the element:"<<std::endl;
                        std::cout<<queueLst.HeadNDequeue()<<std::endl;
                        break;
                }
                break;
            case 3:
                std::cout<<queueLst.Front()<<std::endl;
                break;
            case 4:
                std::cout<<queueLst.Size();
                break;
            case 5:
                queueLst.Clear();
                std::cout<<"Cleared All"<<std::endl;
                break;
            case 6:
                if(queueLst.Empty() == true){
                    std::cout<<"Yes, it's Empty"<<std::endl;
                }else{
                    std::cout<<"No, it's not Empty"<<std::endl;
                }
                break;
        }
    }
}

template <typename Data>
void startQueueVec(){
    srand(time(nullptr));
    QueueVec<Data> queueVec;
    popolaQueue(queueVec);
    int scelta = -1;
    Data element;
    while(scelta != 0) {
        std::cout << "\n[0]Cancel" << std::endl << "[1]Add Element to the tail" << std::endl << "[2]Remove an Element from the front" << std::endl
                  << "[3]See the Front of the Queue"<< std::endl << "[4]Size" << std::endl
                  << "[5]Clear All" << std::endl << "[6]is Empty?" << std::endl;
        std::cin >> scelta;
        switch (scelta) {
            case 0:
                std::cout<<"Bye";
                break;
            case 1:
                std::cout<<"Element to add:"<<std::endl;
                std::cin>>element;
                queueVec.Enqueue(element);
                break;
            case 2:
                std::cout<<"[1]Just Remove"<<std::endl<<"[2]Remove and see"<<std::endl;
                int rmv;
                std::cin>>rmv;
                switch (rmv) {
                    case 1:
                        queueVec.Dequeue();
                        break;
                    case 2:
                        std::cout<<"This is the element:"<<std::endl;
                        std::cout<<queueVec.HeadNDequeue()<<std::endl;
                        break;
                }
                break;
            case 3:
                std::cout<<queueVec.Front()<<std::endl;
                break;
            case 4:
                std::cout<<queueVec.Size();
                break;
            case 5:
                queueVec.Clear();
                std::cout<<"Cleared All"<<std::endl;
                break;
            case 6:
                if(queueVec.Empty() == true){
                    std::cout<<"Yes, it's Empty"<<std::endl;
                }else{
                    std::cout<<"No, it's not Empty"<<std::endl;
                }
                break;
        }
    }
}

template <typename Data>
void startStackLst(){
    srand(time(nullptr));
    StackLst<Data> stackLst;
    popolaStack(stackLst);
    int scelta = -1;
    Data element;
    while(scelta != 0) {
        std::cout << "\n[0]Cancel" << std::endl << "[1]Add Element to the front" << std::endl << "[2]Remove an Element from the front" << std::endl
                  << "[3]See the Front of the Queue"<< std::endl << "[4]Size" << std::endl
                  << "[5]Clear All" << std::endl <<"[6]is Empty?"<<std::endl;
        std::cin >> scelta;
        switch (scelta) {
            case 0:
                std::cout<<"Bye";
                break;
            case 1:
                std::cout<<"Element to add:"<<std::endl;
                std::cin>>element;
                stackLst.Push(element);
                break;
            case 2:
                std::cout<<"[1]Just Remove"<<std::endl<<"[2]Remove and see"<<std::endl;
                int rmv;
                std::cin>>rmv;
                switch (rmv) {
                    case 1:
                        stackLst.Pop();
                        break;
                    case 2:
                        std::cout<<"This is the element:"<<std::endl;
                        std::cout<<stackLst.TopNPop()<<std::endl;
                        break;
                }
                break;
            case 3:
                std::cout<<stackLst.Top()<<std::endl;
                break;
            case 4:
                std::cout<<stackLst.Size();
                break;
            case 5:
                stackLst.Clear();
                std::cout<<"Cleared All"<<std::endl;
                break;
            case 6:
                if(stackLst.Empty() == true){
                    std::cout<<"Yes, it's Empty"<<std::endl;
                }else{
                    std::cout<<"No, it's not Empty"<<std::endl;
                }
                break;
        }
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

void popolaStack(Stack<int>& s){
    for (int i = 0; i < menu.getSize(); ++i) {
        s.Push(rand() % 101);
    }
}
void popolaStack(Stack<float>& s){
    for (int i = 0; i < menu.getSize(); ++i) {
        s.Push((float)rand()/(float)(RAND_MAX/rand()));
    }
}

void popolaStack(Stack<std::string>& s){
    for(int i = 0; i <menu.getSize(); ++i){
        s.Push(random_string((rand() % 12)+ 1));
    }
}

void popolaQueue(Queue<int>& q){
    for (int i = 0; i < menu.getSize(); ++i) {
        q.Enqueue(rand() % 101);
    }
}
void popolaQueue(Queue<float>& s){
    for (int i = 0; i < menu.getSize(); ++i) {
        s.Enqueue((float)rand()/(float)(RAND_MAX/rand()));
    }
}

void popolaQueue(Queue<std::string>& q){
    for(int i = 0; i <menu.getSize(); ++i){
        q.Enqueue(random_string((rand() % 12)+ 1));
    }
}

template <typename Data>
void startStackVec(){
    srand(time(nullptr));
    StackVec<Data> stackVec;
    popolaStack(stackVec);
    int scelta = -1;
    Data element;
    while(scelta != 0) {
        std::cout << "\n[0]Cancel" << std::endl << "[1]Add Element to the front" << std::endl << "[2]Remove an Element from the front" << std::endl
                  << "[3]See the Front of the Queue"<< std::endl << "[4]Size" << std::endl
                  << "[5]Clear All" << std::endl <<"[6]is Empty?" << std::endl;
        std::cin >> scelta;
        switch (scelta) {
            case 0:
                std::cout<<"Bye";
                break;
            case 1:
                std::cout<<"Element to add:"<<std::endl;
                std::cin>>element;
                stackVec.Push(element);
                break;
            case 2:
                std::cout<<"[1]Just Remove"<<std::endl<<"[2]Remove and see"<<std::endl;
                int rmv;
                std::cin>>rmv;
                switch (rmv) {
                    case 1:
                        stackVec.Pop();
                        break;
                    case 2:
                        std::cout<<"This is the element:"<<std::endl;
                        std::cout<<stackVec.TopNPop()<<std::endl;
                        break;
                }
                break;
            case 3:
                std::cout<<stackVec.Top()<<std::endl;
                break;
            case 4:
                std::cout<<stackVec.Size();
                break;
            case 5:
                stackVec.Clear();
                std::cout<<"Cleared All"<<std::endl;
                break;
            case 6:
               if(stackVec.Empty() == true){
                   std::cout<<"Yes, it's Empty"<<std::endl;
               }else{
                   std::cout<<"No, it's not Empty"<<std::endl;
               }
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
                  << "[2]Choose Struct (List or Vector)" << std::endl;
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
                chooseStruct();
                switch (menu.getClasse()) {
                    case 1: //Vettore
                        std::cout << "Your Vector will be populated with random elements, choose a size."
                                  << std::endl << "Size: (digit a number > 0! not characters!)" << std::endl;
                        std::cin >> strutt_size;
                        menu.setSize(strutt_size);
                        if (menu.getTipo() == 3) {
                            if (menu.getStruttura() == 1) {
                                startStackVec<std::string>();
                            } else {
                                startQueueVec<std::string>();
                            }
                        } else if(menu.getTipo() == 1){
                            if (menu.getStruttura() == 1) {
                                startStackVec<int>();
                            } else {
                                startQueueVec<int>();
                            }
                        }else if(menu.getTipo() == 2){
                            if (menu.getStruttura() == 1) {
                                startStackVec<float>();
                            } else {
                                startQueueVec<float>();
                            }
                        }
                        break;
                    case 2: //Lista
                        std::cout << "Your List will be populated with random elements, choose a size." << std::endl
                                  << "Size: (digit a number > 0! not characters!)" << std::endl;
                        std::cin >> strutt_size;
                        menu.setSize(strutt_size);
                        if (menu.getTipo() == 3) {
                            if (menu.getStruttura() == 1) {
                                startStackLst<std::string>();
                            } else {
                                startQueueLst<std::string>();
                            }
                        } else if(menu.getTipo() == 1){
                            if (menu.getStruttura() == 1) {
                                startStackLst<int>();
                            } else {
                                startQueueLst<int>();
                            }
                        }else if(menu.getTipo() == 2){
                            if (menu.getStruttura() == 1) {
                                startStackLst<float>();
                            } else {
                                startQueueLst<float>();
                            }
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