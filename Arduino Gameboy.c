#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

HANDLE serial_th;

int main(){

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

    DWORD oylesine;
    BOOL baglantidurumu;
    BOOL olasihata=1;
    char serial_port[] = "\\\\.\\COM6";                         // ACILACAK PORT ISMI, GEREKLI GORULURSE DEGISTIRILEBILIR.
    int st;
    char numb[20], select[20];                          // ARDUINOYA INTEGER HALLINDE SAYI GONDEREMEDIGIMIZ ICIN STRINGLER HALINDE GONDERECEGIZ.

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
 
    baglantidurumu = FALSE;             // BAGLANTI KURULANA KADAR FALSE HALINDE KALACAK.
    serial_th=CreateFile(serial_port,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,0);    // serial_th adinda bir dosyayi girilen port uzerinden aciyoruz.

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

    if(serial_th==INVALID_HANDLE_VALUE)
    {
        if(GetLastError()==ERROR_ALREADY_EXISTS){                                   // VERILEN PORTTA DOSYA ACAMAMASI DURUMUNDA OLUSABILECEK HATALAR.
            printf("Dosya zaten mevcut, tekrar deneyin...\n");
        }
        else if(GetLastError()==ERROR_FILE_NOT_FOUND){
            printf("Port yonetimi basarisiz... %s portu mevcut degil.\n", serial_port);
        }
        else{
            printf("Bilinmeyen hata, tekrar deneyin...\n");
        }
    }

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

    else{
        DCB dcbSerialParams = {0};

        if (!GetCommState(serial_th, &dcbSerialParams))   // PARAMETRELERIN ALINABILIRLIGINI KONTROL EDILIYOR.
        {
            printf("mevcut parametreler alinamadi, lütfen tekrar deneyin!..");
        }

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

        else
        {
            dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;
            dcbSerialParams.StopBits=ONESTOPBIT;  
            dcbSerialParams.Parity=NOPARITY;                         // PARAMETRELER AYARLANIYOR.
            dcbSerialParams.BaudRate=CBR_9600;
            dcbSerialParams.ByteSize=8;

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

            if(!SetCommState(serial_th, &dcbSerialParams)){
                printf("SERİ PORT PARAMETRELERİ KURULAMADI, LÜTFEN TEKRAR DENEYİN!..\n");
            }
            else{
                baglantidurumu = TRUE;
                PurgeComm(serial_th, PURGE_RXCLEAR | PURGE_TXCLEAR);                    //  BAGLANTI BASARILI!
                printf("baglanti basariyla kuruldu... devam ediliyor.\n");
                Sleep(2000);
            }
        }
    }

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

    if(baglantidurumu==TRUE){                   // BAGLANTI KURULDUYSA PROGRAM USER-INTERFACE'E IZIN VERIYOR.
        LOOP:do{        

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/            
            getch();
            system("cls");
            printf("## WELCOME TO GTU GROUP 18'S ARDUINO    ##\n");
    	    printf("## STUDENT NAME: MEHMET HAYRULLAH OZKUL ##\n");
    	    printf("## STUDENT NAME: BERK HAKAN OGE         ##\n");
    	    printf("## STUDENT NAME: TAYYIP SONER TEKIN     ##\n");
    	    printf("## STUDENT NAME: IBRAHIM CIM            ##\n");
    	    printf("## STUDENT NAME: EREN TORLAK            ##\n");
    	    printf("## STUDENT NAME: ONUR ATASEVER          ##\n");
    	    printf("## STUDENT NAME: SELEN ERDOGAN          ##\n");
    	          
    	          //NUMARALAR 
    	    printf("## PLEASE SELECT ONE FROM THE FOLLOWING TABLE ##\n");
    	    printf("(1) SNAKE GAME\n");
    	    printf("(2) METEOR GAME\n");                                    // PROGRAM USER-INTERFACE.
    	    printf("(3) MEMORY GAME\n");                              
    	    printf("(0) EXIT\n");
            printf("SELECT: ");
            st=scanf("%s", &select[0]);

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

            if((select[0]=='1') && (st)){
                printf(" YOU HAVE SELECTED TO PLAY SNAKE GAME!!!\n");
                printf(" SNAKE GAME PLAYING RIGHT NOW...\n");
                olasihata=WriteFile(serial_th, &select, sizeof(select), &oylesine ,NULL);    
                unsigned char num_ber, sayi[10];   
                int i=1;
                int basamak=0;       
                do{
                    olasihata=ReadFile(serial_th, &num_ber, 1, &oylesine ,NULL);
                    sayi[i]=num_ber;
                    basamak++;
                    i++;
                    if(num_ber=='x'){
                    	printf("You have lost the game!!!!!\n\n");
                    	goto LOOP;
                    	
					}
                }while(num_ber!='x');  

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

            }
            else if((select[0]=='2') && (st)){
                printf(" YOU HAVE SELECTED TO PLAY METEOR GAME!!!\n");
                printf(" METEOR GAME PLAYING RIGHT NOW...\n");
                olasihata=WriteFile(serial_th, &select, sizeof(select), &oylesine ,NULL);        
                printf("METEOR GAME IN ARDUINO\n");
                unsigned char num_ber, sayi[10];   
                int i=1;
                int basamak=0;       
                do{
                    olasihata=ReadFile(serial_th, &num_ber, 1, &oylesine ,NULL);
                    sayi[i]=num_ber;
                    basamak++;
                    i++;
                    if(num_ber=='x'){
                        printf("You have lost the game!!!!!\n\n");
                    	goto LOOP;
                    	
					}
                }while(num_ber!='x');  
                

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

            }
            else if((select[0]=='3') && (st)){
                printf(" YOU HAVE SELECTED TO PLAY MEMORT GAME!!!\n");
                printf(" MEMORY GAME PLAYING RIGHT NOW...\n");
                olasihata=WriteFile(serial_th, &select, sizeof(select), &oylesine ,NULL);        
                printf("MEMORY GAME IN ARDUINO\n");
                unsigned char num_ber, sayi[10];  
				printf("Please enter a difficulty level between 1-3: ");
				scanf("%s", &select);
				olasihata=WriteFile(serial_th, &select, sizeof(select), &oylesine ,NULL);   
                int i=1;
                int basamak=0;       
                do{
                    olasihata=ReadFile(serial_th, &num_ber, 1, &oylesine ,NULL);
                    sayi[i]=num_ber;
                    basamak++;
                    i++;
                    if(num_ber=='x'){
                    	printf("\nYou have LOST the game!!!\n");
                        goto LOOP;
                    }else if(num_ber=='w'){
                    	printf("\nYou have WON the game!!!\n");
                    	goto LOOP;
                    	
					}
                }while(num_ber!='x' && num_ber!='w');  
                


            }else if((select[0]=='0') && (st)){
                printf("exiting... say goodbye.");
            }

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

            else{
                printf("You have entered an invalid value, please re-enter.");
            }

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

                if(olasihata==0){
                    printf("An error occured in the process (writing or reading from arduino) please try again...\n");
                    olasihata=1;
                }

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

            Sleep(500);
            getchar();
            getchar();
        }while(select[0]!='0');
    }
    CloseHandle(serial_th);
}
