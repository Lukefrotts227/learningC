#include <stdio.h>

typedef struct animal {
    char name[20];
    int age;
    char species[30];
} animal;

typedef struct person {
    char name[50];
    int age;
    char occupation[50];
} person;

enum creature {
    CAT,
    DOG,
    BIRD,
    FISH,
};

int main() {
    animal myPet;
    person person1;

    // Assign values to the struct members
    sprintf(myPet.name, "Fluffy");
    myPet.age = 3;
    sprintf(myPet.species, "Cat");

    sprintf(person1.name, "John Doe");
    person1.age = 30;
    sprintf(person1.occupation, "Software Engineer");

    // Use the enum to create variables
    enum creature myCreature = DOG;

    printf("My %s is a %s and is %d years old.\n", myPet.name, myPet.species, myPet.age);
    printf("The person's name is %s, and they work as a %s.\n", person1.name, person1.occupation);

    switch (myCreature) {
        case CAT:
            printf("My creature is a cat.\n");
            break;
        case DOG:
            printf("My creature is a dog.\n");
            break;
        case BIRD:
            printf("My creature is a bird.\n");
            break;
        case FISH:
            printf("My creature is a fish.\n");
            break;
        default:
            printf("Unknown creature.\n");
            break;
    }

    return 0;
}
