#include <iostream>
#include "Meals.h"

using namespace std;

Breakfast::Breakfast(){                    //def const
	cal = 0;
	amount = 0;
}

Breakfast::Breakfast(int c,int a){         //const with arg
	cal = c;
	amount = a;
}

Breakfast::Breakfast(const Breakfast& other){    //copy const
	cal = other.cal;
	amount = other.amount;
}

Breakfast& Breakfast::operator=(const Breakfast& other){        //assignment operator
	cal = other.cal;
	amount = other.amount;
	
	return *this;
}

istream& operator>>(istream& in,Breakfast& other){                //cin overload
int bs=0,bm=0,bl=0;
cout<<"\nHow many small breakfast you had:";
in>>bs;
int sc = bs*200;
cout<<"How many medium breakfast you had:";
in>>bm;
int mc = bm*400;
cout<<"How many large breakfast you had:";
in>>bl;
int lc = bl*600;
other.cal = sc+mc+lc;
other.amount = bs+bm+bl;

return in;
}

ostream& operator<<(ostream& out,const Breakfast& other){            //cout overload
	out<<"Amount of breakfast had in 7 days:"<<other.amount;
	out<<"\nAmount of cal taken in 7 days at Breakfast:"<<other.cal;
	
	return out;
}

Breakfast operator+(Breakfast b1,Breakfast b2){              //+ op. overload to add 2 object together
	Breakfast temp;
	temp.amount = b1.amount + b2.amount;
	temp.cal = b1.cal + b2.cal;
	
	return temp;
}

Lunch::Lunch(){                              //def const
	cal = 0;
	amount = 0;
}

Lunch::Lunch(int c,int a){                     //const with arg
	cal = c;
	amount = a;
}

Lunch::Lunch(const Lunch& other){                 //copy const
	cal = other.cal;
	amount = other.amount;
}

Lunch& Lunch::operator=(const Lunch& other){                 //assignment operator
	cal = other.cal;
	amount = other.amount;
	
	return *this;
}

istream& operator>>(istream& in,Lunch& other){                 //cin overload
int bs=0,bm=0,bl=0;
cout<<"\nHow many small Lunch you had:";
in>>bs;
int sc = bs*400;
cout<<"How many medium Lunch you had:";
in>>bm;
int mc = bm*600;
cout<<"How many large Lunch you had:";
in>>bl;
int lc = bl*800;
other.cal = sc+mc+lc;
other.amount = bs+bm+bl;

return in;
}

ostream& operator<<(ostream& out,const Lunch& other){                 //cout overload
	out<<"Amount of Lunch had in 7 days:"<<other.amount;
	out<<"\nAmount of cal taken in 7 days at Lunch:"<<other.cal;

    return out;
}

Lunch operator+(Lunch b1,Lunch b2){                        //+ op. overload to add 2 object together
	Lunch temp;
	temp.amount = b1.amount + b2.amount;
	temp.cal = b1.cal + b2.cal;
	
	return temp;
}

Dinner::Dinner(){                                          //def const
	cal = 0;
	amount = 0;
}

Dinner::Dinner(int c,int a){                   //const with arg
	cal = c;
	amount = a;
}

Dinner::Dinner(const Dinner& other){                  //copy const
	cal = other.cal;
	amount = other.amount;
}

Dinner& Dinner::operator=(const Dinner& other){               //assignment operator
	cal = other.cal;
	amount = other.amount;
	
	return *this;
}

istream& operator>>(istream& in,Dinner& other){              //cin overload
int bs=0,bm=0,bl=0;
cout<<"\nHow many small Dinner you had:";
in>>bs;
int sc = bs*400;
cout<<"How many medium Dinner you had:";
in>>bm;
int mc = bm*600;
cout<<"How many large Dinner you had:";
in>>bl;
int lc = bl*800;
other.cal = sc+mc+lc;
other.amount = bs+bm+bl;

return in;
}

ostream& operator<<(ostream& out,const Dinner& other){               //cout overload
	out<<"Amount of Dinner had in 7 days:"<<other.amount;
	out<<"\nAmount of cal taken in 7 days at Dinner:"<<other.cal;
	
	return out;
}

Dinner operator+(Dinner b1,Dinner b2){                    //+ op. overload to add 2 object together
	Dinner temp;
	temp.amount = b1.amount + b2.amount;
	temp.cal = b1.cal + b2.cal;
	
	return temp;
}
