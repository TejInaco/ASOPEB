/* Em ambas as situacoes o programa encerra, só no kill -INT pid é que puxa
 * o handler especificado, mas ambas as chamadas retornam zero.
 * SIGINT  »»  utput ZERO : Success
 * 
 * Cria um ciclo while com a funcao sleep a retorna o numero de segundos que faltam
 * Acrescentar a variavel definida
 * 
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo){
    printf("In SIGINT peh peh peh handler ...\n");
}


int main(void) {
    int secc = 30;
    
    if (signal(SIGINT,sigint_handler) < 0) { // a chamada de sistema signal permite associar
        // uma rotina de tratamento (signal handler) a um determinado sinal.
    
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);
    }
    printf("Sleeping for 30 seconds ...\n");
    while(  (secc =  sleep(secc)) > 0 );
    printf("Waking up ...\n");
    exit(0);
}
