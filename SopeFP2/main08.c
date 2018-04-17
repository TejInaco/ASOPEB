//TAGS #FORK #PARENT #CHILD #CAT #EXECLP #WEXITSTATUS
//ps u command to confirm
//the print  after the exec never will be printed because the only msg usefull after the exec is an error mensage
//furthermore, the son process because of the exec will not be printed the printf outside the if
//this happens because the child copies everything from the father and because of that no fuction or printf will be used after the exec call
//WEXITSTATUS gives the child status
//Only possible to run when  chagend for a system() instead a execlp call. Both are very similar however, system() does a fork inside himself
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){

int pid;
int status;

pid=fork();

if(pid > 0){
        wait(&status);
        printf("I'm the parent (PID=%d)\n\n",getpid());
        printf("My son exited with EXIT CODE = %d", WEXITSTATUS(status));

}else{
        printf("I'm the son (PID= %d)\n\n",getpid());
        execlp("cat","cat","main08.c",">","main08_copy.c", NULL);
        //try execl() -vai dar erro
        //execl("./runteste1","runteste1","3",NULL);
        // o printf nao chega a ser impresso porque a unica funcao que faz sentido depois de um exec eh uma msg de error caso exec devolva erro
        printf("EXEC() failed !!!\n");
	exit(1);
}
printf(" PID=%d exiting ...\n",getpid() );
return 0;
}

