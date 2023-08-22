#include <iostream> 
#include <string> 

class Person{

    std::string name; 
    int age; 

    public: 
        Person(std::string n, int a) : name(n), age(a){}

        Person& operator--(){
            age--; 
            return *this; 
        }
        Person& operator++(){
            age++; 
            return *this; 
        }

        Person operator--(int){
            Person temp = *this; 
            age--; 
            return temp; 
        }

        Person operator++(int){
            Person temp = *this; 
            age++; 
            return temp; 
        }

        void display(){
            std::cout << name << " is " << age << " years old\n"; 
        }

}; 



int main(){
    Person bill("Bill", 29); 
    bill.display(); 
    --bill; 
    bill.display(); 
    ++bill; 
    bill++; 
    bill++; 
    bill.display(); 

    return 0; 
}