/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[], char *envp[]){
    pid_t pid;
    
    if (argc != 2) {
        printf("usage: %s dirname\n",argv[0]);
        exit(1);
    }
    
    pid=fork();
    
    if (pid > 0) //processo-pai porque o fork retornou o pid do filho
        printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);
    else if (pid == 0){ //processo-filho nota se -1 erro;
        execlp(argv[0], "ls", argv[1],NULL); // por ls  -laR
        printf("Command not executed !\n"); // ver apontamentos do prof de teorica
        exit(1);
        //fazer um WEXITSTATUS(status) - exemplo
    } 
    exit(0);
}