
//TAGS #FORK #PARENT #CHILD #EXECL() #EXECLP()
//zombies process
//ps u command to confirm
// fork returns two values so this means it will return 4 times, this means 1 for the if, and one for the print, plus the chil for the if and for
//the print

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){

int pid;


pid=fork();

if(pid > 0){
	wait(NULL);
        printf("I'm the parent (PID=%d)\n\n",getpid());
    
}else{
        printf("I'm the son (PID= %d)\n\n",getpid());
	execlp("ls","ls","-la", NULL); 
	printf("...\n");
}

printf(" PID=%d exiting ...\n",getpid() );
return 0;
}

