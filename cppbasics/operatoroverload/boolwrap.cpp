#include <iostream> 
#include <string> 

using namespace std; 

class boolean{

    private: 
        bool value; 
    public: 
        boolean(bool val) : value(val){}
        boolean() : value(true) {}

        explicit boolean(int val) : value(val != 0) {}

        operator bool() const {
            return value;
        }

        boolean& operator=(bool val){
            value = val; 
            return *this;
        }



        friend ostream& operator<<(ostream& os, const boolean& obj){
            if(obj.value == true){
                os << "true"; 
            }else{
                os << "false"; 
            }
            return os; 
        }

        bool operator==(const boolean& other) const {
            if(other.value == value){
                return true; 
            }
            return false; 
        }

        bool operator!=(const boolean& other) const {
            if(other.value != value){
                return true; 
            }
            return false; 
        }


}; 


int main(void){

    boolean something; 

    something = true; 

    if(something){
        cout << something << '\n'; 

    }else{
        cout << something << " see it is false \n";
    }

    return 0; 
}