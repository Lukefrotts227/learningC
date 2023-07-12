#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

class Employee{

    private: 
        string name; 
        string position; 
        int id; 

    public: 
        Employee(string n, string p, int i)
        {
            name = n; 
            position = p; 
            id = i; 

        }
        string getName(){
            return name; 
        }

        string getPosition(){
            return position; 
        }

        int getId(){
            return id; 
        }


};

class Company{

    private: 
        string name; 
        vector<Employee> employees;


    public: 
        string getName(){
            return name; 
        }

        vector<Employee> getEmpolyees(){
            return employees; 
        }

};


int main(void){

    // return value of 0 is success in program
    return 0; 
}