#include <iostream> 
#include <memory> 
#include <string> 
#include <vector>


using namespace std; 




template <typename T, typename H>
class Node{
    public: 
        H key;
        T data; 
        Node * next; 

        Node(const H& n, const T& val) : key(n), data(val), next(nullptr)

}; 

template <typename T, typename H>
class Table{
    private: 
        
    public: 

}; 