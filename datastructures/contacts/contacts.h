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
    unsigned int index = hash(name, size); 


    if((contacts[index] != NULL) && (strcmp(contacts[index]->name, name) == 0)){

        return contacts[index]; 
    }

    return NULL; 
}

contact ** prim_table_insert(contact ** contacts, unsigned int size, const char * name, int number){
    unsigned int index = hash(name, size); 

    contact * new_contact = (contact*)malloc(sizeof(contact)); 

    if(new_contact == NULL){
        fprintf(stderr, "memory allocation error"); 

        return NULL; 
    }


    if (contacts[index] == NULL){
        strcpy(new_contact->name, name); 
        new_contact->number = number; 

        contacts[index] = new_person; 

    }

    fprintf(stderr, "someone already exists here"); 
    return NULL
}

contact ** table_delete(contact ** contacts, unsigned int size, const char * name){

}

contact ** resize_table(contact ** contacts, unsigned int size, unsigned int new_size){

}

contact ** table_insert(contact ** contacts, unsigned int size, const char * name, int number){

}














