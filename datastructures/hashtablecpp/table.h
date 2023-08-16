#include <iostream> 
#include <memory> 
#include <string> 
#include <vector>
#include <functional> 
#include <typeinfo> 


using namespace std; 

    class DoubInt{
        public: 
            double doub; 
            int num; 

            DoubInt(double d, int n) : doub(d), num(n){}
    };

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

    unsigned int generic_string_hash_2(string key){
        int hash_value = 0; 
        for(int i = 0; i < key.size(); i++){
           hash_value = hash_value + key[i] ^ (key[i] << 5); 
           hash_value = hash_value * (key[i] * (key[i] << 3)); 
        }

        for(int i = 0; i < (int)key.size()/2; i++){
            hash_value += key[i] << 12; 
            hash_value *= key[i] ^ (hash_value >> 4); 
        }

        return hash_value; 
    } 

    unsigned int built_in_string_hash(string key){
        hash<string> hasher; 
        size_t hash_value = hasher(key); 
        unsigned int new_hash_value = static_cast<unsigned int>(hash_value); 
        return new_hash_value;
    }



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
        unsigned int (*hash_func)(Key key);

    public:
        Table(unsigned int s, unsigned int (*h)(Key)) : size(s), hash_func(h), table(s, nullptr) {}

        unsigned int get_index(const Key& key) {
            return hash_func(key) % size;
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

            unsigned int temper = size; 
            size = new_size; 
            table.resize(new_size, nullptr);

            for (unsigned int i = 0; i < temp.size(); ++i) {
                Node<Key, Data>* current = temp[i];
                while (current) {
                    Node<Key, Data>* next = current->next;
                    this->insert(current->key, current->data); 
                    current = next;
                }
            }

            //size = new_size;
        }

        int getTableSize(){
            return table.size(); 
        }

        void print(bool withNull){

            for(unsigned int i = 0; i < size; i++){
                Node<Key, Data>* ptr = table[i]; 
                if(withNull == true && ptr==nullptr){
                    cout << i << ".\tNULL" << "\n"; 
                    

                }else if (ptr != nullptr){
                    cout << i << "\t";
                    do{
                        if(ptr != NULL){
                            cout << ptr->key << "--"; 

                        }else{
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