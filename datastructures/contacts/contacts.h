#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


#define MAX_SIZE 256


typedef struct contact{
    char name[256]; 
    int number; 

}contact; 

unsigned int hash(const char * name, unsigned int size){
    int len = strlen(name); 

    unsigned int hash_value = 0; 

    for(int i = 0; i < len; i++){

    }
}


contact **  init_table(unsigned int size){
    contact ** contacts = malloc(size * sizeof(contact*)); 

    if(contact == NULL){
        fprintf(stderr, "memory allocation failure"); 

    }

    for(unsigned int i = 0; i < size; i++){
        contacts[i] = NULL
    }
    return contacts; 
}



contact * table_lookup(contact ** contacts, unsigned int size, const char * name){

}

contact ** prim_table_insert(contact ** contacts, unsigned int size, const char * name, int number){

}

contact ** table_delete(contact ** contacts, unsigned int size, const char * name){

}

contact ** resize_table(contact ** contacts, unsigned int size, unsigned int new_size){

}

contact ** table_insert(contact ** contacts, unsigned int size, const char * name, int number){
    
}














