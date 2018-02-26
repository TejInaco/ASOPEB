#include <sys/times.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {
  
  /* Conversion string into int */
  int data1 = atoi(argv[1]);
  int data2 = atoi(argv[2]);
  printf( "\nargv[1] in intger=%d\n",data1 );
  printf( "\nargv[2] in intger=%d\n",data2 );
  int r = 0; 
  int i = 0;
  
  
  //variaveis para a medicao do tempo
  clock_t start, end;

  struct tms t;  //exemplo do material de apoio
  long ticks; //exemplo do material de apoio
  
  
  
  start = times(&t); /*inicio da medicao do tempo;*/
  ticks = sysconf(_SC_CLK_TCK);



  
  //loop do programa principal
  while( (i < 10 ) && r != data2 ){
    r = rand() % data1;
    
    printf("Numero escolhido : %d\n", r);
    i++;
    printf("Numero iter : %d\n", i);
  }
  



    
  printf( "\nClock ticks per second: %ld\n", ticks );
  end = times(&t);
  //fim do programa final 
  
  printf( "Clock:                     %4.2f s\n", (double) ( end-start)/ticks );
  printf( "User time:                 %4.2f s\n", (double) ( t.tms_utime)/ticks );
  printf( "System time:               %4.2f s\n", (double) ( t.tms_stime)/ticks );
  printf( "Children user time:        %4.2f s\n", (double) (t.tms_cutime)/ticks );
  printf( "Children system time:      %4.2f s\n", (double) (t.tms_cstime)/ticks );
  
 exit(0); 
}

