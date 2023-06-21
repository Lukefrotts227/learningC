// J-S 
#include <pthread.h>
#include <windows.h> 
#include <stdio.h> 
#include <unistd.h>

void *turn1(void *args)
{
    for (int i = 0; i < 44; i++)
    {
        sleep(2); 
        printf("Turn 1 : %i\n", i);
    }
    return NULL;

}

void turn2()
{   
    for (int i = 0; i < 44; i++)
    {
        sleep(1); 
        printf("Turn 2 : %i\n", i);
    }

}

int main(void) {
    pthread_t newthread; 
    pthread_create(&newthread, NULL, turn1, NULL);
    turn2();
    pthread_join(&newthread, NULL); 
    // success
    return 0;
}