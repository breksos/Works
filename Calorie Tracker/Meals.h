#ifndef MEALS_H
#define MEALS_H
#include <iostream>
using namespace std;

class Breakfast{      //variables needed to create breakfast object
	private:
		int cal;
		int amount;
	
	public:             //operator function and constructor prototypes which are defined in meals.h library
	    Breakfast();
		Breakfast(int c,int a);
		Breakfast(const Breakfast& other);
		Breakfast& operator=(const Breakfast& other);
		friend istream& operator>>(istream& in,Breakfast& other);
		friend ostream& operator<<(ostream& out,const Breakfast& other);
		friend Breakfast operator+(Breakfast b1,Breakfast b2);	
		friend class User;
};

class Lunch{            //variables needed to create Lunch object
	private:
		int cal;
        int amount;
    
    public:            //operator function and constructor prototypes which are defined in meals.h library
    	Lunch();
    	Lunch(int c,int a);
    	Lunch(const Lunch& other);
    	Lunch& operator=(const Lunch& other);
    	friend istream& operator>>(istream& in,Lunch& other);
    	friend ostream& operator<<(ostream& out,const Lunch& other);
    	friend Lunch operator+(Lunch l1,Lunch l2);
        friend class User;
};

class Dinner{           //variables needed to create Dinner object
	private:
		int cal;
		int amount;
		
	public:           //operator function and constructor prototypes which are defined in meals.h library
	    Dinner();
		Dinner(int c,int a);
		Dinner(const Dinner& other);
		Dinner& operator=(const Dinner& other);
		friend istream& operator>>(istream& in,Dinner& other);
		friend ostream& operator<<(ostream& out,const Dinner& other);
		friend Dinner operator+(Dinner d1,Dinner d2);	
        friend class User;
		
};
#endif
