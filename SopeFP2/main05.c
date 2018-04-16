
//TAGS #FORK #PARENT #CHILD #sleep #zoombie
//zombies process tree of child processes with some zombies
//ps u command to confirm
// fork returns two values so this means it will return 4 times, this means 1 for the if, and one for the print, plus the chil for the if and for
//the print

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){

int pid,i;

for(i=1;i<=3;i++){
pid=fork();

if(pid > 0){
        printf("I'm the parent (PID=%d)\n\n",getpid());
        sleep(6);
}else{
        printf("I'm the son (PID= %d). My parent is %d\n\n",getpid(),getppid());
	break; //note this por causa do ciclo for
}
}
printf(" PID=%d exiting ...\n",getpid() );
return 0;
}

