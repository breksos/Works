#include <iostream>
#include "sinan.h"
#include "manyetizma.h"
#include <cmath>
using namespace std;

//*****************************************SAYI-ALMA-FONKSIYONLARI*************************
double get_positive_double(){
	double a;
	basla:
        cin >> a;
        try{
            if(a < 0){
                throw 1;
            }
            if(cin.fail())
            	throw 2;
        }
        catch(int e){
            if(e == 1){
                cout << "Lutfen pozitif sayi giriniz = ";
                goto basla;
            }
            if(e == 2){
            	cin.clear();
				cin.ignore(1000,'\n');
            	cout << "Lutfen double turunde bir veri giriniz = ";
            	goto basla;
			}
        }
    return a;
}

int get_positive_int(){
	int a;
	basla:
        cin >> a;
        try{
            if(a < 0){
                throw 1;
            }
            if(cin.fail())
            	throw 2;
        }
        catch(int e){
            if(e == 1){
                cout << "Lutfen pozitif sayi giriniz = ";
                goto basla;
            }
            if(e == 2){
            	cin.clear();
				cin.ignore(1000,'\n');
            	cout << "Lutfen integer turunde bir veri giriniz = ";
            	goto basla;
			}
        }
    return a;
}

//*************************************PARCACIK*****************************************
Parcacik::Parcacik(){
	q = 0;
	
	Bv.x = 0;
	Bv.y = 0;
	Bv.z = 0;
	
	Vv.x = 0;
	Vv.y = 0;
	Vv.z = 0;
	
	Fv.x = 0;
	Fv.y = 0;
	Fv.z = 0;
}

Parcacik::Parcacik(double q_, vector B, vector V, vector F){
	q = q_;
	Bv = B;
	Vv = V;
	Fv = F;
}

Parcacik::Parcacik(const Parcacik& p1){

    q = p1.q;
    Bv = p1.Bv;
    Vv = p1.Vv;
    Fv = p1.Fv;

}

Parcacik& Parcacik::operator=(const Parcacik& p1){
	q = p1.q;
    Bv = p1.Bv;
    Vv = p1.Vv;
    Fv = p1.Fv;
	
	return *this;
}

Parcacik& Parcacik::operator+(const Parcacik& p1){
	q = q + p1.q;
	Bv = Bv + p1.Bv;
	Vv = Vv + p1.Vv;
	Fv = Fv + p1.Fv;
	
	return *this;
}

ostream& operator<<(ostream& os, Parcacik& p1){
	os << "q = " << p1.get_q() << endl;
	os << "B =\n" << p1.get_B() << endl;
	os << "V =\n" << p1.get_V() << endl;
	os << "F =\n" << p1.get_F() << endl;
}

void Parcacik::set_q(double q_){q = q_;}
void Parcacik::set_B(vector B_){Bv = B_;}
void Parcacik::set_V(vector V_){Vv = V_;}
void Parcacik::set_F(vector F_){Fv = F_;}
double Parcacik::get_q(){return q;}
vector Parcacik::get_B(){return Bv;}
vector Parcacik::get_V(){return Vv;}
vector Parcacik::get_F(){return Fv;}

vector Parcacik::yuke_etki_eden_mkuvvet(){
	system("cls");
	double x;
	cout << "Parcacigin yukunu giriniz (C) : ";
	cin >> q;
	
	cout << "Hiz bilgisi icin i, j, k bilesenlerini giriniz (m/s)" << endl;
	cout << "i (x ekseni) = ";
	cin >> x;
	Vv.setx(x);
	cout << "j (y ekseni) = ";
	cin >> x;
	Vv.sety(x);
	cout << "k (z ekseni) = ";
	cin >> x;
	Vv.setz(x);
	
	cout << "Manyetik alan i(x), j(y), k(z) bilesenlerini giriniz(Tesla)" << endl;
	cout << "i = ";
	cin >> x;
	Bv.setx(x);
	cout << "j = ";
	cin >> x;
	Bv.sety(x);
	cout << "k = ";
	cin >> x;
	Bv.setz(x);
	
	Fv = q * (Vv * Bv);
	cout << "---------------------------------" << endl;
	cout << "Parcaciga etki eden manyetik kuvvet = " << endl;
	cout << "X ekseninde " << Fv.getx() << " N" << endl;
	cout << "Y ekseninde " << Fv.gety() << " N" << endl;
	cout << "Z ekseninde " << Fv.getz() << " N" << endl;
	return Fv;
}
//*************************************MAKARA******************************************
Makara::Makara(){
	ID = 0;
	B= 0;
	I = 0;
	N = 0;
	L = 0;
}

