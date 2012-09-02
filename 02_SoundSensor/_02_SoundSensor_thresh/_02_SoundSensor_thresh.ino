/*
  Analog Read/Write 
  Turns on an LED while button is pressed, then off if button is released.
 
  This example code is in the public domain.
 */
 
// an LED connected on most Arduino boards.
// give it a name:
int led = 11;

// analog pin 0 has a pushbutton attached to it. Give it a name:
int soundSensor = A0;
int sensorValue = 0;
int prevSensorValue = 0;
int midLevel = 512;

int thresholdValue = 150;

int ON = 1;
int OFF = 0;
int ledState = OFF;
int ledStateChanged = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  // read the input from SoundSensor.

  
  sensorValue = analogRead(soundSensor);
  sensorValue = abs(sensorValue - midLevel);
  sensorValue = prevSensorValue + (sensorValue - prevSensorValue) * 0.5; 
  
  prevSensorValue = sensorValue;
  
  if(sensorValue > thresholdValue){
    
    if(ledStateChanged != 1){
      if(ledState == ON){
        ledState = OFF;
        digitalWrite(led,ledState);
        
      }else if(ledState == OFF){
        ledState = ON;
        digitalWrite(led,ledState);
      }
    }
    
    ledStateChanged = 1;
    
  }else{
    
    ledStateChanged = 0;
    
  }
 
  // print out the value you read:
    Serial.print("mic:");
    Serial.print(sensorValue);
    Serial.print(",led:");
    Serial.println(ledState);
 
  delay(10);               // wait for a while

}
