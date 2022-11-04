#include <stdio.h>                                          
#include <stdlib.h>
#include <time.h>

int Mapping(char map[15][30]);                           /*required function declerations*/
int dice();
int move_p1(char map[15][30]);
void print_map(char map[15][30]);
int move_p2(char map[15][30]);
int StartGame();
/*
* Main func calling the functions we have created ans using the variables
*
*
*
*
*
*
*
*
*/
int main()
{
	srand(time(NULL));
    char map[15][30],c;
    int x,y,r;
    
    r = StartGame();

	Mapping(map);
/*
*
*if p1 got bigger dice value in startgame func this loop starts
*
*
*
*
*/
    if(r==1){
    while(1){
    printf("Press enter to Roll dice\n\n");
    c = getchar();
    x = move_p1(map);
    c = getchar();    
    y = move_p2(map);
    c = getchar();
    print_map(map);
    if(y==3||x==5){break;}    
    }
    }
/*
*
*if p2 got bigger dice value in startgame func this loop starts
*
*
*
*
*/
    else if(r==2){   
    while(1){
    printf("Press enter to Roll dice\n\n");
    c = getchar();
    y = move_p2(map);
    c = getchar();    
    x = move_p1(map);
    c = getchar();
    print_map(map);
    if(y==3||x==5){break;}    
    }
}
	if(y==3){printf("\033[0m\n\nPlayer2 won\n");}
    else if(x==5){printf("\033[0m\n\nPlayer1 won\n");}
return 0;
}

/*
*Mapping func
*
*char map[15][30]
*
*we need to use our map as a func parameter so that we dont lose the data
*printing values inside array according to given map in pdf
*
*
*/
int Mapping(char map[15][30]){

    int i,j = 1;
    int x,y,z,res = 99 ;
    
   


   for(i = 0;i<15;i++){                   
    
    for(j = 0;j<30;j++){
    if(i==0||j==0||j==29||i==14){map[i][j]='*';}
    else if(i==2&&j>=2&&j<=27){map[i][j]='*';}
    else if(i>=2&&i<=12&&j==27){map[i][j]='*';}
    else if(i==4&&j>=4&&j<=25){map[i][j]='*';}
    else if(i>=4&&i<=10&&j==25){map[i][j]='*';}
    else if(i==12&&j>=2&&j<=27){map[i][j]='*';}
    else if(i==10&&j>=4&&j<=25){map[i][j]='*';}
    else if(i>=2&&i<=12&&j==2){map[i][j]='*';}
    else if(i>=4&&i<=10&&j==4){map[i][j]='*';}
    else if((i==1&&j==14)||(i==7&&j==28)||(i==13&&j==14)){map[i][j]='x';}
    else if((i==3&&j==10)||(i==3&&j==18)||(i==5&&j==26)||(i==10&&j==26)||(i==11&&j==10)||(i==11&&j==18)){map[i][j]='x';}
    else if((i==2&&j==1)||(i==4&&j==3)){map[i][j]='_';}
    else if(i==1&&j==1){map[i][j]='1';}   
    else if(i==3&&j==3){map[i][j]='2';}
    else map[i][j] = ' ';
    }
   }
      print_map(map);
}
/*
*dice func
*
*void no parameters returns a random integer takes the place of a real dice in rreal life
*
*
*
*/
int dice(){
 
  int x;
  x = 1 + (rand()%6);

  return x;  
}

/*
*move_p1 func
*
*parameters map array moving index 1 according to dice value inside array
*
*checking whether the user stepped on a fault point or not aswell
*
*returns integer 5 if played won 1 if not
*
*
*
**/

