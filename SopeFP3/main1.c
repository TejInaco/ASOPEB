/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: notus
 *
 * Created on 19 de Fevereiro de 2018, 13:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>
#include <time.h>


int main( int argc, char *argv[] ){
  
  /* Conversion string into int */
  int data1 = atoi(argv[1]);
  int data2 = atoi(argv[2]);
  
  printf( "\nargv[1] in intger=%d\n",data1 );
  printf( "\nargv[2] in intger=%d\n",data2 );

  //variaveis para a medicao do tempo
clock_t start, end;
clock_t start2, end2;
struct tms t;           //exemplo do material de apoio
long ticks;             //exemplo do material de apoio


double cpu_time_used;
  
  
  int r = 0; 
  int i = 0;

//inicio da contagem do clock;
 //start = clock();

start = time(&t); /*inicio da medicao do tempo;*/
ticks = sysconf(_SC_CLK_TCK);
  
  //loop do programa principal
  while( (i < 10 ) && r != data2 ){
    r = rand() % data1;
    
    printf("Numero escolhido : %d\n", r);
    i++;
    printf("Numero iter : %d\n", i);
  }
 
 
 end2 = time(&t);
 //fim do programa final
 //end = clock();
 
 
 //calculos 
 cpu_time_used = ((double) (end -start)) / CLOCKS_PER_SEC;
  
  printf("\nTempo do CPU : %lf\n", cpu_time_used );
  printf( "\nClock ticks per second: %ld\n", ticks );
  printf( "Clock:       %4.2f s\n", (double) (end-start)/ticks );
  printf( "User time:       %4.2f s\n", (double) (t.tms_utime)/ticks );
  printf( "System time:       %4.2f s\n", (double) (t.tms_stime)/ticks );
  printf( "Children user time:       %4.2f s\n", (double) (t.tms_cutime)/ticks );
  printf( "Children system time:       %4.2f s\n", (double) (t.tms_cstime)/ticks );
  
    return (EXIT_SUCCESS);
}

