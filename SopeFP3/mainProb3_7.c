/*
 * @brief The only thing coherent after a execlp is an error message or a exit
 * process. In this way, the meaning behind this code is compiling a program 
 * declared in the main call, who will be pass over to the exec by the argv[1]
 */

// PROGRAMA p7.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    char prog[20];
    
    sprintf(prog,"%s.c",argv[1]);
    
    execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL);
    
    //1º - filename
    //2º - listagem de arg
    printf("Can't execute \n");
    exit(-1);

}