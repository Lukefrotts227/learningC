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

        Node<Data> * insert(Node<Data> * node, const Data& data){
            if(node == nullptr){
                return new Node<Data>(data); 
            }

            if(data < node->data){
                node->left = insert(node->left, data); 
            }else if(data > node-> data){
                node->right = insert(node->right, data); 
            }

            return node; 
        }

    public: 
        Tree() : root(nullptr){}



        bool insert(const Data& data){
            
            root = insert(root, data); 
        
        }


        void print(){
            
        }

};