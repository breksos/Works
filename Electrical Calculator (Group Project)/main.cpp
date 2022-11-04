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
		
		cout<<"\t\t\t\t\tElektrik Ana Menüsüne Hoþgeldiniz\n\n\n\n"<<endl;
		cout<<"Devrelerle ilgili iþlemler için [1] giriniz"<<endl;
		cout<<"Yüklerle ve yüksistemleri ile ilgili iþlemler için[2] giriniz"<<endl;
		cout<<"Manyetizma ile ilgili iþlemler için [3] giriniz"<<endl;
		cout<<"Programdan çýkmak için [4] giriniz"<<endl;
		
		cout<<"Seçiminiz: ";
		cin>>x;
		
		switch(x){
			
			case 1:
				int d;
				system("cls");
				cout<<"Alternatif Akým devresi oluþturmak için [1] giriniz"<<endl;
				cout<<"Doðru Akým devresi oluþturmak için [2] giriniz"<<endl;
				cout<<"Seçiminiz: ";
				cin>>d;
				
				if(d==1){
					double t;
					Devre_Ac D;
					cin>>D;
					cout<<"Devam etmek için ENTER basýnýz";
					getch();
					system("cls");
					cout<<D;
				    t = D.moment_psu();
				    cout<<"Anlýk voltaj deðeri: "<<t<<endl;
				    t = D.calc_sinusoidal_curr();
				    cout<<"Anlýk sinuzodial akým: "<<t<<endl;
				    t = D.rms_curr();
				    cout<<"Rms akým deðeri: "<<t<<endl;
				    t = D.rms_volt();
				    cout<<"Rms voltaj deðeri: "<<t<<endl;
				    t = D.mom_volt_cross_res();
				    cout<<"Direnç üstünden geçen voltaj: "<<t<<endl;
				    t = D.mom_volt_cross_con();
				    cout<<"Kondansatör üzerinden geçen voltaj: "<<t<<endl;
				    t = D.mom_volt_cross_coil();
				    cout<<"Bobin üzerinden geçen voltaj: "<<t<<endl;
				    t = D.mom_charge_con();
				    cout<<"Anlýk kondansatör yükü: "<<t<<endl;
				    t = D.inductif_reactans();
				    cout<<"Sistemin indüktif reaktans deðeri: "<<t<<endl;
				    t = D.calc_Vmax_res();
				    cout<<"Direnç üstündeki max voltaj: "<<t<<endl;
				    t = D.calc_Vmax_coil();
				    cout<<"Bobin üstündeki max voltaj: "<<t<<endl;
				    t = D.calc_Vmax_con();
				    cout<<"Kondansatör üzerindeki max voltaj: "<<t<<endl;
				    t = D.calc_emp();
				    cout<<"Sistemin Empedans deðeri: "<<t<<endl;
				    t = D.calc_pow();
				    cout<<"Sistemin gücü: "<<t<<endl;
				    getch();
				    system("cls");
				}
				if(d==2){
					double s;
					Devre_Dc DC;
					cin>>DC;
					cout<<"Devam etmek için ENTER basýnýz";
					getch();
					system("cls");
					cout<<DC;
					s = DC.calc_curr();
					cout<<"Devrenin akým deðeri: "<<s<<endl;
					s = DC.calc_power();
					cout<<"Devrenin gücü: "<<s<<endl;
					DC.calc_bill();
				    s = DC.charg_cond();
				    cout<<"Kondansatörün verilen zamanda yüklenme oraný: "<<s<<endl;
				    s = DC.decharg_cond();
				    cout<<"Kondansatörün boþalma sýrasýnda yükü: "<<s<<endl;
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
				 cout<<"Parçacýk sistemi oluþturmak için [1] giriniz"<<endl;
				 cout<<"Makara sistemi oluþturmak için [2] giriniz"<<endl;
				 cout<<"Tel sistemi oluþturmak için [3] giriniz"<<endl;
				 cout<<"Solenoid oluþturmak için [4] giriniz"<<endl;
				 cout<<"Seçiminiz: ";
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
				 	cout << "Devam etmek için herhangi bir tuþa basýnýz.";
				 	getch();
				 	t.t_manyetik_alan_bul();
				 	cout << "Devam etmek için herhangi bir tuþa basýnýz.";
				 	getch();
				 	t.paralel_tel_arasi_kuvvet();
				 	cout << "Devam etmek için herhangi bir tuþa basýnýz.";
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
