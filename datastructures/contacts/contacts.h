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
    bool cool; 
    contact * extras; 
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

    if (tbl.contacts == NULL) {
        fprintf(stderr, "memory allocation failure"); 
        tbl.cool = false; 
        tbl.extras = NULL;
    } else {
        tbl.cool = true; // Just an example, you can set this to true/false as needed
        tbl.extras = NULL;
    }

    for (unsigned int i = 0; i < size; i++) {
        tbl.contacts[i] = NULL;
    }

    return tbl; 
}

table table_lookup(table contacts, unsigned int size, const char * name) {
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

table table_delete(table contacts, unsigned int size, const char * name) {
    if (table_lookup(contacts, size, name).contacts == NULL) {
        return contacts;
    }

    unsigned int index = hash(name, size); 

    contacts.contacts[index] = NULL; 

    return contacts; 
}












