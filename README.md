# Photosphere
Arduino project using 2 stepper motors and a joystick to take Photosphere pictures with mounted android phone.

   This bit of code is meant to be run with Arduino Uno and 28BYJ-48 Stepper motors with ULN2003AN drivers.
   The stepper motors are cheap and usually comes with these drivers, when bought from ebay. 
   They run at 5v / ~0.24 A / ~10RPM

   Manufacturer Datasheet: http://www.raspberrypi-spy.co.uk/wp-content/uploads/2012/07/Stepper-Motor-28BJY-48-Datasheet.pdf

----------------------------------------------------------------------------------------------------------------
## SETTING UP:

How to plug your motors in and control them using Joystick module.
   
1.   Plug in your Joystick X and Y pins to Arduino pins A0 and A1.
⋅⋅⋅ If you want to use the "slowmode" by using your Joysticks button plug the button to A3.
⋅⋅⋅ Also the +5v to Arduino 5v and GND to Arduino GND.


Plug your #1 driver board pins 1,2,3,4 to Arduino pins 2,3,4,5.

And the #2 driver board pins 1,2,3,4 to Arduino pins 6,7,8,9.

Then connect the driver boards 5v to Arduino 5v or other 5v power supply and GND.

Make sure if using Auxiliary power supply to connect your Arduino GND to supply GND.



Upload the code to your Arduino and you're good to go!

-----------------------------------------------------------------------------------------------------------------

Have fun building the robot!