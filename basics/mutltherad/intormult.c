#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>


void *firstThread(void *varg){
    sleep(1); 
    printf("Printing Thread\n"); 
    return NULL;
}

int main()
{
    pthread_t thread_id; 
    printf("Before\n"); 

    pthread_create(&thread_id, NULL, firstThread, NULL); 
    pthread_join(thread_id, NULL); 
    printf("After\n"); 
    exit(0);
    return 0; 
}