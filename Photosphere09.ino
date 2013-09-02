
#include <AccelStepper.h>

#define FULLSTEP 4
#define HALFSTEP 8
#define STEPS  64
 
  AccelStepper motor1(FULLSTEP, 2, 4, 5, 3); 
  AccelStepper motor2(FULLSTEP, 6, 8, 9, 7); 

int ledPin = 13;

int X = 0;
int Y = 0;

//  Ilotikun kanavat
int Xpin = A0;
int Ypin = A1;
int button = A2;

//  Ilotikun conffaus ja calibrointi
int Xzero;
int Yzero;
int deadpoint = 50;   //  Kuollut alue tikun keskipisteestä 
int slowpoint = 20;  //  Hidasalue

//  Moottorien käyntiarvot
const int max = 4000.0;
const int accel = (max/4);
const int slow = 10;

void setup()
{  
    pinMode(button, INPUT);
    pinMode(ledPin, OUTPUT);
    
    motor1.setMaxSpeed(max);
    motor1.setAcceleration(accel);

    motor2.setMaxSpeed(max);
    motor2.setAcceleration(accel);

    Xzero = calibrate(Xpin);
    delay(100);
    Yzero = calibrate(Ypin);
    delay(500);
    blinkLED(5, 200);

}

void loop()
{

    //  X-akseli

    X = position(Xpin, Xzero, deadpoint);
    motor1.setAcceleration(accel);
    motor1.move(X);
    motor1.run();

    //  Y-akseli

    Y = position(Ypin, Yzero, deadpoint);
    motor2.setAcceleration(accel);
    motor2.move(Y);
    motor2.run();

    while (digitalRead(button) == LOW){
        X = position(Xpin, Xzero, 0);
        motor1.setAcceleration(slow);
        motor1.move(X);
        motor1.runSpeed();
        Y = position(Ypin, Yzero, 0);
        motor2.setAcceleration(slow);
        motor2.move(Y);
        motor2.run();
    }

}

int position (int pin, int zero, int deadpoint) {

  int i;
  int val = 0;

  int lowpoint = zero - deadpoint;  
  int highpoint = zero + deadpoint;
  
  for (i = 0; i < 5; i++){
    val = val + analogRead(pin);
    delayMicroseconds(1);
  }

  val = val / 5;

  if (val > highpoint){
    val = map(val, highpoint, 1023, 0, 100);
  }

  else if (val < lowpoint){
    val = map(val, lowpoint, 0, 0, 100);
    val = 0 - val;
  }
  
  else {
    val = 0;
  }
  
  return val;

}

int calibrate (int pin){
  int i;
  int val;

  for (i = 0; i < 50; i++){
    val = val + analogRead(pin);
    delayMicroseconds(100); 
  }
  
  val = val / 50;
   return val;
}

void blinkLED(int times, int lengthms){
  int i = 0;
  while (i < times){
    digitalWrite(ledPin, HIGH);   // sets the LED on
    delay(lengthms);                  // waits for a second
    digitalWrite(ledPin, LOW);    // sets the LED off
    delay(lengthms);
    i++;
  } 
}


