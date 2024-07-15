#include <test.hpp>
#include "test.hpp"
#include <random>
#include <ctime>
#define MaxString 12
#define MaxInt 1001

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


void chooseStruct(){
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
template<typename Data>
void printElement(const Data& dato, void * _){
     std::cout<<dato<<" ";
 }

template<typename Data>
void raisedToSecond(Data& dato, void * _){
    dato *= dato;
}

template<typename Data>
void func_2n(Data& dato, void * _){
    dato *= 2;
}

void stringConcatenate(const std::string& dat, const void* _, void* acc) {
    if(dat.size() <= *((int*)_)){
        ((std::string*) acc)->append(dat);
    }
}

template<typename Data>
void sumMinors(const Data& dat, const void* _, void* acc) {
  if(dat < *((int*) _)){
      *((int*) acc) += dat;
  }
}

template<typename Data>
void productMinors(const Data& dat, const void* _, void* acc) {
    if(dat > *((int*) _)){
        *((float*) acc) *= dat;
    }
}

char to_upper(char &ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch - 32;
    return ch;
}


void toUpper(std::string& strg, void* _){
    for(int i = 0; i < strg.size(); ++i) {
        strg[i] = to_upper(strg[i]);
    }
}

std::string random_string(unsigned long length)
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string random_string;
    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[rand() % CHARACTERS.size()];
    }
    return random_string;
}



void strngStruct(){
     if(menu.getClasse()==1){
                                            /***************************Vettore****************************/
         Vector<std::string> vecc(menu.getSize());
         srand(time(nullptr));
         for(int i = 0; i < vecc.Size(); ++i){
             vecc[i] = random_string((rand() % MaxString)+ 1);
         }
         int scelta = -1;
         unsigned long element;

         while(scelta != 0) {
             std::cout<<"\n[0]Cancel"<<std::endl<<"[1]View Elements"<<std::endl<<"[2]View an Element"<<std::endl
                      <<"[3]Choose an element and see if it exists"<<std::endl<<"[4]Calculate functions"<<std::endl
                      <<"[5]Apply function"<<std::endl<<"[6]Resize"<<std::endl;
             std::cin>>scelta;
             std::string concat = "";
             std::string exsts;
             switch (scelta) {
                 case 0:
                     std::cout<<"Bye!"<<std::endl;
                     break;
                 case 1: //visualizza elementi
                     vecc.MapPreOrder(&printElement<std::string>, nullptr);
                     break;
                 case 2: //visualizza elemento
                     std::cout << "N. of the Element:" << std::endl;
                     std::cin >> element;
                     if (0 < element <= vecc.Size()) {
                         printElement(vecc[element - 1], nullptr);
                     } else {
                         std::cout << "U pressed not a valid key";
                     }
                     break;
                 case 3://exists?
                     std::cout << "Write a digit and I will tell you if it exists:" << std::endl;
                     bool esiste;
                         std::cin >> exsts;
                         if (vecc.Exists(exsts) == true) {
                             esiste = true;
                         } else {
                             esiste = false;
                         }
                     std::cout<<"The element"<<(esiste ? " " : " doesn't ")<< "exists"<<std::endl;
                     break;
                 case 4:
                    //Concatenazione string
                    std::cout<<"Choose the size Max for the concatenation:"<<std::endl;
                    int n;
                    std::cin>>n;
                    vecc.FoldPreOrder(&stringConcatenate, &n , &concat);
                    std::cout<<"The element concatenated:"<<std::endl;
                    std::cout<<concat;
                    break;
                 case 5:
                   //Uppercase string
                   vecc.MapPreOrder(&toUpper, nullptr);
                   std::cout<<"Applied the Upper function";
                     break;
                 case 6:
                     //Resize
                     unsigned long new_size;
                     std::cout<<"Insert the new Value of the vector:"<<std::endl;
                     std::cin>>new_size;
                     vecc.Resize(new_size);
                     break;
             }
         }
     }                                       /*********************Lista**********************/
     else if(menu.getClasse()==2){
         List<std::string> lst;
         srand(time(nullptr));
         for(int i = 0; i < menu.getSize(); ++i) {
             lst.InsertAtFront(random_string((rand() % MaxString) + 1));
         }
             int scelta = -1;
             unsigned long element;
             while(scelta != 0) {
                 std::cout<<"\n[0]Cancel"<<std::endl<<"[1]View Elements"<<std::endl<<"[2]View an Element"<<std::endl
                          <<"[3]Choose an element and see if it exists"<<std::endl<<"[4]Calculate functions"<<std::endl
                          <<"[5]Apply function"<<std::endl<<"[6]Add Element"<<std::endl<<((menu.getSize() == 0) ? "" : "[7]Delete Element")<<std::endl;
                 std::cin>>scelta;
                 std::string exsts;
                 std::string concat = "";
                 std::string elemAdded = "";
                 switch (scelta) {
                     case 0:
                         std::cout<<"Bye!"<<std::endl;
                         break;
                     case 1: //visualizza elementi
                         lst.MapPreOrder(&printElement<std::string>, nullptr);
                         break;
                     case 2: //visualizza elemento
                         std::cout << "N. of the Element:" << std::endl;
                         std::cin >> element;
                         if (0 < element <= lst.Size()) {
                             printElement(lst[element - 1], nullptr);
                         } else {
                             std::cout << "U pressed not a valid key"<<std::endl;
                         }
                         break;
                     case 3://exists?
                         std::cout << "Write a digit and I will tell you if it exists:" << std::endl;
                         bool esiste;
                         std::cin >> exsts;
                         if (lst.Exists(exsts) == true) {
                             esiste = true;
                         } else {
                             esiste = false;
                         }
                         std::cout<<"The element"<<(esiste ? " " : " doesn't ")<< "exists"<<std::endl;
                         break;
                     case 4:
                         //Concatenazione string
                         std::cout<<"Choose the size Max for the concatenation:"<<std::endl;
                         int n;
                         std::cin>>n;
                         lst.FoldPreOrder(&stringConcatenate, &n , &concat);
                         std::cout<<"The element concatenated:"<<std::endl;
                         std::cout<<concat;
                         break;
                     case 5:
                         //Uppercase string
                         lst.MapPreOrder(&toUpper, nullptr);
                         std::cout<<"Applied the Upper function"<<std::endl;
                         break;
                     case 6:
                         //Aggiunta Elementi
                         int headOrQ;
                         std::cout<<"[1]Add in the Head"<<std::endl<<"[2]Add in the Queue"<<std::endl;
                         std::cin>>headOrQ;
                         std::cout<<"Write the element:"<<std::endl;
                         std::cin>>elemAdded;
                         switch(headOrQ){
                             case 1:
                                 lst.InsertAtFront(elemAdded);
                                 break;
                             case 2:
                                 lst.InsertAtBack(elemAdded);
                                 break;
                         }
                         break;
                     case 7:
                         int rmv;
                         std::cout<<"From The Head:"<<std::endl<<"[1]Remove and see the element"<<std::endl<<"[2]Just Remove"<<std::endl;
                         std::cin>>rmv;
                         std::string elem;
                         //Eliminazione Elementi
                         switch (rmv) {
                             case 1:
                                 elem = lst.FrontNRemove();
                                 std::cout<<"The Element:"<<std::endl;
                                 std::cout<<elem;
                                 break;
                             case 2:
                                 lst.RemoveFromFront();
                                 break;
                         }
                         break;
                 }
             }


         }
     }



