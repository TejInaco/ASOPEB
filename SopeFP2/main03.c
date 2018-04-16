//TAGS #FORK #PARENT #CHILD
//Fork return value is different for 'parent' and 'child'
// Which one runs first, after fork?
//ps command to confirm
// fork returns two values so this means it will return 4 times, this means 1 for the if, and one for the print, plus the chil for the if and for
//the print

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){

int pid;

write(STDOUT_FILENO, "before fork...\n",14 );

pid=fork();

if(pid > 0){
        printf("I'm the parent (PID=%d)\n\n",getpid());
}else{
        printf("I'm the son (PID= %d)\n\n",getpid());
}

printf(" PID=%d exiting ...\n",getpid() );

return 0;
}


