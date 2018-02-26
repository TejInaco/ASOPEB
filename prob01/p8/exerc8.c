#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
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
  double cpu_time_used;
    
  int r = 0; 
  int i = 0;

  //inicio da contagem do clock;
   start = clock();

  
  //loop do programa principal
  while( (i < 10 ) && r != data2 ){
    r = rand() % data1;
    
    printf("Numero escolhido : %d\n", r);
    i++;
    printf("Numero iter : %d\n", i);
  }
 
 
   end = clock();
  //calculos 
  cpu_time_used = ((double) (end -start)) / CLOCKS_PER_SEC;
  
  printf("\nTempo do CPU : %lf\n", cpu_time_used );
   exit(0);
}
