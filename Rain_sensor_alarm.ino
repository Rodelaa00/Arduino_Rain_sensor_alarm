
// Viral Science
// Rain Detection Module

int rainsense= A0; // analog sensor input pin 0
int buzzerout= 10; // digital output pin 10 - buzzer output
int countval= 0; // counter value starting from 0 and goes up by 1 every second
int ledout1= 11; // digital output pin 11 - led output
 int ledout2= 12;
 int ledout3= 13;
void setup(){
   Serial.begin(9600);
   pinMode(buzzerout, OUTPUT);
   pinMode(ledout1, OUTPUT); 
   pinMode(ledout2, OUTPUT); 
   pinMode(ledout3, OUTPUT); 
   pinMode(rainsense, INPUT);
}
void loop(){
   int rainSenseReading = analogRead(rainsense);
   Serial.println(rainSenseReading); // serial monitoring message 
   delay(250);// rain sensing value from 0 to 1023.
   // from heavy rain - no rain.
    if (countval >= 10 && countval<30){ 
      Serial.print("count value=");
    Serial.println(countval);
      Serial.println("Medium rain");
      digitalWrite(buzzerout, LOW);  //raise an alert after x time
      digitalWrite(ledout1, HIGH);
      digitalWrite(ledout2, HIGH);
      digitalWrite(ledout3,LOW);// led glow
   }
   if (countval >= 30){ 
    Serial.print("count value=");
    Serial.println(countval);
      Serial.println("Heavy rain");
      digitalWrite(buzzerout, HIGH);  //raise an alert after x time
      digitalWrite(ledout1, HIGH);
      digitalWrite(ledout2, HIGH);
      digitalWrite(ledout3, HIGH);// led glow
   }
   //raining for long duration rise buzzer sound
   // there is no rain then reset the counter value
   if (rainSenseReading <500){ 
      countval++; // increment count value
      if(countval<=10){
      Serial.print("count value=");
      Serial.println(countval);}
   }
   else if (rainSenseReading >500 && rainSenseReading <700) { // if not raining
      digitalWrite(buzzerout, LOW); // turn off buzzer 
      digitalWrite(ledout1, HIGH); // turn off led
      digitalWrite(ledout2,LOW);
      digitalWrite(ledout3, LOW);
      countval = 0; // reset count to 0
   }
   delay(1000);
}
