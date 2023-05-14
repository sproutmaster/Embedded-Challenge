#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Circuit_Playground.h>
int LED = 0;
void setup() {
// setup button to record/stop gesture recognition
// setup neo pixels to turn green when unlocked and red for locked
// play a beep when unlocked
  DDRC |= (1<<7); //C7 is the LED PIN
  DDRF &= ~(1<<6); //F6 is the right push button
  DDRD &= ~(1<<4); //D4 is the left push button
}

}

void loop() 
  // when button is pressed to record mode, read accelerometer value x, y and z till stop button is pressed. Take the average of magnitude of each of those
  // and store it. Compare it when the stop button is pressed. If it matches, turn neopixels green and beep, else red. Repeat
{
  if((PINF & (1<<6)) != 0) //if right push button is pressed, turn on LED to indicate start recording
  {
    PORTC |= (1<<7);
    LED = 1;
  }

  if((PIND & (1<<4)) != 0) //if left push button is pressed, turn off LED to indicate stop recording
  {
    PORTC &= ~(1<<7);
    LED = 0;
  }
  
  if(LED == 1)
  {
    void Accelerometer();
  }
}

void Accelerometer()
{
  
}
