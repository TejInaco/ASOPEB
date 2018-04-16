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
#define NUMITER 20000

void * thrfunc(void * arg) {
 int i;
 
fprintf(stderr, "Starting thread %s\n", (char *) arg);
 
 for (i = 1; i <= NUMITER; i++) write(STDERR,arg,1);
 
 return NULL;
}

int main()
{
    char useConstante;
    scanf("%d", &useConstante);
    
    pthread_t ta, tb;

    pthread_create(&ta, NULL, thrfunc, useConstante);
    pthread_create(&tb, NULL, thrfunc, useConstante++);

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
 
 return 0;
}