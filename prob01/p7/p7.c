// PROGRAMA p7.c
#include <stdio.h>
#include <stdlib.h>

static void exitHandler1(void){
  printf("Executing exit handler 1\n");
}

static void exitHandler2(void){
  printf("Executing exit handler 2\n");
}


int main( int argc, char *argv[] ) {
  //eles executam na ordem inversa
 
//  if( atexit(exitHandler2) == 0 && atexit(exitHandler1) == 0 ){
    printf("Main Done!");
  atexit(exitHandler2);
  atexit(exitHandler1);
  //abort();
  exit(0);  
 // }
   
   // zero é geralmente indicativo de "sucesso"
}
