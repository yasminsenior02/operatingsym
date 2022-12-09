//Yasmin Senior
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarmOn = 0;
int numAlarm = 0;

time_t start, stop;

void handler(int signum)
{ 
  printf("Hello World!\n");
  sleep(1);
  alarmOn = 1;
  numAlarm++;
}

void handleSigint(int signum){
  int timeTotal;
  stop = time(NULL);
  timeTotal = stop - start;
  printf("The number of alarms were %d\n", numAlarm);
  exit(1);
}

int main(int argc, char argv[])
{
  signal(SIGALRM, handler); 
  signal(SIGINT, handleSigint);
  start = time(NULL);
  while(1){ 
    alarmOn = 0;
    alarm(2);
    while(!alarmOn);
      printf("Turing was right!\n");
      alarmOn = 1;
  }
  return 0; 
}