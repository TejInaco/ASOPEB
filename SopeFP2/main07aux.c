
//TAGS #FORK #PARENT #CHILD
//ps u command to confirm
// fork returns two values so this means it will return 4 times, this means 1 for the if, and one for the print, plus the chil for the if and for
//the print

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

int i,n;

n=atoi(argv[1]);
for(i=1; i<=n; i++){
	printf("CHILD (%d-%d): Hello father... %d!\n",getpid(),getppid(),i);
}
return 10;
}

