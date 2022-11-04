#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


/*
*
*Func prototypes we have defined and used during the homework
*
*/


void mapping(int pos[7],char arr[15][15],char[7][15]);
void print(char arr[15][15]);
void words(char arr[50][15]);
void rand_words(char arr[50][15],char list[7][15]);
void play(int pos[7],char arr[15][15],char list[7][15]);

int main(){

srand(time(0));

char arr[15][15];
char list[50][15];
char rand_word[7][15];
int pos[7];
words(list);
printf("\n\n");
rand_words(list,rand_word);
mapping(pos,arr,rand_word);
print(arr);
play(pos,arr,rand_word);
printf("\n");
return 0;

}
/*
*void mapping func storing the pos of hidden words and filling in the map accordingly
*
*choosing a random number and according to that placing the word inside the map
*
*it is also calculating the fact that words dont mix up inside the map
*
*
*
**/
void mapping(int pos[7],char arr[15][15],char list[7][15]){

int x,a,i,choice,j,z,rand1,rand2,rand3;

for(i=0;i<15;i++){
	for(j=0;j<15;j++){
		arr[i][j] = ' ';
	}
}
a = 0;
while(a < 7){

choice = rand()%8 + 1;
pos[a] = choice;
/*
*Going left to right
*/
if(choice == 1){
      
    x = strlen(list[a]);
    x = x - 2;
    printf("\n%s\n",list[a]);
    reset:
    rand2 = rand()%14 + 1;
    rand3 = rand()%(14-x) + 1;
    
    z = 0;
	for(j=rand3;j<rand3+x;j++){
		if(arr[rand2][j]==' '){
	arr[rand2][j] = list[a][0+z];
	z++;
}
else goto reset;
	}
	printf("Row:%d Col:%d choice:%d\n\n",rand2,rand3,choice);

}
/*
*Going right to left
*/
else if(choice == 2){
     
    x = strlen(list[a]);
    x = x - 2;
    printf("\n%s\n",list[a]);
    reset2:
    rand2 = rand()%14 + 1;
    rand3 = (rand()%(14-x + 1))+x;
    
    z = 0;
	for(j=rand3;j>rand3-x;j--){
		if(arr[rand2][j]==' '){
	arr[rand2][j] = list[a][0+z];
	z++;
}
else goto reset2;
	}
printf("Row:%d Col:%d choice:%d\n\n",rand2,rand3,choice);
}
/*
*Going downwards
*/
else if(choice == 3){
      
    x = strlen(list[a]);
    x = x - 2;
    printf("\n%s\n",list[a]);
    reset3:
    rand2 = rand()%(14-x) + 1;
    rand3 = rand()%14 + 1;
    
    z = 0;
	for(j=rand2;j<rand2+x;j++){
		if(arr[j][rand3]==' '){
	arr[j][rand3] = list[a][0+z];
	z++;
	}
	else goto reset3;
}
printf("Row:%d Col:%d choice:%d\n\n",rand2,rand3,choice);
}
/*
*Going upwards
*/
else if(choice == 4){
       
    x = strlen(list[a]);
    x = x - 2;
    printf("\n%s\n",list[a]);
    reset4:
    rand2 = (rand()%(14-x + 1))+x;
    rand3 = rand()%14 + 1;
    
    z = 0;
	for(j=rand2;j>rand2-x;j--){
	if(arr[j][rand3]==' '){
	arr[j][rand3] = list[a][0+z];
	z++;
	}
	else goto reset4;
}
printf("Row:%d Col:%d choice:%d\n\n",rand2,rand3,choice);
}
/*
*Going left to right downwards diagonal
*/
else if(choice == 5){
      
    x = strlen(list[a]);
    x = x - 2;
    printf("\n%s\n",list[a]);
    reset5:
    rand2 = rand()%(14-x) + 1;
    rand3 = rand()%(14-x) + 1;
    
    z = 0;
	for(j=rand3;j<rand3+x;j++){
		if(arr[rand2+z][j]==' '){
	arr[rand2+z][j] = list[a][0+z];
	z++;
	}
	else goto reset5;
}
printf("Row:%d Col:%d choice:%d\n\n",rand2,rand3,choice);
}
/*
*Going right to left upwards diagonal
*/
else if(choice == 6){
        
    x = strlen(list[a]);
    x = x - 2;
    printf("\n%s\n",list[a]);
    reset6:
    rand2 = (rand()%(14-x + 1))+x;
    rand3 = (rand()%(14-x + 1))+x;
    
    z = 0;
	for(j=rand3;j>rand3-x;j--){
		if(arr[rand2-z][j]==' '){
	arr[rand2-z][j] = list[a][0+z];
	z++;
	}
	else goto reset6;
}
printf("Row:%d Col:%d choice:%d\n\n",rand2,rand3,choice);
}
/*
*Going left to right upwards diagonal
*/
else if(choice == 7){
    
    x = strlen(list[a]);
    x = x - 2;
    printf("\n%s\n",list[a]);
    reset7:
    rand2 = (rand()%(14-x + 1))+x;
    rand3 = rand()%(14-x) + 1;
    
    z = 0;
	for(j=rand3;j<rand3+x;j++){
	if(arr[rand2-z][j]==' '){
	arr[rand2-z][j] = list[a][0+z];
	z++;
	}
	else goto reset7;
}
printf("Row:%d Col:%d choice:%d\n\n",rand2,rand3,choice);
}
/*
*Going right to left downwards diagonal
*/
else if(choice == 8){  
    x = strlen(list[a]);
    x = x - 2;
    printf("\n%s\n",list[a]);
    reset8:
    rand2 = rand()%(14-x) + 1;
    rand3 = (rand()%(14-x + 1))+x;
    
    z = 0;
	for(j=rand3;j>rand3-x;j--){
		if(arr[rand2+z][j]==' '){
	arr[rand2+z][j] = list[a][0+z];
	z++;
	}
	else goto reset8;
}
printf("Row:%d Col:%d choice:%d\n\n",rand2,rand3,choice);
}
a++;
}
for(i=0;i<15;i++){
	for(j=0;j<15;j++){
		if(arr[i][j]==' '){
		do
		arr[i][j]=rand();
		while(!(arr[i][j]>=97 && arr[i][j]<=122));
	}
}
}
}
/*
*print func 1 param char array
*
*prints out the map
*
*
*
*/
void print(char arr[15][15]){
	int i,j;

	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
}
/*
*words func void no return 1 parameter arr of 50 and 15 lenght
*
*reads the words from txt file and stores in arr
*
*
*
*/
void words(char arr[50][15]){

	FILE *ptr;
	int i=0;

	ptr = fopen("wordlist.txt","r");
	while(!feof(ptr)){
		fgets(arr[i],15,ptr);
		i++;
	}
    fclose(ptr);
/*
*
*rand_words func 2 param arr[50][15] and list
*
*chooses 7 random words from the list we stored in void words func
*
*
*/

}

