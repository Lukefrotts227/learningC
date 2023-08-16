#include <iostream> 
#include "table.h"

using namespace std; 

class Entry{
    public: 
        double cost; 
        int amount; 

        Entry(double c, int a) : cost(c), amount(a){}

};

unsigned int hasher(string key){
        unsigned int hash_value = 0;

    for(int i = 0; i < key.length(); i++){
        hash_value += key[i]; 
        hash_value *= key[i]; 
        hash_value += key[i] << hash_value; 
    }

    return hash_value; 
}


int main(){

    Table<string, Entry> my_table(12, generic_string_hash_1);  

    my_table.insert("Bananas", Entry(3.44, 4)); 
    my_table.insert("Corn", Entry(2.44, 3)); 
    my_table.insert("Peanuts", Entry(8.44, 7)); 

    my_table.print(true);


    
    return 0; 
}