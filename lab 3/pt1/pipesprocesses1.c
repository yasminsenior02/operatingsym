#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

//Credit to: Yasmin Senior + Deante Taylor
int main() 
{ 
   
  
    int fd1[2];  // Used to store two ends of first pipe 
    int fd2[2];  // Used to store two ends of second pipe 
  
    char input_str[100]; 
    pid_t p; 
  
    if (pipe(fd1)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    if (pipe(fd2)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
  
    printf("Enter a string to concatenate:");
    scanf("%s", input_str);
    input_str[101] ='\0'; //input null terminator
    p = fork();
  
    if (p < 0) 
    {
      fprintf(stderr, "fork Failed" ); 
      return 1; 
    } 
  
    // Parent process 
  
    else if (p > 0) 
    { 
      close(fd1[0]);  // Close reading end of pipes 
  
      
      write(fd1[1], input_str, strlen(input_str)+1);
      read(fd2[0], input_str, 100);
        
     
      wait(NULL);
      
      strcat(input_str, "gobison.org");
      
      printf("Parent concatenated string: %s\n", input_str);
  
      close(fd2[1]); // Close writing end of pipes 
      close(fd1[1]); 
    } 
  
    // Child process
    
  else
  {
    close(fd1[1]);  // Close writing end of first pipes 
    close(fd2[0]);  // Close the reading end of 2nd pipe
      
   
    read(fd1[0], input_str, 100); 
  
    strcat(input_str, "howard.edu");
  
    printf("Child concatenated string: %s\n", input_str);
    
    printf("Enter a string to concatenate:");
    scanf("%s", input_str);

    write(fd2[1], input_str, strlen(input_str)+1);
    
    // Close both reading ends 
    close(fd1[0]); 
    close(fd2[1]); 
    
    exit(0); 
  } 
}