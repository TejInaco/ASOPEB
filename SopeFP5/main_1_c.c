/* 
 * File:   main_1_c.c
 * Author: notus
 * To run in the terminal
 * Instructions:
 * gcc -Wall -o main_1b main_1_b.c
 * 
 *  */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1
#define MAX_LENGHT 256


int main(void) {

    int fd[2];
    pid_t pid;
    pipe(fd);
    
    if( (pid = fork() ) < 0){
        fprintf( stderr, "fork error\n");
    }
    
    if(pid > 0) //father process 
    {
        
        char nb1[MAX_LENGHT];
        char nb2[MAX_LENGHT];
        
        printf( "Parent:\n" );
        printf( "Insert numbers x y ? " );
        scanf( "%s %s", nb1, nb2);
        close( fd[READ]  ); // read pipe isn't used at all
        write( fd[WRITE], nb1, MAX_LENGHT );
        write( fd[WRITE], nb2, MAX_LENGHT );
        close( fd[WRITE] ); // close write pipe
         
    }
    else // child process
    { 
        
        char b1[MAX_LENGHT];
        char b2[MAX_LENGHT];
        int n;
        //printf("First print f Son:\n");
        
        close( fd[WRITE] );
        
        n = read( fd[READ], b1 , MAX_LENGHT  );
        b1[n] = 0;
        
        n = read( fd[READ], b2 , MAX_LENGHT  );
        b2[n] = 0;
       
        printf( "Son  ###  Son:\n");
        
        int b1_int = atoi(b1);
        int b2_int = atoi(b2);
        
        printf( "Soma = %d\n", b1_int + b2_int );
        printf( "Substracao = %d\n", b1_int - b2_int );
        printf( "Produto = %d\n", b1_int * b2_int );
        printf( "Divisao = %d\n", b1_int / b2_int );
        close ( fd[READ] );
       
    }
    return 0;
}
