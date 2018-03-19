/*
 * Conclusao: como o fork() devolve dois valores, ao efectuar os switchs
 * se nos livrarmos do break; ele irá avaliar nos dois resultados
 * dai agora ele entrar no primeiro case e no default
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
//    pid_t pid3;
    
    pid=fork();
    
    switch (pid) {
        case -1:
            perror("fork");
            break;
        case 0: //filho
            
            switch(pid2){
                case -1:
                    perror("fork");
                    break;
                case 0: //filho
                    printf("my  no 2Switch\n");
//                    pid3 = fork();
/*                        switch(pid2){
                                case -1:
                                    perror("fork");
                                    break;
                                case 0: //filho
                                    printf("friends !\n");
                                    break;
                                default:             
                                    printf("my  -3\n");
                                    
                                    break;
*/ //                        }
//                    break;
                default:             
                        printf("friends !\n");
                        break;
                        
            }
            //printf("My !\n");
            break;
        default: //pai
            printf("Hello - 1\n");
            pid2 = fork();
            break;
    }
     
return 0;   
}