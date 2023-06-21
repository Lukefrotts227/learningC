#include <stdio.h> 

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

    
    return 0;
}