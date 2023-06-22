#include <iostream> 
using namespace std; 

class Dog{
    private: 
        string name; 
        int age; 
        int weight; // in kg
    public: 
    
        Dog(string n, int a, int w){
            name = n; 
            age = a; 
            weight = w;
        }
        Dog(string n){
            name = n; 
            age = 2; 
            weight = 21; 
        }

        void bark(){
            if (weight > 33){
                cout << "WOOF\n"; 
            }
            else{
                cout << "wuf\n";
            }
        }
};

int main(void)
{
    Dog barry = Dog("barry", 4, 44); 

    Dog john = Dog("John", 4, 12); 

    barry.bark(); 
    john.bark();

    return 0; 
}