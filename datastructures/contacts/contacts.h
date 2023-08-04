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
    tbl.contacts = malloc(size * sizeof(contact*)); 
    tbl.extras = malloc(1 * sizeof(contact*))


    if (tbl.contacts == NULL) {
        fprintf(stderr, "memory allocation failure"); 
        tbl.extras = NULL;
        return NULL; 
    }

    if(tbl.extras == NULL){
        fprintf(stderr, "memory allocation failure"); 
        return NULL
    }
    

    for (unsigned int i = 0; i < size; i++) {
        tbl.contacts[i] = NULL;
    }
    tbl.extras[0] = NULL; 

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


contact * findInCache(table arr, char * name){
    for(int i = 0; i < sizeof(arr.extras) / sizeof(contact); i++){

        if(strcmp(arr.extras[i]->name, name) ==0){
            return arr.extras[i]; 
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
        strcpy(contacti->name, name);
        contacti->number = number;
        contacts.contacts[index] = contacti;
        return contacts;
    }
    
    if(contacts.contacts[index] != NULL && inCache(contacts,name) == false && strcmp(contacts.contacts[index]->name, name) == 0){
        contact * contacti = (contact*)malloc(sizeof(contact)); 

        table_delete(contacts, size, name); 

        strcpy(contacti->name, name); 
        contacti->number = number; 
        contact.contacts[index] = contacti; 
        return contacts; 

    }

    if(contacts.contacts[index] != NULL && inCache(contacts, name) == false){
        

    }

    if(inCache(contacts, name) == true){
        
    }

    return NULL; 
    
    
    
}












