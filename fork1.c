#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int globvar = 6; /* external variable in initialized data */
char buf[] = "a write to stdout\n";

void err_sys(const char* x) 
{ 
    perror(x); 
    exit(1); 
}

int main(void)
{
	int var;
	pid_t pid;

/* automatic variable on the stack */
	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
		err_sys("write error");
	printf("before fork\n"); /* we don’t flush stdout */

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {    /* child */
		globvar++;        /* modify variables */
		var++;
	} else {
		sleep(2);	  /* parent */
	}



	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
	exit(0);
}
