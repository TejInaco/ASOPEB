/*
 * @brief a
 * @param Criou 3 processos zombies com o pid 10025, 10032, 10042, cujo 
 * o seus status aparece como Z+, e mais à direita aparece [SOPE] <defunct>
 * 
 * @brief b 
 * @param Manter um if com o waitppit(status)
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
#include <stdlib.h>

int main(void){
    pid_t pid;
    int i, j;
    int status;
    
    printf("I'm process %d. My parent is %d.\n", getpid(),getppid());

    for (i=1; i<=3; i++) {
        pid = fork();
        
        if ( pid < 0) {
            printf("fork error");
            exit(1);
        } else if (pid == 0) {
            printf("I'm process %d. My parent is %d. I'm going to work for 1 second ...\n",getpid(),getppid());
            sleep(1); // simulando o trabalho do filho
            printf("I'm process %d. My parent is %d. I finished my work\n", getpid(),getppid());
            exit(0);
        }else{
        
        }
// a eliminar na alinea c)
// simulando o trabalho do pai
        if(   waitpid(&status) < -1 ){
                printf("Pid process %d.\n", pid);
                for (j=1; j<=10; j++) {
                    sleep(1);
                    printf("father working ...\n");
                }
            }
        }
    exit(0);
    }
    


