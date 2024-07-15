
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>
#include <random>
#define seed 23141232
/* ************************************************************************** */
using namespace lasd;
using namespace std;
enum Action{
    Predecessore,
    Successore,
    Insert,
    TestCopy,
    TestMove
};


template<typename Data>
void printElement(const Data& dato, void * _){
    std::cout<<dato<<" | ";
}

default_random_engine gen(seed);
uniform_int_distribution<unsigned int> distr0_100(0, 100);
uniform_int_distribution<unsigned int> distr0_4(0, 4);
int main() {
  std::cout << "Lasd Libraries 2020" << std::endl;
 // launchMenu(); // To call in the menu of your library test!
    BST<int> bst;
    BST<int> bst1;
    unsigned long err = 0, test = 0;


    for (int j = 1; j <= 1000; ++j) {
        auto action = static_cast<Action>(distr0_4(gen));
        cout<<"["<<j<<"] ";
        if(action == Insert){
            unsigned long nELements = distr0_100(gen)/3;
            cout<<"Insert "<< nELements << " values"<< endl;
            for (int k = 0; k < nELements; ++k) {
                unsigned long num = distr0_100(gen);
                cout<<"\tInsert "<<num<<"in ("<< "bst"<<") ";
                bst.Insert(num);
                cout<<" ok"<<endl;
                cout<<"\tInsert "<<num<<"in ("<< "bst1"<<") ";
                bst1.Insert(num);
                cout<<" ok"<<endl;
                ++test;
                if(bst != bst1){
                    cout << "Errore, gli alberi non sono uguali"<< endl;
                    ++err;
                }
            }
            cout<<"ok"<<endl;
        }else if(action == TestMove){
            cout<< "Test Move";
            BST<int> bst_copy(bst);
            BST<int> bst1_copy(bst1);

            BST<int> bst_move(move(bst_copy));
            BST<int> bst1_move(move(bst1_copy));
            ++test;
            if(bst1_move != bst_move){
                err++;
                cout<< "Gli alberi spostati con il costruttore sono diversi! (bst1_move != bst_move)"<<endl;
            }test++;
            if(bst != bst_move){
                err++;
                cout<< "Gli alberi spostati con il costruttore sono diversi! (bst != bst_move)"<<endl;
            }test++;
            if(bst1 != bst1_move){
                err++;
                cout<< "Gli alberi spostati con il costruttore sono diversi! (bst1 != bst1_move)"<<endl;
            }test++;
            bst = move(bst_move);
            bst1 = move(bst1_move);
            test++;
            if(bst != bst1){
                err++;
                cout<< "Gli alberi spostati per assegnazione sono diversi!"<<endl;
            }

        }else if(action == TestCopy){
            cout<<"Test Copy";
            BST<int> bst_copy(bst);
            BST<int> bst1_copy(bst1);
            unsigned int nElements = distr0_100(gen)/3;
            for (int k = 0; k < nElements; k++) {
                int num = distr0_100(gen);

                bst.Insert(num);
                bst1.Insert(num);

                bst_copy.Insert(num);
                bst1_copy.Insert(num);

            }
            ++test;

            if(bst_copy != bst1_copy){
                ++err;
                cout<< "Gli alberi copiati col costruttore sono diversi! (bst_copy != bst1_copy)"<<endl;
            } test++;
            if(bst != bst_copy){
                ++err;
                cout<< "Gli alberi copiati col costruttore sono diversi! (bst != bst_copy)"<<endl;
            } test++;
            if(bst1 != bst1_copy){
                +err;
                cout<< "Gli alberi copiati col costruttore sono diversi! (bst1 != bst1_copy)"<<endl;
            } test++;

            bst_copy = bst;
            bst1_copy = bst1;
            test++;
            if(bst_copy != bst1_copy){
                cout<< "Gli alberi copiati per assegnazione sono diversi!"<<endl;
                err++;
            }
            cout<< " ok"<<endl;
            ++test;

        }else if(action == Predecessore){
            cout<< "Predecessore Test"<<endl;
            unsigned int r = distr0_100(gen);
            cout<<"BST"<<"\t";
            bst.MapInOrder(&printElement<int>, nullptr);
            cout<<endl;
            cout<<"BST1"<<"\t";
            bst1.MapInOrder(&printElement<int>, nullptr);
            cout<<endl;
            try{
              cout<<"Predecessor of "<<r<<"is ->" << bst.Predecessor(r);
            }catch(length_error e){
                cout<<"length error Successor"<<endl;
            }
            ++test;
        }else if(action == Successore){
            cout<< "Successore Test"<<endl;
            unsigned int r = distr0_100(gen); cout<<"BST"<<"\t";
            bst.MapInOrder(&printElement<int>, nullptr);
            cout<<endl;
            cout<<"BST1"<<"\t";
            bst1.MapInOrder(&printElement<int>, nullptr);
            cout<<endl;
            try{
                cout<<"Successor of "<<r<<"is ->" << bst.Successor(r);
                cout<<" ok"<<endl;
            }catch(length_error e){
                cout<<"length error Successor"<<endl;
            }
            ++test;
        }
    }
    cout << "End. errors/tests: "<< err << "/" << test << endl;
  return 0;
}
/***************************************************************************************************/

int main(){
     std::cout << "Lasd Libraries 2020" << std::endl;
     launchMenu(); // To call in the menu of your library test!
     return 0;
}
