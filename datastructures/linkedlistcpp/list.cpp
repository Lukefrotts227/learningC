#include <iostream> 
#include <memory> 
#include <string> 


template <typename Data> 
class Node{
    Data data; 
    Node * prev; 
    Node * next; 

    Node(const Data& d) : Data(d), prev(nullptr) next(nullptr) {}
};


template <typename Data> 
class DoublyLinkedList{
    private: 
        Node<Data> * head; 
        Node<Data> * tail; 
        unsigned int size; 

    public: 
        DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}


        bool append(const Data& data){
            Node<Data> * newNode = new Node<Data>(data); 
        }

        bool prepend(const Data& data){
            Node<Data> * newNode = new Node<Data>(data); 

        }

        bool insert(const Data& data, unsigned int pos){

        }

        bool del(const Data& data){

        }

        bool del_pos(unsigned int pos){
            
        }


        ~DoublyLinkedList(){
            Node<Data>* current = head; 

            while(current){
                Node<Data>* next = current->next;
                delete current; 
                current = next;  
            }
        }
}; 



int main(){

    return 0; 
}