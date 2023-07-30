#include <stdio.h> 
#include <stdlib.h>

typedef struct node {
    int valud;
    struct node *next;
}node;

void printLL(node *p)
{
    while (p != NULL)
    {
        printf("%d\n", p->valud); 
        p = p->next; 
    }
}




int main()
{
    node *head; 
    node *one = NULL; 
    node *two = NULL; 
    node *three = NULL; 

    one = malloc(sizeof(node));
    two = malloc(sizeof(node));
    three = malloc(sizeof(node));

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