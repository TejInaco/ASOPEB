#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/* Nota Explicativa
 * A chamada de sistema signal permite associar uma rotina de tratamento (signal handler) a um determinado
 * sinal.
 * Enviar sinal SIGINT ao programa de execucacao.
 * Usar o comando Kill para enviar o sinal ao processo.
 * Linha de comandos: kill -INT 12121 »ACTIVA o HANDLER 
 *                  OU
 * SIGINT » enviado através do crtl+c: vai puxar o handler definido
 * Passa para o processo seguinte. O echo devolvido é 127
 *
 * Sleep - delay for a specified amount of time
 * sleep()  makes  the  calling  thread  sleep  until seconds seconds have 
 * elapsed or a signal arrives which is not ignored.
 * Devolve o numero de segundo em falta caso seja interrompida
 *
 * Created on 12 de Março de 2018, 16:13
 */
void sigint_handler(int signo){
    printf("In SIGINT peh peh peh handler ...\n");
}


int main(void) {
    if (signal(SIGINT,sigint_handler) < 0) {   
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);
    }
    printf("Sleeping for 30 seconds ...\n");
    
    sleep(30);
    
    printf("Waking up ...\n");
    exit(0);
} 

