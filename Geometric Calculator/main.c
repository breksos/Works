#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int select_shape();                      /*the given function prototypes for the assignment in the pdf file*/
int select_calc();
int calculate(int (*f)(),int (*f1)());
int calc_triangle(int x);
int calc_quadrilateral(int x);
int calc_circle(int x);
int calc_pyramid(int x);
int calc_cylinder(int x);

enum shapes {Triangle = 1,Quadrilateral,Circle,Pyramid,Cylinder};            /*required enum lists for shapes and calculators*/
enum Calculators {Area = 1,Perimeter,Volume};



int main(){

 calculate(select_shape,select_calc);                           /*calling in the calculate function to main everythigns done inside*/

return 0;
}





int calculate(int (*f)(),int (*f1)()){                     /*calculate function doing all the job in an infinite loop of switch case untill user wants to exit*/


do{
 
 switch(f()){
/*case names are the enums we have since they are matched with integers and creating our main menu calling the calculator user asks for this is done for all the shapes down below*/

 	case Triangle:
    
    switch(f1()){

    case Area:
  
    calc_triangle(Area);

    break;

    case Perimeter:
    
    calc_triangle(Perimeter);

    break;

    case Volume:

    calc_triangle(Volume);

    break;

    case 0:

    return 0;

    break;
    default:
    printf("Wrong input!!!\n\n");

    }


 	break;
 	case Quadrilateral:
    
    
    
    switch(f1()){

    case Area:

    calc_quadrilateral(Area);

    break;
    case Perimeter:
    
    calc_quadrilateral(Perimeter);

    break;
    case Volume:
  
    calc_quadrilateral(Volume);

    break;
    case 0:
    return 0;
    break;
     
     default:
    printf("Wrong input!!!\n\n"); 

    }


 	break;


 	case Circle:


    
    switch(f1()){

    case Area:

    calc_circle(Area);

    break;
    case Perimeter:

    calc_circle(Perimeter);

    break;
    case Volume:

    calc_circle(Volume);

    break;
    case 0:
    return 0;
    break;
 
    default:
    printf("Wrong input!!!\n\n"); 

    }
 	break;


 	case Pyramid:


    
    switch(f1()){

    case Area:

    calc_pyramid(Area);    

    break;
    case Perimeter:

    calc_pyramid(Perimeter);

    break;
    case Volume:
    
    calc_pyramid(Volume);

    break;
    case 0:
    return 0;
    break;
 
    default:
    printf("Wrong input!!!\n\n");
    }
 	break;


 	case Cylinder:


    switch(f1()){

    case Area:
    
    calc_cylinder(Area);

    break;
    case Perimeter:

    calc_cylinder(Perimeter);

    break;
    case Volume:

    calc_cylinder(Volume);

    break;
    case 0:
    return 0;
    break;
 
    default:
    printf("Wrong input!!!\n\n");

    }
 	break;
    case 0:
    return 0;
 	break;
 
 default:
 printf("Wrong input!!!\n\n\n");


 }
 

}

while(1);



}


int select_shape(){         /*selecting the shape from the enum shape list we have and returning the value to calculate() func.*/
    
    int s,check;
    char c;

 printf("\n\nWelcome to the geometric calculator!\n");
 printf("Select a shape to calculate:\n");
 printf("----------------------------\n");
 printf("1.Triangle\n");
 printf("2.Quadrilateral\n");
 printf("3.Circle\n");
 printf("4.Pyramid\n");
 printf("5.Cylinder\n");
 printf("0.Exit\n");
 printf("----------------------------\n");
 printf("Input: ");
 check = scanf("%d",&s);
 if(check != 1){scanf("%c",&c);printf("That wasnt a number\n\n");}
 else return s;
 


}


int select_calc(){             /*choosing between the area perimeter and the volume calculators*/

int s,check =99;
    char c;

while(check!=1){
    
    printf("Select calculator:\n");
    printf("-----------------------\n");
    printf("1.Area\n");
    printf("2.Perimeter\n");
    printf("3.Volume\n");
    printf("0.Exit\n");
    printf("-----------------------\n");
    printf("Input: ");
    
    check = scanf("%d",&s);   
     if(check != 1){scanf("%c",&c);printf("That wasnt a number\n\n");}
     
}
return s;
}


