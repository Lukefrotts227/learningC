#include <iostream> 
#include <string> 


using namespace std; 


class Creature{

    private: 
        string name; 
        double height; 
        double weight;
    public:  
        Creature(string n, double h, double w){
            name = n; 
            height = h; 
            weight = w; 
        }

        void sound()
        {
            cout << "I am making a sound \n"; 
        }
}; 

class Dog : Creature {

    public: 
        void bark(){
            cout << "woof \n";
        }

}; 



int main(void)
{

    return 0; 
}