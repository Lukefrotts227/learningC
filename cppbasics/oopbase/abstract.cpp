#include <iostream> 
#include <string> 
using namespace std;

class Human {
    private: 
        string name; 
        int height; 
        int weight; 

    public: 
        virtual void speak(){
            cout << " I am a human \n"; 
        }
};


class Child : Human {}; 

class Teacher : Human {}; 

class Engineer : Human {};

int main(int argc, char *argv[])
{

    return 0;
}