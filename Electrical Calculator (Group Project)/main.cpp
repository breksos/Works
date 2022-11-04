#include <iostream>
#include <cmath>
#include <clocale>
#include <conio.h>
#include "manyetizma.h"
#include "sinan.h"
#include "Devre.h"

using namespace std;

int main(){
	setlocale(LC_ALL,"Turkish");
	int x = 0;
	while(1){
		
		cout<<"\t\t\t\t\tElektrik Ana Men�s�ne Ho�geldiniz\n\n\n\n"<<endl;
		cout<<"Devrelerle ilgili i�lemler i�in [1] giriniz"<<endl;
		cout<<"Y�klerle ve y�ksistemleri ile ilgili i�lemler i�in[2] giriniz"<<endl;
		cout<<"Manyetizma ile ilgili i�lemler i�in [3] giriniz"<<endl;
		cout<<"Programdan ��kmak i�in [4] giriniz"<<endl;
		
		cout<<"Se�iminiz: ";
		cin>>x;
		
		switch(x){
			
			case 1:
				int d;
				system("cls");
				cout<<"Alternatif Ak�m devresi olu�turmak i�in [1] giriniz"<<endl;
				cout<<"Do�ru Ak�m devresi olu�turmak i�in [2] giriniz"<<endl;
				cout<<"Se�iminiz: ";
				cin>>d;
				
				if(d==1){
					double t;
					Devre_Ac D;
					cin>>D;
					cout<<"Devam etmek i�in ENTER bas�n�z";
					getch();
					system("cls");
					cout<<D;
				    t = D.moment_psu();
				    cout<<"Anl�k voltaj de�eri: "<<t<<endl;
				    t = D.calc_sinusoidal_curr();
				    cout<<"Anl�k sinuzodial ak�m: "<<t<<endl;
				    t = D.rms_curr();
				    cout<<"Rms ak�m de�eri: "<<t<<endl;
				    t = D.rms_volt();
				    cout<<"Rms voltaj de�eri: "<<t<<endl;
				    t = D.mom_volt_cross_res();
				    cout<<"Diren� �st�nden ge�en voltaj: "<<t<<endl;
				    t = D.mom_volt_cross_con();
				    cout<<"Kondansat�r �zerinden ge�en voltaj: "<<t<<endl;
				    t = D.mom_volt_cross_coil();
				    cout<<"Bobin �zerinden ge�en voltaj: "<<t<<endl;
				    t = D.mom_charge_con();
				    cout<<"Anl�k kondansat�r y�k�: "<<t<<endl;
				    t = D.inductif_reactans();
				    cout<<"Sistemin ind�ktif reaktans de�eri: "<<t<<endl;
				    t = D.calc_Vmax_res();
				    cout<<"Diren� �st�ndeki max voltaj: "<<t<<endl;
				    t = D.calc_Vmax_coil();
				    cout<<"Bobin �st�ndeki max voltaj: "<<t<<endl;
				    t = D.calc_Vmax_con();
				    cout<<"Kondansat�r �zerindeki max voltaj: "<<t<<endl;
				    t = D.calc_emp();
				    cout<<"Sistemin Empedans de�eri: "<<t<<endl;
				    t = D.calc_pow();
				    cout<<"Sistemin g�c�: "<<t<<endl;
				    getch();
				    system("cls");
				}
				if(d==2){
					double s;
					Devre_Dc DC;
					cin>>DC;
					cout<<"Devam etmek i�in ENTER bas�n�z";
					getch();
					system("cls");
					cout<<DC;
					s = DC.calc_curr();
					cout<<"Devrenin ak�m de�eri: "<<s<<endl;
					s = DC.calc_power();
					cout<<"Devrenin g�c�: "<<s<<endl;
					DC.calc_bill();
				    s = DC.charg_cond();
				    cout<<"Kondansat�r�n verilen zamanda y�klenme oran�: "<<s<<endl;
				    s = DC.decharg_cond();
				    cout<<"Kondansat�r�n bo�alma s�ras�nda y�k�: "<<s<<endl;
				    getch();
				    system("cls");
				}
		 break;
		 
		 
		 case 2:
		    	system("cls");
				yuksistemi();
				getch();
				system("cls");
				break;
		    	
		 case 3:
		         int l;
		         system("cls");
				 cout<<"Par�ac�k sistemi olu�turmak i�in [1] giriniz"<<endl;
				 cout<<"Makara sistemi olu�turmak i�in [2] giriniz"<<endl;
				 cout<<"Tel sistemi olu�turmak i�in [3] giriniz"<<endl;
				 cout<<"Solenoid olu�turmak i�in [4] giriniz"<<endl;
				 cout<<"Se�iminiz: ";
				 cin>>l;
				 if(l==1){
				 	Parcacik p;
				 	p.yuke_etki_eden_mkuvvet();
				 	getch();
				 	system("cls");
				 }
				 if(l==2){
				 	Makara m;
				 	m.m_manyetik_alan_bul();
				 	getch();
				 	system("cls");
				 }  	
				 if(l==3){
				 	Tel t;
				 	t.tele_etki_eden_kuvvet();
				 	cout << "Devam etmek i�in herhangi bir tu�a bas�n�z.";
				 	getch();
				 	t.t_manyetik_alan_bul();
				 	cout << "Devam etmek i�in herhangi bir tu�a bas�n�z.";
				 	getch();
				 	t.paralel_tel_arasi_kuvvet();
				 	cout << "Devam etmek i�in herhangi bir tu�a bas�n�z.";
				 	getch();
				 	system("cls");
				 }
				 if(l==4){
				 	Solenoid sl;
				 	sl.solenoid_manyetik_alan();
				 	getch();
				 	system("cls");
				 }
				 break;
		  case 4:
		  return 0;	
		  
		  default:
		  cout<<"wrong entry press enter and try again!!";
		  getch();
		  system("cls");	 
		}
	}
}
