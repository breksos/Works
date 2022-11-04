#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <conio.h>
using namespace std;

class Eczane{            //eczane class to create pharmacy objects//
private:
		int ID;
		char isim[100];
		char adres[100];
	
public:
       Eczane(){
       	ID = 0;
       	strcpy(isim,"yok");
       	strcpy(adres,"yok");
	   }	
	
	
		void set_ID(int id){                              //constructors and member functions//
				ID = id;
			}
			void set_name(char name[100]){
			strcpy(isim,name);
			}
			void set_adres(char loc[100]){
			strcpy(adres,loc);
			}
			int get_ID(){
				return ID;
			}
			char* get_name(){
				return isim;
			}
			char* get_adres(){
				return adres;
			}
			void newpharma(){
				int id;
				char name[100],loc[100],ilac[100];
				cout<<"id: ";
				cin>>id;
				set_ID(id);
				fflush(stdin);
				cout<<"name: ";
			    cin>>name;
			    strcpy(ilac,name);
			    strcat(ilac,"_ilac.dat");
			    fstream new_file; 
			
                new_file.open(ilac,ios::out);  
                if(!new_file) 
                {
                cout<<"Pharmacy medicine file creation failed\n";
                }
                else
                {
                cout<<"Pharmacy medicine file created\n";
                new_file.close(); 
                }
				set_name(name);
				cout<<"location: ";
	        	cin>>loc;
	        	set_adres(loc);
			}
			void printdata(){
				cout<<"Pharmacy ID: "<<ID<<"\nPharmacy Name: "<<isim<<"\nPharmacy Adres: "<<adres<<endl;
			}
			friend fstream& operator << (fstream& os,const Eczane& obj);

	};
	fstream& operator << (fstream& os,const Eczane& obj){                   //opertor overloading to write object into file//
				os.write((char*)&obj,sizeof(obj));
				os.flush();
				return os;
		}
			void eczn_listesi_olustur(){              //function to create new pharmacy list//
			fstream new_file; 
			
            new_file.open("eczane_list.dat",ios::out);  
            if(!new_file) 
            {
             cout<<"File creation failed\n";
            }
             else
           {
            cout<<"New file created\n";
            new_file.close(); 
            getch();
            system("cls");
           }
           }
           
           
           class Ilac{          //Ilac class to create medicine objects//
	private:
		int ID;
		int miktar;
		double fiyat;
		char isim[100];
		
	public: 
	        Ilac(){                   //constructors and member functions//
	        	ID = 0;
	        	miktar = 0;
	        	fiyat = 0.0;
	        	strcpy(isim,"yok");
			}
			Ilac(int id,int adet,double price,char ad[100]){
				ID = id;
				miktar = adet;
				fiyat = price;
				strcpy(isim,ad);
			}
			Ilac(const Ilac& other){
				ID = other.ID;
				miktar = other.miktar;
				fiyat = other.fiyat;
				strcpy(isim,other.isim);
			}
			Ilac& operator=(const Ilac& other){
				ID = other.ID;
				miktar = other.miktar;
				fiyat = other.fiyat;
				strcpy(isim,other.isim);
				return *this;
			}
			void set_ID(int id){
				ID = id;
			}
			void set_name(char name[100]){
				strcpy(isim,name);
			}
			void set_fiyat(double price){
				fiyat = price;
			}
			void set_miktar(int adet){
				miktar = adet;
			}	
			
			int get_ID(){
				return ID;
			}
			char* get_name(){
				return isim;
			}
			double get_fiyat(){
				return fiyat;
		    }
		    int get_miktar(){
		    	return miktar;
			}
		    void newmed(){            //function to create new medicine object//
				int id,adet;
				double fiyat;
				char name[100];
				cout<<"id: ";
				cin>>id;
				set_ID(id);
				fflush(stdin);
				cout<<"name: ";
			    cin>>name;
				set_name(name);
				cout<<"miktar: ";
	        	cin>>adet;
	        	set_miktar(adet);
	        	cout<<"fiyat: ";
	        	cin>>fiyat;
	        	set_fiyat(fiyat);
			}
			friend fstream& operator << (fstream& os,const Ilac& obj);
			void printdata(){
				cout<<"ID: "<<ID<<"\nName: "<<isim<<"\nAmount: "<<miktar<<"\nPrice: "<<fiyat<<endl;
			}
		
};
fstream& operator << (fstream& os,const Ilac& obj){      //overloaded operator to write medicine object into file//
				os.write((char*)&obj,sizeof(obj));
				os.flush();
				return os;
		}
 
