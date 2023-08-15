#include <iostream> 
#include <string> 

struct Outer {
    std::string john; 
    
    struct Inner {
        std::string bob;
    };

    class ClassInner { 
        private: 
            std::string name; 
            int number; 

        public: 
            ClassInner(std::string s, int n) : name(s), number(n){}

            std::string getName(){
                return name; 
            }
            int getNumber(){
                return number;
            }

            void setName(std::string str){
                name = str; 
            }

            void setNumber(int n){
                number = n; 
            }


    }; 
};


int main(void){
    Outer out; 
    out.john = "johnny the man"; 

    Outer::Inner in; 
    in.bob = "this is bob"; 

    Outer::ClassInner mine("billy bob john", 283); 

    std::cout << in.bob << " then " << out.john  << " then " << mine.getName() << " then " << mine.getNumber() << " then " <<  "\n"; 

    return 0; 

}