Makara::Makara(int id_, double b_, double i_, double n_, double l_){
	ID = id_;
	B = b_;
	I = i_;
	N = n_;
	L = l_;
}

Makara::Makara(const Makara& m1){
	ID = m1.ID;
	B = m1.B;
	I = m1.I;
	N = m1.N;
	L = m1.L;
}

Makara& Makara::operator=(const Makara& m1){
	ID = m1.ID;
	B = m1.B;
	I = m1.I;
	N = m1.N;
	L = m1.L;
	
	return *this;
} 

Makara& Makara::operator+(const Makara& m1){
	ID = ID + m1.ID;
	B = B + m1.B;
	I = I + m1.I;
	N = N + m1.N;
	L = L + m1.L;
	
	return *this;
} 

ostream& operator<<(ostream& os, Makara& m1){
	os << "B = " << m1.get_m_B() << "Tesla" << endl;
	os << "I = " << m1.get_m_I() << "A" << endl;
	os << "N = " << m1.get_m_N() << endl;
	os << "L = " << m1.get_m_L() << "m" << endl;
}

void Makara::set_m_ID(int id_){ID = id_;}
void Makara::set_m_B(double b_){B = b_;}
void Makara::set_m_I(double i_){I = i_;}
void Makara::set_m_N(double n_){N = n_;}
void Makara::set_m_L(double l_){L = l_;}
int Makara::get_m_ID(){return ID;}
double Makara::get_m_B(){return B;}
double Makara::get_m_I(){return I;}
double Makara::get_m_N(){return N;}
double Makara::get_m_L(){return L;}

double Makara::m_manyetik_alan_bul(){
	system("cls");
	cout << "Makaradan gecen akimi giriniz (A) = ";
	cin >> I;
	cout << "Makaranin sarim sayisini giriniz = ";
	N = get_positive_int();
	cout << "Makaranin uzunlugunu giriniz (m) = ";
	L = get_positive_double();
	B = ((4 * M_PI) * pow(10,-7)) * (I / L) * N;
	cout << "-------------------------------------" << endl;
	cout << "Makara uzerinden gecen manyetik alan siddeti = " << B << " Tesla" << endl;
	return B;
}
//*************************************TEL******************************************
Tel::Tel(){
	ID = 0;
	F = 0;
	B = 0;
	I = 0;
	r = 0;
	L = 0;
}

Tel::Tel(int id_, double f_, double b_, double i_, double r_, double l_){
	ID = id_;
	F = f_;
	B = b_;
	I = i_;
	r = r_;
	L = l_;
}

Tel::Tel(const Tel& t1){
	ID = t1.ID;
	F = t1.F;
	B = t1.B;
	I = t1.I;
	r = t1.r;
	L = t1.L;
}

Tel& Tel::operator=(const Tel& t1){
	ID = t1.ID;
	F = t1.F;
	B = t1.B;
	I = t1.I;
	r = t1.r;
	L = t1.L;
	
	return *this;
}
void Tel::set_t_ID(int id_){ID = id_;}
void Tel::set_t_F(double f_){F = f_;}
void Tel::set_t_B(double b_){B = b_;}
void Tel::set_t_I(double i_){I = i_;}
void Tel::set_t_r(double r_){r = r_;}
void Tel::set_t_L(double l_){L = l_;}
int Tel::get_t_ID(){return ID;}
double Tel::get_t_F(){return F;}
double Tel::get_t_B(){return B;}
double Tel::get_t_I(){return I;}
double Tel::get_t_r(){return r;}
double Tel::get_t_L(){return L;}

