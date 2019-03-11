#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main ()
{
  pid_t child_pid;
  //char *cmd = "ps aux | awk '{ print $8,\"\t\",$2}' | grep -w Z";
   /* Create child*/
  child_pid = fork ();
  if (child_pid > 0) {

    /* Parent process */
    printf ("Parent(pid = %d): I am starting...\n", getpid());
    printf ("Parent: I am dying....\n");
    //sleep (10);
    //printf ("\nThe Zombie processes are: \n");
    //system (cmd);
    exit(0);
  }
  else {

    /*Child process. Exit immediately. */
    sleep(10);
    printf ("Child(pid = %d)\n", getpid());
    printf ("Child(ppid = %d)\n", getppid());
    exit (0);
  }
  return 0;
}
