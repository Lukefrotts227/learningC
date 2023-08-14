#include <iostream> 
#include <memory> 
#include <string> 
#include <cstdlib> 


using namespace std; 

class MyClass{
    private:
        int data; 
        string name; 
    public: 
        MyClass(int d, string n) : data(d), name(n) {}

        int getData(){
            return data;
        }
        string getName(){
            return name; 
        }
        void setData(int d){
            data = d;
        }

        void setName(string n){
            name = n; 
        }
        void showClass(){
            cout << "name: " << name << " data: " << data << "\n"; 
        }
}; 


int main(void){
    int size; 
    cout << "Enter the size: "; 
    cin >> size; 

    unique_ptr<MyClass*[]> ptr(new MyClass*[size]);
    int tempI; 
    string tempS;

    for (int i = 0; i < size; i++){
        cout << "Enter the number data: ";
        cin >> tempI; 
        cout << "Enter the name: "; 
        cin >> tempS; 
        
        ptr[i] =  new MyClass(tempI, tempS); 
    }

    for (int i = 0; i < size; i++){
        ptr[i]->showClass();
    }

    return 0; 
}