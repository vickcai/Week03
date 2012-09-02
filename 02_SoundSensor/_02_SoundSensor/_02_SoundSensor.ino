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

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  // read the input from SoundSensor.
  int sensorValue = analogRead(soundSensor);
  
  // print out the value you read:
  Serial.println(sensorValue);
  int brightness;
  
  brightness = map(sensorValue,0,1023,0,255);
   
  analogWrite(led, brightness);   // turn the LED on (HIGH is the voltage level)

  delay(10);               // wait for a while

}
