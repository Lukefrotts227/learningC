#include <stdio.h> 
#include <string.h> 

typedef struct {
    char name[64]; 
    int age; 
}Person; 




int main(void)
{
    Person joe; 
    Person bob; 
    Person john; 
    Person jose; 

    bob.age = 33;
    strncpy(bob.name, "Bob", sizeof(bob.name) - 1);
    bob.name[sizeof(bob.name) - 1] = '\0';

    jose.age = 22;
    strncpy(jose.name, "Jose", sizeof(jose.name) - 1);
    jose.name[sizeof(jose.name) - 1] = '\0';

    joe.age = 15; 
    strncpy(joe.name, "Joe", sizeof(joe.name) - 1); 
    joe.name[sizeof(joe.name) - 1] = '\0'; 

    john.age = 56; 
    strncpy(john.name, "John", sizeof(john.name) - 1); 
    john.name[sizeof(john.name) -1] = '\0'; 
    

    Person people[] = {bob, jose, joe, john}; 
    Person *ptr = &people[0]; 
    int size = sizeof(people) / sizeof(people[0]); 


    for (int i = 0; i < size; ++i){
        printf("%s : %d\n", ptr->name, ptr->age);

        ptr += 1;
    }

    

    return 0; 
}