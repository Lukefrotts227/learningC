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


    public: 
}; 



int main(){

    return 0; 
}