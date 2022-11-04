#include <iostream>
#include "User.h"
#include "Meals.h"
#include "Sports.h"
#include <conio.h>
using namespace std;

int main(){
	int x;
	while(1){
	system("cls");
	cout<<"Input [1] to enter user mode";
	cout<<"\nInput [2] to enter developer mode";
	cout<<"\nInput [3] to exit the application";
	cout<<"\nYour choice: ";
	cin>>x;
	
	switch(x){
		case 1:                             //User screen creating a new user and displaying it//
			{
			system("cls");
			User u;
			cin>>u;
			cout<<"\n!!Press ENTER to get summary screen!!";
			getch();
			system("cls");
			cout<<"Summary screen:\n";
			cout<<u;
			getch();
			break;
		}
	    case 2:                                                      //developer mode section testing every function ever//
	    {
			
	    	system("cls");
	    	User a;
	    	cout<<a;
	    	User a1("Berk","OGE",20,1,10,85.6,1000);
	    	cout<<"\n"<<a1;
	    	User a2(a1);
	    	cout<<"\n"<<a2;
	    	User a3;
	    	a3 = a1;
	    	cout<<"\n"<<a3;
	        User a4("Sude","Bahcivan",20,2,10,50,2000);
	        cout<<"\n"<<a4;
	        User a5;
	        a5 = a4 + a1;
			cout<<"\n"<<a5<<"\n\n";
			User a6;
			cin>>a6;
			cout<<"\n\npress enter to keep going"; //calc_cal function is tested inside cin overload//
			getch();
			system("cls");
			cout<<a6;
			cout<<"\n\npress enter to keep going";
			getch();
			system("cls");
			Breakfast b1;
			cout<<b1;
			Lunch l1(1800,3);
			cout<<"\n"<<l1;
			Dinner d1(2200,4);
			Dinner d2(d1);
			cout<<"\n"<<d2;
			Dinner d3;
			d3 = d2;
			cout<<"\n"<<d3;
			Lunch l2;
			cin>>l2;
			cout<<"\n"<<l2;
			Lunch l3;
			l3 = l2+l1;
			cout<<"\n"<<l3;
			getch();
			system("cls");
			Tennis t;
			cout<<t<<endl;
			Basketball ba(150,30);
			cout<<"\n"<<ba<<endl;
			Basketball ba2(ba);
			cout<<"\n"<<ba2<<endl;
			Basketball ba3;
			ba3 = ba2;
			cout<<"\n"<<ba3<<endl;
			Swimming s;
			cin>>s;
			cout<<"\n"<<s;
			Swimming s2(140,20);
			cout<<"\n"<<s2;
			Swimming s3;
			s3 = s2 + s;
			cout<<"\n"<<s3;
			getch();
	    	break;
	}
	case 3:                                  //case to exit the app
		cout<<"Thanks for choosing us :)";
		return 0;
        
		default:
        cout<<"Wrong entry try again!!";
        getch();
        system("cls");
        break;
	
	}
}
	return 0;
}
