#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>

#define MAX_SIZE 256 
#define TABLE_SIZE 99


typedef struct node{
    char key[256]; 
    int data; 
}node; 

node * hash_table[TABLE_SIZE];

unsigned int hash(const char *name, int size){
    int len = strnlen(name, MAX_SIZE); 

    unsigned int hashval = 0; 
    for (int i = 0; i < len; i++){
        hashval += name[i]; 
        hashval += name[i] << 3; 
        hashval = (hashval * name[i]) % size; 

    }

    return hashval; 
}

bool init_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL; 
    }
    return true; 
}

void print_table(){
    printf("Start:\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t---\n",i);
        }
        else { 
            printf("\t%i\t%s\n", i, hash_table[i]);
        }
    }
    printf("Finish:\n");
}

bool insert_item(node *p){
    if(p == NULL) return false; 
    int index = hash(p->key, TABLE_SIZE); 
    if (hash_table[index] != NULL){
        return false;
    }
    hash_table[index] = p; 
    return true; 
}

node * table_lookup(char *name){
    int index = hash(name, TABLE_SIZE); 
    if (hash_table[index] !=  NULL && strncmp(hash_table[index]->key, name, TABLE_SIZE) ==0){
        return hash_table[index];

    }
    return NULL;
}

bool delete_item(char *name){
    int index = hash(name, TABLE_SIZE); 

    if (hash_table[index] !=  NULL && strncmp(hash_table[index]->key, name, TABLE_SIZE) ==0){

        hash_table[index] = NULL; 

        return true; 
    }

    return false; 
}

int main(void){
    init_table(); 

   
    
    node tom = {.key="tom", .data=22}; 
    node jon = {.key="jon", .data=13};
    node johan = {.key="johan", .data=99};
    node earl = {.key="earl", .data=25};
    node jane = {.key="jane", .data=12};


    insert_item(&tom);
    insert_item(&jon);
    insert_item(&johan);
    insert_item(&earl);
    insert_item(&jane);

    node * found = table_lookup("jane"); 

    printf("I found %s with a value of %i\n", found->key, found->data); 

    delete_item("jane");
    found = table_lookup("jane"); 
    

    if (found == NULL){
        printf("we were able to delete jane"); 
    }



    /*for (int i = 0; i < name_len; i++){
        printf("%s => %u\n", names[i], hash(names[i], TABLE_SIZE));
    }
    */

    return 0;
}