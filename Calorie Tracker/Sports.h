#ifndef SPORTS_H
#define SPORTS_H
#include <iostream>
using namespace std;

class Tennis{   
	private:     //variables needed to  create the tennis class
		int size;
		int time;
	
	public:           //constructor operator and function prototypes which are defined in sports.h library
	    Tennis();
		Tennis(int s,int t);
		Tennis(const Tennis& other);
		Tennis& operator=(const Tennis& other);
		friend istream& operator>>(istream& in,Tennis& other);
		friend ostream& operator<<(ostream& out,const Tennis& other);
		friend Tennis operator+(Tennis t1,Tennis t2);
		friend class User;	
};

class Basketball{       //variables needed to  create the Basketball class
	private:
		int size;
		int time;
	
	public:             //constructor operator and function prototypes which are defined in sports.h library
	    Basketball();
		Basketball(int s,int t);
		Basketball(const Basketball& other);
		Basketball& operator=(const Basketball& other);
		friend istream& operator>>(istream& in,Basketball& other);
		friend ostream& operator<<(ostream& out,const Basketball& other);
		friend Basketball operator+(Basketball b1,Basketball b2);
		friend class User;	
};

class Swimming{            //variables needed to  create the Swimming class
	private:
		int size;
		int time;
	
	public:          //constructor operator and function prototypes which are defined in sports.h library
	    Swimming();
		Swimming(int s,int t);
		Swimming(const Swimming& other);
		Swimming& operator=(const Swimming& other);
		friend istream& operator>>(istream& in,Swimming& other);
		friend ostream& operator<<(ostream& out,const Swimming& other);
		friend Swimming operator+(Swimming s1,Swimming s2);	
		friend class User;
};


class Football{                  //variables needed to  create the Football class
	private:
		int size;
		int time;
	
	public:            //constructor operator and function prototypes which are defined in sports.h library
	    Football();
		Football(int s,int t);
		Football(const Football& other);
		Football& operator=(const Football& other);
		friend istream& operator>>(istream& in,Football& other);
		friend ostream& operator<<(ostream& out,const Football& other);
		friend Football operator+(Football f1,Football f2);
		friend class User;	
};
#endif
