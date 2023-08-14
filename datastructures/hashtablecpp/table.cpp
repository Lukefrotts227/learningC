#include <iostream> 
#include <memory> 
#include <string> 
#include <vector>
#include <typeinfo> 


using namespace std; 


template <typename Key, typename Data>
class Node{
    public: 
        Key key;
        Data data; 
        Node * next; 

        Node(const Key& n, const Data& val) : key(n), data(val), next(nullptr) {}

}; 

template <typename Key, typename Data>
class Table {
    private:
        unsigned int size;
        vector<Node<Key, Data>*> table;
        unsigned int (*hash)(Key key);

    public:
        Table(unsigned int s, unsigned int (*h)(Key)) : size(s), hash(h), table(s, nullptr) {}

        unsigned int get_index(const Key& key) {
            return hash(key) % size;
        }

        void insert(const Key& key, const Data& data) {
            unsigned int ind = get_index(key);

            Node<Key, Data>* newNode = new Node<Key, Data>(key, data);

            newNode->next = table[ind];
            table[ind] = newNode;
        }
        Node<Key, Data>* lookup(const Key& key){
            unsigned int ind = get_index(key); 
            Node<Key, Data>* current = table[ind]; 
            while(current){
                if(current->key == key){
                    return current;
                }
                current = current->next; 
            }
            return nullptr; 
        }

        void del(){

        }

        void Resize(int new_size){
            
        }

        ~Table() {
            for (unsigned int i = 0; i < size; ++i) {
                Node<Key, Data>* current = table[i];
                while (current) {
                    Node<Key, Data>* next = current->next;
                    delete current;
                    current = next;
                }
            }
        }
};


unsigned int hasher(int key) {
    return key * 10 / 323;
}

int main() {

    Table<int, string> hash_table(10, hasher);

    
    return 0;
}