#include "contacts.h"
#include <stdio.h> 



char * get_name(){
    char * name; 
    printf("Enter the name: "); 
    scanf("s", name); 
    
    return name; 
}


long long int get_phonenumber(){
    long long int num; 
    printf("Enter a phone number: "); 
    scanf("%lld", &num); 
    
    return num; 
}

contact * uni_lookup(table list, unsigned int size, const char * name){
    contact * test = table_lookup(list, size, name); 

    if (test != NULL){
        return test; 
    }

    int ind = findInCache(list, name); 

    if (ind == -1){
        return NULL;
    }

    return list.extras[ind]; 
}


int main (void){

    unsigned int size; 

    printf("Enter the size: "); 
    scanf("%d", &size); 
    
    table list = init_table(size); 


    

    table_destroy(list, size); 



}