void ilac_edit(){                          //function to edit medicine information in a spesific file//
	char name[100],edit[100];
				double newfiyat=0.0;
				int adet=0,id=0;
				cout<<"Please enter the pharmacy medicine list to edit medicine: ";
				cin>>name;
				fstream file;
				strcat(name,"_ilac.dat");
				file.open(name,ios::binary|ios::in);
				Ilac a;
				file.seekg(0,ios_base::beg);
				file.seekp(0,ios_base::beg);
				cout<<"Enter medicine id to edit: ";
				cin>>id;
				fstream file2;
				file2.open("copy.dat",ios::app|ios::binary|ios::in);
				file2.seekp(0,ios_base::beg);
				file2.seekg(0,ios_base::beg);
				while(file.read((char*)&a,sizeof(a))!=NULL){
					if(id==a.get_ID()){
						cout<<"Enter the new name: ";
						cin>>edit;
						cout<<"\nEnter the new price: ";
						cin>>newfiyat;
						cout<<"\nEnter the new amount: ";
						cin>>adet;
						a.set_name(edit);
						a.set_fiyat(newfiyat);
						a.set_miktar(adet);
					}
					file2 << a;
				}
				file.close();
				remove(name);
				file2.close();
				rename("copy.dat",name);
				getch();
            system("cls");
}
void ilac_ara(){                  //function to search for a spesific medicine in every exsiting pharmacy file//
	char temp[100],aranan[100];
				int id = 0,adet = 0;
				double price = 0.0;
				cout<<"Please enter the medicine name you are looking for: ";
				cin>>aranan;
				fstream file;
				fstream file2;
				Ilac a;
				Eczane e;
				file.open("eczane_list.dat",ios::binary|ios::in);
				file.seekg(0,ios_base::beg);
				file.seekp(0,ios_base::beg);
				while(file.read((char*)&e,sizeof(e))!=NULL){
			    strcpy(temp,e.get_name());
			    strcat(temp,"_ilac.dat");
			    file2.open(temp,ios::binary|ios::in);
			    file2.seekp(0,ios_base::beg);
			    file2.seekg(0,ios_base::beg);
			    while(file2.read((char*)&a,sizeof(a))!=NULL){
			    	if(strcmp(aranan,a.get_name())==0){
			    		e.printdata();cout<<"\n";
					}
				}
				file2.close();
				}
				file.close();
				getch();
            system("cls");
}
void ecznleri_goster(){           //function to display every pharmacy we have so far//
	fstream file;
            file.open("eczane_list.dat",ios::app|ios::binary|ios::in);
            Eczane e;
            file.seekp(0,ios_base::beg);
            file.seekg(0,ios_base::beg);
            fflush(stdin);
            cout<<"Liste: \n";
            while(file.read((char*)&e,sizeof(e)) != NULL){e.printdata();cout<<"\n";}
            file.close();
            getch();
            system("cls");
}
void eczn_goster(){                //fuýnction to display a spesific pharmacy//
			char search[100],adres[100];
            int id=0;
		    fstream file;
		    file.open("eczane_list.dat",ios::app|ios::binary|ios::in);
		    Eczane e;
		    cin>>search;
		    file.seekg(0,ios_base::beg);
		    file.seekp(0,ios_base::beg);
		    fflush(stdin);
		    while(file.read((char*)&e,sizeof(e)) != NULL){
		    if(strcmp(search,e.get_name())==0){
		    	id=e.get_ID();
		    	strcpy(adres,e.get_adres());
			cout<<"ID: "<<id<<"\n"<<"Name: "<<search<<"\n"<<"Adres: "<<adres<<endl;
			}
			}
			file.close();
			getch();
            system("cls");
}
void ilac_listesi_goster(){            //function to display a spesific pharmacies medicine file//
	char isim[100],ilac[100];
			fstream file;
			cout<<"Please enter the Pharmacy name to see the list: ";
			cin>>isim;
			strcat(isim,"_ilac.dat");
			strcpy(ilac,isim);
            file.open(ilac,ios::app|ios::binary|ios::in);
            Ilac a;
            file.seekp(0,ios_base::beg);
            file.seekg(0,ios_base::beg);
            fflush(stdin);
            cout<<"List:\n";
            while(file.read((char*)&a,sizeof(a)) != NULL){a.printdata();cout<<"\n";}
            file.close();
            getch();
            system("cls");
}
void eczn_ekle(){                  //function to add new pharmacies to our main pharmacy list//
	fstream file;
            file.open("eczane_list.dat",ios::app|ios::binary|ios::in);
            Eczane e;

            e.newpharma();
            file << e;

            file.seekp(0,ios_base::beg);
            file.seekg(0,ios_base::beg);
            fflush(stdin);
            file.close();
            cout<<"List has been updated!!\n";
            getch();
            system("cls");
}
void ilac_ekle(){                 //function to add medicine to a pharmacies medicine list file//
		char name[100];
				cout<<"Please enter the pharmacy name you want to add new medicine: ";
				cin>>name;
				strcat(name,"_ilac.dat");
				fstream file;
            file.open(name,ios::app|ios::binary|ios::in);
            Ilac a;
            a.newmed();
            ;
            file << a;

            file.seekp(0,ios_base::beg);
            file.seekg(0,ios_base::beg);
            fflush(stdin);
		    file.close();
           
            cout<<"New medicine has been added to the list!!\n";
            getch();
            system("cls");
}
	
