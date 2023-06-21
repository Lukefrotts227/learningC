#include <stdio.h> 
#include <stdlib.h>

typedef struct node {
    int valud;
    struct node *next;
};

void printLL(struct node *p)
{
    while (p != NULL)
    {
        printf("%d\n", p->valud); 
        p = p->next; 
    }
}


int main()
{
    struct node *head; 
    struct node *one = NULL; 
    struct node *two = NULL; 
    struct node *three = NULL; 

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    one->valud = 1; 
    two->valud = 2; 
    three->valud = 3;

    one->next = two; 
    two->next = three; 
    three->next = NULL;

    head = one; 
    printLL(head);






    return 0;
}