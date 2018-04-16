/* 
 * File:   main.c
 * Author: notus
 * Created on 16 de Abril de 2018, 16:28
 * // PROGRAMA 1b.c
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 10000

void * thrfunc(void * arg) {
 int i;
 
fprintf(stderr, "Starting thread %s\n", (char *) arg);
 
 for (i = 1; i <= NUMITER; i++) write(STDERR,arg,1);
 
 return NULL;
}

int main()
{
    int useConstante;
    scanf("%i", &useConstante);
    
    //int * pointerToUse; // = (int *) malloc(sizeof(int));
    
    int * pointerToUse = &useConstante;
    
    
    pthread_t ta, tb;
   
    pthread_create(&ta, NULL, thrfunc, &pointerToUse);
    useConstante++;
    pthread_create(&tb, NULL, thrfunc, &pointerToUse);

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
 
 return 0;
}
