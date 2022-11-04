#ifndef physClasses
#define physClasses
#include <iostream>
#include <cmath>
#include "sinan.h"
using namespace std;
//*************************************SAYI-ALMA-FONKSIYONLARI**************************
double get_positive_double();
int get_positive_int();
//***********************************PARCACIK*******************************************
class Parcacik{
	friend class vector;
	private:
		double q; //yuk miktari
		vector Bv; // manyetik alan vektoru
		vector Vv; // hiz vektoru
		vector Fv; // kuvvet vektoru
	public:
		Parcacik();
		Parcacik(double q_, vector B, vector V, vector F);
		Parcacik(const Parcacik& p1);
		Parcacik& operator=(const Parcacik& p1);
		Parcacik& operator+(const Parcacik& p1);
		friend ostream& operator<<(ostream& os, Parcacik& p1);
		void set_q(double q_);
		void set_B(vector B_);
		void set_V(vector V_);
		void set_F(vector F_);
		double get_q();
		vector get_B();
		vector get_V();
		vector get_F();
		vector yuke_etki_eden_mkuvvet();
};
//*************************************MAKARA*******************************************
class Makara{
	friend class vector;
	private:
		int ID;
		double B; // manyetik alan siddeti
		double I; // akim siddeti
		double N; // sarim sayisi
		double L; // uzunluk
	public:
		Makara();
		Makara(int id_, double b_, double i_, double n_, double l_);
		Makara(const Makara& m1);
		Makara& operator=(const Makara& m1);
		Makara& operator+(const Makara& m1);
		friend ostream& operator<<(ostream& os, Makara& m1);
		void set_m_ID(int id_);
		void set_m_B(double b_);
		void set_m_I(double i_);
		void set_m_N(double n_);
		void set_m_L(double l_);
		int get_m_ID();
		double get_m_B();
		double get_m_I();
		double get_m_N();
		double get_m_L();
		double m_manyetik_alan_bul();	
};
//*****************************************TEL*******************************************
class Tel{
	friend class vector;
	private:
		int ID;
		double F; // manyetik kuvvet
		double B; // manyetik alan siddeti
		double I; // akim siddeti
		double r; // tel ve nokta/tel arasý uzaklik
		double L; // tel uzunlugu
	public:
		Tel();
		Tel(int id_, double f_, double b_, double i_, double r_, double l_);
		Tel(const Tel& t1);
		Tel& operator=(const Tel& t1);
		Tel& operator+(const Tel& t1);
		friend ostream& operator<<(ostream& os, Tel& t1);
		void set_t_ID(int id_);
		void set_t_F(double f_);
		void set_t_B(double b_);
		void set_t_I(double i_);
		void set_t_r(double r_);
		void set_t_L(double l_);
		int get_t_ID();
		double get_t_F();
		double get_t_B();
		double get_t_I();
		double get_t_r();
		double get_t_L();
		vector tele_etki_eden_kuvvet();
		double t_manyetik_alan_bul();
		double paralel_tel_arasi_kuvvet();
};
//*************************************SOLENOID*******************************************
class Solenoid{
	friend class vector;
	private: 
		int N; // sarim sayisi
		double L; // uzunluk
		double I; // akim
	public:
		Solenoid();
		Solenoid(int n_, double l_, double i_);
		Solenoid(const Solenoid& s1);
		Solenoid& operator=(const Solenoid& s1);
		Solenoid& operator+(const Solenoid& s1);
		friend ostream& operator<<(ostream& os, Solenoid& s1);
		void set_N(int n_);
		void set_L(double l_);
		void set_I(double i_);
		int get_N();
		double get_L();
		double get_I();
		double solenoid_manyetik_alan();
};
//*************************************OVERLOADED(<<)OPERATOR***************************
ostream& operator<<(ostream& os, Parcacik& p1);
ostream& operator<<(ostream& os, Makara& m1);
ostream& operator<<(ostream& os, Tel& t1);
ostream& operator<<(ostream& os, Solenoid& s1);
#endif
