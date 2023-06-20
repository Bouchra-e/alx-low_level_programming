#include <stdio.h>
#include <unistd.h>

int main(void) 
{
pid_t parent_pid = getppid();

printf("PID of the parent process : %d\n", parent_pid);
return 0;
}
