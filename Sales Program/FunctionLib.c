#include <stdio.h>
#include <stdlib.h>
#include "P1_200102002005_BHO_sales.h"
#include <string.h>
#include <stdbool.h>
#include <math.h>

void insertCustomer( CustomerPtr *cPtr,char *Name ,int c_ID, int c_type,double c_x, double c_y){
	
	CustomerPtr Oldptr;
	CustomerPtr Currptr;                                                //new customer function saving data to linked list one by one//
	CustomerPtr Newptr;
	
	
	Newptr = (CustomerPtr)malloc(sizeof(Customer));                           

	if(Newptr!=NULL){
	
	    strcpy(Newptr->name,Name);
		Newptr->ID=c_ID;
		Newptr->type=c_type;
		Newptr->x_coord=c_x;
		Newptr->y_coord=c_y;
		Newptr -> Nextptr = NULL;
        		
		Oldptr = NULL;
		Currptr = *cPtr;
		
		while(Currptr != NULL&&c_y > Currptr ->y_coord){
			Oldptr = Currptr;
			Currptr = Currptr -> Nextptr; 
		}
		
		if(Oldptr == NULL){
			Newptr -> Nextptr = *cPtr;
			*cPtr = Newptr;
		}
		else {
			Oldptr -> Nextptr = Newptr;
			Newptr -> Nextptr = Currptr;
		}
	}
	else{
		printf("Data not inserted No memory available");
	}
	return;
}

int isEmptyC( CustomerPtr sPtr )              //function to check if the list is whether NULL or not//
{
	return sPtr == NULL;
} 

int isEmptyP( ProductPtr sPtr )                    //function to check if the list is whether NULL or not//
{
	return sPtr == NULL;
} 

int isEmptyS( PurchasedPtr sPtr )                 //function to check if the list is whether NULL or not//
{
	return sPtr == NULL;
} 


void printCustomer(CustomerPtr currentcPtr,int c_ID){         //function to check if the customer list is empty if not printing the data one by one untill the pointer is null//
 

	if ( isEmptyC( currentcPtr ) ) {
		printf( "List is empty.\n" );
	} 
	else {
		
		printf("the list is :\n");



		while ( currentcPtr != NULL ) {
			printf("customer name: %s\n",currentcPtr->name);
			printf( "Customer ID: %d\n", currentcPtr->ID);
			printf("Customer Type: %d\n",currentcPtr->type);
	      	printf("X coordinates of the customer: %.2lf\n",currentcPtr->x_coord);
	      	printf("Y coordinates of the customer: %.2lf\n",currentcPtr->y_coord);
			printf("\n\n");
			currentcPtr = currentcPtr->Nextptr;
		} 
	
}
}

  
void Typecustomer(CustomerPtr currentcPtr,int c_type){                      //function to print only wanted type of customer info//   
	
	
		CustomerPtr temp=currentcPtr;
		
	while(temp!=NULL){
		if(temp->type==c_type){
			printf("customer name: %s\n",temp->name);
			printf("Customer ID: %d\n", temp->ID);
			printf("Customer Type: %d\n",temp->type);
	      	printf("X coordinates of the customer: %.2lf\n",temp->x_coord);
	      	printf("Y coordinates of the customer: %.2lf\n",temp->y_coord);
			printf("\n\n");
		
			
		}
         temp=temp->Nextptr;		
	}
	
}
  
  
  
int deleteCustomer( CustomerPtr *cPtr, int c_ID){                          //function to delete the customer data if it is exsiting in our list//
	
	CustomerPtr Oldptr;
	CustomerPtr Currptr;
	CustomerPtr Tempptr;
	
	if(c_ID==(*cPtr)->ID){
		Tempptr = *cPtr;
		*cPtr=(*cPtr)->Nextptr;
		free(Tempptr);
		return c_ID;
	}
	else {
		Oldptr= *cPtr;
		Currptr= (*cPtr)->Nextptr;
	    while(Currptr!=NULL&&Currptr->ID!=c_ID){
	    	Oldptr=Currptr;
	    	Currptr= Currptr->Nextptr;
		}
		if(Currptr!=NULL){
			Tempptr=Currptr;
			Oldptr->Nextptr=Currptr->Nextptr;
			free(Tempptr);
			return c_ID;
		}
	}
	return 0;
}

