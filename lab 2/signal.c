/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//Credit to: Professor Burge Office Hours 07 OCT 2021

int alarmOn = 0;

void alarmHandler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(5);
 
  alarmOn = 1;
  
 //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, alarmHandler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 1 second
  
  while(1){
    alarmOn = 0;
    alarm(5);
  
    while (!alarmOn) //busy wait for signal to be delivered
     ;
    printf("Turing was right!\n");
  }
  return 0; //never reached
}