int calc_triangle(int x){            /*calculator screen when the user chooses a value this func takes it as a input and uses in switch case statement comparing to enum values
                                       the same screen is available for all the shapes and functions are listed down below calculators are done according to given equations is pdf file*/

    float s,res,a = 1.0,z,y;
    int chk = 99;
    char c;

    switch(x){

        case Area:
        
        while(chk!=1){
        printf("Enter side 1: ");           /*this control point checks whether the user entered a valid input and not an integer staying in while loop until a valid input 
                                                  after a valid input the loop breaks and continues to the next scanf function no comments required for the rest of the shapes because usage is the same*/
        chk = scanf("%f",&a);
        if(chk != 1){scanf("%c",&c);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter side 2: ");
        chk = scanf("%f",&y);
        if(chk != 1){scanf("%c",&c);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter side 3: ");
        chk = scanf("%f",&z);
        if(chk != 1){scanf("%c",&c);printf("that wasnt a number!!\n");}
    }

        s = (a+y+z)/2;
        res = sqrt(s*(s-a)*(s-y)*(s-z));
        if(a<=0||y<=0||z<=0){printf("invalid triangle values\n");}
        else if(a>y+z||y>a+z||z>a+y){printf("invalid trianglevalues \n");}
        else printf("\nArea: %f\n",res);

        break;
        case Perimeter:
        
        while(chk!=1){
        printf("Enter side 1: ");
        chk = scanf("%f",&a);
        if(chk != 1){scanf("%c",&c);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter side 2: ");
        chk = scanf("%f",&y);
        if(chk != 1){scanf("%c",&c);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter side 3: ");
        chk = scanf("%f",&z);
        if(chk != 1){scanf("%c",&c);printf("that wasnt a number!!\n");}
    }
        res = a+y+z;
        if(a<=0||y<=0||z<=0){printf("invalid triangle values\n");}
        else if(a>y+z||y>a+z||z>a+y){printf("invalid trianglevalues \n");}
        else printf("\nPerimeter: %f\n",res);
        break;
        case Volume:

        printf("You cannot calculate the volume of a triangle");

        break;
    }

    return -1;
}

int calc_quadrilateral(int x){

    float s,res,a,z,y,c;
    int chk = 99;
    char cr;

    switch(x){

        case Area:
        
        while(chk!=1){
        printf("Enter side 1: ");
        chk = scanf("%f",&a);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter side 2: ");
        chk = scanf("%f",&y);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter side 3: ");
        chk = scanf("%f",&z);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }

        chk = 99;
           while(chk!=1){
        printf("Enter side 4: ");
        chk = scanf("%f",&c);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }


        s = (a+y+z+c)/2;
        res = sqrt((s-a)*(s-y)*(s-z)*(s-c));

        if(a<=0||y<=0||z<=0||c<=0){printf("invalid side values\n");}
        else printf("\nArea: %f\n",res);

        break;
        case Perimeter:
        
        while(chk!=1){
        printf("Enter side 1: ");
        chk = scanf("%f",&a);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter side 2: ");
        chk = scanf("%f",&y);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter side 3: ");
        chk = scanf("%f",&z);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }

        chk = 99;
           while(chk!=1){
        printf("Enter side 4: ");
        chk = scanf("%f",&c);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }  
        res = a+y+z+c;
        if(a<=0||y<=0||z<=0||c<=0){printf("invalid side values\n");}
        else printf("\nPerimeter: %f\n",res);

        break;
        case Volume:

        printf("You cannot calculate the volume of a Quadrilateral");

        break;
    }

    return -1;
}

int calc_circle(int x){

    float s,res,a,z,y,c;
    char cr;
    int chk = 99;

    switch(x){

        case Area:
 
        while(chk!=1){
        printf("Enter side radius: ");
        chk = scanf("%f",&a);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;
        
        res = 3.14*pow(a,2);
        if(a<=0){printf("invalid radius value\n");}
        else printf("Area: %f\n",res);

        break;
        case Perimeter:
        
        
        while(chk!=1){
        printf("Enter side radius: ");
        chk = scanf("%f",&a);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
        res = 2*3.14*a;
        if(a<=0){printf("invalid radius value\n");} 
        else printf("\ncircumference of your circle: %f\n",res);

        break;
        case Volume:

        printf("You cannot calculate the volume of a circle");

        break;
    }

    return -1;
}


int calc_pyramid(int x){

    float b,l,res,a,z;
char cr;int chk = 99;

    switch(x){

        case Area:
 
        while(chk!=1){
        printf("Enter base side: ");
        chk = scanf("%f",&a);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter height: ");
        chk = scanf("%f",&l);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;  

        b = pow(a,2);
        l = 2*a*l;
        res =b+l;

        if(a<=0||l<=0){printf("invalid side values\n");}
        else {printf("Base surface area: %f",b);
        printf("\nlateral surface area: %f",l); 
        printf("\nSurface Area: %f",res);}

        break;

        case Perimeter:
        
        printf("You cannot calculate the perimeter of a Pyramid"); 
        break;
        
        case Volume:

        
        
        while(chk!=1){
        printf("Enter base side: ");
        chk = scanf("%f",&a);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter slate height: ");
        chk = scanf("%f",&l);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;    
         
         
        res = 0.333334*a*a*l;
        if(a<=0||l<=0){printf("invalid side values\n");}
        else printf("Volume: %f",res);

        break;
    }

    return -1;
}


int calc_cylinder(int x){

    float b,l,res,a,z;
     char cr;int chk = 99;

    switch(x){

        case Area:
 
        while(chk!=1){
        printf("Enter radius: ");
        chk = scanf("%f",&a);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter height: ");
        chk = scanf("%f",&z);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;      

        b = 3.14 * pow(a,2);
        l = 2*3.14*a*z;
        res =2*3.14*a*(a+z);

        if(a<=0||z<=0){printf("invalid side values\n");}
        else {printf("Base surface area: %f",b);
        printf("\nlateral surface area: %f",l); 
        printf("\nSurface Area: %f",res);}

        break;
        case Perimeter:
        
        printf("You cannot calculate the perimeter of a Cylinder"); 
        break;
        
        case Volume:

        
        while(chk!=1){
        printf("Enter radius: ");
        chk = scanf("%f",&a);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;
           while(chk!=1){
        printf("Enter height: ");
        chk = scanf("%f",&z);
        if(chk != 1){scanf("%c",&cr);printf("that wasnt a number!!\n");}
    }
    chk = 99;

        res = 3.14 * pow(a,2) * z;
        if(a<=0||z<=0){printf("invalid side values\n");}
        else printf("Volume: %f",res);

        break;
    }

    return -1;
}