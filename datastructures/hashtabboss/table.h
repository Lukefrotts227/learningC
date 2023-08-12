#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 


#define MAX_NAME_LENGTH 256


typedef struct node{
    char name[MAX_NAME_LENGTH]; 

    node * next; 
}node;

unsigned int hash(const char * name, unsigned int size){

}

node ** table_init(unsigned int size){

}

node * table_lookup(node ** tbl, unsigned int size, const char * name){

}

node ** table_insert(node ** tbl, unsigned int size, const char * name){

}

node ** table_delete(node ** tbl, unsigned int size, const char * name){

}

node ** table_resize(node ** tbl, unsigned int size, unsigned int new_size){

}

int table_largest_list(node ** tbl, unsigned int size){

}

node ** table_destroy(node ** tbl, unsigned int size){
    
}

