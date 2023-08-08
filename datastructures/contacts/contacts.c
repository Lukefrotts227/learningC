#include "contacts.h"
#include <stdio.h> 
#include <string.h> 




char * get_name(){
    char * name; 
    printf("Enter the name: "); 
    scanf("s", name); 
    
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

table load_from_file(table cont, unsigned int size, char * file_name){

    cont = init_table(size); 

    FILE * file_p; 
    file_p = fopen(file_name, "r"); 
    if(file_p == NULL){
        fprintf(stderr, "file did not open\nExiting progam\n"); 

        exit(0); 
    }

    char first_name[256]; 
    char last_name[256];
    char name[256]; 
    long long int number; 

    while(fscanf(file_p, "%s %s %lld", first_name, last_name, &number) == 2){
        strcpy(name, first_name); 
        strcat(name, " "); 
        strcat(name, last_name); 

        table_insert(cont, size, name, number); 
    }

    return cont; 

}

void load_to_file(table cont, unsigned int size, char * file_name){



    table_destroy(cont, size); 

}


int main (void){

    unsigned int size; 

    printf("Enter the size: "); 
    scanf("%d", &size); 

   

    




}











