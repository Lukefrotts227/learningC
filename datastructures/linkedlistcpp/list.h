#include <iostream> 
#include <memory> 
#include <string> 


using namespace std; 

template <typename Data> 
class Node{
    public:
        Data data; 
        Node * prev; 
        Node * next; 

        Node(const Data& d) : data(d), prev(nullptr), next(nullptr) {}
};


template <typename Data> 
class DoublyLinkedList{
    private: 
        Node<Data> * head; 
        Node<Data> * tail; 
        unsigned int size; 

    public: 
        DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
        
        bool isEmpty(){
            return size == 0; 
        }


        bool append(const Data& data){
            Node<Data> * newNode = new Node<Data>(data); 
            if(this->isEmpty()){
                head = newNode; 
                tail = newNode; 
                size++; 
                return true;
            }
            tail->next = newNode; 
            newNode->prev = tail; 
            tail = newNode; 
            size++;
            return true; 


        }


        bool prepend(const Data& data){
            Node<Data> * newNode = new Node<Data>(data); 
            if(this->isEmpty()){
                head = newNode; 
                tail = newNode; 
                size++; 
                return true; 
            }
            head->prev = newNode; 
            newNode->next = head; 
            head = newNode; 
            size++; 
            return true; 
        }

        bool insert(const Data& data, unsigned int pos){
            if(pos >=size || pos < 0){
                return false; 
            }

            if(pos == 0){
                this->prepend(data); 
                return true; 
            } 

            if(pos == size){
                this->append(data); 
                return true; 
            }
            Node<Data>* newNode = new Node<Data>(data);
            Node<Data>* current; 
            

            if(pos > size/2){
                current = tail; 
                for(int i = size; i > pos + 1; i--){    
                    current = current->prev; 
                }

            }else{
                current = head; 
                for(int i = 0; i < pos - 1; i++){
                    current = current->next; 
                }
            }

            newNode->next = current; 
            newNode->prev = current->prev; 
            current->prev->next = newNode; 
            current->prev = newNode; 

            return true;

        }

        Node<Data> * search(const Data& data, bool fromFront){
            Node<Data> * current; 
            if(fromFront){
                current = head; 
                while(current != nullptr){
                    if(current-data == data){
                        return current; 
                    }
                }
            }else{
                current = tail;
                while(current != nullptr){
                    if(current->data == data){
                        return current; 
                    }
                    current = current->prev; 
                }
            }

            return nullptr; 

        }
        Node<Data> * search_post(int pos){
            if(pos >= size || pos < 0){
                return nullptr; 
            }
            Node<Data> * current; 

            if(pos > size/2){
                current = tail; 
                for(int i = size; i > pos; i--){
                    current = current->prev; 
                }
            }else{
                current = head; 
                for(int i = 0; i < pos; i++){
                    current = current->next; 
                }

            }

            return current; 
        }

        bool del(const Data& data, bool fromFront){

            Node<Data> * current; 

            if(fromFront){
                current = head; 
                while(current != nullptr){
                    if(current->data == data){
                        if(current->prev){
                            current->prev->next = current->next; 

                        }else{
                            head = current->next; 
                        }

                        if(current->next){
                            current->next->prev = current->prev; 
                        }else{
                            tail = current->prev; 
                        }
                        delete current; 
                        size--; 
                        return true; 
                    }
                    current = current->next; 
                }

            }else{
                current = tail; 
                while(current != nullptr){
                    if(current->data == data){
                        if(current->prev){
                            current->prev->next = current->next; 

                        }else{
                            head = current->next; 
                        }

                        if(current->next){
                            current->next->prev = current->prev; 
                        }else{
                            tail = current->prev; 
                        }
                        delete current; 
                        size--; 
                        return true; 
                    }
                    current = current->next; 
                    
                }

            }
            return false; 
        }

        bool del_pos(unsigned int pos){
            if(pos >= size || pos < 0){
                return false;
            }
            Node<Data> * current; 

            if(pos > size/2){
                current = tail; 
                for(int i = size; i > pos; i--){
                    current = current->prev; 
                }

            }else{
                current = head; 
                for(int i = 0; i < pos; i++){
                    current = current->next; 
                }

            }
            if(current->prev){
                current->prev->next = current->next; 

            }else{
                head = current->next; 
            }

            if(current->next){
                current->next->prev = current->prev; 
            }else{
                tail = current->prev; 
            }
            delete current; 
            size--; 
            return true; 


            return true; 
        }

        void print(bool fromFront){
            if(fromFront){
                Node<Data> * current = head; 

                while(current != nullptr){
                    cout << current->data << "--"; 
                    current = current->next; 
                }
            }else{
                Node<Data> * current = tail; 

                while(current != nullptr){
                    cout << current->data << "--"; 
                    current = current->prev; 
                }
            }
            cout << '\n'; 
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
