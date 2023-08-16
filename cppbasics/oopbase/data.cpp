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

        void printList(){
            Node * current = head; 
            while(current != nullptr){
                cout << current->data << " "; 
                current = current->next; 

            }
            cout << "\n"; 
        }

        

};

int main(void){

    LinkedList list; 
    list.prepend("billy");
    list.prepend("johnny"); 
    list.printList();
    list.prepend("Jane"); 
    list.prepend("Jill"); 
    list.printList(); 

    return 0; 

}