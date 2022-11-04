#ifndef P1_200102002005_BHO_sales
#define P1_200102002005_BHO_sales
//customer structure for list//
struct customer {
int ID;
char name[50] ;
 unsigned int type : 1;
double x_coord;
double y_coord;
struct Customer *Nextptr; 
};


typedef struct customer Customer; 
typedef Customer * CustomerPtr; 

//Product structure for list//

struct product {
int ID;
char name[50];
unsigned int type : 4;
double price;
struct Product *Nextptr; 
};

typedef struct product Product; 
typedef Product * ProductPtr;

//Purchasing structure for  invoice list//
struct purchased {
int ID;
int invoice_ID;
int customer_ID;
int product_ID;
double cost;
int tip;
double total;
struct Purchased *nextPtr; 
}; 

typedef struct purchased Purchased; 
typedef Purchased * PurchasedPtr; 


struct leastcommon{
	int ID;
	int count;
};

typedef struct leastcommon least;


//*****************************************************//
//customer function prototypes//

void insertCustomer( CustomerPtr *cPtr,char *Name,int c_ID, int c_type,double c_x, double c_y);
int deleteCustomer( CustomerPtr *cPtr, int c_ID);
int isEmptyC( CustomerPtr cPtr );
void printCustomer(CustomerPtr currentcPtr,int c_ID);
int searchC(CustomerPtr cPtr,int c_ID);
double cargo(CustomerPtr *cPtr,int c_ID);
void Typecustomer(CustomerPtr currentcPtr,int c_type);
void cargolist(CustomerPtr *cPtr,int c_ID);
//**********************************************************//
//product funtion prototypes//

void insertProduct(ProductPtr *pPtr,char *Name,int p_ID,int p_type,double p_price);
void printProduct(ProductPtr CurrentpPtr);
int deleteProduct(ProductPtr *pPtr,int p_ID);
int isEmptyP(ProductPtr sPtr);
int searchP(ProductPtr pPtr,int p_ID);
void Typeproduct(ProductPtr pPtr,int p_type);
//***********************************************************//
//purchase funtion prototypes//
void purchase(PurchasedPtr *sPtr,int s_ID,int in_ID,int cs_ID,int cp_ID,double price,double tot,int Tip);
double findprice(ProductPtr pPtr,int p_ID,int x);
void printSale( PurchasedPtr CurrentsPtr);
double purchasedAnalyze(PurchasedPtr sPtr,int cp_ID);
double boughtamount(PurchasedPtr sPtr,ProductPtr pPtr,int p_ID);
void mostcommon(PurchasedPtr sPtr);
void allproductcost(PurchasedPtr sPtr);
void customershoplist(PurchasedPtr sPtr,int cs_ID);
void mostcommoncus(PurchasedPtr sPtr,int cp_ID);
void customertotal(PurchasedPtr sPtr,int cs_ID);
void mincost(PurchasedPtr sPtr);
void maxcost(PurchasedPtr sPtr);
double typeprice(PurchasedPtr sPtr,int Tip);
void leastCom(PurchasedPtr sPtr,int cp_ID);
int findID(int searchID,int size,int *countarr,int *indexarr);
int findsize(PurchasedPtr sPtr);

#endif
