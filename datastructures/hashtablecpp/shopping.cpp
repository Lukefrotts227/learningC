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

    Table<string, DoubInt> my_table(12, generic_string_hash_1);  


    my_table.insert("cake", DoubInt(4.22, 5)); 
    my_table.insert("coffee", DoubInt(4.55, 3)); 
    my_table.insert("apples", DoubInt(2.33, 12));  

    my_table["cola"] = DoubInt(3.32, 4); 


    my_table.print(true); 

    my_table.print_point("apples"); 

    my_table.resize(33);
    my_table.replace("apples", DoubInt(4.22, 8)); 
    my_table.print_point("apples");

    my_table.print(true); 





    
    return 0; 
}