template<typename Data>
void startTheStruct(){
                                     /************************VETTORE********************************/
    if(menu.getClasse() == 1){ //Vettore
        Vector<Data> vecc(menu.getSize());
        srand(time(nullptr));
        if(menu.getTipo() == 1){ //int
            for(int i = 0; i < vecc.Size(); ++i){
                vecc[i] = rand() % MaxInt;
            }
        }else if(menu.getTipo() == 2){ //float
            for(int i = 0; i < vecc.Size(); ++i){
                vecc[i] = (float)rand()/(float)(RAND_MAX/rand());
            }
        }
        int scelta = -1;
        unsigned long element;
        while(scelta != 0) {
            std::cout<<"\n[0]Cancel"<<std::endl<<"[1]View Elements"<<std::endl<<"[2]View an Element"<<std::endl
                     <<"[3]Choose an element and see if it exists"<<std::endl<<"[4]Calculate functions"<<std::endl
                     <<"[5]Apply function"<<std::endl<<"[6]Resize"<<std::endl;
            std::cin>>scelta;
            int integersReturned = 0;
            float floatReturned = 1;
            switch (scelta) {
                case 0:
                    std::cout<<"Bye!"<<std::endl;
                    break;
                case 1: //visualizza elementi
                      vecc.MapPreOrder(&printElement<Data>, nullptr);
                    break;
                case 2: //visualizza elemento
                    std::cout << "N. of the Element:" << std::endl;
                    std::cin >> element;
                    if (0 < element <= vecc.Size()) {
                        printElement(vecc[element - 1], nullptr);
                    } else {
                        std::cout << "U pressed a not valid key";
                    }
                    break;
                case 3://exists?
                    std::cout << "Write a digit and I will tell you if it exists:" << std::endl;
                    bool esiste;
                    if (menu.getTipo() == 1) {
                        int exsts;
                        std::cin >> exsts;
                        if (vecc.Exists(exsts) == true) {
                            esiste = true;
                        } else {
                            esiste = false;
                        }
                    } else if (menu.getTipo() == 2) {
                        float exsts;
                        std::cin >> exsts;
                        if (vecc.Exists(exsts) == true) {
                            esiste = true;
                        } else {
                            esiste = false;
                        }
                    } else if ((menu.getTipo() == 3)) {
                        int exsts;
                        std::cin >> exsts;
                        if (vecc.Exists(exsts) == true) {
                            esiste = true;
                        } else {
                            esiste = false;
                        }
                    }
                    std::cout<<"The element"<<(esiste ? " " : " doesn't ")<< "exists"<<std::endl;
                    break;
                case 4:
                    unsigned long n;

                    if(menu.getTipo()==1){ //interi < di n
                        std::cout<<"Choose a number -> N <- and I'll return you: Sum(Integers < N):"<<std::endl;
                        std::cin>>n;
                        vecc.FoldPreOrder(&sumMinors<int>, &n,&integersReturned );
                        std::cout<<"Sum(Integers < N):"<<std::endl;
                        std::cout<<integersReturned;
                    }else if(menu.getTipo()==2) { //prodotto float > n
                        std::cout<<"Choose a number -> N <- and I'll return you: Product(Float > N):"<<std::endl;
                        std::cin>>n;
                        vecc.FoldPreOrder(&productMinors<float>, &n,&floatReturned);
                        std::cout<<"Product(Float > N):"<<std::endl;
                        std::cout<<floatReturned;
                    }
                    break;
                case 5:
                    if(menu.getTipo()==1){

                        vecc.MapPreOrder(&func_2n<Data>, nullptr);
                        std::cout<<"Applied the 2n function for the int";

                    }else if(menu.getTipo()==2){

                        vecc.MapPreOrder(&raisedToSecond<Data>, nullptr);
                        std::cout << "Applied the n^2";
                    }
                    break;
                case 6:
                    //Resize
                    unsigned long new_size;
                    std::cout<<"Insert the new Value of the vector:"<<std::endl;
                    std::cin>>new_size;
                    vecc.Resize(new_size);
                    break;

            }
        }
                                            /****************************LISTA******************************/
    }else if(menu.getClasse() == 2){ //Lista
        List<Data> lst;
        srand(time(nullptr));
        if(menu.getTipo() == 1){ //int
            for(int i = 0; i < menu.getSize(); ++i){

                lst.InsertAtFront(rand() % MaxInt);
            }
        }else if(menu.getTipo() == 2){ //float
            for(int i = 0; i < menu.getSize(); ++i){
                lst.InsertAtFront((float)rand()/(float)(RAND_MAX/rand()));
            }
        }else if(menu.getTipo() == 3){ //char
            for(int i = 0; i < menu.getSize(); ++i){
                lst.InsertAtFront((char) rand());
            }
        }
        int scelta = -1;
        unsigned long element;
        while(scelta != 0) {
            std::cout << "\n[0]Cancel" << std::endl << "[1]View Elements" << std::endl << "[2]View an Element"
                      << std::endl << "[3]Choose an element and see if it exists" << std::endl
                      << "[4]Calculate functions" << std::endl << "[5]Apply function" << std::endl
                      <<"[6]Add Element"<<std::endl<<((menu.getSize() == 0) ? "" : "[7]Delete Element")<<std::endl;
            std::cin >> scelta;
            float floatReturned = 1;
            int integersReturned = 0;
            switch (scelta) {
                case 0:
                    std::cout << "\nBye!" << std::endl;
                    break;
                case 1: //visualizza elementi
                    lst.MapPreOrder(&printElement<Data>, nullptr);
                    break;
                case 2: //visualizza elemento
                    std::cout << "N. of the Element:" << std::endl;
                    std::cin >> element;
                    if (0 < element <= lst.Size()) {
                        printElement(lst[element - 1], nullptr);
                    } else {
                        std::cout << "U pressed a not valid key";
                    }
                    break;
                case 3://exists?
                    std::cout << "Write a digit and I will tell you if it exists:" << std::endl;
                    bool esiste;
                    if (menu.getTipo() == 1) {
                        int exsts;
                        std::cin >> exsts;
                        if (lst.Exists(exsts) == true) {
                            esiste = true;
                        } else {
                            esiste = false;
                        }
                    } else if (menu.getTipo() == 2) {
                        float exsts;
                        std::cin >> exsts;
                        if (lst.Exists(exsts) == true) {
                            esiste = true;
                        } else {
                            esiste = false;
                        }
                    } else if ((menu.getTipo() == 3)) {
                        char exsts;
                        std::cin >> exsts;
                        if (lst.Exists(exsts) == true) {
                            esiste = true;
                        } else {
                            esiste = false;
                        }
                    }
                    std::cout << "The element" << (esiste ? " " : " doesn't ") << "exists" << std::endl;
                    break;
                case 4:
                    unsigned long n;
                    if(menu.getTipo()==1){ //interi < di n
                        std::cout<<"Choose a number -> N <- and I'll return you: Sum(Integers < N):"<<std::endl;
                        std::cin>>n;
                        lst.FoldPreOrder(&sumMinors<int>, &n,&integersReturned );
                        std::cout<<"Sum(Integers < N):"<<std::endl;
                        std::cout<<integersReturned;
                    }else if(menu.getTipo()==2) { //prodotto float > n
                        std::cout<<"Choose a number -> N <- and I'll return you: Product(Float > N):"<<std::endl;
                        std::cin>>n;
                        lst.FoldPreOrder(&productMinors<float>, &n,&floatReturned);
                        std::cout<<"Product(Float > N):"<<std::endl;
                        std::cout<<floatReturned;
                    }
                    break;
                case 5:
                    if (menu.getTipo() == 1) {

                        lst.MapPreOrder(&func_2n<Data>, NULL);
                        std::cout << "Applied the 2n function for the int";
                    } else if (menu.getTipo() == 2) {

                        lst.MapPreOrder(&raisedToSecond<Data>, NULL);
                        std::cout << "Applied the n^2";
                    }
                    break;
                case 6:
                    //Aggiunta Elementi
                    int headOrQ;
                    std::cout<<"[1]Add in the Head"<<std::endl<<"[2]Add in the Queue"<<std::endl;
                    std::cin>>headOrQ;
                    std::cout<<"Write the element:"<<std::endl;
                    Data c;
                    std::cin>>c;
                    switch(headOrQ){
                        case 1:
                            lst.InsertAtFront(c);
                            break;
                        case 2:
                           lst.InsertAtBack(c);
                            break;
                    }
                    break;
                case 7:
                    int rmv;
                    std::cout<<"From The Head:"<<std::endl<<"[1]Remove and see the element"<<std::endl<<"[2]Just Remove"<<std::endl;
                    std::cin>>rmv;
                    Data elem;
                    //Eliminazione Elementi
                    switch (rmv) {
                        case 1:
                            elem = lst.FrontNRemove();
                            std::cout<<"The Element:"<<std::endl;
                            std::cout<<elem;
                            break;
                        case 2:
                            lst.RemoveFromFront();
                            break;
                    }
                    break;
            }
        }
    }
}



