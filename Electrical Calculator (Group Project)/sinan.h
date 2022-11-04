#ifndef _sinan_
#define _sinan_
#include <cmath>
#include <iostream>
#define K 8.987e9 
#define PI 3.1428
using namespace std;

double kok(double q);
void perfect_get_double(double& a,istream& i);
double take_double(double a,double b);
double take_int(int l,int u);



class vector{
	friend class Parcacik;
	private:
		double x;
		double y;
		double z;
	public:
		vector();
		vector(double xx,double yy,double zz);
		vector(const vector &v);
		vector& operator=(const vector& v);
		void setx(double xx){x = xx;}
		void sety(double yy){y = yy;}
		void setz(double zz){z = zz;}
		double getx()const{return x;}
		double gety()const{return y;}
		double getz()const{return z;}
		
		vector operator+(const vector& v);
		vector operator-(const vector& v);
		vector operator*(const vector& v);
		
		friend ostream& operator<<(ostream& o,const vector& v);
		friend istream& operator>>(istream& i,vector& v);
		double magnitude();
	    
};


class charge{
	private:
		double x;
		double y;
		double charge_;
	public:
		//constructors
		charge();
		charge(double xx,double yy,double ch);
		charge(const charge& c);
		charge& operator=(const charge& c);
		//set,get
		void setx(double xx){x = xx;}
		void sety(double yy){y = yy;}
		void setc(double cc){charge_ = cc;}
		double getx(){return x;}
		double gety(){return y;}
		double getc(){return charge_;}
		friend ostream& operator<<(ostream& out,const charge& c);
		friend istream& operator>>(istream& in,charge& c);	
		double range(charge &c);
		vector SingleChargeField(double xx,double yy);
	
};

vector operator*(const vector& v2,double coeff);
vector operator*(double coeff,const vector& v2);
double potential_twocharge(charge& a,charge &b);

class ChargeSystem{
	private:
		int size;
		charge* root;
		double total_energy;
	public:
		ChargeSystem();
		ChargeSystem(int sizee,charge* hold);
		ChargeSystem(int sizee,double R,double CC);
		ChargeSystem(const ChargeSystem& ch);
		ChargeSystem& operator=(const ChargeSystem& ch);
		~ChargeSystem();
		
		
		charge& operator[](int x);
		
		void print();
		void prinnt();
		double calculate_total_system_energy();
		double potentialofdot(double xx,double yy);
		vector TotalFieldindotof(double xx,double yy);
	
	
};
void yuksistemi();
#endif
