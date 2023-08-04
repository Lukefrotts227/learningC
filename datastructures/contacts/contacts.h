// The standard lib modules I am including alongside any other definitions
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h> 


#define MAX_SIZE 256

// defining the contact struct which is the data contained in the hashtable
typedef struct contact {
    char name[MAX_SIZE]; 
    int number; 
} contact;

// defining a struct that includes the table, the cache for the table and the size of the cache at the time
typedef struct table {
    contact ** contacts; 
    int cache_size; 
    contact ** extras; 
} table;

// The hash function I am using for the table
unsigned int hash(const char * name, unsigned int size) {
    int len = strlen(name); 

    unsigned int hash_value = 0; 

    for (int i = 0; i < len; i++) {
        hash_value += name[i]; 
        hash_value = hash_value & name[i];
        // have to mod to the size it fits in the table
        hash_value = (hash_value * name[i]) % size; 
    }

    return hash_value; 
}

// init the table, allocating the required memory
table init_table(unsigned int size) {
    table tbl;
    tbl.contacts = (contact**)malloc(size * sizeof(contact*)); 


    if (tbl.contacts == NULL) {
        fprintf(stderr, "memory allocation failure"); 
        tbl.extras = NULL;
        // return NULL; 
    }


    
    // fill with nulls
    for (unsigned int i = 0; i < size; i++) {
        tbl.contacts[i] = NULL;
    }
    tbl.extras = NULL; 

    tbl.cache_size = 0; 

    return tbl; 
}

// lookup function to find a contact 
contact * table_lookup(table contacts, unsigned int size, const char * name) {
    unsigned int index = hash(name, size); 
    
    // constant time lookup
    if ((contacts.contacts[index] != NULL) && (strcmp(contacts.contacts[index]->name, name) == 0)) {
        return contacts.contacts[index]; 
    }

    return NULL; 
}

// check if a contact is in the cache 
bool inCache(table arr, const char * name){
    
    for(int i = 0; i < sizeof(arr.extras) / sizeof(contact); i++){
        if(strcmp(arr.extras[i]->name,name)==0){
            return true;
        }
    }
    return false;
}

// lookup function for the cache 
int findInCache(table arr, const char * name){
    for(int i = 0; i < sizeof(arr.extras) / sizeof(contact); i++){

        if(strcmp(arr.extras[i]->name, name) ==0){
            return i; 
        }
    }

    return -1;

}

// delete a contact from the table
table table_delete(table contacts, unsigned int size, const char * name) {
    // check if it is in the table or not
    if (table_lookup(contacts, size, name) == NULL) {
        return contacts;
    }

    unsigned int index = hash(name, size); 

    contacts.contacts[index] = NULL; 

    if (contacts.contacts[index] != NULL) {
        free(contacts.contacts[index]);
        contacts.contacts[index] = NULL;
    }

    return contacts; 
}
// the insert function for the table
table table_insert(table contacts, unsigned int size, const char * name, int number){
    unsigned int index = hash(name, size);
    
    // standard if it is not in the cache or table, and not colliding
    if(inCache(contacts, name) == false && (contacts.contacts[index]==NULL)){
        contact * contacti = (contact*)malloc(sizeof(contact));
        if(contacti == NULL){
            fprintf(stderr, "memory allocation failure"); 
            //return NULL; 
        }
        strcpy(contacti->name, name);
        contacti->number = number;
        contacts.contacts[index] = contacti;
        return contacts;
    }
    // replace number if name in made table
    if(contacts.contacts[index] != NULL && inCache(contacts,name) == false && strcmp(contacts.contacts[index]->name, name) == 0){
        contact * contacti = (contact*)malloc(sizeof(contact)); 

        if(contacti == NULL){
            fprintf(stderr, "memory allocation failure"); 
            //return NULL; 
        }

        table_delete(contacts, size, name); 

        strcpy(contacti->name, name); 
        contacti->number = number; 
        contacts.contacts[index] = contacti; 
        return contacts; 

    }
    // adding a new contact to cache if collision
    if(contacts.contacts[index] != NULL && inCache(contacts, name) == false){
        // if the cahce is empty we allocate memory to it
        if(contacts.cache_size == 0){
            contacts.extras = (contact**)malloc(1 * sizeof(contact*)); 
            contact * contacti = (contact*)malloc(sizeof(contact)); 

            if(contacts.extras == NULL){
                fprintf(stderr, "memeory allocation failure"); 
                //return NULL;
            }

            if(contacti == NULL){
                fprintf(stderr, "memroy allocation failure");
                //return NULL;
            }

            strcpy(contacti->name, name); 
            contacti->number = number; 
            contacts.extras[0] = contacti; 
            return contacts; 

        }

        // if the cache is not empty we use reallox
        
        contact * contacti = (contact*)malloc(sizeof(contact)); 
        contacts.extras = (contact**)realloc(contacts.extras, contacts.cache_size+1 * sizeof(contact*)); 

        if(contacts.extras == NULL){
            fprintf(stderr, "memory alloaction failure"); 
            //return NULL;
        }

        if(contacti == NULL){
            fprintf(stderr, "memory allocation failure"); 
            //return NULL; 
        }
         
        strcpy(contacti->name, name); 
        contacti->number = number; 
        contacts.contacts[contacts.cache_size] = contacti; 
        contacts.cache_size++; 
        return contacts; 

    }
    // replace info for contact in cache
    if(inCache(contacts, name) == true){

        contact * contacti = (contact*)malloc(sizeof(contact)); 

        if (contacti == NULL){
            fprintf(stderr, "memory allocation failure"); 
            //return NULL; 
        }
        int pos = findInCache(contacts, name); 

        strcpy(contacti->name, name); 
        contacti->number = number; 
        contacts.extras[pos] = contacti; 
        return contacts; 
        
    }

    return contacts; 
    
    
    
}

table table_resize(table contacts, unsigned int size, unsigned int new_size){

    table new_contacts = init_table(new_size); 


    for(unsigned int i = 0; i < size; i++){

        if(contacts.contacts[i] != NULL){
            table_insert(new_contacts, new_size, contacts.contacts[i]->name, contacts.contacts[i]->number); 
        }
    }

    for(unsigned int i = 0; i < contacts.cache_size; i++){

        table_insert(new_contacts, new_size, contacts.extras[i]->name, contacts.extras[i]->number); 
    }

    for(unsigned int i = 0; i < size; i++){
        if(contacts.contacts[i] != NULL){
            free(contacts.contacts[i]);
        }
    }

    for(unsigned int i = 0; i < contacts.cache_size; i++){
        free(contacts.extras[i]); 

    }

    free(contacts.extras); 
    free(contacts.contacts); 
    return new_contacts; 


}

void table_destroy(table contacts, unsigned int size){

    for(unsigned int i = 0; i < size; i++){
        if(contacts.contacts[i] != NULL){
            free(contacts.contacts[i]); 
        }
    }
    free(contacts.contacts); 

    for(unsigned int i = 0; i < contacts.cache_size; i++){
        free(contacts.extras[i]);
    }

    free(contacts.extras); 

}
