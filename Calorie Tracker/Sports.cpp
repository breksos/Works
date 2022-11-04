#include <iostream>
#include "Sports.h"

using namespace std;

Tennis::Tennis(){               //def const
	size = 0;
	time =0;
}

Tennis::Tennis(int s,int t){          //const with arguments
	size = s;
	time = t;
}

Tennis::Tennis(const Tennis& other){          //copy const
	size = other.size;
	time = other.time;
}

Tennis& Tennis::operator=(const Tennis& other){           //assignment operator
	size = other.size;
	time = other.time;
	
	return *this;
}

istream& operator>>(istream& in,Tennis& other){              //cin overload
	cout<<"\nHow long have you played tennis in minutes:";
	in>>other.time;
	other.size = other.time*5;
	
	return in;
}

ostream& operator<<(ostream& out,const Tennis& other){           //cout overload
	cout<<"Minutes played:"<<other.time;
	cout<<"\nCalories burnt:"<<other.size;
}

Tennis operator+(Tennis t1,Tennis t2){                //+ operator overload to add two objects together
	Tennis temp;
	temp.size = t1.size + t2.size;
	temp.time = t1.time + t2.time;
	
	return temp;
}

Basketball::Basketball(){       //def const
	size = 0;
	time =0;
}

Basketball::Basketball(int s,int t){        //const with arguments
	size = s;
	time = t;
}

Basketball::Basketball(const Basketball& other){               //copy const
	size = other.size;
	time = other.time;
}

Basketball& Basketball::operator=(const Basketball& other){          //assignment operator
	size = other.size;
	time = other.time;
	
	return *this;
}

istream& operator>>(istream& in,Basketball& other){               //cin overload
	cout<<"How long have you played Basketball in minutes:";
	in>>other.time;
	other.size = other.time*6;
	
	return in;
}

ostream& operator<<(ostream& out,const Basketball& other){              //cout overload
	cout<<"Minutes played:"<<other.time;
	cout<<"\nCalories burnt:"<<other.size;
}

Basketball operator+(Basketball b1,Basketball b2){          //+ operator overload to add two objects together
	Basketball temp;
	temp.size = b1.size + b2.size;
	temp.time = b1.time + b2.time;
	
	return temp;
}

Swimming::Swimming(){                   //def const
	size = 0;
	time =0;
}

Swimming::Swimming(int s,int t){           //const with arguments
	size = s;
	time = t;
}

Swimming::Swimming(const Swimming& other){           //copy const
	size = other.size;
	time = other.time;
}

Swimming& Swimming::operator=(const Swimming& other){              //assignment operator
	size = other.size; 
	time = other.time;
	
	return *this;
}

istream& operator>>(istream& in,Swimming& other){             //cin overload
	cout<<"How long have you played Swimming in minutes:";
	in>>other.time;
	other.size = other.time*7;
	
	return in;
}

ostream& operator<<(ostream& out,const Swimming& other){            //cout overload
	cout<<"Minutes played:"<<other.time;
	cout<<"\nCalories burnt:"<<other.size;
}

Swimming operator+(Swimming s1,Swimming s2){            //+ operator overload to add two objects together
	Swimming temp;
	temp.size = s1.size + s2.size;
	temp.time = s1.time + s2.time;
	
	return temp;
}

Football::Football(){                 //def const
	size = 0;
	time =0;
}

Football::Football(int s,int t){                //const with arguments
	size = s;
	time = t;
}

Football::Football(const Football& other){              //copy const
	size = other.size;
	time = other.time;
}

Football& Football::operator=(const Football& other){                //assignment operator
	size = other.size;
	time = other.time;
	
	return *this;
}

istream& operator>>(istream& in,Football& other){                   //cin overload
	cout<<"How long have you played Football in minutes:";
	in>>other.time;
	other.size = other.time*5;
	
	return in;
}

ostream& operator<<(ostream& out,const Football& other){              //cout overload
	cout<<"Minutes played:"<<other.time;
	cout<<"\nCalories burnt:"<<other.size;
}

Football operator+(Football f1,Football f2){                   //+ operator overload to add two objects together
	Football temp;
	temp.size = f1.size + f2.size;
	temp.time = f1.time + f2.time;
	
	return temp;
}

