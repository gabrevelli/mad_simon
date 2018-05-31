#include<Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>  //Software Serial Port  
#define Rx1 3    //Pin 10 pour RX, PB2 sur votre board, a brancher sur le TX du HC-06
#define Tx1 4    //Pin 11 pour TX, PB3 sur votre board, a brancher sur le RX du HC-06
#define Rx2 7
#define Tx2 6

SoftwareSerial BTSerie1(Rx1,Tx1);
SoftwareSerial BTSerie2(Rx2,Tx2);

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

/* Couleurs (format RGB) 
const int COLOR_BLACK[] = {0,0,0};
const int COLOR_RED [] = {4096,0,0};
const int COLOR_GREEN [] = {0,4096,0};
const int COLOR_BLUE [] = {0,0,4096};
const int COLOR_MAGENTA [] ={4096,0,4096};
const int COLOR_CYAN [] = {0,4096,4096};
const int COLOR_YELLOW [] = {4096,4096,0};
const int COLOR_WHITE [] = {4096,4096,4096};
*/
int liste[100];
const int led[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,15,15};
const int coul[]= {0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,1,1,1};
const int freq[]= {200,800,400,1000,600,1200};


// led 0 = VERT
// led 1 = YELLOW
// led 2 = BLEU
// led 3 = MAGENTA
// led 4 = CYAN
// led 5 = ROUGE

void setup(){
  pwm.begin();
  pwm.setPWMFreq(50);
  pinMode(2, OUTPUT);
  pinMode(Tx1, OUTPUT);
  pinMode(Tx2, OUTPUT);
  pinMode(Rx1, INPUT);
  pinMode(Rx2, INPUT);
  BTSerie1.begin(9600);
  BTSerie2.begin(9600);
  Serial.begin(9600);   
  Serial.println("debut"); 
  BTSerie1.write("choisissez votre type de partie !");
  BTSerie2.write("choisissez votre type de partie !");
}

void loop(){
  if(BTSerie1.available()) {  
    word rep = BTSerie1.read();
    if(rep == 48+6){
      Jeu(1);
      BTSerie1.write("choisissez votre type de partie !");
    }
    else if(rep == 48+8){
      Jeu(3);
      BTSerie1.write("choisissez votre type de partie !");
      BTSerie2.write("choisissez votre type de partie !");
    }
  }
  if(BTSerie2.available()) {  
    word rep = BTSerie2.read();
    if(rep == 48+7){
      Jeu(2);
      BTSerie2.write("choisissez votre type de partie !");
    }
    else if(rep == 48+8){
      Jeu(3);
      BTSerie1.write("choisissez votre type de partie !");
      BTSerie2.write("choisissez votre type de partie !");
    }
  }
}

void Jeu(int typePartie){
  for(int j: led){
    pwm.setPWM(j,0,4096);
  }
  ResetListe();
  liste[0]= Random(6);
  int verif = typePartie; 
  while(verif!=0){
    int i =0;
    while(liste[i]!=12345){
      SonEtLum(liste[i]);
      delay(500);
      i++;
    }
    verif = Reponse(verif,i);
    delay(500);
    liste[i]= Random(6);
  }
}
int Random(int j){
  return millis()%j;
}

void ResetListe(){
  for(int k=0;k<100;k++){
    liste[k]=12345;
    }
}
void SonEtLum(int n){
  displayColor(n);
  tone(2, freq[n], 1000); 
  delay(1000); 
  undisplayColor(n);
}

void displayColor(int n){
  for(int j=0; j<=2; j++){
    pwm.setPWM(led[(n*3)+j],(coul[(n*3)+j])*4096,-4096+(coul[(n*3)+j])*4096);
  }
}

void undisplayColor(int n){
  for(int j=0; j<=2; j++){
    pwm.setPWM(led[(n*3)+j],0,4096);
  }
}

void error(){
  int i = 0;
  ResetListe();
  tone(2, 150, 1500);
  while(i<8){
    for(int j=0; j<6; j++){
      pwm.setPWM(led[j*3+2],0,4096);
      pwm.setPWM(led[j*3+1],0,4096);
      pwm.setPWM(led[j*3],4096,0);
    }
    delay(100);
    for(int k=0; k<6; k++){
      undisplayColor(k);
    }
    delay(100);
    i++;
  }
}

int Reponse(int l, int i){
  for(int j=0; j<i; j++){
    if(l==1){
      unsigned long t = millis();
      BTSerie1.listen();
      while(true){
        if(millis()-t>10000){
          error();
          return 0;
        }
        if(BTSerie1.available()) {  
          word rep = BTSerie1.read();
          if(rep == 48+liste[j]){
            SonEtLum(liste[j]);
            break;
          }
          error();
          return 0;
        }
      }
    }
    else if(l==2){
      unsigned long t = millis();
      BTSerie2.listen();
      while(true){
        if(millis()-t>10000){
          error();
          return 0;
        }
        if(BTSerie2.available()) {  
          word rep = BTSerie2.read();
          if(rep == 48+liste[j]){
            SonEtLum(liste[j]);
            break;
          }
          error();
          return 0;
        }
      }
    }
    else if(l==3){
      unsigned long t = millis();
      int m=0;
      int n=0;
      while(true){
        if((millis()-t>10000)||((m!=0)&&(n!=0))){
          if((m==1)&&(n==1)){
            SonEtLum(liste[j]);
            break;
          }
          if(m==1){
            SonEtLum(liste[j]);
            BTSerie2.write("vous avez perdu");
            l=1;
            break;
          }
          if(n==1){
            SonEtLum(liste[j]);
            BTSerie1.write("vous avez perdu");
            l=2;
            break;
          }
          error();
          return 0;
        }
        BTSerie1.listen();
        if(BTSerie1.available()) {  
          word rep = BTSerie1.read();
          if(rep == 48+liste[j]){
            if(m==2){
              continue;
            }
            m=1;
            continue;
          }
          m=2;
          continue;
        }
        BTSerie2.listen();
        if(BTSerie2.available()) {  
          word rep = BTSerie2.read();
          if(rep == 48+liste[j]){
            if(n==2){
              continue;
            }
            n=1;
            continue;
          }
          n=2;
          continue;
        }
      }
    }
  }
  return l;
}

