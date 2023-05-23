#include <stdio.h>
#include <stdbool.h>

int main() {
    char keep;
    bool keepgoing = true;
    char name[23];

    while (keepgoing) {
        printf("Enter your name, please: ");
        scanf("%s", name);

        printf("Your name is %s\n", name);

        printf("Do you wish to keep going (y/n): ");
        scanf("%s", &keep); 

        if (keep == 'n') {
            keepgoing = false;
        }
    }

    printf("Okay, you are done.\n");
    return 0;
}