int searchC(CustomerPtr cPtr,int c_ID){              //function to search and find a customers info in linked list//
	 
	CustomerPtr temp=cPtr;
	while(temp!=NULL){
		if(temp->ID==c_ID)return 1;
		temp=temp->Nextptr;
	}

}


void insertProduct(ProductPtr *pPtr,char *Name,int p_ID,int p_type,double p_price){          //new product function saving data to linked list one by one//


	ProductPtr Oldptr;
	ProductPtr Currptr;
	ProductPtr Newptr;
	
	
	Newptr = (ProductPtr)malloc(sizeof(Product));

	if(Newptr!=NULL){
		strcpy(Newptr->name,Name);
		Newptr->ID=p_ID;
		Newptr->type=p_type;
		Newptr->price=p_price;
		Newptr -> Nextptr = NULL;
        		
		Oldptr = NULL;
		Currptr = *pPtr;
		
		while(Currptr != NULL){
			Oldptr = Currptr;
			Currptr = Currptr -> Nextptr; 
		}
		
		if(Oldptr == NULL){
			Newptr -> Nextptr = *pPtr;
			*pPtr = Newptr;
		}
		else {
			Oldptr -> Nextptr = Newptr;
			Newptr -> Nextptr = Currptr;
		}
	}
	else{
		printf("Data not inserted No memory available");
}
}

void printProduct( ProductPtr CurrentpPtr){                        //function to check if the product list is empty if not printing the data one by one untill the pointer is null//
 

	if ( isEmptyP( CurrentpPtr ) ) {
		printf( "List is empty.\n" );
	} 
	else {
		printf("the list is :\n");

		
		while ( CurrentpPtr != NULL ) {
			printf("Product Name: %s\n",CurrentpPtr->name);
			printf( "Product ID: %d\n", CurrentpPtr->ID);
			printf("Product Type: %d\n",CurrentpPtr->type);
	      	printf("Product Price: %.2lf\n",CurrentpPtr->price);
			printf("\n\n");
			CurrentpPtr = CurrentpPtr->Nextptr;
		} 
	}

}

int searchP(ProductPtr pPtr,int p_ID){                //function to search and find a products info in linked list//
	
	ProductPtr temp=pPtr;
	while(temp!=NULL){
		if(temp->ID==p_ID)return 1;
		temp=temp->Nextptr;
	}
return -1;
}

int findtype(ProductPtr pPtr,int p_ID){
	
		ProductPtr temp=pPtr;
	while(temp!=NULL){
		if(temp->ID==p_ID)return temp->type;
		temp=temp->Nextptr;
	}
	return -1;
}

double typeprice(PurchasedPtr sPtr,int Tip){
	
	double c=0;
	PurchasedPtr temp=sPtr;
	while(temp!=NULL){
		if(temp->tip==Tip){
		c=c+(temp->cost);
	}
		temp=temp->nextPtr;
        
  }
	return c; 
}

void Typeproduct(ProductPtr pPtr,int p_type){                              //function to print only wanted type of product info//   
	
	
		ProductPtr temp=pPtr;
		
	while(temp!=NULL){
		if(temp->type==p_type){
			printf("Product name: %s\n",temp->name);
			printf( "Product ID: %d\n", temp->ID);
			printf("Product Type: %d\n",temp->type);
			printf("Product price: %.2lf",temp->price);
			printf("\n\n");
		
		}
         temp=temp->Nextptr;		
	}
}

