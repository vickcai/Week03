/*
 Touch Sensor Example

 This example shows how to fade an LED on pin 11
 using the analogWrite() function.
 

 */

int led = 11;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// digital pin 2 has a pushbutton attached to it. Give it a name:
int touchSensor = 2;
int buttonState = LOW;

int isLedFading = 0;


// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(touchSensor, INPUT);  
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:
  
  buttonState = digitalRead(touchSensor); //
  
  
  buttonState = 1 - buttonState; // inverse TouchState
  
  if(buttonState == 1){
    if(isLedFading == 0){
       
      isLedFading = 1;
       
          // ramp up the LED brightness.
      for(int i = 0; i <= 255; i = i + fadeAmount){
        brightness = i;
        analogWrite(led, brightness);    
        delay(30);                            
      }
    
      delay(100); //wait for a while at the top brigtness
      
      // ramp down the LED brightness.
      for(int i = 255; i >= 0; i = i - fadeAmount){
        brightness = i;
        analogWrite(led, brightness);    
        delay(30);                              
      }
      
      isLedFading = 0;
    }
  
    
  }
  
  
  delay(100); //wait for a while 


}

