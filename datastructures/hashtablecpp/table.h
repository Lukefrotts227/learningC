#include <iostream> 
#include <memory> 
#include <string> 
#include <vector>
#include <typeinfo> 


using namespace std; 

struct Types{
    class StInt{
        public:
            string str; 
            int num;
            StInt(string s, int n) : str(s), num(n){}
    };

    template <typename D1, typename D2>
    class DVect{
        public: 
            vector<D1> vec1; 
            vector<D2> vec2; 

            DVect(const std::vector<D1>& values1, const std::vector<D2>& values2) : vec1(values1), vec2(values2) {}
    };

}; 



struct Hashers{
    unsigned int generic_string_hash_1(string key){
        unsigned int hash_value = 0; 

        for (int i = 0; i < key.size(); i++){
            hash_value += key[i];
            hash_value *= i; 
            hash_value ^= key[i] + (i << 4);     
        }

        return hash_value; 
    }

    unsigned int generic_int_hash_1(int key){
        key = ~key + (key << 15); // Mix bits
        key = key ^ (key >> 12);
        key = key + (key << 2);
        key = key ^ (key >> 4);
        key = key * 2057;
        key = key ^ (key >> 16);
        return key;
    }
}; 


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
        unsigned int get_size(){
            return size;
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
        bool insert(const Key& key, const Data& data) {
            unsigned int ind = get_index(key);

            Node<Key, Data>* findin = this->lookup(key); 
            if(findin != nullptr){
                findin->data = data; 
                return true; 
            }

            Node<Key, Data>* newNode = new Node<Key, Data>(key, data);

            newNode->next = table[ind];
            table[ind] = newNode;
            return true; 
        }

        bool del(const Key& key){
            unsigned int ind = get_index(key); 
            Node<Key, Data>* current = table[ind]; 
            Node<Key, Data>* prev = nullptr; 


            while (current) {
                    if (current->key == key) {
                        if (prev) {
                            prev->next = current->next;
                        } else {
                            table[ind] = current->next;
                        }
                        delete current;
                        return true; 
                    }
                prev = current; 
                current = current->next; 
            }

            return false; 

        }

        
        void resize(int new_size) {
            vector<Node<Key, Data>*> temp = table;

            
            table.clear();

            
            table.resize(new_size, nullptr);

            for (unsigned int i = 0; i < temp.size(); ++i) {
                Node<Key, Data>* current = temp[i];
                while (current) {
                    Node<Key, Data>* next = current->next;
                    insert(current->key, current->data); 
                    current = next;
                }
            }

            size = new_size;
        }

        int getTableSize(){
            return table.size(); 
        }

        void print(bool withNull){

            for(unsigned int i = 0; i < size; i++){
                if(withNull == true || table[i] != nullptr){
                    Node<Key, Data> * ptr = table[i]; 
                    cout << i << ".\t"; 
                    do{ 
                        if(ptr != nullptr){
                            cout << ptr->key << "--"; 
                        }
                        else{
                            cout << "NULL--"; 
                        }
                        ptr = ptr->next; 
                    }while(ptr != nullptr);
                    cout << "\n"; 
                }
            }
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