int deleteProduct( ProductPtr *pPtr, int p_ID){                          //function to delete the product data if it is exsiting in our list//
	
	ProductPtr Oldptr;
	ProductPtr Currptr;
	ProductPtr Tempptr;
	
	if(p_ID==(*pPtr)->ID){
		Tempptr = *pPtr;
		*pPtr=(*pPtr)->Nextptr;
		free(Tempptr);
		return p_ID;
	}
	else {
		Oldptr= *pPtr;
		Currptr= (*pPtr)->Nextptr;
	    while(Currptr!=NULL&&Currptr->ID!=p_ID){
	    	Oldptr=Currptr;
	    	Currptr= Currptr->Nextptr;
		}
		if(Currptr!=NULL){
			Tempptr=Currptr;
			Oldptr->Nextptr=Currptr->Nextptr;
			free(Tempptr);
			return p_ID;
		}
	}
	return 0;
}

void purchase(PurchasedPtr *sPtr,int s_ID,int in_ID,int cs_ID,int cp_ID,double Price,double tot,int Tip){           //function to make a purchase and save invoice data to structure via lists//
	
	
	PurchasedPtr Oldptr;
	PurchasedPtr Currptr;
	PurchasedPtr Newptr;
	ProductPtr pPtr;
	
	Newptr = (ProductPtr)malloc(sizeof(Purchased));


	if(Newptr!=NULL){
		

		Newptr->ID=s_ID;
		Newptr->invoice_ID=in_ID;
		Newptr->customer_ID=cs_ID;
		Newptr->product_ID=cp_ID;
		Newptr->cost=Price;
		Newptr->total=tot;
		Newptr->tip=Tip;
		Newptr -> nextPtr = NULL;
        		
		Oldptr = NULL;
		Currptr = *sPtr;
		
		while(Currptr != NULL){
			Oldptr = Currptr;
			Currptr = Currptr -> nextPtr; 
		}
		
		if(Oldptr == NULL){
			Newptr -> nextPtr = *sPtr;
			*sPtr = Newptr;
		}
		else {
			Oldptr -> nextPtr = Newptr;
			Newptr -> nextPtr = Currptr;
		}
 }
	else{
		printf("Data not inserted No memory available");


}
}


void printSale( PurchasedPtr CurrentsPtr){                      //to print existing invoice files one by one untill the pointer is null//
 

	if ( isEmptyS(CurrentsPtr) ) {
		printf( "List is empty.\n" );
	} 
	else {
		printf("the list is :\n");

		
		while ( CurrentsPtr != NULL ) {
			printf( "Sale ID: %d\n", CurrentsPtr->ID);
			printf("invoice ID: %d\n",CurrentsPtr->invoice_ID);
	      	printf("Customer ID: %d\n",CurrentsPtr->customer_ID);
	      	printf("Product ID: %d\n",CurrentsPtr->product_ID);
	      	printf("Product type: %d\n",CurrentsPtr->tip);
	      	printf("Cost: %.2lf\n",CurrentsPtr->cost);
	      	printf("Total with cargo fee: %.2lf\n",CurrentsPtr->total);
			printf("\n\n");
			CurrentsPtr = CurrentsPtr->nextPtr;
		} 
	}

}

void customershoplist(PurchasedPtr sPtr,int cs_ID){                //function to only print the spesific customers invoice files//
	
	PurchasedPtr temp=sPtr;
		
	while(temp!=NULL){
		if(temp->customer_ID==cs_ID){
			printf("Sale ID: %d\n",temp->ID);
			printf( "Invoice ID: %d\n", temp->invoice_ID);
			printf("Customer ID: %d\n",temp->customer_ID);
			printf("Product ID: %d\n",temp->product_ID);
			printf("Cost %.2lf\n",temp->cost);
			printf("Total charges with cargo: %.2lf",temp->total);
			printf("\n\n");
		
			
		}
         temp=temp->nextPtr;		
	}
	
}
	

