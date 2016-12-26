# Marlin_AT90USB
Arduino IDE support for Marlin boards using the AT90USB646 &amp; At90USB1286 

To add AT90USB646 &amp; At90USB1286 support to Arduino 1.6.x:
  1) download the ZIP file
  2) unzip the file
  3) copy the Marlin_AT90USB directory to the Arduino hardware directory
  
USAGE
  This extension supports both the "standard" and the "Teensyduino Teensy++ 2.0" pin maps as
  defined in fastio.h.

  Selection of the pin map is done by 
   a) enabling/disabling the "AT90USBxx_TEENSYPP_ASSIGNMENTS" flag in fastio.hardware
   b) selecting the appropriate board in the Arduino TOOLS menu:
       AT90USB1286_TEENSYPP
       AT90USB646_TEENSYPP
       AT90USB1286_STANDARD
       AT90USB646_STANDARD
  
  The Rev B pinsXXX.h files will warn you if the pin map selections are inconsistent.
  
NOTES:
  The "AT90USBxx_TEENSYPP_ASSIGNMENTS" pin map in fastio.h assigns pins to ports E2 & E3.
  This is because some of the Marlin supported boards use E3 as digital IO.
  
  PWM0A is available in both pin maps.  PWM0A and PWM1C share the same pin.  Normally 
  PWM1C is available but ... Marlin uses TIMER1 as an interrupt source.  The way TIMER1
  is setup by Marlin makes PWM1A, PWM1B and PWM1C UNUSEABLE as general purpose PWMs.  
   