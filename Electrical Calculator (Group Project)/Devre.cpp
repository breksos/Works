#include <iostream>
#include "Devre.h"
#include <cmath>
#define e 2.7182818

using namespace std;

double take_double(int den){
	//omersinanozer 1901022056 taraf�ndan yaz�lan fonksiyonu overloading ile kendime uyarlad�m Berk Hakan �GE 200102002005
	double c = 0;
	den = 0;
	tekrar:
	cout <<"S�f�rdan b�y�k say� giriniz"<< endl;
	cin >> c;
	bool flag = false;
	if(c >= den ){
		flag = true;
	} 
	try{
		if(cin.fail()){
			throw 1;
		}
		if(flag == false){
			throw 2;
		}
	}
	catch(int q){
		if(q == 1){
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "ERROR:it seems like you put inappropriate data type" << endl;
			goto tekrar;
		}
		if(q == 2){
			goto tekrar;
		}
	}
	return c;
}

Devre_Dc::Devre_Dc(){      //def const
	psu = 0;
	res = 0;
	con = 0;
}

Devre_Dc::Devre_Dc(double p,double r,double c){    //const w arg
	psu = p;
	res = r;
	con = c;
}

Devre_Dc::Devre_Dc(const Devre_Dc& other){    //copy const
	psu = other.psu;
	res = other.res;
	con = other.con;
}

Devre_Dc& Devre_Dc::operator=(const Devre_Dc& other){   //copy assignment
	psu = other.psu;
	res = other.res;
	con = other.con;
	
	return *this;
} 

double Devre_Dc::get_psu(){            //get fonksiyonlar�
	return psu;
}

double Devre_Dc::get_res(){
	return res;
}

double Devre_Dc::get_con(){
	return con;
}

void Devre_Dc::set_psu(double p){       //set fonksiyonlar�
	psu = p;
}

void Devre_Dc::set_res(double r){
	res = r;
}

void Devre_Dc::set_con(double c){
	con = c;
}

double Devre_Dc::calc_curr(){        //ak�m hesaplama
	double curr=0;
	if(con==0){
		curr = psu / res;
	}
	else{
		double t=0;
		cout<<"Ak�m� gormek istediginiz zamani giriniz: "<<endl;    //ak�m i�in gerekli zaman
		t = take_double(0);
		curr = (psu / res)*pow(e,-t/res*con);
	}
	return curr;
}

double Devre_Dc::calc_power(){            //g�� hesaplay�c�
	double pwr=0;
	double c=0;
	if(con==0){
		pwr = pow(psu,2)/res;
	}
	else{
		double t=0;
		cout<<"Gucu hesaplamak istediginiz zamani giriniz: "<<endl;     //kondansat�r varsa zaman gerekmektedir
		t = take_double(0);
		c = (psu / res)*pow(e,-t/res*con);
		pwr = pow(c,2)*res;
	}
	return pwr;
}

void Devre_Dc::calc_bill(){                        //fatura haz�rlay�c�
	double b=0;
	cout<<"Fatura i�in birim fiyat giriniz: "<<endl;
	b = take_double(0);
	double pwr = calc_power();
	cout<<"Faturan�z: "<<30*(pwr/1000)*b<<" + vergiler" <<endl;
}

double Devre_Dc::charg_cond(){         // kondansat�r y�klenmesi
	double Q = 0,q = 0,t = 0;
	cout<<"yuklenmis miktar icin bir zaman giriniz: ";
	t = take_double(0);
	Q = psu*con;
	q = Q*(1-pow(e,-t/(res*con))); 

    return q;
}

double Devre_Dc::decharg_cond(){          // de�arj olan kondansat�r
	double Q = 0,q=0,t=0;
	cout<<"Desarj an�nda yuk miktari icin zaman giriniz: ";
	t = take_double(0);
	Q = psu*con;
	q = Q*pow(e,-t/(res*con));
	
	return q;
}

istream& operator>>(istream& in, Devre_Dc& other){     // overloaded operat�r
	int den = 0;
	cout<<"L�tfen voltaj miktar�n� giriniz: ";
    other.psu = take_double(den);
	cout<<"\n Lutfen devrede istedginiz direnc miktarini giriniz: ";
	other.res = take_double(den);
	cout<<"\n L�tfen devrede istediginiz kondansator degerini giriniz: ";
	other.con = take_double(den);
	
	return in;
}

ostream& operator<<(ostream& out,const Devre_Dc& other){    // overloaded operat�r
	out<<"Voltaj: "<<other.psu<<endl;
	out<<"Direnc: "<<other.res<<endl;
	out<<"Kondansator: "<<other.con<<endl;
	
	return out;
}
 
Devre_Ac::Devre_Ac(){         //def const
	max_psu = 0; 
	current = 0;
	res = 0;
	coil = 0;
	con = 0;
	freq = 0;
}

Devre_Ac::Devre_Ac(double p,double r,double l,double c,double f){      //const w arg
	max_psu = p;
	res = r;
	coil = l;
	con  = c;
	freq = f;
	current = calc_curr();
}

Devre_Ac::Devre_Ac(const Devre_Ac& other){       // copy const
	max_psu = other.max_psu;
	current = other.current;
	res = other.res;
	coil = other.coil;
	con  = other.con;
	freq = other.freq;
}

Devre_Ac& Devre_Ac::operator=(const Devre_Ac& other){      //copy assignment operat�r
	max_psu = other.max_psu;
	current = other.current;
	res = other.res;
	coil = other.coil;
	con = other.con;
	freq = other.freq;
	
	return *this;
}

double Devre_Ac::get_max_psu(){         //get fonksiyonlar�
	return max_psu;
}

double Devre_Ac::get_current(){       
	return current;
}