void launchMenu(){
    unsigned long menuChoosing;
    unsigned long exitMenu;
    coutRighe(3);
    coutAst(10);
    std::cout<<" ~Welcome to the Menu of Francesco De Stasio~ ";
    coutAst(10);
    coutRighe(3);
    unsigned long strutt_size;
    while(menuChoosing != 0){
        std::cout<<"\nChoose an option:"<<std::endl<<"[0]Quit"<<std::endl<<"[1]Start Test"<<std::endl<<"[2]Choose Struct (List or Vector)"<<std::endl;
        std::cin >> menuChoosing;
        switch (menuChoosing) {
            case 0:
                std::cout<<"GoodBye";
                exitMenu = 2;
                break;
            case 1:
                lasdtest();
                break;
            case 2:
                chooseStruct();
                switch (menu.getClasse()) {
                    case 1: //Vettore
                        std::cout << "Your Vector will be populated with random elements, choose a size."
                        << std::endl << "Size: (digit a number > 0! not characters!)" << std::endl;
                        std::cin >> strutt_size;
                        menu.setSize(strutt_size);
                        break;
                    case 2: //Lista
                        std::cout << "Your List will be populated with random elements, choose a size." << std::endl
                                  << "Size: (digit a number > 0! not characters!)" << std::endl;
                        std::cin >> strutt_size;
                        menu.setSize(strutt_size);
                }
                if(menu.getTipo() == 1){
                    startTheStruct<int>();
                }else if(menu.getTipo() == 2){
                    startTheStruct<float>();
                }else if(menu.getTipo() == 3){
                    strngStruct();
                }
                break;
            default:
                std::cout<<"Ooops, you pressed a wrong key, you want go back? [1]Yes, sorry.. [2]No, let me quit"<<std::endl;
                std::cin>>exitMenu;
                switch(exitMenu){
                    case 1:
                        break;
                    case 2:
                        std::cout<<"GoodBye!!";
                        menuChoosing = 0;
                        break;
                    default:
                        std::cout<<"Pay Attention next time!";
                        menuChoosing = 0;
                        break;
                }
        }
    }
}
