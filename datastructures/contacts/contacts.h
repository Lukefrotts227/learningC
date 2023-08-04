#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h> 


#define MAX_SIZE 256


typedef struct contact {
    char name[256]; 
    int number; 
} contact;

typedef struct table {
    contact ** contacts; 
    int cache_size; 
    contact ** extras; 
} table;

unsigned int hash(const char * name, unsigned int size) {
    int len = strlen(name); 

    unsigned int hash_value = 0; 

    for (int i = 0; i < len; i++) {
        hash_value += name[i]; 
        hash_value = hash_value & name[i];
        hash_value = (hash_value * name[i]) % size; 
    }

    return hash_value; 
}

table init_table(unsigned int size) {
    table tbl;
    tbl.contacts = (contact**)malloc(size * sizeof(contact*)); 


    if (tbl.contacts == NULL) {
        fprintf(stderr, "memory allocation failure"); 
        tbl.extras = NULL;
        return NULL; 
    }


    

    for (unsigned int i = 0; i < size; i++) {
        tbl.contacts[i] = NULL;
    }
    tbl.extras = NULL 

    tbl.cache_size = 0; 

    return tbl; 
}

contact * table_lookup(table contacts, unsigned int size, const char * name) {
    unsigned int index = hash(name, size); 

    if ((contacts.contacts[index] != NULL) && (strcmp(contacts.contacts[index]->name, name) == 0)) {
        return contacts.contacts[index]; 
    }

    table empty_table;
    empty_table.contacts = NULL;
    empty_table.cool = false;
    empty_table.extras = NULL;

    return empty_table; 
}

int table_size(table arr) {
    return sizeof(arr.contacts) / sizeof(contact); 
}

bool isEmpty(table arr){
    if(table_contents == NULL){
        return true;
    }
    return false;
}

bool inCache(table arr, char * name){
    
    for(int i = 0; i < sizeof(arr.extras) / sizeof(contact); i++){
        if(strcmp(arr.extras[i]->name,name)==0){
            return true;
        }
    }
    return false;
}


int findInCache(table arr, char * name){
    for(int i = 0; i < sizeof(arr.extras) / sizeof(contact); i++){

        if(strcmp(arr.extras[i]->name, name) ==0){
            return i; 
        }
    }

    return NULL;

}

table table_delete(table contacts, unsigned int size, const char * name) {
    if (table_lookup(contacts, size, name).contacts == NULL) {
        return contacts;
    }

    unsigned int index = hash(name, size); 

    contacts.contacts[index] = NULL; 

    free(contact.contacts[index]); 

    return contacts; 
}

table table_insert(table contacts, unsigned int size, const char * name, int number){
    unsigned int index = hash(name, size);
    
    if(inCache(contacts, name) == false && (contacts.contacts[index]==NULL)){
        contact * contacti = (contact*)malloc(sizeof(contact));
        if(contacti == NULL){
            fprintf(stderr, "memory allocation failure"); 
            return NULL; 
        }
        strcpy(contacti->name, name);
        contacti->number = number;
        contacts.contacts[index] = contacti;
        return contacts;
    }
    
    if(contacts.contacts[index] != NULL && inCache(contacts,name) == false && strcmp(contacts.contacts[index]->name, name) == 0){
        contact * contacti = (contact*)malloc(sizeof(contact)); 

        if(contacti == NULL){
            fprintf(stderr, "memory allocation failure"); 
            return NULL; 
        }

        table_delete(contacts, size, name); 

        strcpy(contacti->name, name); 
        contacti->number = number; 
        contact.contacts[index] = contacti; 
        return contacts; 

    }

    if(contacts.contacts[index] != NULL && inCache(contacts, name) == false){
        if(contacts.cache_size == 0){
            contacts.extras = (contact**)malloc(1 * sizeof(contact*)); 
            contact * contacti = (contact*)malloc(sizeof(contact)); 

            if(contacts.extras == NULL){
                fprintf(stderr, "memeory allocation failure"); 
                return NULL;
            }

            if(contactsi == NULL){
                fprintf(stderr, "memroy allocation failure");
                return NULL;
            }

            strcpy(contacti->name, name); 
            contacti->number = number; 
            contacts.extras[0] = contacti; 
            return contacts; 

        }

        
        contact * contacti = (contact*)malloc(sizeof(contact)); 
        contacts.extras = (contact**)realloc(contacts.extras, contacts->cache_size+1 * sizeof(contact*)); 

        if(contacts.extras == NULL){
            fprintf(stderr, "memory alloaction failure"); 
            return NULL
        }

        if(contacti == NULL){
            fprintf(stderr, "memory allocation failure"); 
            return NULL; 
        }
         
        strcpy(contacti->name, name); 
        contacti->number = number; 
        contacts.contact[cache_size] = contacti; 
        contacts->cache_size++; 
        return contacts; 

    }

    if(inCache(contacts, name) == true){

        contact * contacti = (contact*)malloc(sizeof(contact)); 

        if (contacti == NULL){
            fprintf(stderr, "memory allocation failure"); 
            return NULL; 
        }
        int pos = findInCache(contacts, name); 

        strcpy(contacti->name, name); 
        contacti->number = number; 
        contacts.extras[pos] = contacti; 
        return contacts; 
        
    }

    return NULL; 
    
    
    
}

table table_resize(table contacts, unsigned int size, unsigned int new_size){

}

table table_destroy(table contacts, unsigned int size){

}












