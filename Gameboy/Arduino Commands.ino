

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "LedControl.h"



#define size 8
#define TABLE_SIZE 8
#define OBJECT_SIZE 4
#define A 8
#define W 9
#define S 10
#define D 11

#define SPACE 7
#define P 6



LedControl _snake=LedControl(4,3,2,1);
LedControl _meteor=LedControl(4,3,2,1);

LedControl _memory=LedControl(4,3,2,1);

byte scene_0[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte scene_1[8] = {0x04,0x00,0x00,0x20,0x04,0x00,0x00,0x20};
byte scene_2[8] = {0x04,0x04,0x00,0x20,0x04,0x00,0x20,0x20};
byte scene_3[8] = {0x00,0x04,0x04,0x20,0x04,0x20,0x20,0x00};
byte scene_4[8] = {0x00,0x00,0x04,0x24,0x24,0x20,0x00,0x00};
byte scene_5[8] = {0x00,0x00,0x00,0x34,0x2C,0x00,0x00,0x00};
byte scene_6[8] = {0x00,0x00,0x00,0x38,0x1C,0x00,0x00,0x00};
byte scene_7[8] = {0x00,0x00,0x00,0x1C,0x38,0x00,0x00,0x00};
byte scene_8[8] = {0x00,0x00,0x00,0x0E,0x70,0x00,0x00,0x00};
byte scene_9[8] = {0x00,0x00,0x02,0x06,0x60,0x40,0x00,0x00};
byte scene_10[8] = {0x00,0x02,0x02,0x02,0x40,0x40,0x40,0x00};
byte scene_11[8] = {0x02,0x02,0x02,0x00,0x00,0x40,0x40,0x40};
byte scene_12[8] = {0x02,0x02,0x00,0x00,0x00,0x00,0x40,0x40};
byte scene_13[8] = {0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40};
byte scene_14[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte scene_15[8] = {0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01};
byte scene_16[8] = {0x03,0x02,0x02,0x03,0x03,0x02,0x02,0x03};
byte scene_17[8] = {0x07,0x04,0x04,0x07,0x07,0x04,0x04,0x07};
byte scene_18[8] = {0x0E,0x09,0x09,0x0E,0x0E,0x09,0x09,0x0E};
byte scene_19[8] = {0x1C,0x12,0x12,0x1C,0x1C,0x12,0x12,0x1C};
byte scene_20[8] = {0x3C,0x24,0x24,0x38,0x38,0x24,0x24,0x38};
byte scene_21[8] = {0x71,0x49,0x49,0x71,0x71,0x49,0x49,0x71};
byte scene_22[8] = {0xE3,0x92,0x92,0xE3,0xE3,0x92,0x92,0xE3};
byte scene_23[8] = {0xC7,0x24,0x24,0xC7,0xC7,0x24,0x24,0xC7};
byte scene_24[8] = {0x8E,0x48,0x48,0x8E,0x8E,0x48,0x48,0x8E};
byte scene_25[8] = {0x1C,0x90,0x90,0x1C,0x1C,0x90,0x90,0x1C};
byte scene_26[8] = {0x38,0x21,0x21,0x39,0x39,0x21,0x21,0x38};
byte scene_27[8] = {0x71,0x42,0x42,0x72,0x72,0x42,0x42,0x71};
byte scene_28[8] = {0xE3,0x84,0x84,0xE4,0xE4,0x85,0x84,0xE3};
byte scene_29[8] = {0xC6,0x08,0x08,0xC8,0xC8,0x0B,0x09,0xC6};
byte scene_30[8] = {0x8C,0x10,0x10,0x90,0x90,0x16,0x12,0x8C};
byte scene_31[8] = {0x18,0x20,0x20,0x20,0x20,0x2C,0x24,0x18};
byte scene_32[8] = {0x31,0x40,0x40,0x40,0x40,0x58,0x48,0x31};
byte scene_33[8] = {0x63,0x81,0x81,0x81,0x81,0xB1,0x91,0x63};
byte scene_34[8] = {0xC7,0x02,0x02,0x02,0x02,0x62,0x22,0xC7};
byte scene_35[8] = {0x8E,0x04,0x04,0x04,0x04,0xC4,0x44,0x8E};
byte scene_36[8] = {0x1C,0x08,0x08,0x08,0x08,0x88,0x88,0x1C};
byte scene_37[8] = {0x39,0x11,0x11,0x11,0x11,0x11,0x11,0x39};
byte scene_38[8] = {0x72,0x22,0x23,0x23,0x22,0x22,0x22,0x72};
byte scene_39[8] = {0xE4,0x44,0x46,0x46,0x45,0x45,0x44,0xE4};
byte scene_40[8] = {0xC9,0x89,0x8D,0x8D,0x8B,0x8B,0x89,0xC9};
byte scene_41[8] = {0x92,0x12,0x1A,0x1A,0x16,0x16,0x12,0x92};
byte scene_42[8] = {0x24,0x24,0x34,0x34,0x2C,0x2C,0x24,0x24};
byte scene_43[8] = {0x48,0x48,0x68,0x68,0x58,0x58,0x48,0x48};
byte scene_44[8] = {0x90,0x90,0xD0,0xD0,0xB0,0xB0,0x90,0x90};
byte scene_45[8] = {0x20,0x20,0xA0,0xA0,0x60,0x60,0x20,0x20};
byte scene_46[8] = {0x40,0x40,0x40,0x40,0xC0,0xC0,0x40,0x40};
byte scene_47[8] = {0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80};
byte scene_48[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};



/*......................................................... Our doubly linked-list structure for snake..........................................................*/



struct our_snake{
int x;
int y;
struct our_snake *next;
struct our_snake *back;
};
typedef struct our_snake snake;

snake *head=NULL;
snake *tail=NULL;


/*......................................................... Our doubly linked-list structure for meteor..........................................................*/


struct our_meteor{
    short int x;
    short int y;
    short int value;
    struct our_meteor *next;
    struct our_meteor *back;
};

typedef struct our_meteor meteor;

meteor *meteor_line_head[TABLE_SIZE];
meteor *meteor_line_tail[TABLE_SIZE];



/*......................................................... Our doubly linked-list structure for object..........................................................*/

struct our_object{
    int x;
    int y;
    struct our_object *next;
};
typedef struct our_object object;

object *object_head=NULL;
object *player=NULL;






int table[TABLE_SIZE][TABLE_SIZE];
int locations[OBJECT_SIZE][OBJECT_SIZE];
int is_Game_End=0;
int unique_value;
char direction = 'd';
int difficulty=1;
int status = 0;



void printCurrent(byte frame[]);
void printCurrent_delayed(byte frame[]);



void print_table_snake(int table[][TABLE_SIZE]);
void reset_Table_snake(int table[][TABLE_SIZE]);
void create_Snake_snake(snake **head, snake **tail, int x, int y);
int place_Snake_snake(snake **head, snake **tail, int table[][TABLE_SIZE], char *direction);
int move_Snake_snake(snake **head, snake **tail, int table[][TABLE_SIZE], int *status, char *direction);
void addNewBait_snake(int table[][TABLE_SIZE]);
void reset_Table_all_snake(int table[][TABLE_SIZE]);



void addNewNode_meteor(meteor **head, meteor **tail, int x, int y, int value);
void setup_table_meteor(meteor *head[TABLE_SIZE], meteor *tail[TABLE_SIZE]);
void move_player_meteor(meteor *head[TABLE_SIZE], int *y, char direction, int *durum, int table[][TABLE_SIZE]);
void put_table_meteor(meteor *head[TABLE_SIZE], int table[][TABLE_SIZE]);
void print_table_meteor(int table[][TABLE_SIZE]);
void move_meteors_meteor(meteor *head[TABLE_SIZE], int *durum);
void add_new_meteors_meteor(meteor **head, int number_of_meteors);



void create_New_Locations_memory();
void create_New_Object_memory();
void create_Object_Node_memory(int x, int y);
void place_Object_memory();
void reset_Table_memory();
void print_Table_memory();
void set_Player_memory();
void move_Player_memory();
void set_Pixel_memory();
unsigned int unique_Value_memory();
void free_locations_memory();
void create_Player_memory();
int play_Game_memory();
int user_gui_memory();


void setup(){
_snake.shutdown(0,false);
_snake.setIntensity(0,8);
_snake.clearDisplay(0);

_meteor.shutdown(0,false);
_meteor.setIntensity(0,8);
_meteor.clearDisplay(0);

_memory.shutdown(0,false);
_memory.setIntensity(0,8);
_memory.clearDisplay(0);
  
Serial.begin(9600);
}







void loop(){
if(Serial.available()>0){
    char start=Serial.read()-48;
    if(start==1)
    {
      
        printCurrent_delayed(scene_0);
        printCurrent_delayed(scene_1);
        printCurrent_delayed(scene_2);
        printCurrent_delayed(scene_3);
        printCurrent_delayed(scene_4);
        printCurrent_delayed(scene_5);
        printCurrent_delayed(scene_6);
        printCurrent_delayed(scene_7);
        printCurrent_delayed(scene_8);
        printCurrent_delayed(scene_9);
        printCurrent_delayed(scene_10);
        printCurrent_delayed(scene_11);
        printCurrent_delayed(scene_12);
        printCurrent_delayed(scene_13);
        printCurrent_delayed(scene_14);
        printCurrent(scene_15);
        printCurrent(scene_16);
        printCurrent(scene_17);
        printCurrent(scene_18);
        printCurrent(scene_19);
        printCurrent(scene_20);
        printCurrent(scene_21);
        printCurrent(scene_22);
        printCurrent(scene_23);
        printCurrent(scene_24);
        printCurrent(scene_25);
        printCurrent(scene_26);
        printCurrent(scene_27);
        printCurrent(scene_28);
        printCurrent(scene_29);
        printCurrent(scene_30);
        printCurrent(scene_31);
        printCurrent(scene_32);
        printCurrent(scene_33);
        printCurrent(scene_34);
        printCurrent(scene_35);
        printCurrent(scene_36);
        printCurrent(scene_37);
        printCurrent(scene_38);
        printCurrent(scene_39);
        printCurrent(scene_40);
        printCurrent(scene_41);
        printCurrent(scene_42);
        printCurrent(scene_43);
        printCurrent(scene_44);
        printCurrent(scene_45);
        printCurrent(scene_46);
        printCurrent(scene_47);
        printCurrent(scene_48);
        randomSeed(analogRead(3));

        for(int i=1;i<=TABLE_SIZE/4;i++)
            create_Snake_snake(&head, &tail, 3, 1+i);
        reset_Table_all_snake(table);
        place_Snake_snake(&head, &tail, table, &direction);
        addNewBait_snake(table);
        print_table_snake(table);

        while(status!=1)
        {
            if((direction!='d') && (digitalRead(A)==HIGH) && direction!='a'){
                direction='a';
            }
            else if((direction!='d') && (digitalRead(D)==HIGH) && direction!='a'){
                direction='d';
            }
            else if((direction!='w') && (digitalRead(S)==HIGH) && direction!='s'){
                direction='s';
            }
            else if((direction!='w') && (digitalRead(W)==HIGH) && direction!='s'){
                direction='w';
            }
            if(status==1){
                break;
            }
            move_Snake_snake(&head, &tail, table, &status, &direction);
            place_Snake_snake(&head, &tail, table, &direction);
            if(status==2)
            {
                addNewBait_snake(table);
                status=0;
            }
            print_table_snake(table);
            delay(200);
        }
         if(status==1){
          Serial.print('x');
        }
        }
        if(start==2){
          _meteor.setIntensity(0,0);
          printCurrent(scene_15);
        printCurrent(scene_16);
        printCurrent(scene_17);
        printCurrent(scene_18);
        printCurrent(scene_19);
        printCurrent(scene_20);
        printCurrent(scene_21);
        printCurrent(scene_22);
        printCurrent(scene_23);
        printCurrent(scene_24);
        printCurrent(scene_25);
        printCurrent(scene_26);
        printCurrent(scene_27);
        printCurrent(scene_28);
        printCurrent(scene_29);
        printCurrent(scene_30);
        printCurrent(scene_31);
        printCurrent(scene_32);
        printCurrent(scene_33);
        printCurrent(scene_34);
        printCurrent(scene_35);
        printCurrent(scene_36);
        printCurrent(scene_37);
        printCurrent(scene_38);
        printCurrent(scene_39);
        printCurrent(scene_40);
        printCurrent(scene_41);
        printCurrent(scene_42);
        printCurrent(scene_43);
        printCurrent(scene_44);
        printCurrent(scene_45);
        printCurrent(scene_46);
        printCurrent(scene_47);
        printCurrent(scene_48);
            randomSeed(analogRead(1));
            int durum1=0;
            int durum2=0;
            int table[TABLE_SIZE][TABLE_SIZE];
            int current_position=TABLE_SIZE/2;
            setup_table_meteor(meteor_line_head, meteor_line_tail);
            put_table_meteor(meteor_line_head, table);
            print_table_meteor(table);
            while(durum1!=1 && durum2!=1){
            
                  if(durum1==1 || durum2==1){
                  Serial.print('x');
                    break;
                }
                put_table_meteor(meteor_line_head, table);

                if((digitalRead(A)==HIGH)){
                    direction='a';
                    move_player_meteor(meteor_line_head, &current_position, direction, &durum1, table);
                }
                else if((digitalRead(D)==HIGH)){
                    direction='d';
                    move_player_meteor(meteor_line_head, &current_position, direction, &durum1, table);
                }


                put_table_meteor(meteor_line_head, table);

                print_table_meteor(table);

                add_new_meteors_meteor(&meteor_line_head[1], 1);
                move_meteors_meteor(meteor_line_head, &durum2);
                if(durum1==1 || durum2==1){
                  Serial.print('x');
                    break;
                }

                delay(400);
                }
            }

            if (start == 3){
              _memory.setIntensity(0,0);
              printCurrent(scene_15);
        printCurrent(scene_16);
        printCurrent(scene_17);
        printCurrent(scene_18);
        printCurrent(scene_19);
        printCurrent(scene_20);
        printCurrent(scene_21);
        printCurrent(scene_22);
        printCurrent(scene_23);
        printCurrent(scene_24);
        printCurrent(scene_25);
        printCurrent(scene_26);
        printCurrent(scene_27);
        printCurrent(scene_28);
        printCurrent(scene_29);
        printCurrent(scene_30);
        printCurrent(scene_31);
        printCurrent(scene_32);
        printCurrent(scene_33);
        printCurrent(scene_34);
        printCurrent(scene_35);
        printCurrent(scene_36);
        printCurrent(scene_37);
        printCurrent(scene_38);
        printCurrent(scene_39);
        printCurrent(scene_40);
        printCurrent(scene_41);
        printCurrent(scene_42);
        printCurrent(scene_43);
        printCurrent(scene_44);
        printCurrent(scene_45);
        printCurrent(scene_46);
        printCurrent(scene_47);
        printCurrent(scene_48);
                randomSeed(analogRead(1));
                create_Player_memory();   
                difficulty=user_gui_memory();
                create_New_Locations_memory();
                create_New_Object_memory();
                reset_Table_memory();
                place_Object_memory();
                set_Player_memory();
                print_Table_memory();
                delay(2000);
                unique_value=unique_Value_memory();
                reset_Table_memory();
                set_Player_memory();
                print_Table_memory();
                is_Game_End = 99;
                while((is_Game_End!=1) && (is_Game_End!=0)){
                 is_Game_End=play_Game_memory();
               }
                if(is_Game_End==1){
                    Serial.print("w");
                }
                else if(is_Game_End==0){
                    Serial.print("x");
                }    
 
                
        /*.....................................This loop plays the game end stops if the game is end................................................................*/


                free_locations_memory();
            }
            reset_Table_all_snake(table);
          }
}







/*......................................................... Printing table according to the array........................................................*/



void print_table_snake(int table[][TABLE_SIZE]){
    
    for(int a=0;a<size;a++){
      _snake.setIntensity(0,0);
        for(int b=0;b<size;b++){
            if(table[a][b]==1){
              _snake.setIntensity(0,0);
                _snake.setLed(0, a, b, true);
            }
            else if(table[a][b]==0){
                _snake.setLed(0, a, b, false);
            }
            else if(table[a][b]==2){
              _snake.setIntensity(0,0);
                _snake.setLed(0, a, b, true);
            }
            else if(table[a][b]==3){
              _snake.setIntensity(0,0);
                _snake.setLed(0, a, b, true);
                delay(100);
                _snake.setLed(0, a, b, false);
                delay(100);
                _snake.setIntensity(0,0);
                _snake.setLed(0, a, b, true);
            }
            delay(10);
        }
    }
}



/*......................................................... Printing table according to the array........................................................*/







/*......................................................... Resetting the array for snake's remaining parts........................................................*/



void reset_Table_snake(int table[][TABLE_SIZE]){
    for(int a=0;a<size;a++){
        for(int b=0;b<size;b++){
            if(table[a][b]==3){
                table[a][b]=3;
            }
            else{
                table[a][b]=0;
            }
        }
    }
    for(int i=0;i<size;i++){
    table[0][i]=1;
    table[i][0]=1;
    table[i][size-1]=1;
    table[size-1][i]=1;
    }
}




void reset_Table_all_snake(int table[][TABLE_SIZE]){
for(int a=0;a<size;a++){
for(int b=0;b<size;b++){
table[a][b]=0;
}
}
for(int i=0;i<size;i++){
table[0][i]=1;
table[i][0]=1;
table[i][size-1]=1;
table[size-1][i]=1;
}
}




/*......................................................... Resetting the array for snake's remaining parts........................................................*/







/*......................................................... Creating our snake by adding new nodes to the doubly linked-list.........................................................*/



void create_Snake_snake(snake **head, snake **tail, int x, int y){
if(*head==NULL){
snake *temp;
temp=(snake*)malloc(sizeof(snake));
temp->next=NULL;
temp->back=NULL;
temp->x=x;
temp->y=y;
*head=temp;
*tail=temp;
}
else{
snake *temp;
temp=(snake*)malloc(sizeof(snake));
temp->next=*head;
(*head)->back=temp;
temp->back=NULL;
temp->x=x;
temp->y=y;
*head=temp;
}
}



/*......................................................... Creating our snake by adding new nodes to the doubly linked-list.........................................................*/







/*......................................................... Placing our snake to the array and checking whether fail and eaten conditions..........................................................*/



int place_Snake_snake(snake **head, snake **tail, int table[][TABLE_SIZE], char *direction){
snake *temp=(*head);
while(temp!=NULL){
table[temp->x][temp->y]=2;
temp=temp->next;
}
free(temp);
return 0;
}



/*......................................................... Placing our snake to the array and checking whether fail and eaten conditions..........................................................*/







/*......................................................... Moving our snake according to the direction given..........................................................*/



int move_Snake_snake(snake **head, snake **tail, int table[][TABLE_SIZE], int *status, char *direction){
snake *temp=(*tail)->back;
snake *temp2=*tail;
table[temp2->x][temp2->y]=0;
while(temp!=NULL){
temp2->x=temp->x;
temp2->y=temp->y;
temp2=temp;
temp=temp->back;
}
if((*direction)=='a'){
(*head)->y--;
}
else if((*direction)=='w'){
(*head)->x--;
}
else if((*direction)=='s'){
(*head)->x++;
}
else if((*direction)=='d'){
(*head)->y++;
}
if(table[(*head)->x][(*head)->y]==1 || table[(*head)->x][(*head)->y]==2){
*status=1;
return 1;
}
if(table[(*head)->x][(*head)->y]==3){
if((*direction)=='a'){
create_Snake_snake(head, tail, (*head)->x, (*head)->y-1);
}
else if((*direction)=='w'){
create_Snake_snake(head, tail, (*head)->x-1, (*head)->y);
}
else if((*direction)=='s'){
create_Snake_snake(head, tail, (*head)->x+1, (*head)->y);
}
else if((*direction)=='d'){
create_Snake_snake(head, tail, (*head)->x, (*head)->y+1);
}
*status=2;
return 0;
}
*status=0;
return 0;
}



/*......................................................... Moving our snake according to the direction given..........................................................*/







/*......................................................... Moving our snake according to the direction given..........................................................*/



void addNewBait_snake(int table[][TABLE_SIZE]){
int rand_x;
int rand_y;
do{
rand_x=(random()%(size-4))+3;
rand_y=(random()%(size-4))+3;
if(table[rand_x][rand_y]==0){
table[rand_x][rand_y]=3;
break;
}
}while(table[rand_x][rand_y]!=3);
}



void printCurrent(byte frame[]) {
  _snake.setIntensity(0,0);
for(int i=0; i<8; i++){
_snake.setRow(0,i,frame[i]);
}
delay(50);
}



void printCurrent_delayed(byte frame[]) {
  _snake.setIntensity(0,0);
for(int i=0; i<8; i++){
_snake.setRow(0,i,frame[i]);
}
delay(300);
}


void addNewNode_meteor(meteor **head, meteor **tail, int x, int y, int value){
    meteor *temp=(meteor*)malloc(sizeof(meteor));
    if(*head==NULL){
        temp->next=NULL;
        temp->back=NULL;
        temp->x=x;
        temp->y=y;
        temp->value=value;
        *head=temp;
        *tail=temp;
    }
    else{
        temp->next=*head;
        (*head)->back=temp;
        temp->back=NULL;
        temp->x=x;
        temp->y=y;
        temp->value=value;
        *head=temp;
    }
}




void setup_table_meteor(meteor *head[TABLE_SIZE], meteor *tail[TABLE_SIZE]){
    for(int a=0;a<TABLE_SIZE;a++){
        for(int b=0;b<TABLE_SIZE;b++){
            if(a==0){
                addNewNode_meteor(&head[a], &tail[a], a, TABLE_SIZE-b-1, 1);
            }
            else if((a!=0) && (a!=TABLE_SIZE-1) && ((b==0) || (b==TABLE_SIZE-1))){
                addNewNode_meteor(&head[a], &tail[a], a, TABLE_SIZE-b-1, 1);
            }
            else if((a==TABLE_SIZE-1) &&  ((b!=0) || (b!=TABLE_SIZE-1))){
                addNewNode_meteor(&head[a], &tail[a], a, TABLE_SIZE-b-1, 1);
            }
            else if((a==TABLE_SIZE-2) && (b==TABLE_SIZE/2-1)){
                addNewNode_meteor(&head[a], &tail[a], a, TABLE_SIZE-b-1, 2);
            }
            else{
                addNewNode_meteor(&head[a], &tail[a], a, TABLE_SIZE-b-1, 0);
            }
        }
    }
}






void move_player_meteor(meteor *head[TABLE_SIZE], int *y, char direction, int *durum, int table[][TABLE_SIZE]){
    meteor *temp=head[TABLE_SIZE-2];
    for(int b=0;b<*y;b++){
        temp = temp->next;
    }
    if((direction=='a' || direction=='A') && table[TABLE_SIZE-2][*y-1]==0){
        temp->value=0;
        temp=temp->back;
        temp->value=2;
        *y-=1;
    }
    else if((direction=='d' || direction=='D') && table[TABLE_SIZE-2][*y+1]==0){
        temp->value=0;
        temp=temp->next;
        temp->value=2;
        *y+=1;
    }
    else if((direction=='d' || direction=='D') && table[TABLE_SIZE-2][*y+1]==3){
        *durum=1;
        return;

    }
    else if((direction=='a' || direction=='A') && table[TABLE_SIZE-2][*y-1]==3){
        *durum=1;
        return;
    }
    else{
        *durum=0;
    }
}





void put_table_meteor(meteor *head[TABLE_SIZE], int table[][TABLE_SIZE]){
    for(int a=0;a<TABLE_SIZE;a++){
        meteor *temp=head[a];
        for(int b=0;b<TABLE_SIZE;b++){
            while(temp!=NULL){
                table[temp->x][temp->y]=temp->value;
                temp = temp->next;
            }
        }
    }
}


void print_table_meteor(int table[][TABLE_SIZE]){
    for(int a=0;a<TABLE_SIZE;a++){
        for(int b=0;b<TABLE_SIZE;b++){
            if(table[a][b]==1){
              _meteor.setIntensity(0,0);
                _meteor.setLed(0, a, b, true);
            }
            else if(table[a][b]==0){
                _meteor.setLed(0, a, b, false);
            }
            else if(table[a][b]==2){
              _meteor.setIntensity(0,0);
                _meteor.setLed(0, a, b, true);
            }
            else if(table[a][b]==3){
              _meteor.setIntensity(0,0);
                _meteor.setLed(0, a, b, true);
                delay(50);
                _meteor.setLed(0, a, b, false);
                delay(50);
                _meteor.setIntensity(0,0);
                _meteor.setLed(0, a, b, true);
            }
            delay(10);
        }
    }
}




void move_meteors_meteor(meteor *head[TABLE_SIZE], int *durum){

    for(int i=TABLE_SIZE-3;i>=1;i--){

        meteor *upper_line=head[i]->next;
        meteor *bottom_line=head[i+1]->next;
        while(upper_line!=NULL){
            if(upper_line->value==3 && bottom_line->value==2){
                *durum=1;
                break;
            }
            else if(upper_line->value==0 && bottom_line->value==2){
                *durum=0;
            }
            else{
                bottom_line->value=upper_line->value;
            }
            upper_line=upper_line->next;
            bottom_line=bottom_line->next;
        }
    }

    meteor *reset_first_line=head[1]->next;
    for(int i=0;i<TABLE_SIZE-2;i++){
        reset_first_line->value=0;
        reset_first_line=reset_first_line->next;
    }
}

void add_new_meteors_meteor(meteor **head, int number_of_meteors){
    meteor *temp=*head;
    for(int i=0;i<number_of_meteors;){
        for(int a=0;a<(random()%(TABLE_SIZE-1))+1;a++){
            temp=temp->next;
        }
        if(temp->value==0){
            temp->value=3;
            i++;
        }
    }
}




void create_New_Locations_memory(){
    for(int a=0;a<OBJECT_SIZE;a++){
        for(int b=0;b<OBJECT_SIZE;b++){
            locations[a][b]=0;
        }
    }
    int rand_x;
    int rand_y;
    for(int i=0;i<difficulty;){
        rand_x=(random()%(OBJECT_SIZE));
        rand_y=(random()%(OBJECT_SIZE));
        if(locations[rand_x][rand_y]==0){
            locations[rand_x][rand_y]=3;
            i++;
        }
    }
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

void create_New_Object_memory(){
    for(int a=0;a<OBJECT_SIZE;a++){
        for(int b=0;b<OBJECT_SIZE;b++){
            if(locations[a][b]==3){
                create_Object_Node_memory(a+((TABLE_SIZE-OBJECT_SIZE)/2), b+((TABLE_SIZE-OBJECT_SIZE)/2));
            }
        }
    }
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

void create_Object_Node_memory(int x, int y){
    if(object_head==NULL){
        object *temp=(object*)malloc(sizeof(object));
        temp->next=NULL;
        temp->x=x;
        temp->y=y;
        object_head=temp;
    }
    else{
        object *temp=(object*)malloc(sizeof(object));
        temp->next=object_head;
        temp->x=x;
        temp->y=y;
        object_head=temp;
    }
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

void place_Object_memory(){
    object *temp=object_head;
    while(temp!=NULL){
        table[temp->x][temp->y]=2;
        temp=temp->next;
    }
    free(temp);
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

void reset_Table_memory(){
    for(int a=0;a<TABLE_SIZE;a++){
        for(int b=0;b<TABLE_SIZE;b++){
            table[a][b]=0;
        }
    }
    for(int i=0;i<TABLE_SIZE;i++){
        table[0][i]=1;
        table[i][0]=1;
        table[i][TABLE_SIZE-1]=1;
        table[TABLE_SIZE-1][i]=1;
    }
}

/*...............................................................................................................................................*/

void print_Table_memory(){
    for(int a=0;a<TABLE_SIZE;a++){
        for(int b=0;b<TABLE_SIZE;b++){
            if(table[a][b]==1){_memory.setIntensity(0,0);
               _memory.setLed(0,a,b,true);
            }
            else if((table[a][b]==0) && ((a==player->x) && (b==player->y))){
              _memory.setIntensity(0,0);
                _memory.setLed(0,a,b,true);
            }
            else if((table[a][b]==0) && ((a!=player->x) || (b!=player->y))){
                _memory.setLed(0,a,b,false);
            }
            else if((table[a][b]==2) && ((a==player->x) && (b==player->y))){
                _memory.setIntensity(0,0);
                _memory.setLed(0,a,b,true);
            }
            else if((table[a][b]==2) && ((a!=player->x) || (b!=player->y))){
                _memory.setIntensity(0,0);
                _memory.setLed(0,a,b,true);
            }
        }
    }
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

void set_Player_memory(){
    player->x=TABLE_SIZE-2;
    player->y=TABLE_SIZE/2;
    player->next=NULL;
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

void move_Player_memory(){
    if((direction=='a'|| direction=='A') && ((table[player->x][player->y-1]==0) || (table[player->x][player->y-1]==2))){
        player->y-=1;
    }   
    else if((direction=='w' || direction=='W') && ((table[player->x-1][player->y]==0) || (table[player->x-1][player->y]==2))){
        player->x-=1;
    }  
    else if((direction=='s' || direction=='S') && ((table[player->x+1][player->y]==0) || (table[player->x+1][player->y]==2))){
        player->x+=1;
    }  
    else if((direction=='d' || direction=='D') && ((table[player->x][player->y+1]==0) || (table[player->x][player->y+1]==2))){
        player->y+=1;
    }
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

void set_Pixel_memory(){
    if(table[player->x][player->y]==0){
        table[player->x][player->y]=2;
    }
    else if(table[player->x][player->y]==2){
        table[player->x][player->y]=0;
    }
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

unsigned int unique_Value_memory(){
    int unique=0;
    for(int a=0;a<TABLE_SIZE;a++){
        for(int b=0;b<TABLE_SIZE;b++){
            if(table[a][b]==2){
                unique += a * a;
                unique += b * b;
            }
        }
    }
    return unique;
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

void free_locations_memory(){
   object *temp;
   while (object_head != NULL){
       temp = object_head;
       object_head = object_head->next;
       free(temp);
    }
    object_head=NULL;
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

void create_Player_memory(){
    player=(object*)malloc(sizeof(object));
    player->x=TABLE_SIZE-2;
    player->y=TABLE_SIZE/2;
}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

int play_Game_memory(){
        
        if(digitalRead(A)==HIGH){
            direction = 'A';
            move_Player_memory();
            print_Table_memory();
             delay(500);
            return 99;
        }
        if(digitalRead(S)==HIGH){
            direction = 'S';
            move_Player_memory();
            print_Table_memory();
             delay(500);
            return 99;
        }
        if(digitalRead(D)==HIGH){
            direction = 'D';
            move_Player_memory();
            print_Table_memory();
             delay(500);
            return 99;
        }
        if(digitalRead(W)==HIGH){
            direction = 'W';
            move_Player_memory();
            print_Table_memory();
             delay(500);
            return 99;
        }
        if(digitalRead(SPACE)==HIGH){
            direction = ' ';
            set_Pixel_memory();
            move_Player_memory();
            print_Table_memory();
             delay(500);
            return 99;
        }
        else if(digitalRead(P)==HIGH){
            if(unique_value==unique_Value_memory()){
                return 1;
            }
            else{
                return 0;
            }
        }
       
        return 99;

}

/*...............................................................................................................................................*/


/*...............................................................................................................................................*/

int user_gui_memory(){
 
    while(1){
      Serial.setTimeout(4000);
        difficulty=Serial.parseInt();
        if(difficulty==0){
            return 0;
        }
        else if(difficulty==1){
            return 2;
        }
        else if(difficulty==2){
            return 3;
        }
        else if(difficulty==3){
            return 4;
        }
        else if(difficulty==4){
            return 7;
        }
  }   
}

/*...............................................................................................................................................*/
