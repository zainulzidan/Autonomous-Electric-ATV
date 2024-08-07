#include "Arduino.h"
#include "ACS712.h"
#include "Servo.h"

//Motor pins initializing
int en1a = 3;
int n1a = 2;
int n2a = 1;
int en2a = 5;
int n3a = 4;
int n4a = 7;
int en1b = 6;
int n1b = 8;
int n2b = 12;
int en2b = 9;
int n3b = 13;
int n4b = 11;

//Servo pin initializing
int sm = 10;

//Receiver pin initializing
int rx = 0;

//Current sensors pin initializing
int cs1 = A5;
int cs2 = A4;
int cs3 = A3;
int cs4 = A2;

int fl=0,fr=0,rr=0,rl=0;
int wheelMatrix[]={fr,fl,rr,rl};

Servo servo1;


void setup() {

pinMode(en1a,OUTPUT);
pinMode(n1a,OUTPUT);
pinMode(n2a,OUTPUT);
pinMode(en2a,OUTPUT);
pinMode(n3a,OUTPUT);
pinMode(n4a,OUTPUT);
pinMode(en1b,OUTPUT);
pinMode(n1b,OUTPUT);
pinMode(n2b,OUTPUT);
pinMode(en2b,OUTPUT);
pinMode(n3b,OUTPUT);
pinMode(n4b,OUTPUT);

pinMode(sm,OUTPUT); 

pinMode(cs1,INPUT);
pinMode(cs2,INPUT);
pinMode(cs3,INPUT);
pinMode(cs4,INPUT);


pinMode(rx,INPUT);


servo1.attach(sm);

}