void rand_words(char arr[50][15],char list[7][15]){

	int i=0,j,rand1;int randlist[7];
    
    while(i<7){
    	set:
    	rand1 = rand() % 49 + 1;
        
        for(j=0;j<7;j++){
        	if(rand1==randlist[j]){goto set;}
        }
        randlist[i]=rand1;
        i++;    
    }


	for(i=0;i<7;i++){
     strcpy(list[i],arr[randlist[i]]);
     
	}
}

/*
*
*Void play func 3 parameters arr map pos of the hidden words and list of words
*
*takes input from user and compares them according to puzzle and is the function where user plays the game
*
*instead of going through all the map and finding the rest of the word I have stored the random placement values in mapping and sent to this func
*
*this way I only need to check pos array if the strings are matching and find my way inside the map according to that
*
*
*/

void play(int pos[7],char arr[15][15],char list[7][15]){

int mis=3,points=0;
int x,y,i,j,way,ctr=0,ctr2=0;
char word[15];
char cx[3],cy[3];

while(mis!=0){

printf("Enter the coordinates of first letter and the letter you found if you want to quit the game enter ':q :q :q'respectively: ");
scanf("%s %s %s",cx,cy,word);
/*
*checking for the quit command
*
*/
if(strcmp(cx,":q")==0&&strcmp(cy,":q")==0&&strcmp(word,":q")==0){printf("Quit command entered your points: %d\n\n",points);break;}

/*switching to int if quit command is not entered*/

x = atoi(cx);
y = atoi(cy);
for(i=0;i<7;i++){
	ctr=0;
	for(j=0;j<strlen(word);j++){
      if(list[i][j]==word[j]){
      	ctr++;
      }
	}
if(ctr==strlen(word)){
	way = pos[i];
	break;
}	
}
if(ctr!=strlen(word)){
	printf("\nYou made a mistake!! %d lives left\n\n",mis-1);
	mis = mis-1;
}
if(ctr==strlen(word)){
	ctr2 = 0;
	for(i=0;i<strlen(word);i++){
		if(way==1){
			if(arr[x][y+i]==word[i]){ctr2++;}
		}
		else if(way==2){
		    if(arr[x][y-i]==word[i]){ctr2++;}
		}
		else if(way==3){
		    if(arr[x+i][y]==word[i]){ctr2++;}
		}
		else if(way==4){
		    if(arr[x-i][y]==word[i]){ctr2++;}
		}
		else if(way==5){
		    if(arr[x+i][y+i]==word[i]){ctr2++;}
		}
		else if(way==6){
		    if(arr[x-i][y-i]==word[i]){ctr2++;}
		}
		else if(way==7){
		    if(arr[x-i][y+i]==word[i]){ctr2++;}
		}
		else if(way==8){
		    if(arr[x+i][y-i]==word[i]){ctr2++;}
		}
	}
	if(ctr2==strlen(word)){
		printf("\nYou found a word\n");points = points + 2;
    for(i=0;i<strlen(word);i++){
    	if(way==1){
			arr[x][y+i] = 'X';
		}
		else if(way==2){
		    arr[x][y-i]  = 'X';
		}
		else if(way==3){
		    arr[x+i][y] = 'X';
		}
		else if(way==4){
		    arr[x-i][y] = 'X';
		}
		else if(way==5){
		    arr[x+i][y+i] = 'X';
		}
		else if(way==6){
		    arr[x-i][y-i] = 'X';
		}
		else if(way==7){
		    arr[x-i][y+i] = 'X';
		}
		else if(way==8){
		    arr[x+i][y-i] = 'X';
		}
    }

	}
	else if(ctr2!=strlen(word)) {printf("You made a mistake %d lives left\n",mis-1);mis--;}
}
print(arr);
	
 if(points==14){printf("You have won the game found all the words 14 points excelent work!!\n\n");break;}
}
if(mis==0){printf("You have lost the game Your points = %d\n\n",points);}


}
