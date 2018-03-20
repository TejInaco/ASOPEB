/*
 * 
 */

/* 
 * File:   main_1_b.c
 * Author: notus
 * Created on 19 de Março de 2018, 17:37
 * To run in the terminal
 * Instructions:
 * gcc -Wall -o main_1b main_1_b.c 
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1


int main(void) {

    int fd[2];
    pid_t pid;
    
    pipe(fd);
    
    pid = fork();
    //fazer a declaracao da estrutura
    struct aEnviar {
        int firstNumb;
        int secondNumb;
    };
     
    if(pid > 0) //father process 
    {
        
        int a[2];
        
        printf( "Parent:\n" );
        printf( "Insert numbers x y ? " );
        scanf( "%d %d", fversion.firstNumb, fversion.secondNumb);
        close( fd[READ]  );
        write( fd[WRITE],a, 2*sizeof(int) );
        close( fd[WRITE] );
         
    }
    else // child process
    { 
        
        int b[2];
        
        //printf("First print f Son:\n");
        
        close( fd[WRITE] );
        read( fd[READ],b, 2*sizeof(int) );
        printf( "Second  Son:\n");
        printf( "Soma = %d\n", b[0]+b[1] );
        printf( "Substracao = %d\n", b[0]-b[1] );
        printf( "Produto = %d\n", b[0]*b[1] );
        
        if( b[1] == 0 ){
            printf( "invalida divisao, excepcao zero.\n" );
        }else{
            printf( "Quociente = %d\n", b[0]/b[1] );
        }
        close( fd[READ] );
    
    }
    
    return 0;
}