int main(){
 
int x,pass1,a=0;
static int pass = 14;                   //our poassword defined static so it wont be changed//
while(1){
	cout<<"To Enter the Pharmacist menu enter [1]\n";    //our main menu//
	cout<<"To Enter the Customer menu enter [2]\n";
	cout<<"To exit the app please enter [0]\n";
	cout<<"Your choice: ";
	cin>>x;
	
	switch(x){                    
		
		case 1:                            //pharmacist entry requires a password entry//
			cout<<"Enter the password to access this menu\n";
			cout<<"Password: ";
			cin>>pass1;
			if(pass1!=pass){
				cout<<"Wrong entry closing system!";
				return 0;
			}
			system("cls");
			cout<<"Please enter 1 to create a pharmacy list if you havent\n";
			cout<<"Please enter 2 to enter new pharmacy information\n";
			cout<<"Please enter 3 to enter new medicine information\n";
			cout<<"Please enter 4 to edit medicine information\n";
			cin>>a;
			
			if(a==1){                         //calling in functions for pharmacist screen//
			eczn_listesi_olustur();
			}
			
			if(a==2){
			system("cls");
            eczn_ekle();
			}
			if(a==3){
			system("cls");	
			ilac_ekle();
			}
			if(a==4){
			system("cls");	
			ilac_edit();
			}
			break;
		case 2:
			int y;
			system("cls");                     //customer main menu//
			cout<<"To search a medicine Please enter 1";
			cout<<"\nTo see the pharmacy list enter 2";
			cout<<"\nTo see a pharmacies information enter 3";
			cout<<"\nTo see the medicine list of a pharmacy enter 4\n";
			cin>>y;
			if(y==1){                             //calling in functions for customers to use//
			system("cls");                                              
			ilac_ara();
			}
			
			if(y==2){
			system("cls");
	        ecznleri_goster();
			}
			
			if(y==3){
			system("cls");
              eczn_goster();
			}
			
			if(y==4){
			system("cls");
			ilac_listesi_goster();
			}
			break;
			
		case 0:
		cout<<"\nThanks for using our program :)";
		getch();
		return 0;
		break;	
		
		default:
		cout<<"Wrong entry try again";
		getch();
		system("cls");
	    break;
	    
	}
	
}
	return 0;
}