double findprice(ProductPtr pPtr,int p_ID,int x){         //function to calculate the price of an item after its bought //

ProductPtr temp=pPtr;
	while(temp!=NULL){
		if(temp->ID==p_ID){
		return (temp->price)*x;
	}
		temp=temp->Nextptr;
  }
}

double cargo(CustomerPtr *cPtr,int c_ID){                //function to calculate the price for cargo services//

	CustomerPtr temp=cPtr;
	while(temp!=NULL){
		if(temp->ID==c_ID){
		return (sqrt(temp->x_coord*temp->x_coord+temp->y_coord*temp->y_coord));
	}
		temp=temp->Nextptr;
  }
	
}


double purchasedAnalyze(PurchasedPtr sPtr,int cp_ID){               //function to calculate the total amount of an item costed in general//
	
	PurchasedPtr temp=sPtr;
	double c;	
		
	while(temp!=NULL){
		if(temp->product_ID==cp_ID){
		c=c+temp->cost;
		}
         temp=temp->nextPtr;		
	}
	return c;
}
	
double boughtamount(PurchasedPtr sPtr,ProductPtr pPtr,int p_ID){      //function to calculate the amount of items bought via ID//
	
ProductPtr temp=pPtr;

while(temp!=NULL){
	if(temp->ID==p_ID){
		return (purchasedAnalyze(sPtr,p_ID)/(temp->price));
	}
	temp=temp->Nextptr;
  }
}	
	

void mostcommon(PurchasedPtr sPtr){                    //function to calculate the most common item thats been bought by everyone in the system//
	
	int maxID=-1,max=INT_MIN,searchindex,currentindex,i,purchasedsize=findsize(sPtr);
	PurchasedPtr temp=sPtr;
	if(purchasedsize==0){
		printf("purchased ptr is empty\n");
		return ;
	}
	    int *countarr=(int*)malloc(sizeof(int)*purchasedsize);
	
	    int *indexarr=(int*)malloc(sizeof(int)*purchasedsize);
	
	for(i=0;i<purchasedsize;i++){
		countarr[i]=0;
		indexarr[i]=0;
	}
	currentindex=0;
	while(temp!=NULL){
    searchindex=findID(temp->product_ID,purchasedsize,countarr,indexarr);
    if(searchindex==-1){
    	indexarr[currentindex]=temp->product_ID;
    	countarr[currentindex]=1;
    	currentindex++;
	}
	else
	{
		countarr[searchindex]++;
	}
	temp=temp->nextPtr;
	}
	 
	 maxID=indexarr[0];
	 max=countarr[0];
	 for(i=1;i<currentindex;i++){
	 	if(countarr[i]>max){
	 		maxID=indexarr[i];
	 		max=countarr[i];
		 }
	 }
	printf("most frequent bought item in general ID: %d\n",maxID);
}

void allproductcost(PurchasedPtr sPtr){               //function to calculate the earnings from all of the products//
	
	PurchasedPtr temp=sPtr;
	double c;	
		
	while(temp!=NULL){
	
		c=c+temp->total;
		
         temp=temp->nextPtr;		
	}
printf("\ntotal income from all products: %.2lf\n",c);
}

void customertotal(PurchasedPtr sPtr,int cs_ID){            //total charging of a customer total of their invoice files//
	
	PurchasedPtr temp=sPtr;
	double c;	
		
		
	while(temp!=NULL){
	if(temp->customer_ID==cs_ID){
		c=c+temp->total;	
	}
	
	temp=temp->nextPtr;	
  }
  printf("\ntotal charge from all purchases made: %.2lf\n",c);
}

void mincost(PurchasedPtr sPtr){                //minimum amounts thats been paid//
	
PurchasedPtr temp=sPtr;
	double min=temp->total;	
	while(temp!=NULL){
		
		if(min>temp->total){
			min=temp->total;
		}		
	
         temp=temp->nextPtr;		
	}
	printf("Minimum invoice payment=%.2lf\n",min);
}

