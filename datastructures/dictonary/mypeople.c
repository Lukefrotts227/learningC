#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>

#define MAX_SIZE 256

typedef struct person{
    char name[MAX_SIZE]; 
    int age; 
    int mass; 
    int height;
}person;

unsigned int hash(const char *name, unsigned int size){

    int len = strnlen(name, MAX_SIZE); 

    unsigned int hash_value = 0; 

    for(int i = 0; i < len; i++){
        hash_value += name[i]; 
        hash_value = hash_value << 2; 
        hash_value = hash_value | len; 
        hash_value = hash_value | len & (hash_value >> 1); 

        hash_value = (hash_value * name[i]) % size; 
    }
    return hash_value; 
}

person** init_table(unsigned int size){
    person** people = (person**)malloc(size * sizeof(person*)); 

    if(people == NULL){
        fprintf(stderr, "Memory allocation faliure.\n"); 
        return NULL; 
    }

    for(unsigned int i = 0; i < size; i++){
        people[i] = NULL; 
    }
    return people; 
}


void print_table(person ** people, unsigned int size){
    
    for(int i = 0; i < size; i++){
        if (people[i] == NULL){
            printf("\t%i\t---\n", i); 
        }
        else {
            printf("\t%i\t%s\n", i, people[i]->name);
        }
    }

}


person* table_lookup(person** people, unsigned int size, const char* name){
    unsigned int index = hash(name, size); 

    if (people[index] != NULL){
        if(strcmp(people[index]->name, name) == 0){
            return people[index]; 
        }
    }

    return NULL; 



}


person** table_insert(person** people, unsigned int size, const char* name, int age, int mass, int height){
    unsigned int index = hash(name, size); 

    person * new_person = (person*)malloc(sizeof(person)); 

    if(new_person == NULL){
        fprintf(stderr, "Memory allocation faliure.\n"); 
        return NULL; 
    }

    strcpy(new_person->name, name); 
    new_person->age = age;
    new_person->mass = mass;
    new_person->height = height;
    
    if(people != NULL){
        free(people[index]); 
        people[index] = new_person; 
    }
    else{
        people[index] = new_person; 

    }

    return people; 
    
}

person** table_delete(person** people, unsigned int size, const char* name){
    if(table_lookup(people, size, name) == NULL){
        return people; 
    }

    unsigned int index = hash(name, size);  

    people[index] = NULL; 



    return people; 
}

int main(void){

    unsigned int size; 


    printf("Please enter the size of the hashtable: "); 
    scanf("%d", &size); 

    person** people = init_table(size); 

    if (people == NULL){

        printf("Failed to init array"); 
        return 1;
    }

    table_insert(people, size, "john frotton", 64, 100, 64); 

    person * obj = table_lookup(people, size, "john frotton"); 

    print_table(people, size); 

    printf("\t%s aged %i years", obj->name, obj->age); 


    table_delete(people, size, "john frotton"); 


    print_table(people, size); 






    for(int i = 0; i < size; i ++){
        free(people[i]); 
    }


    free(people); 
    return 0; 
}