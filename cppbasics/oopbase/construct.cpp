#include <iostream> 
using namespace std; 

class Dog{
    private: 
        char[50] name; 
        int age; 
        int weight; // in kg
    public: 
        Dog(char[50] n, int a, int w){
            name = n; 
            age = a; 
            weight = w;
        }
        Dog(char[50] n){
            name = n; 
            age = 2; 
            weight = 21; 
        }

        void bark(){
            if (weight > 33){
                cout << "WOOF"; 
            }
            else{
                cout << "wuf";
            }
        }
};