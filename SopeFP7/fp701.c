
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAXELEMS 10000000 // nr. max de posicoes
#define MAXTHREADS 100 // nr. max de threads
#define min(a, b) (a)<(b)?(a):(b)

int npos;
pthread_mutex_t mut=PTHREAD_MUTEX_INITIALIZER; // mutex p/a sec.critica
int buf[MAXELEMS], pos=0, val=0; // variaveis partilhadas
/**
* A partir do momento que comento pthread_mutex_lock(&mut) e
* pthread_mutex_unlock(&mut); vai dar erro no buffer quando elements > threads
*/
void *fill(void *nr){
 while (1) {
     pthread_mutex_lock(&mut);
     if (pos >= npos) {
         pthread_mutex_unlock(&mut);
         return NULL;
        }
    buf[pos] = val;
    pos++; val++;
    pthread_mutex_unlock(&mut);
    *(int *)nr += 1;
   }
}


void *verify(void *arg){
 int k;
 for (k=0; k<npos; k++)
       if (buf[k] != k) // detecta valores errados
        printf("ERROR: buf[%d] = %d\n", k, buf[k]);
  return NULL;
}

/**
* Sincronizacao de threads acedendo a variaveis partilhadas, usando um mutex
**/
int main(int argc, char *argv[]) {
   int k, nthr, count[MAXTHREADS]; // array para contagens
   pthread_t tidf[MAXTHREADS], tidv; // tids dos threads
   int total;

   if(argc != 3){
     printf("Usage: %s <nr_pos> <nr_thrs>\n",argv[0]);
     return 1;
   }

  npos = min(atoi(argv[1]), MAXELEMS); //no. efectivo de posicoes
  nthr = min(atoi(argv[2]), MAXTHREADS); //no. efectivo de threads

   for (k=0; k<nthr; k++) { // criacao das threads 'fill'
    count[k] = 0;
    pthread_create(&tidf[k], NULL, fill, &count[k]);
   }

   total=0;

   for (k=0; k<nthr; k++) { //espera threads 'fill'
     pthread_join(tidf[k], NULL);
     printf("count[%d] = %d\n", k, count[k]);
     total += count[k];
   }

   printf("total count = %d\n",total); // mostra total

   pthread_create(&tidv, NULL, verify, NULL);
   pthread_join(tidv, NULL); // espera thread 'verify'

   return 0;
  }
/**
1b) O surgimento de erros ocorrem quando o primeiro argumento eh maior do que o
numero de threads, ou seja, o numero efectivo de psicoes eh maior do que o
numero efectivo de threads.
Isto obriga o thread fill a entrar no seu if, que tem um pthread_mutex_unlock(&mut)
que nao esta a fazer pthread_mutex_unlock de nada
#### pthread_mutex_unlock ####
If successful, the pthread_mutex_lock() and pthread_mutex_unlock() functions shall
return zero; otherwise, an error number shall be returned to indicate the error.
### In another words
The pthread_mutex_unlock() function may fail if:
[EPERM]
The current thread does not own the mutex.
These functions shall not return an error code of [EINTR].
*/
