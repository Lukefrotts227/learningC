


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h> 


#define MAX_SIZE 256


typedef struct contact{
    char name[256]; 
    int number; 

}contact; 

typedef struct table{
    contact ** contacts; 
    bool cool; 

}table;



unsigned int hash(const char * name, unsigned int size){
    int len = strlen(name); 

    unsigned int hash_value = 0; 

    for(int i = 0; i < len; i++){

        hash_value += name[i]; 
        hash_value = hash_value & name[i];
        hash_value = (hash_value * name[i])%size; 

    }

    return hash_value; 
}


table init_table(unsigned int size){
    if (size == 0){
        contact ** contacts = (contact**)malloc(0 * sizeof(contact));
        return contacts; 
    }

    contact ** contacts = malloc(size * sizeof(contact*)); 

    if(contacts == NULL){
        fprintf(stderr, "memory allocation failure"); 

    }

    for(unsigned int i = 0; i < size; i++){
        contacts[i] = NULL;
    }
    return contacts; 
}



table table_lookup(contact ** contacts, unsigned int size, const char * name){
    unsigned int index = hash(name, size); 


    if((contacts[index] != NULL) && (strcmp(contacts[index]->name, name) == 0)){

        return contacts[index]; 
    }

    return NULL; 
}

int table_size(contact ** arr){

    return sizeof(arr) / sizeof(contact); 
}

bool check_empty_table(contact ** arr){

    if(table_size(arr) < 1){
        return true; 
    }
    return false; 
}


table table_delete(contact ** contacts, unsigned int size, const char * name){
    if(table_lookup(contacts, size, name ) == NULL){
        return contacts;
    }

    unsigned int index = hash(name, size); 

    contacts[index] = NULL; 

    return contacts; 



}














