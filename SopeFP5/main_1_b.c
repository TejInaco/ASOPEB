/* 
 * File:   main_1_b.c
 * Author: notus
 * Created on 19 de Março de 2018, 17:37
 * To run in the terminal
 * Instructions:
 * gcc -Wall -o main_1b main_1_b.c 
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1


int main(void) {

    int fd[2];
    pid_t pid;
    
    pipe(fd);
    
    
    //fazer a declaracao da estrutura
    typedef struct aEnviar {
        int firstNumb;
        int secondNumb;
    } Pair;
     
    
    
    if( (pid = fork() ) < 0 ){
        fprintf( stderr, "fork error\n");
        exit(1);
    }
    
    
    if(pid > 0) //father process 
    {
        Pair p;
        
        printf( "Parent:\n" );
        printf( "Insert numbers x y ? " );
        scanf( "%d %d", &p.firstNumb, &p.secondNumb ) ;
        
        close( fd[READ]  ); //read pipe isn't used  at all
        write( fd[WRITE], &p, sizeof( Pair) );
        close( fd[WRITE] ); //close write pipe
         
    }
    else // child process
    { 
        
        Pair p2;
        
        //printf("First print f Son:\n");
        close( fd[WRITE] );
        read( fd[READ], &p2, sizeof( Pair) );
        printf( "Second  Son:\n");
        printf( "Soma = %d\n", p2.firstNumb + p2.secondNumb );
        printf( "Substracao = %d\n", p2.firstNumb - p2.secondNumb );
        printf( "Produto = %d\n", p2.firstNumb * p2.secondNumb );
        printf( "Divisao = %d\n", p2.firstNumb / p2.secondNumb );
        
        close( fd[READ] );
        
    }
    return 0;
}