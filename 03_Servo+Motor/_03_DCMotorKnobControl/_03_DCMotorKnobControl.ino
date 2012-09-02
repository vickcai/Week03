/*
  DC motor control
  Control a DC motor through FET module.
  Change its speed by PWM(analogWrite) control. 
  
  This example code is in the public domain.
 */
 
// an DC motor
// give it a name:
int motorPin = 11;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(motorPin, OUTPUT);  
  
}

// the loop routine runs over and over again forever:
void loop() {

  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  // print out the value you read:
  Serial.println(sensorValue);
  int brightness;
  
  brightness = map(sensorValue,0,1023,0,255);
   
  analogWrite(motorPin, brightness);   // turn the LED on (HIGH is the voltage level)

  delay(10);               // wait for a while

}
