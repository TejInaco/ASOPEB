// PROGRAMA p03.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

void *PrintHello(void *threadnum){
   printf("Hello from thread no. %d!\n", *(int *) threadnum);
   pthread_exit(NULL);
}

int main(){
 pthread_t threads[NUM_THREADS];
 int t;

 for(t=0; t< NUM_THREADS; t++){
   printf("Creating thread %d\n", t);
   pthread_create(&threads[t], NULL, PrintHello, (void *)&t);
 }

 pthread_exit(0);
}
/**
*
## 3a ##
 Na consola visualiza-se os dados indicados em baixo.
Mas, ah medida que vamos correndo o ficheiro, o resultado nunca serah igual
porque as posicoes dos threads mudam. Nao existe um padrao.
Apenas podemos dizer que o thread 0 é o primeiro a ser criado.
Creating thread 0
Creating thread 1
Creating thread 2
Hello from thread no. 2!
Creating thread 3
Hello from thread no. 2!
Hello from thread no. 3!
Creating thread 4
Hello from thread no. 4!
Creating thread 5
Hello from thread no. 5!
Creating thread 6
Hello from thread no. 6!
Creating thread 7
Hello from thread no. 7!
Creating thread 8
Hello from thread no. 8!
Creating thread 9
Hello from thread no. 9!
Hello from thread no. 10!

## 3b ###

*/
