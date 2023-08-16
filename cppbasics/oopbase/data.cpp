#include <iostream> 
#include <string> 


using namespace std; 
class Node{
    public: 
        string data; 

        Node * next; 


        Node(string d, Node * n) : data(d), next(n){}      

}; 

class LinkedList{
    private: 
        Node * head; 

    public: 
        LinkedList() : head(nullptr){}

        ~LinkedList(){
            while(head != nullptr){
                Node * temp = head; 
                head = head->next; 
                delete temp; 
            }
        }

        void prepend(string data){
            Node * newNode = new Node(data, head); 
            head = newNode; 
        }

        

}

int main(void){

}