#include <iostream> 
#include <memory> 
#include <string> 
#include <vector>


using namespace std; 




template <typename Key, typename Data>
class Node{
    public: 
        Key key;
        Data data; 
        Node * next; 

        Node(const Key& n, const Data& val) : key(n), data(val), next(nullptr)

}; 

template <typename Key, typename Data>
class Table{
    private: 
        unsigned int size; 
        Node<Key, Data> * table; 
        unsigned int (*hash)(Key key); 

        
    public: 
        Table(unsigned int s, unsigned int(*h)(Key)) : size(s) hash(h){
            table = new Node<Key, Data>[size]; 
        }

        ~Table() {
        delete[] table; 
        }
        unsigned int get_index(const Key& key){
            return hash(key) % size; 
        }

        void insert(const Key& key, const Data& data){
            unsigned int ind =  get_index(key); 

            Node<Key, Data>* newNode = new Node<Key, Data>(key, data); 

            newNode->next = table[ind].next;
            table[ind].next = newNode; 

        }
}; 


int main(){

    return 0; 
}