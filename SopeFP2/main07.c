
//TAGS #FORK #PARENT #CHILD #sleep #zoombie
//ps u command to confirm
// fork returns two values so this means it will return 4 times, this means 1 for the if, and one for the print, plus the chil for the if and for
//the print  after the exec never will be printed because the only msg usefull after the exec is an error mensage
//furthermore, the son process because of the exec will not be printed the printf outside the if
//this happens because the child copies everything from the father and because of that no fuction or printf will be used after the exec call

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
	//execlp("ls","ls","-la", NULL);
	//try execl() -vai dar erro
	execl("./runteste1","runteste1","3",NULL);
	// o printf nao chega a ser impresso porque a unica funcao que faz sentido depois de um exec eh uma msg de error caso exec devolva erro
	printf("Cheguei a ser impressoo? \n");
}

printf(" PID=%d exiting ...\n",getpid() );

return 0;
}

