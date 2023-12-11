int trigPin = 8;
int echoPin = 9;
int checkDelay = 250;
int distance;
int distPrc;
int distTotal;
int duration, dist;
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int calib, C1, C2, C3;


void GetDist(){
  digitalWrite(trigPin, HIGH); //send out pulse
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW); //end pulse
  duration = pulseIn(echoPin, HIGH); //read how long it takes pulse to come back
  dist = (duration/2) / 29.1; // calculate distance; speed of sound is 29.1 microseconds/cm
  distance = dist;
  if(dist >= 200 || dist <= 0){
    Serial.println("out of range");
  }
  else{
    lcd.clear();
    lcd.print(dist);
    lcd.print(" cm");
    Serial.print(dist);
    Serial.println(" cm");
  }

  delay(checkDelay);
}

void getGPS(){
  // mock GPS coordinates
  Serial.println("48.46"); //lat of UVIC
  Serial.println("123.31"); //long of UVIC   

  delay(5000);
}

void setup() {
  lcd.noAutoscroll();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  lcd.begin(0, 0);

}

void loop() {
  GetDist();
  getGPS();
}
