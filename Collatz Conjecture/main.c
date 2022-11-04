#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/*
*main func calling in the check_loop_iterative func first and the histogram func only
*
*inputs taken from the user is the first integer and the loop lenght
*
*using malloc and free commands for the integer pointers aswell
*/

int main()
{

  int x,j,y,digit;
  
	printf("Enter the first element of the array: ");
	scanf("%d",&x);
	printf("\nEnter the size of the sequence: ");
	scanf("%d",&y);
  int *seq = (int*)malloc(sizeof(int)*y); 
  int *looplen = (int*)malloc(sizeof(int)*(y/2));
  int* loop = (int*)malloc(sizeof(int)*MAX_RANGE);
  int *h = (int*)malloc(sizeof(int)*9);
  check_loop_iterative(generate_sequance,x,y,loop,looplen);
  if(*(loop)!=0){
    printf("Our loop = {");
    for(j=0;j<*(loop+MAX_RANGE);j++){
      printf("%d",*(loop+j));
      if(j<*(loop+MAX_RANGE)-1){printf(", ");}
    }
    printf("}\n");
  }
  
  free(loop);
  free(looplen);

  hist_of_firstdigits(generate_sequance,x,y,h,digit);

      printf("histogram of the sequance = {");
    for(j=0;j<9;j++){
      printf("%d ",*(h+j));
      if(j<8)printf(",");
    }
    printf("}\n");
  
  free(h);
  free(seq);
  

	return 0;
}

