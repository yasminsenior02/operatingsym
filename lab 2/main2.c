#include  <stdio.h>
#include  <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define   MAX_COUNT  200

pid_t getpid(void);
pid_t getppid(void);

void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

int  main(){
//may need to change to void main (void)
  pid_t pid;
  unsigned int j;
  for (j=0; j<2; j++){
    pid = fork();
    if (pid == 0){
      ChildProcess(j);
    }
    else if (pid < 0) {
      printf("Error in fork\n");
    }
    else{
      ParentProcess();
    }
  }
  return 0;
}

void  ChildProcess(int j){
  
  unsigned int randNum;
  
  printf("Child PID: %d is going to sleep!\n", getpid());
  
  srand(getpid());
  sleep(10);
  
  randNum = rand() % 10;
  sleep(randNum + 1);
  
  printf("Child PID: is awake\nWhere is my Parent: %d ?\n", getppid());
  
  exit(0);
}


void  ParentProcess(void){
  unsigned int i; 
  signed int pid; 
  signed int status;
  
  for (i = 1; i<2; i++){
    pid = wait(&status);
    printf("Child PID: %d has completed\n", pid);
  }
  
  /*
     for (i = 1; i <= MAX_COUNT; i++){
       printf("This line is from parent, value = %d\n", i);
       printf("Child PID: %d has completed", pid);
     }
     sleep(30);
     printf("*** Parent is done ***\n");
   */
}