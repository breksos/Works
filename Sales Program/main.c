#include <stdio.h>
#include <stdlib.h>
#include "P1_200102002005_BHO_sales.h"

int main(){
	
	int id,x,type,pID,pType,sale_ID,p,i,inID,cont=1,res,tip;
	double coord_x,coord_y,price,cost,Cargo,a,total,b,c;
	char Name[50],PName[50];
	
	CustomerPtr Startptr = NULL;                                                   //starting pointers defined to null to call inside functions//
	ProductPtr StartptrP = NULL;                                                                 
	PurchasedPtr StartptrS = NULL;
	printf("\t\t\t\t\tSale Management System Main Menu\n");
	printf("\n");
	printf("Please enter [1] to enter new customer information\n");                      //main menu design for switch case system//
	printf("Please enter [2] to delete an existing customer information\n");
	printf("Please enter [3] to see the current customer list\n");
	printf("Please enter [4] to enter new product information\n");
	printf("Please enter [5] to see all the current product list\n");
	printf("Please enter [6] to delete an existing product\n");
	printf("Please enter [7] to make a purchase\n");
	printf("Please enter [8] to see all the invoice files\n");
    printf("Please enter [9] to see product analyze files\n");
    printf("Please enter [10] to see the customer analyze files\n");
    printf("Please enter [99] to exit the app\n");
    printf("Your choice: ");
	scanf("%d",&x);
	
	while(x!=99){
		
	switch (x){
	
		
		case 1:
           	
			printf("Please enter New customer information\n\n");                  //case 1 for entering new customer data into the list//
			printf("please enter your name: ");
		    fflush(stdin);
			gets(Name);
			printf("Please enter the ID: ");
		    scanf("%d",&id);
		    printf("Please enter the type");
		    scanf("%d",&type);
		    printf("Please enter the X coordinates of location: ");
		    scanf("%lf",&coord_x);
		    printf("Please enter the Y coordinates of location: ");
		    scanf("%lf",&coord_y);
		    insertCustomer(&Startptr,&Name,id,type,coord_x,coord_y);
		   
		    break;
		    
		case 2:
				 
		    	if(!isEmptyC(Startptr)){                                      //case 2 for deleting an existing customers data//
		    		printf("Enter ID to delete: ");
		    		scanf("%d",&id);
		    		if(deleteCustomer(&Startptr,id)){
		    			printf("%d is deleted.\n",id);
					}
					else{
						printf("%d not found try again: ",id);
                        scanf("%d",&id);					
					}
				}
		
				break;
				
		case 3:
		    if(!isEmptyC(Startptr)){                                   //case 3 for printing every customers information//
			printCustomer(Startptr,id);
		}
		else{
			printf("Empty List\n");
		}
			break;
			
        case 4:
        	printf("Please enter the Product Name: ");                    //case 4 for entering new product data to the list//
        	fflush(stdin);
        	gets(PName);
        	printf("Please enter new product ID: ");
        	scanf("%d",&pID);
        	printf("Please enter the product type: ");
        	scanf("%d",&pType);
        	printf("Please enter the product price: ");
        	scanf("%lf",&price);
        	insertProduct(&StartptrP,PName,pID,pType,price);
        	break;
			
		
		case 5:                                                                //case 5 for printing every product data existing//
			if(!isEmptyP(StartptrP)){		
		printProduct(StartptrP);
	    }
	    else{
	    	printf("list is empty");
		} 
		break;		
		
		case 6:
			if(!isEmptyP(StartptrP)){                                   //case 6 for deleting an existing product//
		    		printf("Enter ID to delete: ");
		    		scanf("%d",&pID);
		    		if(deleteProduct(&StartptrP,pID)){
		    			printf("%d is deleted.\n",pID);
					}
					else{
						printf("%d not found try again: ",pID);
                        scanf("%d",&pID);
					}
				}
			break;
	    
	    case 7:                                                            //case 7 for making a purchase and saving the data to purchase structure via list and pointers//
	    	printf("please enter sale id: ");
	    	scanf("%d",&sale_ID);
	    	printf("\nplease enter invoice id: ");
	    	scanf("%d",&inID);
	    	printf("Please enter customer ID: ");
	    	scanf("%d",&id);
	    	if(searchC(Startptr,id)==1){
	    		cont=1;
	    		while(cont!=0){
				
	    		printf("please enter the product code: ");
	    		scanf("%d",&pID);
	    		if(searchP(StartptrP,pID)==1){
	    			printf("please enter the amount of product you want to buy: ");
	    			scanf("%d",&p);
	    			printf("if you are done with shopping enter '0' ");
	    			tip=findtype(StartptrP,pID);
	    			price=findprice(StartptrP,pID,p);
	    			total=findprice(StartptrP,pID,p)+cargo(Startptr,id);
	    			purchase(&StartptrS,sale_ID,inID,id,pID,price,total,tip);
	    			scanf("%d",&cont);
				}
	
				else{printf("wrong id entry try again \n");
			}
				
		 } 
	}
		else {printf("wrong id entry");
			}	
			
			break;
	
	
	    case 8:
	    if(!isEmptyS(StartptrS)){                             //case 8 for printing every single invoice file existing//
			printSale(StartptrS);
		}
		else{
	    	printf("list is empty");
		} 
			break;
    
        case 9:
    
        	printf("plase enter product ID: ");                     //case 9 for product data analyzing//
        	scanf("%d",&pID);
            a=boughtamount(StartptrS,StartptrP,pID);
            printf("Amount of products bought:%.2lf\n",a);
            b=purchasedAnalyze(StartptrS,pID);
            printf("Total cost from the item:%.2lf",b);
            printf("\n\n");
            mostcommon(StartptrS);
            allproductcost(StartptrS);
            printf("\nEnter type from 1-3 to list items: ");
            scanf("%d",&type);
            Typeproduct(StartptrP,type);
            printf("\n");
            
            printf("Please choose a product type from 1-3 to see total cost of type: ");
            scanf("%d",&type);
            c=typeprice(StartptrS,type);
		 	printf("\nTotal cost of choosen type is: %.2lf",c);
			 break;
		
		
		case 10:
		    printf("please enter customer type 1 or 0 to list them: ");           //case 10 for customer data analyzing//
		    scanf("%d",&type);
		    Typecustomer(Startptr,type);
		    
			printf("please enter your ID for shopping history list: ");
			scanf("%d",&id);
			customershoplist(StartptrS,id);	
		  
		    printf("please enter ID for total payment: ");
		    scanf("%d",&id);
		    customertotal(StartptrS,id);
		
		    printf("\nMinimum and Maximum payments thats been made in general:\n");
		    mincost(StartptrS);
		    maxcost(StartptrS);
		    
		    printf("Enter ID for most common and least common item customer bought: ");
		    scanf("%d",&id);
		    mostcommoncus(StartptrS,id);
			leastCom(StartptrS,id);
			cargolist(Startptr,id);
		  
			break;
		
		}
	getch();
	system("cls");	
	printf("\t\t\t\t\tSale Management System Main Menu\n");
	printf("\n");
	printf("Please enter [1] to enter new customer information\n");
	printf("Please enter [2] to delete an existing customer information\n");
	printf("Please enter [3] to see the current customer list\n");
	printf("Please enter [4] to enter new product information\n");
	printf("Please enter [5] to see all the current product list\n");
	printf("Please enter [6] to delete an existing product\n");
	printf("Please enter [7] to make a purchase\n");
	printf("Please enter [8] to see all the invoice files\n");
	printf("Please enter [9] to see product analyze files\n");
	printf("Please enter [10] to see the customer analyze files\n");
	printf("Please enter [99] to exit the app\n");
    printf("Your choice: ");
	scanf("%d",&x); 
	}
	printf("Thanks for choosing us :)");
	getch();
	return 0;
	}
