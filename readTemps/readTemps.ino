#include <Wire.h>

unsigned long currentTime;
unsigned long loopTime;
float temperature=0;
float displayTemp=0;
float tempTotal=0;
float numberOfValues=0;

int ledgreen = 13;
int ledyellow = 12;
int ledred = 11;

void setup() {
Serial.begin(9600);
currentTime = millis();
  loopTime = currentTime; 
  //initialize the pins as outputs
  pinMode(ledgreen, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
}


void loop() {
  currentTime = millis();
   temperature = getTemperature(); // read temperature
tempTotal=tempTotal+temperature;
numberOfValues = numberOfValues + 1;

  
  
  if(currentTime >= (loopTime + 200)){
  displayTemp=tempTotal/numberOfValues;
  
   // float temperature = getTemperature(); // read temperature
    Serial.println(displayTemp);
    tempTotal=0;
    numberOfValues=0;
    loopTime=currentTime;
    
    if (displayTemp>80){
      digitalWrite(ledgreen,HIGH);
      digitalWrite(ledred,LOW);
      digitalWrite(ledyellow,LOW);
    }
    else if (displayTemp>72) {
      digitalWrite(ledgreen,LOW);
      digitalWrite(ledred,LOW);
      digitalWrite(ledyellow,HIGH);
    }
    else {
      digitalWrite(ledgreen,LOW);
      digitalWrite(ledred,HIGH);
      digitalWrite(ledyellow,LOW);
    }
    
    
  }
  
  
  
  
}


float getTemperature() {
    int sensorValue = analogRead(A1);              // read voltage from analog pin 1
 int processedValue = 270-((sensorValue - 98)*100);
 // float voltage = sensorValue * (5.0/1023.0);    // convert sensor range of 0-1023 to Arduino voltage range of 0-5V
 // float temperature = (voltage * 19.96) - 26.75; // convert voltage to temperature 
 // return temperature;                            // return temperature in Celsius 


return processedValue;
}

// byte smiley[] = {B00000,B00000,B01010,B00000,B10001,B01110,B00000,B00000};
//temperature ranges externally
// 25 degrees Celsius is optimal for premature babies
// 18 degrees Celsius is realistic 
//36.4 degreese celsius is hypothermia
//36.7 is good
//36.5 is okay
//if babies temperature drops one degree below 36.5 degrees baby loses 10% of engergy 
