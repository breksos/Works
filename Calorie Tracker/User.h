#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User{
	private:                 //variables needed to create user object
		char name[100];
		char surname[100];
		int age;
		int id;
		int week;
		double weight;
	    double cal;
	    
	public:                      //function operator and constructor prototypes which are defined in user.cpp file also befriended other classes since we need their variables calculating cal variable
        User();
        User(char n[100],char s[100],int a,int i,int t,double w,int c);
        User(const User& other);
        User& operator=(const User& other);
        double calc_cal();
        friend istream& operator>>(istream& in,User& other);
        friend ostream& operator<<(ostream& out,const User& other);
        friend User operator+(User u1,User u2);
        friend class Breakfast;
        friend class Lunch;
        friend class Dinner;
        friend class Tennis;
        friend class Basketball;
        friend class Swimming;
        friend class Football;
};
       
#endif
