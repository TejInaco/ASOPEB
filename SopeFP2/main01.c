
//TAGS #FORK #PARENT #CHILD
//Fork return value is different for 'parent' and 'child'
//ps command to confirm

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void){

int fork_return_values;

printf("before fork...\n");

fork_return_values=fork();

printf("I'm process %d: 'fok_return_value'=%d. My parent is %d.\n\n", getpid(),fork_return_values,getppid());

return 0;
}