void loop() {
if(rx == HIGH) {
  en1a=255;
  n1a=HIGH;
  n2a=LOW;
  en2a=255;
  n3a=HIGH;
  n4a=HIGH;
  en1b=255;
  n1b=HIGH;
  n2b=LOW;
  en2b=255;
  n3b=HIGH;
  n4b=LOW;
  
  updMatrix();

  if(wheelMatrix[0]==0 && wheelMatrix[1]== 0 && wheelMatrix[2]== 1 && wheelMatrix[3]== 1){
    n1a=HIGH;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=LOW;
    n2b=LOW;
    n3b=LOW;
    n4b=LOW;
    }
  else if(wheelMatrix[0]==1 && wheelMatrix[1]== 1 && wheelMatrix[2]== 0 && wheelMatrix[3]== 0){
    n1b=HIGH;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;
    n1a=LOW;
    n2a=LOW;
    n3a=LOW;
    n4a=LOW;
    } 
  else if(wheelMatrix[0]==0 && wheelMatrix[1]== 1 && wheelMatrix[2]== 0 && wheelMatrix[3]== 1){
    n1a=HIGH;
    n2a=LOW;
    n3a=LOW;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=LOW;
    n4b=LOW;
    
    servo1.write(90);
    delay(100);
    servo1.write(45); //turns 45 degree anticlock
    delay(1000);
    }
  else if(wheelMatrix[0]==1 && wheelMatrix[1]== 0 && wheelMatrix[2]== 1 && wheelMatrix[3]== 0){
    n1a=LOW;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=LOW;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;

    servo1.write(90);
    delay(100);
    servo1.write(135); //turns 45 degree clock
    delay(1000);

    }
  else if(wheelMatrix[0]==0 && wheelMatrix[1]== 1 && wheelMatrix[2]== 1 && wheelMatrix[3]== 0){
    n1a=HIGH;
    n2a=LOW;
    n3a=LOW;
    n4a=LOW;
    n1b=LOW;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;
    }
  else if(wheelMatrix[0]==1 && wheelMatrix[1]== 0 && wheelMatrix[2]== 0 && wheelMatrix[3]== 1){
    n1a=LOW;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=LOW;
    n4b=LOW;
    }
  else if(wheelMatrix[0]==1 && wheelMatrix[1]== 0 && wheelMatrix[2]== 0 && wheelMatrix[3]== 0){
    n1a=LOW;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;

    servo1.write(90);
    delay(100);
    servo1.write(115); //turns 25 degree clock
    delay(1000);  
    }
  else if (wheelMatrix[0]==0 && wheelMatrix[1]== 1 && wheelMatrix[2]== 0 && wheelMatrix[3]== 0){
    n1a=HIGH;
    n2a=LOW;
    n3a=LOW;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;
    
    servo1.write(90);
    delay(100);
    servo1.write(65); //turns 25 degree anticlock
    delay(1000); 
    }
  else if(wheelMatrix[0]==0 && wheelMatrix[1]== 0 && wheelMatrix[2]== 1 && wheelMatrix[3]== 0){
    n1a=HIGH;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=LOW;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;

    servo1.write(90);
    delay(100);
    servo1.write(115); //turns 25 degree clock
    delay(1000);     
    }
  else if(wheelMatrix[0]==0 && wheelMatrix[1]== 0 && wheelMatrix[2]== 0 && wheelMatrix[3]== 1){
    n1a=HIGH;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=LOW;
    n4b=LOW;

    servo1.write(90);
    delay(100);
    servo1.write(65); //turns 25 degree anticlock
    delay(1000);    
    }
  else if(wheelMatrix[0]==0 && wheelMatrix[1]== 1 && wheelMatrix[2]== 1 && wheelMatrix[3]== 1){
    n1a=HIGH;
    n2a=LOW;
    n3a=LOW;
    n4a=LOW;
    n1b=LOW;
    n2b=LOW;
    n3b=LOW;
    n4b=LOW;

    servo1.write(90);
    delay(100);
    servo1.write(65); //turns 25 degree anticlock
    delay(1000);   
    }
  else if(wheelMatrix[0]==1 && wheelMatrix[1]== 0 && wheelMatrix[2]== 1 && wheelMatrix[3]== 1){
    n1a=LOW;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=LOW;
    n2b=LOW;
    n3b=LOW;
    n4b=LOW;

    servo1.write(90);
    delay(100);
    servo1.write(115); //turns 25 degree clock
    delay(1000); 
    }
  else if(wheelMatrix[0]==1 && wheelMatrix[1]== 1 && wheelMatrix[2]== 0 && wheelMatrix[3]== 1){
    n1a=LOW;
    n2a=LOW;
    n3a=LOW;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=LOW;
    n4b=LOW;

    servo1.write(90);
    delay(100);
    servo1.write(65); //turns 25 degree anticlock
    delay(1000);  
    }
  else if(wheelMatrix[0]==1 && wheelMatrix[1]== 1 && wheelMatrix[2]== 1 && wheelMatrix[3]== 0){
    n1a=LOW;
    n2a=LOW;
    n3a=LOW;
    n4a=LOW;
    n1b=LOW;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;

    servo1.write(90);
    delay(100);
    servo1.write(115); //turns 25 degree clock
    delay(1000); 
    }
  else if(wheelMatrix[0]==0 && wheelMatrix[1]== 0 && wheelMatrix[2]== 0 && wheelMatrix[3]== 0){
    n1a=HIGH;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;
    }
  else (wheelMatrix[0]==1 && wheelMatrix[1]== 1 && wheelMatrix[2]== 1 && wheelMatrix[3]== 1);{


    //ZIG ZAG(two z)
    servo1.write(90);
    delay(100);
    servo1.write(45); //turns 45 degree anticlock
    delay(5000);
    
    n1a=HIGH;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;
    delay(5000);
    
    servo1.write(90);
    delay(100);
    servo1.write(135); //turns 45 degree clock
    delay(5000);

    n1a=HIGH;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;
    delay(5000);

    servo1.write(90);
    delay(100);
    servo1.write(45); //turns 45 degree anticlock
    delay(5000);
    
    n1a=HIGH;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;
    delay(5000);
    
    servo1.write(90);
    delay(100);
    servo1.write(135); //turns 45 degree clock
    delay(5000);

    n1a=HIGH;
    n2a=LOW;
    n3a=HIGH;
    n4a=LOW;
    n1b=HIGH;
    n2b=LOW;
    n3b=HIGH;
    n4b=LOW;
    delay(5000);
    }
   
  }
}
void updMatrix (void){
  int a1dc = analogRead(cs1);
  float a1voltage = a1dc*5/1023.0;
  float a1current = (a1voltage-2.5)/0.185; 
  
  int a2dc = analogRead(cs2);
  float a2voltage = a2dc*5/1023.0;
  float a2current = (a2voltage-2.5)/0.185;
  
  int a3dc = analogRead(cs3);
  float a3voltage = a3dc*5/1023.0;
  float a3current = (a3voltage-2.5)/0.185;
  
  int a4dc = analogRead(cs4);
  float a4voltage = a4dc*5/1023.0;
  float a4current = (a4voltage-2.5)/0.185;

  if(a1current<=2){
    fl=1;
    }
  if(a2current<=2){
    fr=1;
    }
  if(a3current<=2){
    rr=1;
    }
  if(a4current<=2){
    rl=1;
    }

  };
