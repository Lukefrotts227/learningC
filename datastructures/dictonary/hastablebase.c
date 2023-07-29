#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define MAX_SIZE 256 
#define TABLE_SIZE 2000


typedef struct node{
    char key[256]; 
    int data; 
}node; 

unsigned int has(char *name, int size){
    int len = strnlen(name, MAX_SIZE); 

    unsigned int hashval = 0; 
    for (int i = 0; i < len; i++){
        hashval += name[i]; 
        hashval = (hashval * name[i]) % TABLE_SIZE; 

    }

    return hashval; 
}

int main(void){
    char *names = {"bob", "henry", "joey", "tom", "julia", "jane"};
    int name_len = 6; 
    for (int i = 0; i < name_len; i++){
        printf("%s => %u", names[i], hash(names[i]));
    }

    return 0;
}