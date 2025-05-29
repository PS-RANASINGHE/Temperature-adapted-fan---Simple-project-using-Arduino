#include <SimpleDHT.h>
int pinDHT11 = A0;          //input for DHT 11
SimpleDHT11 dht11(pinDHT11);

int detectada=0;            // time when the pulse goes to zero
int last_CH1_state = 0;
float val=0;      //final average value read by the LM35(sensor1)
float mVal =0.0;  // mapped value of the temperature sensor
float val1=0;                  //value read by the LM35(sensor2)
float val2=0;                  //value read by the LM35(sensor3)
float val3=0;                  //value read by the LM35(sensor4)
float val = (val1+val2+val3)/3;    // final average temperature value
void setup() {
  Serial.begin(9600);
  PCICR |= (1 << PCIE0);    //enable PCMSK0 scan                                                 
  PCMSK0 |= (1 << PCINT0);  //Set pin D8 trigger an interrupt on state change. Input from optocoupler
  pinMode(3,OUTPUT);        //Define D3 as output for the DIAC pulse
  pinMode(4,OUTPUT);        //output for LED indicator 
  pinMode(5,OUTPUT);        //output for LED indicator 
  pinMode(6,OUTPUT);        //output for LED indicator 
  pinMode(7,OUTPUT);        //output for LED indicator 
  pinMode(9,OUTPUT);        //output for LED indicator   
pinMode(13,OUTPUT);
}

void loop() {
  digitalWrite(13,HIGH);
 val = analogRead(A1);
float mv = ( val/1024.0)*5000;
float cel = mv/10;
mVal = map(cel,26.0,30.0,10000.0,15.0);
Serial.print("Raw Value = " );  // shows pre-scaled value                    
  Serial.print(val);      
  Serial.print("\t Temperature in C = ");
  Serial.print(cel,1);
 
  Serial.println("=================================");
  Serial.println("CURRENT ROOM TEMPERATURE AND HUMIDITY");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  int kal = temperature;
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);

if (1){
  if ((int)temperature < 26)
  {
     digitalWrite(4,LOW);
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
     delayMicroseconds(6000);
      analogWrite(3,150);
      delayMicroseconds(100);
      digitalWrite(3,LOW);
      detectada=0;
     digitalWrite(9,HIGH);
  }
  if ((int)temperature>26 && (int)temperature<=28)
  {
     digitalWrite(9,LOW);
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
     delayMicroseconds(5000);
      analogWrite(3,150);
      delay(6000);
      digitalWrite(3,LOW);
      detectada=0;
     digitalWrite(4,HIGH);
  }
    if ((int)temperature>28 && (int)temperature<=30)
  {
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
     digitalWrite(9,LOW);
     delayMicroseconds(10000);
     analogWrite(3,250);
      delay(10000);
      digitalWrite(3,LOW);
      detectada=0;
     digitalWrite(4,HIGH);
     digitalWrite(5,HIGH);
  }
     if ((int)temperature>30 && (int)temperature<=32)
  {
     digitalWrite(7,LOW);
     digitalWrite(9,LOW);
     delayMicroseconds(500);
     analogWrite(3,150);
        delay(10);
      digitalWrite(3,LOW);
      detectada=0;
     digitalWrite(4,HIGH);
     digitalWrite(5,HIGH);
     digitalWrite(6,HIGH);
  }
       if ((int)temperature>32)
  {
     digitalWrite(9  ,LOW);
     delayMicroseconds(20);
      analogWrite(3,150);
       delay(10);
     digitalWrite(3,LOW);
     detectada=0;
     digitalWrite(4,HIGH);
     digitalWrite(5,HIGH);
     digitalWrite(6,HIGH);
     digitalWrite(7,HIGH);
  }
  
 /*delayMicroseconds(mVal);
 digitalWrite(10,HIGH);
 delayMicroseconds(100);
 digitalWrite(3,LOW);*/
 detectada=0;    
  
}
}

ISR(PCINT0_vect){
  /////////////////////////////////////               //Input from optocoupler
  if(PINB & B00000001){                               //We make an AND with the pin state register, We verify if pin 8 is HIGH???
    if(last_CH1_state == 0){                          //If the last state was 0, then we have a state change...
      detectada=1;                                    //We haev detected a state change!
    }
  }
  else if(last_CH1_state == 1){                       //If pin 8 is LOW and the last state was HIGH then we have a state change      
    detectada=1;                                      //We haev detected a state change!
    last_CH1_state = 0;                               //Store the current state into the last state for the next loop
    }
}
