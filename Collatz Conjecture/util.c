#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/*
*generate_sequance func 3 int and 1 int pointer parameter
*
*creating the sequance as it is required and is recursive
*
*
*/

void generate_sequance(int xs, int currentlen, int seqlen, int *seq){
  

  if(currentlen==0){*seq = xs;}

  else if(xs%2==0){
  	*seq = xs/2;
  }
  else if(xs%2!=0){
  	*seq = 3*xs + 1;
  }
  if(currentlen!=seqlen-1){
  generate_sequance(*seq,currentlen+1,seqlen,seq+1);
}
}
/*
*
*check_loop_iterative func takes a void func pointer 2 int and 2 int pointers as parameter
*
*calls in the generate sequance func and creates the sequance and checks the sequance for loops inside
*
*is recursive
*/
void check_loop_iterative(void (*f)(int,int,int,int*),int xs,int seqlen,int *loop,int *looplen){
  
int *ls;
int *le; 
int j,a,lsd,led;
static int x = 0;
ls = &lsd;
le = &led;
int *seq = (int*)malloc(sizeof(int)*seqlen);
  
  f(xs,0,seqlen,seq);

  if(x==0){
    printf("Our sequence: ");
  for(int t = 0;t<seqlen;t++){
  printf("%d ",*(seq+t));
  }
  create_loop_len(looplen,seqlen);x = 1;
}


  if(*looplen!=1 && a!=1){printf("\nTrying to find a loop for loop lenght =  %d \n",*looplen);}

  a = has_loop(seq,seqlen,*looplen,&lsd,&led);
  
  if(a==1){
  *(loop+MAX_RANGE) = *looplen;   
  printf("LOOP FOUND with loop lenght of %d\nfirst occurance: %d(first digit) %d(last digit) \t\n\n",*looplen,*ls,*le);
  for(j=0;j<*looplen;j++){
    *(loop+j) = *(seq+j+*ls);
  }
}
else if(*looplen==2&&a!=1){
  
  printf("No loop has been found");
  *(loop) = 0;
  *(looplen) = 0;
}
  if(*looplen!=1 && a!=1){
    free(seq);
   check_loop_iterative(generate_sequance,xs,seqlen,loop,looplen+1); 
  }
}
/*
*
*has_loop func got 3 int pointer and a int parameter
*
*it is the function checking for loops inside the sequance for the function above
*
*returns 1 if loop has been found else 0
*
*/
int has_loop(int *arr,int n,int looplen,int *ls,int *le){


int t,ctr=0;
 
 int i=0;

printf("\n");
for(i=n-1;i>0;i--){
	if(*(arr+i)==*(arr+i-looplen)){
   t = i; 
   ctr++;
   if(ctr==looplen){
    break;
   }
  }
}

*le = t;
*ls = t - looplen;

 if(ctr==looplen){return 1;}
 
 else return 0;
}
/*
 *create_loop_len func fills in the looplen pointer like an array with the possible loop lenghts 
 * 
 * 
 * used in check_loop_iterative func
 * 
 * 
 */
void create_loop_len(int *looplen,int seqlen){

 int i,t;


 for(i=0;i<seqlen/2;i++){

  *(looplen+i) = (seqlen/2)-i;

 }
}
/*
*
*hist_of_firstdigits func takes a void func pointer and 2 integers and 1 int pointer
*
*calls in the generate_sequance func creates the sequance according to given starting integer and lenght
*
*fills in the according to histogram of first digits in the sequance
*
*
*/
void hist_of_firstdigits(void (*f)(int,int,int,int *),int xs,int seqlen,int *h,int digit){

  int x,a,s;
  static int i = 0;

  int *seq = (int*)malloc(sizeof(int)*seqlen);
  f(xs,0,seqlen,seq);
  while(*(seq+i)>10){
    *(seq+i) = *(seq+i)/10;
  }

 digit = *(seq+i);
 if(digit==1){
  *(h+0) = 1 + *(h+0);
}

else if(digit==2){
  *(h+1) = 1 + *(h+1);
}

else if(digit==3){
  *(h+2) = 1 + *(h+2);
}

else if(digit==4){
  *(h+3) = 1 + *(h+3);
}

else if(digit==5){
  *(h+4) = 1 + *(h+4);
}

else if(digit==6){
  *(h+5) = 1 + *(h+5);
}

else if(digit==7){
  *(h+6) = 1 + *(h+6);
}

else if(digit==8){
  *(h+7) = 1 + *(h+7);
}

else if(digit==9){
  *(h+8) = 1 + *(h+8);
}

if(i!=seqlen){
  free(seq);
 i = i + 1; 
hist_of_firstdigits(generate_sequance,xs,seqlen,h,digit);
}
}