int move_p1(char map[15][30]){
    int i,j,x,y,z,c;
    x = dice();
    for(i=1;i<15;i++){
        for(j=1;j<30;j++){
            if(map[i][j]=='1'){
                y=i;
                z=j;
                if(y==2&&z==1){return 5;}   
            }
  }
}
    if(y==1&&z+x<29){map[y][z]=' ';map[y][z+x]='1';if(z+x==14){map[1][14]='x';map[y][z-2]='1';}}
    else if(y==1&&z+x>=28){map[y][z]=' ';c = x-(28-z);map[y+c][28]='1';if(y+c==7&&z==28){map[y+x][z]='x';map[y-1][z-1]='1';}}
    
    else if(z==28&&y+x<14){map[y][z]=' ';map[y+x][z]='1';if(y+x==7&&z==28){map[y+x][z]='x';map[y-2][z]='1';}}
    else if(z==28&&y+x>=13){map[y][z]=' ';c = x-(13-y);map[13][z-c]='1';}
    
    else if(y==13&&z-x>0){map[y][z]=' ';map[y][z-x]='1';if(z-x==14){map[13][14]='x';map[y][z+2]='1';}}
    else if(y==13&&z-x<=1){map[y][z]=' ';c = x + (1-z) ;map[y-c][1]='1';}

    else if(z==1&&y-x>0){map[y][z]=' ';map[y-x][z]='1';}
    else if(z==1&&y-x<=1){map[y][z]=' ';c = x + (1-y);map[1][z+c]='1';return 5;}
    if(y==2&&z==1){return 5;}
    printf("\n\033[0mPlayer 1 rolled dice = %d\n",x);
    return 1;
    
}
/*
*
*move_p2 func
*
*parameter map
*
*this time moving index 2 inside the array doing the same job as move_p1 func
*
*
*
*
*
*/
int move_p2(char map[15][30]){
    int i,j,x,y,z,c;
    x = dice();
    for(i=1;i<15;i++){
        for(j=1;j<30;j++){
            if(map[i][j]=='2'){
                y=i;
                z=j;
                if(y==4&&z==3){return 3;}
            }
  }
}
    if(y==3&&z+x<27){map[y][z]=' ';map[y][z+x]='2';if(z+x==10){if(z==4&&z+x==10){map[3][10]='x';map[3][3]='2';}else map[3][10]='x';map[y][z-2]='2';}else if(z+x==18){map[3][18]='x';map[y][z-2]='2';}}
    else if(y==3&&z+x>=26){map[y][z]=' ';c = x-(26-z);map[y+c][26]='2';if(y+c==5){map[5][26]='x';map[y][z-2]='2';}}
    
    else if(z==26&&y+x<12){map[y][z]=' ';map[y+x][z]='2';if(y+x==5){map[5][26]='x';map[3][25]='2';}if(y+x==10){map[10][26]='x';map[y-2][26]='2';}}
    else if(z==26&&y+x>=11){map[y][z]=' ';c = x-(11-y);map[11][z-c]='2';}
    
    else if(y==11&&z-x>2){map[y][z]=' ';map[y][z-x]='2';if(z-x==10){map[11][10]='x';map[y][z+2]='2';}else if(z-x==18){map[11][18]='x';map[y][z+2]='2';}}
    else if(y==11&&z-x<=3){map[y][z]=' ';c = x + (3-z) ;map[y-c][3]='2';}

    else if(z==3&&y-x>2){map[y][z]=' ';map[y-x][z]='2';}
    else if(z==3&&y-x<=3){map[y][z]=' ';c = x + (3-y);map[3][z+c]='2';return 3;}
    if(y==4&&z==3){return 3;}
    printf("\n\033[0mPlayer 2 rolled dice = %d\n",x);

     return 1;
    
}
/*
*print_map printing our array and giving some colour coding to the assets inside array
*
*no return value we dont need any
*
*parameter is map since we need to print our game map
*
*
*
*
*
*/

void print_map(char map[15][30]){
   int i,j;
    for(i = 0;i<15;i++){                   
 
      for(j = 0;j<30;j++){
    if(map[i][j]=='*'){printf("\033[0;33m");}
    else if(map[i][j]=='x'){printf("\033[0;31m");}
    else if(map[i][j]=='1'||map[i][j]=='2'){printf("\033[0;34m");}
    printf("%c ",map[i][j]);
    
    
    }
    printf("\n");
   }

}

/*
*
*int StartGame Func 
*
*no parameters needed
*
*returns a random int value to decide which player starts the game first
*
*
*/
int StartGame(){
   
   int r,z;
   char c;

 while(1){
        printf("Roll dice to determine who goes first Press enter to Roll dice P1 goes first\n");
        c = getchar();
        z = dice();
        printf("\nPlayer 1 rolled dice = %d\n",z);
        c = getchar();
        r = dice();
        printf("\nPlayer 2 rolled dice = %d\n",r); 
        if(r!=z){break;}
    }
    if(z>r){return 1;}
    else if(r>z){return 2;}

}