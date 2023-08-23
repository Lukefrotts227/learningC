#include <iostream> 
#include <string> 

using namespace std; 

// lets say we define our own data type

 class Item{
    public: 
        string name; 
        int number; 

    Item(string n, int num) : name(n), number(num){}
    Item(string n) : name(n), number(0){}
    Item(int num) : name("default"), number(num){}
    Item(): name("default"), number(0){}

    // we can define custom operators for it

    friend ostream& operator<<(ostream& os, const Item& obj){
        os << obj.name << " : " << obj.number; 
        return os; 
    }

    Item& operator++(){
        number++; 
        return *this;
    }

    Item& operator--(){
        number--; 
        return *this; 
    }

    Item& operator++(int){
        Item temp = *this; 
        number++; 
        return temp; 
    }

    Item& operator--(int){
        Item temp = *this; 
        number--; 
        return temp; 
    }

    bool operator==(const Item& obj) const{
        return (number == obj.number) && (name == obj.name); 
    }

    bool operator!=(const Item& obj) const{
        return (number != obj.number) || (name != obj.name);
    }


  }; 



  int main(){

  }