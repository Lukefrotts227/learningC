#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <stdio.h> 


#define MAX_NAME_LENGTH 256


typedef struct node{
    char name[MAX_NAME_LENGTH]; 

    node * next; 
}node;

unsigned int hash(const char * name, unsigned int size){
    int len = strlen(name); 
    unsigned int hash_value; 
    for(int i = 0; i < len; i++){
        hash_value += name[i]; 
        hash_value = hash_value & name[i] | len; 
        hash_value = (hash_value * name[i]) % size;
    }
    return hash_value; 
}

node ** table_init(unsigned int size){
    node ** table = (node**)malloc(size * sizeof(node*)); 
    if(table == NULL){
        fprintf(stderr, "mem failed to allocate\n"); 
        return NULL; 
    }

    for(int i = 0; i < size; i++){
        table[i] = NULL; 
    }

    return table; 

}

node * table_lookup(node ** tbl, unsigned int size, const char * name){

    unsigned int index = hash(name, size); 
    node * ptr = tbl[index]; 

    if(tbl[index] == NULL){
        return NULL;
    }


    do{
        if(strcmp(name, ptr->name) == 0){
            return ptr;
        }
        ptr = ptr->next; 
    }while(ptr != NULL); 

    return NULL; 

}

node ** table_insert(node ** tbl, unsigned int size, const char * name){
    unsigned int index = hash(name, size); 

    if(table_lookup(tbl, size, name) != NULL){
        fprintf(stderr, "name already exists at location\n"); 
        return tbl; 
    }

    node * ind = (node*)malloc(sizeof(node)); 
    if(ind == NULL){
        fprintf(stderr, "mem failed to allocate\n"); 
        return tbl; 
    }

   strcpy(ind->name, name); 
   ind->next = tbl[index]; 
   tbl[index] = ind; 

   return tbl; 


}

node ** table_replace(node ** tbl, unsigned int size, const char * name){

}

node ** table_delete(node ** tbl, unsigned int size, const char * name){

}

void table_destroy(node ** tbl, unsigned int size){

}

node ** table_resize(node ** tbl, unsigned int size, unsigned int new_size){

}

int table_largest_list(node ** tbl, unsigned int size){

}
