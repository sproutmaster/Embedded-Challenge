#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_CircuitPlayground.h>
#include <SPI.h>

//int LED = 0;

float X1, Y1, Z1;
float X2 = 0;
float Y2 = 0;
float Z2 = 0;

void setup() {
// setup button to record/stop gesture recognition
// setup neo pixels to turn green when unlocked and red for locked
// play a beep when unlocked

//  DDRC |= (1<<7); //C7 is the LED PIN
//  DDRF &= ~(1<<6); //F6 is the right push button
//  DDRD &= ~(1<<4); //D4 is the left push button

    Serial.begin(9600);
    CircuitPlayground.begin();
    CircuitPlayground.setBrightness(10);
    //CircuitPlayground.setAccelRange(LIS3DH_RANGE_2_G);   // 2, 4, 8 or 16 G!

}


void get_avg()
{
    X1 = 0;
    Y1 = 0;
    Z1 = 0;

    // Set Color of led's to yelow while reading data

    for(int i = 0; i<= 9; i++)
        CircuitPlayground.setPixelColor(i, 255, 255, 0);



    // store avg vlaue of each axis until user presses stop
    while(1)
    {
        X1 += CircuitPlayground.motionX();
        Y1 += CircuitPlayground.motionY();
        Z1 += CircuitPlayground.motionZ();

        if(CircuitPlayground.rightButton())
        {
            Serial.print("X: ");
            Serial.print(X1);
            Serial.print("  Y: ");
            Serial.print(Y1);
            Serial.print("  Z: ");
            Serial.println(Z1);

            Serial.print("X Ratio: ");
            Serial.print(X2/X1);
            Serial.print("  Y Ratio: ");
            Serial.print(Y2/Y1);
            Serial.print("  Z Ratio: ");
            Serial.print(Z2/Z1);

            if(X2/X1 < 1.5 && Y2/Y1 < 1.5 && Z2/Z1 < 1.5) // this needs to be changed
            {
                CircuitPlayground.playTone(440, 400);

                for(int i = 0; i<= 9; i++)
                    CircuitPlayground.setPixelColor(i, 0, 255, 0);

                delay(2000);
            }

            X2 = X1;
            Y2 = Y1;
            Z2 = Z1;

            // Set color to red
            for(int i = 0; i<= 9; i++)
                CircuitPlayground.setPixelColor(i, 255, 0, 0);

            CircuitPlayground.playTone(2000, 400);

            break;
        }

        delay(100);
    }



}

void loop()
/*
   when button is pressed to record mode, read accelerometer value x, y and z till stop button is pressed. Take the average of magnitude of each of those
   and store it. Compare it when the stop button is pressed. If it matches, turn neopixels green and beep, else red. Repeat
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
*/
{


    if(CircuitPlayground.leftButton())
        get_avg();

    delay(10);

}