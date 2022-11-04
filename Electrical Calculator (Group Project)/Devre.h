#ifndef DEVRELER
#define DEVRELER
#include <iostream>
using namespace std;

class Devre_Dc{
	private:              //elemanlar
		double psu;
		double res;
		double con;
	
	public:
	    Devre_Dc();     //def const
		Devre_Dc(double p,double r,double c);  //const w/ arg
		Devre_Dc(const Devre_Dc& other);   //copy const
		Devre_Dc& operator=(const Devre_Dc& other);    //copy assignment
		double get_psu(); //get fonksiyonlar�
		double get_res();
		double get_con();
		void set_psu(double p);  //set fonksiyonlar�
		void set_res(double r);
		void set_con(double c);
		double calc_curr();  //ak�m hesaplama
		double calc_power();//g�� hesaplama
		void calc_bill(); //verilen fiyata g�re fatura hesaplama
		double charg_cond(); //Kondansat�r�n �arj olu�unu hesaplama
		double decharg_cond();//kondansat�r�n de�arj olu�unu hesaplama
		friend double take_double(int den);// exception handling fonksiyonu
		friend istream& operator>>(istream& in,Devre_Dc& other);//in ve out operator overloading
		friend ostream& operator<<(ostream& out,const Devre_Dc& other);
			
};

class Devre_Ac{
	private:          //elemanlar
		double max_psu;
		double current;
		double res;
		double coil;
		double con;
		double freq;
		
	public:            
	    Devre_Ac();   //Def const
		Devre_Ac(double p,double r,double l,double c,double f);  //const w arg
		Devre_Ac(const Devre_Ac& other);   //copy const
		Devre_Ac& operator=(const Devre_Ac& other);    //copy assignment
		double get_max_psu(); //get fonksiyonlar�
		double get_current();
		double get_res();
		double get_coil();
		double get_con();
		double get_freq();
 		void set_max_psu(double p);   //set fonksiyonlar�
		void set_current(double curr);
		void set_res(double r);
		void set_coil(double l);
		void set_con(double c);
		void set_freq(double f);
		double moment_psu();       // anl�k voltaj
		double voltage_amp();      //voltaj genli�i
		double calc_curr();            //ak�m hesaplay�c�
		double calc_sinusoidal_curr();    //sin�zodial ak�m
		double rms_curr();   //rms ak�m
		double rms_volt();    //rms voltaj
		double mom_volt_cross_res();     //diren� �st�ndeki voltaj
		double inductif_reactans();      //ind�ktif reaktans
		double mom_volt_cross_coil();    //bobin �st�ndeki voltaj
		double cap_reactans();         //kapasitif reaktans
		double mom_volt_cross_con();      // kondansat�r �zerindeki voltaj
		double mom_charge_con();       //kondansat�r �arjlanmas�
		double calc_Vmax_res();          //max diren� voltaj�
		double calc_Vmax_coil();     //max bobin voltaj�
		double calc_Vmax_con();       //max kondansat�r voltaj�
		double calc_emp();       // empedans hesaplama
		double calc_pow(); //g�� hesaplay�c�
		friend double take_double(int den);// exception handling fonksiyonu      
		friend istream& operator>>(istream& in,Devre_Ac& other);       //in ve out operat�rleri
		friend ostream& operator<<(ostream& out,const Devre_Ac& other);
		
};

#endif
