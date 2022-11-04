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
		double get_psu(); //get fonksiyonlarý
		double get_res();
		double get_con();
		void set_psu(double p);  //set fonksiyonlarý
		void set_res(double r);
		void set_con(double c);
		double calc_curr();  //akým hesaplama
		double calc_power();//güç hesaplama
		void calc_bill(); //verilen fiyata göre fatura hesaplama
		double charg_cond(); //Kondansatörün þarj oluþunu hesaplama
		double decharg_cond();//kondansatörün deþarj oluþunu hesaplama
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
		double get_max_psu(); //get fonksiyonlarý
		double get_current();
		double get_res();
		double get_coil();
		double get_con();
		double get_freq();
 		void set_max_psu(double p);   //set fonksiyonlarý
		void set_current(double curr);
		void set_res(double r);
		void set_coil(double l);
		void set_con(double c);
		void set_freq(double f);
		double moment_psu();       // anlýk voltaj
		double voltage_amp();      //voltaj genliði
		double calc_curr();            //akým hesaplayýcý
		double calc_sinusoidal_curr();    //sinözodial akým
		double rms_curr();   //rms akým
		double rms_volt();    //rms voltaj
		double mom_volt_cross_res();     //direnç üstündeki voltaj
		double inductif_reactans();      //indüktif reaktans
		double mom_volt_cross_coil();    //bobin üstündeki voltaj
		double cap_reactans();         //kapasitif reaktans
		double mom_volt_cross_con();      // kondansatör üzerindeki voltaj
		double mom_charge_con();       //kondansatör þarjlanmasý
		double calc_Vmax_res();          //max direnç voltajý
		double calc_Vmax_coil();     //max bobin voltajý
		double calc_Vmax_con();       //max kondansatör voltajý
		double calc_emp();       // empedans hesaplama
		double calc_pow(); //güç hesaplayýcý
		friend double take_double(int den);// exception handling fonksiyonu      
		friend istream& operator>>(istream& in,Devre_Ac& other);       //in ve out operatörleri
		friend ostream& operator<<(ostream& out,const Devre_Ac& other);
		
};

#endif
