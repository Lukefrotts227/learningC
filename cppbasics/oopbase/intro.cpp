#include <iostream> 

using namespace std; 

class Person {
    public: 
        char name[50]; 
        int age; 

};


int main(void)
{
    Person person1; 
    cout << "Enter the name of the person: "; 
    cin >> person1.name; 
    cout << "Enter the age of the person: "; 
    cin >> person1.age; 

    cout << person1.name << " is " << person1.age << " years old!" << endl;
    return 0; 
}