#include <stdio.h>
#include <stdlib.h>

/*
*
*Disclaimer because unions can't store data more than one I have used file systems to store the data I needed to print while the system was working
*
*while closing the program with the ooption 5 the files which are used to store the data for unions are deleted and only the main report file is saved
*
*
*
*
*
*our unions and struct defined down below
*
*
*
*/

union Person{
   char name[50];
   char address[50];
    int id;
    int phone;
};

union Loan{
    float amount;
    float rate;
    int period;
};

typedef struct BankAcc
{
   union Person Customer;
   union Loan Loans[3];
}BankAcc;

/*
*
*required function prototypes
*
*
*/

int power(float base, int period);
int addcustomer(BankAcc new[50]);
void getreport();
void newloan();
float calculateLoan(float amount, int period, float interestRate);
int listcustomer();

/*
*
*main func inside loop to stay working unless user wants to exit
*
*
*/

int main(){

BankAcc user[50];
int control = 1;
char c;

while(1){
   printf("\nWelcome to the Bank management system\n\n");
   printf("1. List all customers\n");
   printf("2. Add new customer\n");
   printf("3.New Loan application\n");
   printf("4. Report Menu\n");
   printf("5. Exit\n");
   printf("Choice = ");
   scanf(" %c",&c);
   switch(c){

      case '1':
      printf("\n");
      listcustomer();
      break;

      case '2':
      if(control == 0){
         printf("Your system is full with 50 customers can't add more!!\n\n");
         break;
      }
      printf("\n");
      addcustomer(user);
      break;

      case '3':
      newloan();
      break;

      case '4':
      printf("\n");
      getreport();
      break;

      case '5':
      printf("\n!!Goodbye!!\n");
      remove("loans.txt");
      remove("Tempfile.txt");
      return 0;
      break;

      default:
      printf("\nWrong Entry Try AGAIN!\n\n");
      break;
   }
}


return 0;

}

/*
*
*Function to create new customer can only create 50 customers
*
*writing into file system in the meanwhile since unions only store the biggest data they have and overwrite each time
*
*/
int addcustomer(BankAcc new[50]){

   FILE *ptr;
   FILE *temp;
   FILE *loan;
   static int a=0;
   int n,temp_period=0;
   float sum=0.0,temp_rate=0.0,temp_loan=0.0,temp_amount=0.0;

   if(a==50){
      printf("Your file is full can't add more customers!!\n\n");
      return 0;
   }

   ptr = fopen("Customer.txt","a+");
   temp = fopen("Tempfile.txt","a+");
   loan = fopen("loans.txt","a+");

   printf("Please enter Customer name: "); 
   scanf("%s",new[a].Customer.name);
   fprintf(ptr,"Customer Name: %s\n",new[a].Customer.name);
   fprintf(temp,"Customer Name: %s\n",new[a].Customer.name);
   
   printf("\nPlease enter Adress: ");
   scanf("%s",new[a].Customer.address);
   fprintf(ptr,"Customer Adress: %s\n",new[a].Customer.address);
   fprintf(temp,"Customer Adress: %s\n",new[a].Customer.address);

   printf("\nPlease enter customer ID: ");
   scanf("%d",&new[a].Customer.id);
   fprintf(ptr,"Customer ID: %d\n",new[a].Customer.id);
   fprintf(temp,"Customer ID: %d\n",new[a].Customer.id);
   fprintf(loan,"Customer ID: %d\n",new[a].Customer.id); 

   printf("\nPlease enter Phone number: ");
   scanf("%d",&new[a].Customer.phone);
   fprintf(ptr,"Customer Phone: %d\n",new[a].Customer.phone);
   fprintf(temp,"Customer Phone: %d\n",new[a].Customer.phone);

   printf("\nPlease enter the amount of loans you need max 3 loans: ");
   scanf("%d",&n);
   while(n>3){
      printf("Max amount is 3 loans try again!\n");
      printf("Enter the amount of loans: ");
      scanf("%d",&n);
      if(n<3&&n>0){
         break;
      }
   }
   fprintf(ptr,"%s ","Loans: [");

   for(int i=0;i<n;i++){

      printf("Enter the loan no.%d amount: ",i+1);
      scanf("%f",&new[a].Loans[i].amount);
      fprintf(ptr,"%.2f ",new[a].Loans[i].amount);
      fprintf(temp,"Loan no.%d amount = %.2f\n",i+1,new[a].Loans[i].amount);
      temp_amount = new[a].Loans[i].amount;
      sum = sum + new[a].Loans[i].amount;

      printf("Enter the loan no.%d rate: ",i+1);
      scanf("%f",&new[a].Loans[i].rate);
      temp_rate = new[a].Loans[i].rate;
      fprintf(temp,"Loan no.%d rate = %.2f\n",i+1,new[a].Loans[i].rate);
      
      printf("Enter the loan no.%d period: ",i+1);
      scanf("%d",&new[a].Loans[i].period);
      temp_period = new[a].Loans[i].period;
      fprintf(temp,"Loan no.%d period = %d\n",i+1,new[a].Loans[i].period);
      
      temp_loan = calculateLoan(temp_amount,temp_period,temp_rate);
      fprintf(loan,"Loan amount: %.2f\n",temp_loan);
      fprintf(loan,"Monthly payment: %2.f\n",(temp_loan/temp_period));

      if(i!=n-1){
         fprintf(ptr,"%s","+ ");
      }
   }
   fprintf(ptr,"%s","]");
   fprintf(ptr,"=> %.2f\n\n",sum);

fclose(ptr);
fclose(temp);
fclose(loan);
a = a+1;
}

