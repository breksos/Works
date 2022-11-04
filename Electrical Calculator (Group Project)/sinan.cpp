#include <iostream>
#include <cmath>
#include "sinan.h"
#include <conio.h>

using namespace std;

double kok(double q){
	return pow(q,0.5);
}


// a double degerini kullanicidan alir error tespiti ile eger string girilirse gereken duzeltmeleri yapar
// kullaniciyi uyarir double degeri alir
void perfect_get_double(double& a,istream &in){
	for(bool flag = true;flag;){
		in >> a;
		try{
			if(in.fail()){
				throw 1;
			}
			else{
				flag = false;
			}
			
		}
		catch(int q){
			if(q == 1){
				cout << "it seems like you put a string instead of double try again" << endl;
				in.clear();
				in.ignore(1000,'\n');
			}
		}
	}
}

// a ve b arasinda double deger alir kullanicidan
// eger string girilirse kullaniciyi uyarir hatalari tespit edip cozer
double take_double(double a,double b){
	//omersinanozer 1901022056 28.05.2021 20:07
	double c;
	tekrar:
	cout << "Put a double in between " << a << " and " << b << endl;
	cin >> c;
	bool flag = false;
	if(c >= a && c <= b){
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

double take_int(int l,int u){
	//omersinanozer 1901022056 28.05.2021 20:25
	//bu fonksiyonu cok karsilastigim bir problemi cozmek icin yazdim
	// bundan onceki projelerde kullanicidan int istedigim zaman kullanici string girdigi zaman 
	// sorun yasiyordum. Bunu asmak icin boyle bi fonksiyon yazdim.
	double x;
	again:
	cout << "Put an integer in between " << l << " and " << u << endl;
	cin >> x;
	x = (int)x;
	bool flag = false;
	for(int i = l;i <= u ;i++){
		if(x == i){
			flag = true;
			break;
		}
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
			goto again;
		}
		if(q == 2){
			goto again;
		}
	}
			
	return x;
}





vector::vector(){
	x = 0;
	y = 0;
	z = 0;
}
vector::vector(double xx,double yy,double zz){
	x = xx;
	y = yy;
	z = zz;
}
vector::vector(const vector &v){
	x = v.x;
	y = v.y;
	z = v.z;
}
vector& vector::operator=(const vector& v){
	if(&v != this){
		x = v.x;
		y = v.y;
		z = v.z;
	}
	return *this;
}


vector vector::operator+(const vector& v){
	vector temp(x+v.getx(),y+v.gety(),z+v.getz());
	return temp;
}
vector vector::operator-(const vector& v){
	vector temp(x-v.getx(),y-v.gety(),z-v.getz());
	return temp;
}
// vector product
vector vector::operator*(const vector& v){
	double i,j,k;
	i = y*v.getz() - z*v.gety();
	j = z*v.getx() - x*v.getz();
	k = x*v.gety() - y*v.getx();
	vector temp(i,j,k);
	return temp;
}

double vector::magnitude(){
	double a = x*x+y*y+z*z;
	a = kok(a);
	return a;
}

ostream& operator<<(ostream& o,const vector& v){
	o << "Vector info:" << endl;
	o << "X:" << v.x << endl;
	o << "Y:" << v.y << endl;
	o << "Z:" << v.z << endl;
	return o;
}
istream& operator>>(istream& in,vector& v){
	double xx,yy,zz;
	cout << "Write x,y,z values of vector" << endl;
	perfect_get_double(xx,in);
	perfect_get_double(yy,in);
	perfect_get_double(zz,in);
	//cout << "test" << xx << yy << zz << endl;
	v.setx(xx);
	v.sety(yy);
	v.setz(zz);
	return in;
}


charge::charge(){
	x = 0;
	y = 0;
	charge_ = 0;
}
charge::charge(double xx,double yy,double ch){
	x = xx;
	y = yy;
	charge_ = ch;
}		
charge::charge(const charge& c){
	x = c.x;
	y = c.y;
	charge_ = c.charge_;
}
charge& charge::operator=(const charge& c){
	if(&c != this){
		x = c.x;
		y = c.y;
		charge_ = c.charge_;
	}
	return *this;
}


double charge::range(charge &c){
	double a = (x-c.x)*(x-c.x)+(y-c.y)*(y-c.y);
	a = kok(a); 
	return a;
}

//scalar vector carpimi
vector operator*(double coeff,const vector& v2){
	vector temp(coeff*v2.getx(),coeff*v2.gety(),coeff*v2.getz());
	return temp;
}
vector operator*(const vector& v2,double coeff){
	vector temp(coeff*v2.getx(),coeff*v2.gety(),coeff*v2.getz());
	return temp;
}
// tek bir yukun bir noktada olusturdugu elektrik alan vektorunu dondurur.
vector charge::SingleChargeField(double xx,double yy){
		vector temp(xx-x,yy-y,0);
		charge dum(xx,yy,0); // charge sinifinin mesafe metodunu kullanmak icin olusturuldu.
		double coef = K*charge_/(this->range(dum) * this->range(dum) * this->range(dum));
		temp = coef*temp;
		return temp;
}


ostream& operator<<(ostream& out,const charge& c){
	out << "Charge info:" << endl;
	out << "cordinate x:" << c.x << endl;
	out << "cordinate y:" << c.y << endl;
	out << "charge:"<<c.charge_<< "C" << endl;
	return out;
}

istream& operator>>(istream& in,charge& c){
	double xx,yy,cc;
	cout << "write x and y cordinates of charge" << endl;
	perfect_get_double(xx,in);
	perfect_get_double(yy,in);
	cout << "write Charge of charge in unit of coulomb" << endl;
	perfect_get_double(cc,in);
	c.setx(xx);
	c.sety(yy);
	c.setc(cc);
	return in;
}

// iki nokta arasindaki potansiyel farki return eder
double potential_twocharge(charge& a,charge &b){
	double pot = (K*a.getc()*b.getc())/(a.range(b));
	return pot;
}


ChargeSystem::ChargeSystem(){ 
	size = 0;
	root = NULL;
	total_energy = 0;
}
ChargeSystem::ChargeSystem(int sizee,charge* hold){
	size = sizee;
	root = new charge[size];
	for(int i = 0;i<size;i++){
		root[i] = hold[i];
	}
	this->calculate_total_system_energy();
}
ChargeSystem::ChargeSystem(int sizee,double R,double CC){
	size = sizee;
	root = new charge[size];
	for(int i=0;i<size;i++){
		root[i].setc(CC);
		root[i].setx(R*cos(2*i*PI/size));
		root[i].sety(R*sin(2*i*PI/size));
		//cout << "("<<R*cos(2*i*PI/size) << "," << R*sin(2*i*PI/size) << "),";

	}
	cout << endl;
}
ChargeSystem::ChargeSystem(const ChargeSystem& ch){
	size = ch.size;
	root = new charge[size];
	for(int i = 0;i<size;i++){
		root[i] = ch.root[i];
	}
	total_energy = ch.total_energy;
}
ChargeSystem& ChargeSystem::operator=(const ChargeSystem& ch){
	if(this != &ch){
		size = ch.size;
		delete [] root;
		root = new charge[ch.size];
		for(int i = 0;i<size;i++){
			root[i] = ch.root[i];
		}
		total_energy = ch.total_energy;
	}
	return *this;
}
ChargeSystem::~ChargeSystem(){
	if(size = 1){
		delete root;
	}
	if(size > 1){
		delete [] root;
	}
	size = 0;
}	


charge& ChargeSystem::operator[](int x){
	return root[x];
}

// test fonksiyonlari charge sisteme ait nokta konum bilgilerini bastiran fonksiyonlar
void ChargeSystem::print(){
	for(int i = 0;i<size;i++){
		cout << i+1 << "."<< root[i] << endl;
	}
}	
void ChargeSystem::prinnt(){
	for(int i = 0;i<size;i++){
		cout << "(" << root[i].getx() << "," << root[i].gety() << ")" << endl;
	}
}	



double ChargeSystem::calculate_total_system_energy(){
	int i,j;
	total_energy = 0;
	for(i = 0;i<size-1;i++){
		for(j=i+1;j<size;j++){
			total_energy += potential_twocharge(root[i],root[j]);
		}
	}
	return total_energy;
}
double ChargeSystem::potentialofdot(double xx,double yy){
	charge a(xx,yy,0);
	double potential = 0;
	for(int i = 0;i<size;i++){
		potential += (K*root[i].getc())/(a.range(root[i]));
	}
	return potential;
}

vector ChargeSystem::TotalFieldindotof(double xx,double yy){
	vector temp;
	double x = 0,y = 0;
	for(int i = 0;i<this->size;i++){
		temp = temp + root[i].SingleChargeField(xx,yy);
		//cout << root[i].SingleChargeField(xx,yy);
		//cout << root[i].SingleChargeField(xx,yy).magnitude() << endl << endl;
		x += root[i].SingleChargeField(xx,yy).getx();
		y += root[i].SingleChargeField(xx,yy).gety();
		//cout << x << " " << y << endl;
	}
	return temp;
}

 void yuksistemi(){
 	cout << "Bu kisimda iki boyutlu uzayda istediginiz forma gore yukler olusturulacaktir" << endl;
 	cout << "Ve olusuturlan yuk sisteminin potansiyel enerjisi," << endl;
 	cout << "yuk sisteminin iki boyutlu uzayda bir noktadaki elektrik alan vektoru" << endl;
 	cout << "yuk sisteminin iki boyutlu uzayda bir noktadaki elektriksel potansiyeli" << endl;
 	cout << "hesaplanabilecektir." << endl << endl << endl;
 	int i;
 	while(true){
 		cout << "Eger N tane yuku istediginiz formda yerlestirmek icin 1" << endl;
 		cout << "Eger N tane yuku DuzgunNgen formasyonunda yerlestirmek icin 2" << endl;
 		cout << "Cikmak icin 3 giriniz" << endl;
 		i = take_int(1,3);
 		if(i == 1){
 			system("cls");
 			cout << "Yuk sisteminde kac tane yuk bulunacaktir ?" << endl;
 			cout << "1 ila 100 arasinda yuk olusturabilirsiniz" << endl;
 			int miktar = take_int(1,100);
 			charge dizi[miktar];
 			cout << "Simdi istediginiz sayida yukun bilgilerini giriniz" << endl;
 			cout << "Eger kucuk bir alanda islem yapilacaksa yuklerin kucuk secilmesi cok onemli" << endl;
 			for(int k = 0;k<miktar;k++){
 				cin >> dizi[k];
			}
 			ChargeSystem sistem(miktar,dizi);
 			while(true){
 				int ii;
 				system("cls");
				cout << "Bu sistemin bir noktada olusturdugu elektrik alan vektorunu bulmak icin 1" << endl;
				cout << "Bu sistemin bir noktada olusturdugu elektrik potansiyelini  bulmak icin 2"	<< endl;
				cout << "Sistemin toplam enerjisini gostermek icin 3" << endl;
				cout << "onceki menuye donmek icin 4 giriniz" << endl;
				ii = take_int(1,4);
				if(ii == 1){
					cout << "Elektrik alan:Noktanin x ve y kordinatlarini giriniz" << endl;
					double xx = take_double(-100000,100000);
					double yy = take_double(-100000,100000);
					cout << sistem.TotalFieldindotof(xx,yy) << "Birimler V/m" << endl;
					getch();
				}
				if(ii == 2){
					cout << "potansiyel:Noktanin x ve y kordinatlarini giriniz" << endl;
					double xx = take_double(-100000,100000);
					double yy = take_double(-100000,100000);
					cout << sistem.potentialofdot(xx,yy) << "V" << endl;
					getch();
				}
				if(ii == 3){
					cout << "toplam enerji:" << sistem.calculate_total_system_energy() <<" joule"<< endl; 
					getch();
				}
				if(ii == 4){
					break;
				}
			}
		}
		if(i == 2){
			system("cls");
			cout << "Sirasiyla istediginiz yuk sayisini x\n yuklerin 0,0 noktasindan uzakligini L\n yuklerin yukunu(coulomb) giriniz" << endl;
			cout << "X=5,L=10,Yük = 1C yazarsaniz" << endl;
			cout << "herbirinin yükü 1C olan ve 0,0 uzakligi 10m olan 5 tane yuk duzgun besgen formunda diziir"  << endl;
			int yuksayisi = take_int(1,150);
			double uzaklik = take_double(0,100000);
			double yukcoul = take_double(0,10);
			ChargeSystem sistem(yuksayisi,uzaklik,yukcoul);
			int ii;
			system("cls");
			cout << "Istediginiz formda yuk sistemi olustuldu" << endl;
			while(true){
 				int ii;
				cout << "Bu sistemin bir noktada olusturdugu elektrik alan vektorunu bulmak icin 1" << endl;
				cout << "Bu sistemin bir noktada olusturdugu elektrik potansiyelini  bulmak icin 2"	<< endl;
				cout << "Sistemin toplam enerjisini gostermek icin 3" << endl;
				cout << "onceki menuye donmek icin 4 giriniz" << endl;
				ii = take_int(1,4);
				if(ii == 1){
					system("cls");
					cout << "Elektrik alan:Noktanin x ve y kordinatlarini giriniz" << endl;
					double xx = take_double(-100000,100000);
					double yy = take_double(-100000,100000);
					cout << sistem.TotalFieldindotof(xx,yy) << "Birimler V/m" << endl;
					getch();
				}
				if(ii == 2){
					system("cls");
					cout << "potansiyel:Noktanin x ve y kordinatlarini giriniz" << endl;
					double xx = take_double(-100000,100000);
					double yy = take_double(-100000,100000);
					cout << sistem.potentialofdot(xx,yy) << "V" << endl;
					getch();
				}
				if(ii == 3){
					system("cls");
					cout << "toplam enerji:" << sistem.calculate_total_system_energy() <<" joule"<< endl; 
					getch();
				}
				if(ii == 4){
					break;
				}
			}
			
			
		}
		if(i == 3){
			break;
		}
	 }
 	
 	
 	
 	
 }