vector Tel::tele_etki_eden_kuvvet(){
	double x;
	vector Fv; // vector olarak manyetik kuvvet
	vector Lv; // vector olarak uzunluk
	vector Bv; // manyetik alan vektoru
	system("cls");
	cout << "Telden gecen akimi giriniz (A) = ";
	cin >> I;
	
	cout << "Manyetik alan i(x), j(y), k(z) bilesenlerini giriniz(Tesla)\n";
	cout << "i = ";
	cin >> x;
	Bv.setx(x);
	cout << "j = ";
	cin >> x;
	Bv.sety(x);
	cout << "k = ";
	cin >> x;
	Bv.setz(x);
	
	cout << "Uzunluk i(x), j(y), k(z) bilesenlerini giriniz(m)\n";
	cout << "i = ";
	cin >> x;
	Lv.setx(x);
	cout << "j = ";
	cin >> x;
	Lv.sety(x);
	cout << "k = ";
	cin >> x;
	Lv.setz(x);
	
	Fv = I * (Lv * Bv);
	
	cout << "------------------------------------" << endl;
	cout << "Tele etkiyen manyetik kuvvet = " << endl;
	cout << "X ekseninde " << Fv.getx() << " N" << endl;
	cout << "Y ekseninde " << Fv.gety() << " N" << endl;
	cout << "Z ekseninde " << Fv.getz() << " N" << endl;
	
	return Bv;
}

double Tel::t_manyetik_alan_bul(){
	system("cls");
	cout << "Telden gecen akimi giriniz (A) = ";
	cin >> I;
	cout << "Tel ve nokta arasindaki uzakligi giriniz = ";
	cin >> r;
	B = ((4 * M_PI) * pow(10,-7) * I) / ((2 * M_PI) * r);
	cout << "---------------------------------------" << endl;
	cout << "Telin belirtilen noktadaki manyetik alan siddeti = " << B << " Tesla" << endl;
	return B;
}

double Tel::paralel_tel_arasi_kuvvet(){
	system("cls");
	Tel t2;
	cout << "Ilk telin tasidigi akimi giriniz (A) = ";
	cin >> I;
	cout << "Tellerin paralel kisimlarinin uzunlugunu giriniz (m) = ";
	cin >> L;
	cout << "Teller arasi mesafeyi giriniz (m) = ";
	cin >> r;
	cout << "Ikinci telin tasidigi akimi giriniz (A) = ";
	cin >> t2.I;
	F = ((4 * M_PI * pow(10,-7)) * (I * t2.I) * L) / ((2 * M_PI) * r);
	cout << "----------------------------------------" << endl;
	cout << "Iki paralel tel arasi kuvvet = " << F << " N" << endl;
}
//*************************************SOLENOID******************************************
Solenoid::Solenoid(){
	N = 0;
	L = 0;
	I = 0;
}

Solenoid::Solenoid(int n_, double l_, double i_){
	N = n_;
	L = l_;
	I = i_;
}

Solenoid::Solenoid(const Solenoid& s1){
	N = s1.N;
	L = s1.L;
	I = s1.I;
}

Solenoid& Solenoid::operator=(const Solenoid& s1){
	N = s1.N;
	L = s1.L;
	I = s1.I;
	
	return *this;
}

Solenoid& Solenoid::operator+(const Solenoid& s1){
	N = N + s1.N;
	L = L + s1.L;
	I = I + s1.I;
	
	return *this;
}

ostream& operator<<(ostream& os, Solenoid& s1){
	os << "N = " << s1.get_N() << endl;
	os << "L = " << s1.get_L() << "m" <<endl;
	os << "I = " << s1.get_I() << "A" << endl;

}

void Solenoid::set_N(int n_){N = n_;}
void Solenoid::set_L(double l_){L = l_;}
void Solenoid::set_I(double i_){I = i_;}
int Solenoid::get_N(){return N;}
double Solenoid::get_L(){return L;}
double Solenoid::get_I(){return I;}

double Solenoid::solenoid_manyetik_alan(){
	system("cls");
	double B; //manyetik alan
	
	cout << "Solenoid tur sayisini giriniz = ";
	N = get_positive_int();
	
	cout << "Uzunluk giriniz(m) = ";
	cin >> L;
	
	cout << "Akimi giriniz(A) = ";
	cin >> I;
	
	
	B = ((4 * M_PI) * pow(10,-7)) * (N/L) * I;
	
	cout << "------------------------------------" << endl;
	cout << "Solenoid merkezindeki manyetik alan = " <<	B << "Tesla" << endl;
	
	return B;
}
