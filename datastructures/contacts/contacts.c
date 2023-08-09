#include "contacts.h"
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdbool.h> 


#define FILE_NAME "contacts.txt"
#define OTHER_SIZE 8

char * to_lowercase(char *str){
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]); 
    }
    return str; 
}


bool keeper(char * str){
    char * strt = to_lowercase(str); 
    if(strcmp(strt, "yes") == 0 || strcmp(strt, "y") == 0 || strcmp(strt, "true") == 0){
        return true; 
    }
    return false; 
}


char * get_name(){
    char *name = (char *)malloc(sizeof(char) * MAX_SIZE); 
    if(name == NULL){
        fprintf(stderr, "memory alloaction failure\n"); 
        exit(0); 
    }   
    printf("Enter the name: "); 
    scanf("%s", name); 
    
    return name; 
}


long long int get_phonenumber(){
    long long int num; 
    printf("Enter a phone number: "); 
    scanf("%lld", &num); 
    
    return num; 
}

contact * uni_lookup(table list, unsigned int size, const char * name){
    contact * test = table_lookup(list, size, name); 

    if (test != NULL){
        return test; 
    }

    int ind = findInCache(list, name); 

    if (ind == -1){
        return NULL;
    }

    return list.extras[ind]; 
}

table load_from_file( unsigned int size, char * file_name){

    table cont = init_table(size); 

    FILE * file_p; 
    file_p = fopen(file_name, "r"); 
    if(file_p == NULL){
        fprintf(stderr, "file did not open\nExiting progam\n"); 

        exit(0); 
    }

    char first_name[255]; 
    char last_name[255];
    char name[256]; 
    long long int number; 

    while(fscanf(file_p, "%s %s %lld", first_name, last_name, &number) == 2){
        strcpy(name, first_name); 
        strcat(name, " "); 
        strcat(name, last_name); 

        table_insert(cont, size, name, number); 
    }

    fclose(file_p); 

    return cont; 

}

void load_to_file(table cont, unsigned int size, char * file_name){

    FILE * file_p; 

    file_p = fopen(file_name, "w"); 

    if(file_p == NULL){

        fprintf(stderr, "file did not open\nExiting program\n"); 

        exit(0); 
    }

    for(int i = 0; i < size; i++){
        if(cont.contacts[i] != NULL){
            fprintf(file_p, "%s %lld\n", cont.contacts[i]->name, cont.contacts[i]->number);
        }
    }

    for(int i = 0; i < cont.cache_size; i++) {
        fprintf(file_p, "%s %lld\n",cont.extras[i]->name, cont.extras[i]->number); 
    }

    fclose(file_p);
    table_destroy(cont, size); 

}


int main (void){

    unsigned int size; 
    int max_cache; 
    bool keepgoing = true; 
    int choice; 
    contact * store; 
    char * name_store; 
    int number_store; 
    char * temp = (char* )malloc(sizeof(char) * OTHER_SIZE); 

    printf("Welcome to Lukas's contact manager\n"); 

    printf("Enter the intro size of the table: "); 
    scanf("%d", &size); 

    printf("Enter the max size of the tables cache: "); 
    scanf("%d", &max_cache); 

    table myContacts = load_from_file(size, FILE_NAME); 

    
    while(keepgoing == true){

        if(myContacts.cache_size > max_cache){
            table_resize(myContacts, size, size+15); 
            size = size + 15; 
        }

        printf("Choose which action you want to perform\n1. Do you want to find a person\n2. Do you want to add a new person\n3. Do you want to remove a person\n");
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        getchar();

        if(choice == 1){
            name_store = get_name(); 

            store = uni_lookup(myContacts, size, name_store); 

            if(store == NULL){
                printf("Name not found!!!\n");
            }

            else{
                printf("The name is: %s\n", store->name); 
                printf("The number is %lld\n", store->number); 
            }
            

        }
        else if(choice == 2){   
            number_store = get_phonenumber(); 
            getchar(); 
            name_store = get_name(); 

            myContacts = table_insert(myContacts, size, name_store, number_store); 

        }
        else if(choice == 3){
            name_store = get_name(); 

            myContacts = table_delete(myContacts, size, name_store); 

        }
        else{
            printf("Invalid choice!!!\n");
        }
         
        printf("Do you wish to remain in the program: "); 
        
        scanf("%s", temp); 
        keepgoing = keeper(temp); 


    }
    free(temp); 
    free(name_store); 
    printf("Okay great!!\n"); 
    load_to_file(myContacts, size, FILE_NAME); 


}











