// Yasmin Senior 
#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  main(void)
{
     int i;
     pid_t  pid;
     for (i=0; i<2; i++){
     pid = fork();
     if (pid == 0) 
          ChildProcess(i);
     else if (pid < 0)
          printf("Issue in fork \n");
     }
          ParentProcess();
}

void  ChildProcess(int mypid)
{
     int randomnum;
     printf("Child Process PID: %d is going to sleep!", getpid());
     srand(getpid());
     randomnum = rand() % 10;
     sleep(randomnum + 1);
     printf("Child Pid: is awake!\nWhere is my Parent: %d?\n", getpid());
}

void  ParentProcess(void)
{
     int i;
     int pid;
     int status;

     for (i = 0; i <= 2; i++){
     pid = wait(&status);
     printf("Child Pid: %d has completed\n",pid);
     }
}