#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  

int trig1=2;
int echo1=3;
int trig2=7;
int echo2=8;
int buzzer=9;

long t1=0;
long t2=0;
long delta=0;

int v=0;

bool firstcase= false;
bool secondcase = false;



void setup() {
  lcd.init();                    
  lcd.backlight();
  Serial.begin(9600);

  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(buzzer,OUTPUT);

  lcd.print("Speed Radar");
  delay(2000);
  lcd.clear();
  digitalWrite(buzzer,1);
}

void loop() {
  digitalWrite(buzzer,1);
  float d1 = readUltrasonic(trig1, echo1);
  float d2 = readUltrasonic(trig2, echo2);

  if(d1 > 0 && d1 < 10 && !firstcase){
    t1 = micros();
    firstcase = true;
  }

  
  if(d2 > 0 && d2 < 10 && firstcase && !secondcase){
    t2 = micros();
    secondcase = true;
  }


  if(firstcase && secondcase){

    delta = t2 - t1;

    if(delta > 1000){  

      v = ( 1000000.0 / delta) * 3.6;

      lcd.clear();
      lcd.print("Speed=");
      lcd.print(v);
      lcd.print(" Km/h");

      lcd.setCursor(0,1);

      if(v > 50){
        lcd.print("Danger!");
        digitalWrite(buzzer,0);
      } else {
        lcd.print("Safe");
        digitalWrite(buzzer,1);
      }

      delay(3000);
      lcd.clear();
    }
    firstcase = false;
    secondcase = false;
    digitalWrite(buzzer,LOW);
  }
}

float readUltrasonic(int trig, int echo){

  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long duration = pulseIn(echo,HIGH,30000);

  if(duration == 0){
    return 999;  
  }

  float distance = duration * 0.017;

  return distance;
}