/*
*
*report screen printing out the info about customer and main idea of the loans they have
*
*
*/

void getreport(){

FILE *ptr;

char temp_line[100];
int s;
ptr = fopen("Customer.txt","r");

if(ptr==NULL){
   printf("\nNO CUSTOMER INFO AVAILABLE FILE DOES NOT EXIST!!!\n");
}
else{
   while(fgets(temp_line,sizeof(temp_line),ptr)){
      printf("%s",temp_line);

   }
}
fclose(ptr);


printf("Do you want to inspect Loans only? if yes enter 1: ");
scanf("%d",&s);

if(s==1){
ptr = fopen("loans.txt","r");

   while(fgets(temp_line,sizeof(temp_line),ptr)){
      printf("%s",temp_line);
   }
}
fclose(ptr);
}
/*
*
*adding new loans to our loan list and taking customer id in the mean time to record who got the loan
*
*
*/
void newloan(){
 
  FILE *loan;

  float f=0.0,a=0.0,r=0.0;
  int p = 0,id=0;

  loan = fopen("loans.txt","a+");

  printf("Enter ID of customer for loan: ");
  scanf("%d",&id);

  printf("\nEnter Loan amount: ");
  scanf("%f",&a);
  printf("\nEnter Loan rate: ");
  scanf("%f",&r);
  printf("\nEnter Loan period: ");
  scanf("%d",&p);

  f = calculateLoan(a,p,r);
  
  printf("Total loan payment amount: %.2f",f);
  printf("\nMonthly payment: %.2f",f/p);

  fprintf(loan,"Customer ID: %d",id);
  fprintf(loan,"Total loan payment amount: %.2f\n",f);
  fprintf(loan,"Monthly loan payment amount: %.2f",f/p);

fclose(loan);
}

/*
*
*using recursive power func I have written this func calculates the loan amount according to period and rate
*
*
*/

float calculateLoan(float amount, int period, float interestRate){

 float x;

 x = power(1+interestRate,period);

 return (amount*x);
 
}
/*
*
*since the pow() func was forbidden to use and a recursive func was needed this func covers its place
*
*/
int power(float base,int period){

  if(period!=0){
   return (base*power(base, period-1));
  }

  else return 1;

}
/*
*
*listing all customer struct elements onto the screen
*
*
*/
int listcustomer(){

  FILE *temp;
  char temp_line[100];

  temp = fopen("Tempfile.txt","r");
  
  if(temp==NULL){
   printf("No customer exists create customer first");
   return 0;
  }

     while(fgets(temp_line,sizeof(temp_line),temp)){
      printf("%s",temp_line);
   }
fclose(temp);

}