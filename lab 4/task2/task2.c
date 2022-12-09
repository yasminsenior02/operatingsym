// credit to Yasmin Senior + Deante Taylor
#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int multiply(int a, int b);
int subtract(int a, int b);
int divide(int a, int b);
int end();

int (*operands[5]) (int a, int b);

int main (void) {
	/* IMPLEMENT ME: Insert your algorithm here */

  int operand1;
  int operand2;
  int operation;
  int (*operands[]) (int,int) = {add,subtract,multiply,divide,end};
    
  while(1){
    printf("Operand 'a': ");
    scanf("%d", &operand1);
      
    printf("Operand 'b': ");
    scanf("%d", &operand2);
    
    printf("Specify the Operation to Complete: \n'0'-add\n'1'-subtract:\n'2'-multiply\n'3'-divide\n'4'-exit program\n");
    scanf("%d", &operation);
    
    printf("Result = %d\n", (*operands[operation]) (operand1,operand2));
      
  }
 
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b){
 printf ("Adding 'a' and 'b'\n"); 
 return a + b; 
}

int multiply(int a, int b){
  printf ("Multiplying 'a' and 'b'\n");
  return a * b; 
}

int subtract(int a, int b){
  printf ("Subtracting 'a' and 'b'\n");
  return a - b; 
}

int divide(int a, int b){
  printf ("Dividing 'a' and 'b'\n");
  return a / b; 
}

int end(){
  printf ("Exiting\n");
  exit(0);
}