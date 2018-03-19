/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Folha de problemas nª3
 * Exercicio: 1
 *
 * Created on 26 de Fevereiro de 2018, 16:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * // PROGRAMA p1.c 
 */
int global=1;

int main(void) {
 int local = 2;
 
    if(fork() > 0) {
       printf("PID = %d; PPID = %d\n", getpid(), getppid());
       global++;
       local--;
    } else {
       printf("PID = %d; PPID = %d\n", getpid(), getppid());
       global--;
        local++;
    }
    
    printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);
    return 0;
} 
 

