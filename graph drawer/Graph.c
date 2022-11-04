#include <stdio.h>                                          

int graph();
int write_file(int x,int y,int z);                            /*required function declerations*/
int graph_write_file();

int main()
{
	char c;
    int x,y,z;
	

    do{

    printf("\n1-)Enter the coefficients\n");                   /*our main menu in infinite loop*/
    printf("2-)Draw the graph\n");
    printf("3-)Print the graph to .txt file\n");
    printf("4-)Exit\n");
    printf("Your choice: ");
    scanf(" %c",&c);
    
    switch(c){

    case '1':                                             /*choosing our coefficients and writing them into file*/
    
    printf("Please enter the coefficient of y^2");
    scanf("%d",&x);
    printf("\nPlease enter the coefficient of y");
    scanf("%d",&y);
    printf("\nPlease enter the final coefficient");
    scanf("%d",&z);
    
    write_file(x,y,z);

    break;

    case '2':                        /*reading from file and printing our graph according to coefficients*/
     
    graph();
    break;

    case '3':

    graph_write_file();                    /*writing our graph into a txt file*/
    
    break;

    case '4':               /*eziting the program*/
    
    return 0;

    break;

    default:
    printf("wrong input try again\n\n");           /*error in case a wrong input*/

    }


}
while(1);

	
}


int write_file(int x,int y,int z){

    FILE *ptr;                                                      /*opening a file in w mode to overwrite left over coefficient info and create file*/

    ptr = fopen("coefficient.txt","w+");
    if(ptr == NULL){printf("file could not be found");return 0;}
    fprintf(ptr,"%d\n%d\n%d\n",x,y,z);
    fclose(ptr);

}

int graph(){

    int i,j = 1;
    int x,y,z,res = 99 ;
    FILE *ptr;
    ptr = fopen("coefficient.txt","r");

    if(ptr == NULL){printf("Error file could not be found\n");return 0;}           /*reading from file and saving the coefficient values to plot our graph*/

    fscanf(ptr,"%d\n%d\n%d\n",&x,&y,&z);
   


   for(i = 15;i>=-15;i--){                   /*nested loops to plot our graph and our cartesian coordinate plane*/
    
    for(j = -55;j<=55;j++){
    
    res = x*i*i + y*i + z;
    if(res<=55 &&res>=-55 && j == res){printf("\033[0;31m#\033[0m");}
    else if(res!=0&&j==0 && i!=0){printf("|");}
    else if(j!=0 && i!=0){printf(" ");}
    if(i==0){printf("-");}
    if(j==55){printf("\n");}
    
    }
    
   }
fclose(ptr);
}


int graph_write_file(){                         /*printing our graph into txt file*/

 int i,j = 1;
    int x,y,z,res = 99 ;
    FILE *ptr;
    FILE *ptr2;
    ptr = fopen("coefficient.txt","r");
    if(ptr == NULL){printf("file could not be found\n");return 0;}
    ptr2 = fopen("graph.txt","w+");
    fscanf(ptr,"%d\n%d\n%d\n",&x,&y,&z);
   


   for(i = 15;i>=-15;i--){
    
    for(j = -55;j<=55;j++){
    
    res = x*i*i + y*i + z;
    if(res<=55 &&res>=-55 && j == res){fprintf(ptr2,"#");}
    else if(res!=0&&j==0 && i!=0){fprintf(ptr2,"|");}
    else if(j!=0 && i!=0){fprintf(ptr2," ");}
    if(i==0){fprintf(ptr2,"-");}
    if(j==55){fprintf(ptr2,"\n");}
    
    }
    
   }
fclose(ptr);
fclose(ptr2);
printf("Succesfully written graph to file\n");
}
