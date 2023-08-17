#include <iostream> 
#include <memory> 
#include <vector> 
#include <string> 


template <typename Data> 
class Node{
    public: 
        Data data; 
        Node * left; 
        Node * right; 

        Node(const Data& value) : data (value), left(nullptr), right(nullptr){}


}; 

template <typename Data> 
class Tree {
    private: 
        Node<Data> * root; 

    public: 
        Tree() : root(nullptr){}

        bool insert(const Data& data){


        
        }

};