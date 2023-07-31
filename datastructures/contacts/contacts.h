#ifndef CONTACTS_H
#define CONTACTS_H


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

        hash_value += name[i]; 
        hash_value = hash_value & name[i];
        hash_value = (hash_value * name[i])%size; 

    }

    return hash_value; 
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

int table_size(arr){

    return sizeof(arr) / sizeof(contact); 
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
    if(table_lookup(contacts, size, name ) == NULL){
        return contacts;
    }

    unsigned int index = hash(name, size); 

    contacts[index] = NULL; 

    return contacts; 



}

contact ** resize_table(contact ** contacts, unsigned int size, unsigned int new_size){

    contact ** new_contacts = init_table(new_size); 

    if (new_contacts == NULL){
        fprintf(stderr, "memeory allocation failure"); 
        return NULL; 
    }


    for(unsigned int i = 0; i < size; i++){

        prim_table_insert(new_contacts, new_size, contacts[i]->name, contacts[i]->number); 
    }




    for(unsigned int i = 0; i < size; i++){
        free(contacts[i]); 
    }

    free(contacts); 

    return new_contacts; 



}

contact ** table_insert(contact ** contacts, unsigned int size, const char * name, int number){
    unsigned int hash(name, size); 

    contact * new_contact = (contact*)malloc(sizeof(contact)); 


    if(new_contact == NULL){
        fprintf(stderr, "memory allocation failure"); 
        return NULL; 
    }


    int need_resize = 1; 

    while (need_resize == 1){

    }


    


}














