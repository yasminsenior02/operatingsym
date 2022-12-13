#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
  // recieved help from Munir credit to Yasmin
int main() 
{ 
    // We use two pipes 
    // First pipe to send input string from parent 
    // Second pipe to send concatenated string from child 
  
    int fd1[2];  
    int fd2[2];  
  
    char fixed_str[] = "howard.edu"; 
    char input_str[100];

    char inputstr2[100];

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
    p = fork(); 
  
    if (p < 0) 
    { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 
  
    else if (p > 0) 
    { 
  
        close(fd1[0]);  // Close reading pipe
  
        // Write input string
        write(fd1[1], input_str, strlen(input_str)+1); 
        
  
        wait(NULL); 
  
        close(fd1[1]);

//---------------------------------------------------------
        close(fd2[1]); // close writing end of pipe 2
        char concat_str[100]; 

        read(fd2[0], concat_str, 100);

        printf("Concatenated string %s\n", concat_str);
        close(fd2[0]);

    } 
  
    // child process is reading from pipe fd1
    else
    { 
        close(fd1[1]);  // Close writing end of first pipes 
      
        // Read a string using first pipe 
        char concat_str[100]; 
        read(fd1[0], concat_str, 100); 
  
        // Concatenate a fixed string with it 
        int k = strlen(concat_str); 
        int i; 
        for (i=0; i<strlen(fixed_str); i++) 
            concat_str[k++] = fixed_str[i]; 
  
        concat_str[k] = '\0';   // string ends with '\0' 
  
        printf("Concatenated string %s\n", concat_str);
        // Close both reading ends 
        close(fd1[0]); 


        printf("Enter a string to concatenate:");
        scanf("%s", inputstr2); 
        strcat(concat_str, inputstr2);
        close(fd2[0]); // close reading end of pipe 2
        // write new input string/concat string to pipe 2
        write(fd2[1], concat_str, strlen(concat_str)+1); 

        wait(NULL);
        close(fd2[1]);

        exit(0); 
    } 
} 