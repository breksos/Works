#include <iostream>
#include <string.h>
#include "User.h"
#include "Meals.h"
#include "Sports.h"
#include <conio.h>
using namespace std;

User::User(){             //def const
	strcpy(name,"No entry");
	strcpy(surname,"No entry");
	age = 0;
	id = 0;
	week = 0;
	weight = 0.0;
	cal = 0;
}
User::User(char n[100],char s[100],int a,int i,int t,double w,int c){         //const with arg
	strcpy(name,n);
	strcpy(surname,s);
	age = a;
	id = i;
	week = t;
	weight = w;
	cal = c;
}
User::User(const User& other){                 //copy const
	strcpy(name,other.name);
	strcpy(surname,other.surname);
	age = other.age;
	id = other.id;
	week = other.week;
	weight = other.weight;
	cal = other.cal;
	
}
User& User::operator=(const User& other){           //assignment operator
	strcpy(name,other.name);
	strcpy(surname,other.surname);
	age = other.age;
	id = other.id;
	week = other.week;
	weight = other.weight;
	cal = other.cal;
    return *this;
}
double User::calc_cal(){                    //function using meals.h and sports.h libraries and calculating the cal intake and burn
	Breakfast b; Lunch l; Dinner d;
	Tennis t; Basketball ba; Swimming s; Football f;
	int calb=0,call=0,cald=0,calt=0,calba=0,cals=0,calf=0;
	cin>>b;
	calb = b.cal;
	cin>>l;
	call = l.cal;
	cin>>d;
	cald = d.cal;
	cin>>t;
	calt = t.size;
	cin>>ba;
	calba = ba.size;
	cin>>s;
	cals = s.size;
	cin>>f;
	calf = f.size;
	cout<<"\n\npress enter to keep going";
	getch();
	system("cls");
	cout<<"Breakfast had this week:"<<b.amount<<endl;
	cout<<"Lunches had this week:"<<l.amount<<endl;
	cout<<"Dinners had this week:"<<d.amount<<endl;
	cout<<"\nHow much tennis played this week:"<<t.time<<" minutes"<<endl;
	cout<<"How much basketball played this week:"<<ba.time<<" minutes"<<endl;
	cout<<"How much swimming done this week:"<<s.time<<" minutes"<<endl;
	cout<<"How much football played this week:"<<f.time<<" minutes"<<endl;
	cout<<"\nTaken calories this week:"<<calb+call+cald<<endl;
	cout<<"Burnt calories this week:"<<calt+calba+cals+calf<<endl;
	return (calb+call+cald-calt-calba-cals-calf);
}
istream& operator>>(istream& in,User& other){               //cin overload
	cout<<"Enter name:";
	in>>other.name;
	cout<<"Enter surname:";
	in>>other.surname;
	cout<<"Enter age:";
	in>>other.age;
	cout<<"Enter ID:";
	in>>other.id;
	cout<<"Enter week number:";
	in>>other.week;
	cout<<"Enter your weight:";
	in>>other.weight;
	other.cal = other.calc_cal();
	return in;
} 
ostream& operator<<(ostream &out, const User& other){         //cout overload
	out<<"Overall result screen:\n";
	out<<"\nName:"<<other.name<<"\nSurname:"<<other.surname<<"\nAge:"<<other.age<<"\nID:"<<other.id<<"\nWeek:"<<other.week<<"\nWeight:"<<other.weight<<"\nCal summary of the week:"<<other.cal;
	return out;
}

User operator+(User u1,User u2){              //+ operator overload to add 2 objects together
	User temp;
	
	strcat(u1.name,u2.name);
	strcpy(temp.name,u1.name);
	strcat(u1.surname,u2.surname);
	strcpy(temp.surname,u1.surname);
	temp.age = u1.age + u2.age;
	temp.id = u1.id + u2.id;
	temp.week = u1.week + u2.week;
	temp.weight = u1.weight + u2.weight;
	temp.cal = u1.cal + u2.cal;
	
	return temp; 
}
