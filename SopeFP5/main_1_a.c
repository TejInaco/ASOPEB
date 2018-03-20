/*
 * Escreva um programa com a funcionalidade que se descreve a seguir, em que dois processos, pai e filho, 
 * comunicam entre si através de um pipe: 
 * o o processo‐pai lê, do teclado, dois números inteiros (guardando‐os em variáveis do tipo inteiro) e 
 * envia‐os ao processo‐filho, através de um pipe; 
 * o o processo‐filho calcula a soma, a diferença, o produto e o quociente dos dois números e apresenta 
 * o resultado no écrã (note que o quociente de dois números inteiros pode não ser inteiro e que a 
 * operação de divisão por zero é inválida). 
 */


/* 
 * Author: notus
 * Created on 19 de Março de 2018, 16:10
 * To run in the terminal
 * Instructions:
 * gcc -Wall -o main_1a main_1_a.c 
 */

/*
 pipe()  creates  a  pipe,  a unidirectional data channel that can be used for interprocess communication.
 The array pipefd is used to return two file descriptors referring to the ends of the pipe.  
 pipefd[0] refers to the read end of the pipe.  
 pipefd[1] refers to the write  end of the pipe.
 Data written to the write end of the pipe is buffered by the kernel until it is read from the read end of the
 pipe.  For further details, see pipe(7)
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
    
    if(pid > 0) //father process 
    {
        
        int a[2];
        
        printf( "Parent:\n" );
        printf( "Insert numbers x y ? " );
        scanf( "%d %d", &a[0], &a[1]);
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