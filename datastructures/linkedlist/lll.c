#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 



typedef struct node {
    char * data; 
    struct node * next; 
}node; 

void insert(node ** head_ref, const char * data){
    node * new_node = (node*)malloc(sizeof(node)); 
    new_node->data = strdup(data);
    new_node->next = *head_ref; 
    *head_ref = new_node; 
}

void display(node* head){
    while(head != NULL){
        printf("%s -> ", head->data);
        head = head->next; 
    }
    printf("END\n"); 
}

int main(int argc, char ** argv){
    node * head = NULL; 
    char temp[100]; 
    if(argc < 2){
        return 1; 
    }
    int iters = atoi(argv[1]); 

    for(int i = 0; i < iters; i++){
        printf("Enter the name: "); 
        scanf("%s", temp);
        insert(&head, temp); 
    }

    display(head); 

    node * curr = head; 
    while(curr != NULL){
        node * temp = curr; 
        curr = curr->next; 
        free(temp->data); 
        free(temp);
    }

    return 0; 
}