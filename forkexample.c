#include <stdio.h>
#include <stdlib.h>

int main() {

	int pid;

	pid = fork();
	if (pid > 0) {
		printf ("Parent: Child id %d\n", pid);
		wait();
		printf ("Parent: Child %d is done.\n", pid); 
	}
	else if (pid == 0) {
		printf ("Child: I am child %d\n", pid);
		exit(0);
	}
	else
		printf ("Fork Error\n");

	return 0;
}
		

