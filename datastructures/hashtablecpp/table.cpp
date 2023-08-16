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
        unsigned int get_size(){
            return size;
        }

        bool insert(const Key& key, const Data& data) {
            unsigned int ind = get_index(key);

            Node<Key, Data>* newNode = new Node<Key, Data>(key, data);

            newNode->next = table[ind];
            table[ind] = newNode;
            return true; 
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
                        return true; // Exit early once deletion is done
                    }
                prev = current; 
                current = current->next; 
            }

            return false; 

        }

        void resize(int new_size) {
            for (unsigned int i = 0; i < size; ++i) {
                Node<Key, Data>* current = table[i];
                while (current) {
                    Node<Key, Data>* next = current->next;
                    delete current;
                    current = next;
                }
            }

            table.clear();  // Clear the vector
            table.resize(new_size, nullptr);  // Resize the vector to the new size

            for (unsigned int i = 0; i < size; ++i) {
                Node<Key, Data>* current = table[i];
                while (current) {
                    Node<Key, Data>* next = current->next;
                    insert(current->key, current->data); // Reinsert elements
                    delete current;
                    current = next;
                }
            }

            size = new_size;
        }

        int getTableSize(){
            return table.size(); 
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

unsigned int string_hash(string key){

    unsigned int hash_value = 0;

    for(int i = 0; i < key.length(); i++){
        hash_value += key[i]; 
        hash_value *= key[i]; 
        hash_value += key[i] << hash_value; 
    }

    return hash_value; 
}


int main() {

    Table<string, double> hash_table(10, string_hash);
    Node<string, double> * finder; 

    hash_table.insert("Apples", 4.89);

    hash_table.insert("Lettuce", 3.23);

    hash_table.insert("Milk", 2.58); 

    finder = hash_table.lookup("Apples"); 
    if(finder){
        cout << "Found it \nKey: " << finder->key << "\nData: " << finder->data << "\n"; 

    }else{
        cout << "did not find \n" ;
    }

    hash_table.del("Apples"); 

    finder = hash_table.lookup("Apples"); 
    if(finder){
        cout << "Found it \nKey: " << finder->key << "\nData: " << finder->data << "\n"; 

    }else{
        cout << "did not find \n"; 
    }

     
    cout << "table size: " << hash_table.getTableSize() << " \n";
    hash_table.resize(15); 
    cout << "table size: " << hash_table.getTableSize() << " \n";

    

    hash_table.insert("Carrot", 3.24); 

    finder = hash_table.lookup("Carrot"); 
    if(finder){
        cout << "Found it \nKey: " << finder->key << "\nData: " << finder->data << "\n"; 

    }else{
        cout << "did not find \n"; 
    }

    

    return 0;
}