void maxcost(PurchasedPtr sPtr){               //maximum amount thats been paid//
	
PurchasedPtr temp=sPtr;
   double max=temp->total;
   
   while(temp!=NULL){

   		if(max<temp->total){
   			max=temp->total;
		   }
	   
	   temp=temp->nextPtr;
   }	
   printf("Maximum invoice payment=%.2lf\n",max);
	
}

void mostcommoncus(PurchasedPtr sPtr,int cp_ID){            //to calculate a customers most common items they have bought//
	
int maxID=-1,max=INT_MIN,searchindex,currentindex,i,purchasedsize=findsize(sPtr);
	PurchasedPtr temp=sPtr;
	if(purchasedsize==0){
		printf("purchased ptr is empty\n");
		return ;
	}
	    int *countarr=(int*)malloc(sizeof(int)*purchasedsize);
	
	    int *indexarr=(int*)malloc(sizeof(int)*purchasedsize);
	
	for(i=0;i<purchasedsize;i++){
		countarr[i]=0;
		indexarr[i]=0;
	}
	currentindex=0;
	while(temp!=NULL){
		if(temp->customer_ID==cp_ID){
		
    searchindex=findID(temp->product_ID,purchasedsize,countarr,indexarr);
    if(searchindex==-1){
    	indexarr[currentindex]=temp->product_ID;
    	countarr[currentindex]=1;
    	currentindex++;
	}
	else
	{
		countarr[searchindex]++;
	}
}
	temp=temp->nextPtr;
	}
	 
	 maxID=indexarr[0];
	 max=countarr[0];
	 for(i=1;i<currentindex;i++){
	 	if(countarr[i]>max){
	 		maxID=indexarr[i];
	 		max=countarr[i];
		 }
	 }
	printf("Most frequent bought item ID: %d",maxID);
}

void cargolist(CustomerPtr *cPtr,int c_ID){                //to print the cargo expenses of a wanted customer//
	
	double Cargo;
	printf("\nPlease enter ID to see cargo expenses: ");
	scanf("%d",&c_ID);
	Cargo=cargo(cPtr,c_ID);
	printf("\ncargo expenses: %.2lf",Cargo);
}

int findsize(PurchasedPtr sPtr){
	PurchasedPtr temp= sPtr;
	int count=0;
	while(temp!=NULL){
		temp=temp->nextPtr;
		count++;
	}
	return count;
}

int findID(int searchID,int size,int *countarr,int *indexarr){
	
	int i;
	for(i=0;i<size;i++){
		if(indexarr[i]==searchID && countarr[i]!=0)return i;
	}
	return -1;
}

void leastCom(PurchasedPtr sPtr,int cp_ID){
		
	int minID=-1,min=INT_MAX,searchindex,currentindex,i,purchasedsize=findsize(sPtr);
	PurchasedPtr temp=sPtr;
	if(purchasedsize==0){
		printf("purchased ptr is empty\n");
		return ;
	}
	    int *countarr=(int*)malloc(sizeof(int)*purchasedsize);
	
	    int *indexarr=(int*)malloc(sizeof(int)*purchasedsize);
	
	for(i=0;i<purchasedsize;i++){
		countarr[i]=0;
		indexarr[i]=0;
	}
	currentindex=0;
	while(temp!=NULL){
		if(temp->customer_ID==cp_ID){
		
    searchindex=findID(temp->product_ID,purchasedsize,countarr,indexarr);
    if(searchindex==-1){
    	indexarr[currentindex]=temp->product_ID;
    	countarr[currentindex]=1;
    	currentindex++;
	}
	else
	{
		countarr[searchindex]++;
	}
}
	temp=temp->nextPtr;
	}
	 
	 minID=indexarr[0];
	 min=countarr[0];
	 for(i=1;i<currentindex;i++){
	 	if(countarr[i]<min){
	 		minID=indexarr[i];
	 		min=countarr[i];
		 }
	 }
	printf("least bought item ID: %d",minID);
}
	


