// PROGRAMA p6a.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_LENGTH 256
//#define MAX 255

int main( int argc, char *argv[] ) {
    FILE *src, *dst;
    char buf[ BUF_LENGTH ];
    //int fileSource, fileDest;
   
  //se o numero de argumentos não for tres dá uma mensagem indicativa em como usar o comando              
  if(argc != 3 ){
     printf("Usage: %s <source> <destination>\n",  argv[0] )
  return 1;
  }
          
  if ( ( src = fopen( argv[1], "r" ) ) == NULL ) {
      //perror( "infile.txt" );
      //%d para inteiros dá-me um erro
      // strerror returnaum apontador
      //printf( "Error1: %d \n", strerror( errno ) );
      printf( "Error E1: %d \n", errno );
      exit(1);
  }
          
  if ( ( dst = fopen( argv[2], "w" ) ) == NULL ) {
      //perror( "outfile.txt" );
      //printf( "Error2: %d \n", strerror(errno ) );
      printf("Error E2: %d\n", errno );
      close( src );
      exit(2);
  }
        
  while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL ) {
          fputs( buf, dst );
  }
  
  fclose( src );
  fclose( dst );
  
  exit(0); // zero é geralmente indicativo de "sucesso"
}
