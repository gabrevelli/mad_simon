#include<Adafruit_PWMServoDriver.h>

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
const int led[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,15,15};
const int coul[]= {0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,1,1,1};
const int freq[]= {200,800,400,1000,600,1200};
int nbrAlea;


void setup(){
  pwm.begin();
  Serial.begin(9600);
  pwm.setPWMFreq(50);
  pinMode(5, OUTPUT);
}

void loop(){
  JeuNormal();
  //error();
  delay(1000);
}

void JeuNormal(){
  int liste[100];
  for(int j: led){
    pwm.setPWM(j,0,4096);
  }
  for(int k=0;k<100;k++){
    liste[k]=12345;
  }
  int h = 0;
  while(h==0){
    int i =0;
    while(liste[i]!=12345){
      SonEtLum(liste[i]);
      Serial.print(liste[i]);
      delay(500);
      i++;
    }
//    Serial.println("0 = CYAN\n1 = MAGENTA\n2 = BLEU\n3 = JAUNE\n4 = VERT\n5 = ROUGE");
//    int k = i;
//    i = 0;
//    while(h==0){
//      while (Serial.available()) {
//        int c = Serial.read();
//        if(c!=liste[i]){
//          error();
//          return;
//        }
//        SonEtLum(c);
//        i++;
//      }
//    }
    Serial.println("#");
    nbrAlea = random(0,6);
    liste[i]= nbrAlea;
  }
}

void SonEtLum(int n){
  displayColor(n);
  tone(5, freq[n], 1000); 
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
  tone(5, 150, 1500);
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

