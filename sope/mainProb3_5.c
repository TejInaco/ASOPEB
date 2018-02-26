/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mainProb3_5.c
 * Author: notus
 *
 * Created on 26 de Fevereiro de 2018, 17:50
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


/*
 * 
 */
int main(void) {
    pid_t pid;
    pid_t pid2;
    
    pid=fork();
    
    switch (pid) {
        case -1:
            perror("fork");
            break;
        case 0: //filho
            pid2 = fork();
            switch(pid2){
                case -1:
                    perror("fork");
                    break;
                case 0: //filho
                    printf("friends !\n");
                    break;
                default:
                    printf("my  no 2Switch\n");
                    break;
            }
            //printf("My !\n");
            break;
        default: //pai
            printf("Hello\n");
            break;
    }
     
return 0;   
}