double Devre_Ac::get_res(){
	return res;
}

double Devre_Ac::get_coil(){
	return coil;
}

double Devre_Ac::get_con(){
	return con;
}

double Devre_Ac::get_freq(){
	return freq;
}

void Devre_Ac::set_max_psu(double p){     //set fonksiyonlar�
	max_psu = p;
}

void Devre_Ac::set_current(double curr){
	current = curr;
}

void Devre_Ac::set_res(double r){
	res = r;
}

void Devre_Ac::set_coil(double l){
	coil = l;
}

void Devre_Ac::set_con(double c){
	con = c;
}

void Devre_Ac::set_freq(double f){
	freq = f;
}

double Devre_Ac::moment_psu(){             // anl�k voltaj de�eri
	double t=0;
	cout<<"Anlik voltaj icin zamani giriniz: ";
	t = take_double(0);
	double w = voltage_amp();
	return (max_psu*cos((M_PI/180)*w*t));
}

double Devre_Ac::voltage_amp(){       // genlik hesaplay�c�
	double w;
	w = 2*M_PI*freq;
	return w;
}

double Devre_Ac::calc_curr(){       // ak�m hesaplay�c�
	
	double I = 0;
	double E = calc_emp();
	I = max_psu/E;
	return I;
	
}

double Devre_Ac::calc_sinusoidal_curr(){       //sin�zodial ak�m hesaplay�c�
   	double t = 0;
   	cout<<"Sinusoidal akimi gormek istediginiz zamani giriniz: ";
   	t = take_double(0);
   	double w = voltage_amp();
   	return (current*cos((M_PI/180)*w*t));
}

double Devre_Ac::rms_volt(){      //rms voltaj
	double x = max_psu/pow(2,0.5);
	return x;
}

double Devre_Ac::rms_curr(){     //rms ak�m
	double x = current/pow(2,0.5);
	return x;
}

double Devre_Ac::mom_volt_cross_res(){        //diren� �zerinden anl�k voltaj
    double t = 0;
    cout<<"Direnc ustundeki anlik voltaj icin zaman giriniz: ";
    t = take_double(0);
    double w = voltage_amp();
    return(max_psu*cos((M_PI/180)*w*t));
} 

double Devre_Ac::inductif_reactans(){        //ind�ktif reaktans hesab�
	double w = voltage_amp();
	
	return coil*w;
}

double Devre_Ac::mom_volt_cross_coil(){         //bobin �zerinden anl�k voltaj
    double t = 0;
    cout<<"Bobin ustundeki anlik voltaj icin zaman giriniz: ";
    t = take_double(0);
	double w = voltage_amp();
	
	return (-(coil*w*current)*sin((M_PI/180)*w*t));
}

double Devre_Ac::cap_reactans(){           //kapasitif reaktans
	double w = voltage_amp();
	double x = 1/(w*con);
	
	return x;
}

double Devre_Ac::mom_volt_cross_con(){      //kondansat�r �zerinden anl�k voltaj
	
	double t = 0;
	cout<<"Kondansator uzerindeki anlik voltaj icin zaman giriniz: ";
	t = take_double(0);
	double w = voltage_amp();
	
	return ((current/(w*con))*sin((M_PI/180)*w*t));
}


double Devre_Ac::mom_charge_con(){              //anl�k kondansat�r y�k�
	double t = 0;
	double w = voltage_amp();
	cout<<"Kondansator uzerindeki anlik yuklenmeyi gormek icin zaman giriniz: ";
	t = take_double(0);
	return ((current/w)*sin((M_PI/180)*w*t));
}

double Devre_Ac::calc_Vmax_res(){        // max voltaj fonksiyonlar�
	return (current*res);
}

double Devre_Ac::calc_Vmax_coil(){
	double w = voltage_amp();
	return (coil*w*current);
}

double Devre_Ac::calc_Vmax_con(){
	double w = voltage_amp();
	return (current/(w*con));
}

double Devre_Ac::calc_emp(){           //empedans hesap makinesi
	double z = 0;
	double Xl = inductif_reactans();
	double Xc = cap_reactans();
	double d = Xl - Xc;
	if(res!=0&&coil!=0&&con!=0){
		double in = pow(res,2)+pow(d,2);
		z = pow(in,0.5);
	}
	if(res==0){
		z = Xl - Xc;
	}
	return z;
}

double Devre_Ac::calc_pow(){          //g�� hesaplay�c�
	double ang = 0;
	ang = atan((calc_Vmax_coil()-calc_Vmax_con())/calc_Vmax_res());
    double pwr = 0.5*max_psu*current*cos((M_PI/180)*ang);
    return pwr;
    
}

istream& operator>>(istream& in,Devre_Ac& other){         //cin overload
	cout<<"Max voltaj degerini giriniz: ";
	other.max_psu = take_double(0);
	cout<<"\nDirenc degerini giirniz: ";
	other.res = take_double(0);
	cout<<"\nBobin degerini giriniz: ";
    other.coil = take_double(0);
    cout<<"\nKondansator degerini giriniz: ";
    other.con = take_double(0);
    cout<<"\nFrekans degerini giriniz: ";
    other.freq = take_double(0);
    other.current = other.calc_curr();
   
    return in;
}

ostream& operator<<(ostream& out,const Devre_Ac& other){  //cout overload
	out<<"Max sistem Voltaji: "<<other.max_psu<<endl;
	out<<"Ak�m: "<<other.current<<endl;
	out<<"Direnc: "<<other.res<<endl;
	out<<"Bobin: "<<other.coil<<endl;
	out<<"Kondansator: "<<other.con<<endl;
	out<<"Frekans: "<<other.freq<<endl;
	
	return out;
}
















