/* What I can improve: 
efficency/time/memory: 
certain aspects of the program are not as efficent as possible. 
For example in the resize funtion I first put all of the data from the old table onto the new one
then I destroy the old table. It would be possible to destroy the data from the old table as I copy it to the new one 

organization/logic: 
There is a large amoutn of reptition of logic in the code. 
A massive amount of it include iterating through a linked list 
abstracted away this reptition would be beneficial
*/

#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <stdio.h> 


#define MAX_NAME_LENGTH 256


typedef struct node{
    char name[MAX_NAME_LENGTH]; 
    // other data 
    struct node * next; 
}node;

unsigned int hash(const char * name, unsigned int size){
    int len = strlen(name); 
    unsigned int hash_value; 
    for(int i = 0; i < len; i++){
        hash_value += name[i]; 
        hash_value = hash_value & name[i]; 
        hash_value = hash_value >> len << name[i] | hash_value; 
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
   // add the other data
   ind->next = tbl[index]; 
   tbl[index] = ind; 

   return tbl; 


}

node ** table_replace(node ** tbl, unsigned int size, const char * name){
    unsigned int index = hash(name, size); 

    node * ptr = tbl[index]; 

    while(ptr != NULL){
        if(strcmp(name, ptr->name) == 0){
            // add new data
            return tbl; 
        }
        ptr = ptr->next; 
    }

    fprintf(stderr, "name not in table"); 
    return tbl; 
}

node ** table_delete(node ** tbl, unsigned int size, const char * name){
    unsigned int index = hash(name, size); 

    node * ptr = tbl[index]; 
    node * prev = NULL; 

    while(ptr != NULL){
        if(strcmp(ptr->name, name) == 0){
            if(prev == NULL){
                tbl[index] = NULL; 
            }
            else{
                prev -> next = ptr->next; 
            }
            free(ptr); 
            return tbl; 
        }
        prev = ptr; 
        ptr = ptr->next; 
    }
    fprintf(stderr, "Not in table\n");
    return tbl;  
}

void table_destroy(node ** tbl, unsigned int size){
    
    for(int i = 0; i < size; i++){
        if(tbl[i] == NULL || tbl[i]->next == NULL){
            free(tbl[i]);
        }
        else{
            node * ptr = tbl[i]; 
            node * temp; 
            while(ptr != NULL){
                temp = ptr; 
                free(ptr); 
                ptr = temp->next; 
            }
        }
    }
    free(tbl); 
}

node ** table_resize(node ** tbl, unsigned int size, unsigned int new_size){
    node ** new_table = table_init(new_size); 

    if(new_table = NULL){
        fprintf(stderr, "mem failed to allocate\n"); 
        return tbl; 
    }
    // if I had new data this is code I would adjust
    for(int i =  0; i < size; i++){
        if(tbl[i] != NULL){
            node * ptr = tbl[i]; 
            do{
                table_insert(new_table, new_size, ptr->name); 
                ptr = ptr->next; 
            }while(ptr != NULL); 
        }
    }

    table_destroy(tbl, size); 
    return new_table; 
}

int table_largest_list(node ** tbl, unsigned int size){
    int max_value = 0; 
    int temp;
    for(int i = 0; i < size; i++){
        if(tbl[i] != NULL){
            node * ptr = tbl[i]; 
            temp = 0; 
            do{
                temp++; 
                ptr = ptr->next; 

            }while(ptr != NULL); 
        }
        if(temp > max_value){
            max_value = temp; 
        }
    }
    return max_value; 
}

void table_print(node ** tbl, bool with_empty, unsigned int size){
    for(int i = 0; i < size; i++){
        if(with_empty == true || tbl[i] != NULL){
            printf("%i.\t", i); 
            node * ptr = tbl[i]; 
            do {
                if(ptr != NULL){
                    printf("%s--", ptr->name); 
                }
                else{
                    printf("NULL--"); 
                }
                ptr = ptr->next; 
            }while(ptr != NULL);
            printf("\n");
        }
    }

}
