
/* 
 * File:   Folha de exercicios nº3
 * Author: Exercicio 2
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Exercicio 2 
 */
int main(void) {
        //primeiro argumento o descritor do ficheiro
        //segundo arg é o buffer
        //tamanho count bytes
//write(STDOUT_FILENO,"1",1); //retorna o nª de bites escritos
printf("%d\n",1);   
    if(fork() > 0) {
        //write(STDOUT_FILENO,"2",1);
        //write(STDOUT_FILENO,"3",1);
        printf("%d\n", 2);
        printf("%d\n", 3);
    } else {
        //write(STDOUT_FILENO,"4",1);
        //write(STDOUT_FILENO,"5",1);
        printf("%d\n", 4);
        printf("%d\n", 5);
    }
printf("exit %d\n",666);
//write(STDOUT_FILENO,"\n",1);
 return 0; 
}

