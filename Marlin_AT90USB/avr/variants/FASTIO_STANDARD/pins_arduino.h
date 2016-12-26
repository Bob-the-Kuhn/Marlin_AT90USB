/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis
  Modified 2012 by Fredrik Hubinette
  Modified 2014-2015 by Matthew Wilson

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define FASTIO_STANDARD 3  // so sketch can tell which board was selected in the Arduino IDE

#define NUM_DIGITAL_PINS            48
#define NUM_ANALOG_INPUTS           8


static const uint8_t SDA = 25;
static const uint8_t SCL = 24;

// Map SPI port to 'new' pins D14..D17
static const uint8_t SS   =  8;
static const uint8_t MOSI = 10;
static const uint8_t MISO = 11;
static const uint8_t SCK  =  9;

// Mapping of analog pins as digital I/O
// A6-A11 share with digital pins
static const uint8_t A0 = 40;   // F0
static const uint8_t A1 = 41;   // F1
static const uint8_t A2 = 42;   // F2
static const uint8_t A3 = 43;   // F3
static const uint8_t A4 = 44;   // F4
static const uint8_t A5 = 45;   // F5
static const uint8_t A6 = 46;   // F6
static const uint8_t A7 = 47;   // F7




#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 40 : -1)



#define digitalPinToPCICR(p)    (((p) >= 8 && (p) <= 15) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) 0
#define digitalPinToPCMSK(p)    (((p) >= 8 && (p) <= 15) ? (&PCMSK0) : ((uint8_t *)0))
#define digitalPinToPCMSKbit(p) ( ((p) >= 8 && (p) <= 15) ? (p) - 8 : (-1))

#define digitalPinHasPWM(p)     ((p) == 12 || (p) == 13 || (p) == 14 || (p) == 15 || (p) == 20 || (p) == 21 || (p) == 22 || (p) == 24 || (p) == 25)


extern const uint8_t PROGMEM analog_pin_to_channel_PGM[];
#define analogPinToChannel(P)  ( pgm_read_byte( analog_pin_to_channel_PGM + (P) ) )

#ifdef ARDUINO_MAIN


// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
// Note PA == 1, PB == 2, etc. (GAH!)
const uint16_t PROGMEM port_to_mode_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
  (uint16_t) &DDRE,
  (uint16_t) &DDRF,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
  (uint16_t) &PORTE,
  (uint16_t) &PORTF,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
  (uint16_t) &PINE,
  (uint16_t) &PINF,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
PA, // 0  - PA0
PA, // 1  - PA1
PA, // 2  - PA2
PA, // 3  - PA3
PA, // 4  - PA4
PA, // 5  - PA5
PA, // 6  - PA6
PA, // 7  - PA7
PB, // 8  - PB0 - SS    - PCINT0
PB, // 9  - PB1 - SCK   - PCINT1
PB, // 10 - PB2 - MOSI  - PCINT2
PB, // 11 - PB3 - MISO  - PCINT3
PB, // 12 - PB4 - PWM2A - PCINT4
PB, // 13 - PB5 - PWM1A - PCINT5
PB, // 14 - PB6 - PWM1B - PCINT6
PB, // 15 - PB7 - PWM0A - PCINT7
PC, // 16 - PC0
PC, // 17 - PC1
PC, // 18 - PC2
PC, // 19 - PC3
PC, // 20 - PC4 - PWM3C
PC, // 21 - PC5 - PWM3B
PC, // 22 - PC6 - PWM3A
PC, // 23 - PC7
PD, // 24 - PD0 - PWM0B - INT0
PD, // 25 - PD1 - PWM2B - INT1
PD, // 26 - PD2 - RX    - INT2
PD, // 27 - PD3 - TX    - INT3
PD, // 28 - PD4
PD, // 29 - PD5
PD, // 30 - PD6
PD, // 31 - PD7
PE, // 32 - PE0
PE, // 33 - PE1
PE, // 34 - PE2
PE, // 35 - PE3
PE, // 36 - PE4           INT4
PE, // 37 - PE5           INT5
PE, // 38 - PE6           INT6
PE, // 39 - PE7           INT7
PF, // 40 - PF0 - A0
PF, // 41 - PF1 - A1
PF, // 42 - PF2 - A2
PF, // 43 - PF3 - A3
PF, // 44 - PF4 - A4
PF, // 45 - PF5 - A5
PF, // 46 - PF6 - A6
PF, // 47 - PF7 - A7
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
  _BV(0), // 0  - PA0
  _BV(1), // 1  - PA1
  _BV(2), // 2  - PA2
  _BV(3), // 3  - PA3
  _BV(4), // 4  - PA4
  _BV(5), // 5  - PA5
  _BV(6), // 6  - PA6
  _BV(7), // 7  - PA7
  _BV(0), // 8  - PB0 - SS    - PCINT0
  _BV(1), // 9  - PB1 - SCK   - PCINT1
  _BV(2), // 10 - PB2 - MOSI  - PCINT2
  _BV(3), // 11 - PB3 - MISO  - PCINT3
  _BV(4), // 12 - PB4 - PWM2A - PCINT4
  _BV(5), // 13 - PB5 - PWM1A - PCINT5
  _BV(6), // 14 - PB6 - PWM1B - PCINT6
  _BV(7), // 15 - PB7 - PWM0A - PCINT7
  _BV(0), // 16 - PC0
  _BV(1), // 17 - PC1
  _BV(2), // 18 - PC2
  _BV(3), // 19 - PC3
  _BV(4), // 20 - PC4 - PWM3C
  _BV(5), // 21 - PC5 - PWM3B
  _BV(6), // 22 - PC6 - PWM3A
  _BV(7), // 23 - PC7
  _BV(0), // 24 - PD0 - PWM0B - INT0
  _BV(1), // 25 - PD1 - PWM2B - INT1
  _BV(2), // 26 - PD2 - RX    - INT2
  _BV(3), // 27 - PD3 - TX    - INT3
  _BV(4), // 28 - PD4
  _BV(5), // 29 - PD5
  _BV(6), // 30 - PD6
  _BV(7), // 31 - PD7
  _BV(0), // 32 - PE0
  _BV(1), // 33 - PE1
  _BV(2), // 34 - PE2
  _BV(3), // 35 - PE3
  _BV(4), // 36 - PE4           INT4
  _BV(5), // 37 - PE5           INT5
  _BV(6), // 38 - PE6           INT6
  _BV(7), // 39 - PE7           INT7
  _BV(0), // 40 - PF0 - A0
  _BV(1), // 41 - PF1 - A1
  _BV(2), // 42 - PF2 - A2
  _BV(3), // 43 - PF3 - A3
  _BV(4), // 44 - PF4 - A4
  _BV(5), // 45 - PF5 - A5
  _BV(6), // 46 - PF6 - A6
  _BV(7), // 47 - PF7 - A7
};


// TODO(unrepentantgeek) complete this map of PWM capable pins
const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
  NOT_ON_TIMER, // 0  - PA0
  NOT_ON_TIMER, // 1  - PA1
  NOT_ON_TIMER, // 2  - PA2
  NOT_ON_TIMER, // 3  - PA3
  NOT_ON_TIMER, // 4  - PA4
  NOT_ON_TIMER, // 5  - PA5
  NOT_ON_TIMER, // 6  - PA6
  NOT_ON_TIMER, // 7  - PA7
  NOT_ON_TIMER, // 8  - PB0 - SS    - PCINT0
  NOT_ON_TIMER, // 9  - PB1 - SCK   - PCINT1
  NOT_ON_TIMER, // 10 - PB2 - MOSI  - PCINT2
  NOT_ON_TIMER, // 11 - PB3 - MISO  - PCINT3
  TIMER2A     , // 12 - PB4 - PWM2A - PCINT4
  TIMER1A     , // 13 - PB5 - PWM1A - PCINT5
  TIMER1B     , // 14 - PB6 - PWM1B - PCINT6
  TIMER0A     , // 15 - PB7 - PWM0A - PCINT7
  NOT_ON_TIMER, // 16 - PC0
  NOT_ON_TIMER, // 17 - PC1
  NOT_ON_TIMER, // 18 - PC2
  NOT_ON_TIMER, // 19 - PC3
  TIMER3C     , // 20 - PC4 - PWM3C
  TIMER3B     , // 21 - PC5 - PWM3B
  TIMER3A     , // 22 - PC6 - PWM3A
  NOT_ON_TIMER, // 23 - PC7
  TIMER0B     , // 24 - PD0 - PWM0B - INT0
  TIMER2B     , // 25 - PD1 - PWM2B - INT1
  NOT_ON_TIMER, // 26 - PD2 - RX    - INT2
  NOT_ON_TIMER, // 27 - PD3 - TX    - INT3
  NOT_ON_TIMER, // 28 - PD4
  NOT_ON_TIMER, // 29 - PD5
  NOT_ON_TIMER, // 30 - PD6
  NOT_ON_TIMER, // 31 - PD7
  NOT_ON_TIMER, // 32 - PE0
  NOT_ON_TIMER, // 33 - PE1
  NOT_ON_TIMER, // 34 - PE2
  NOT_ON_TIMER, // 35 - PE3
  NOT_ON_TIMER, // 36 - PE4           INT4
  NOT_ON_TIMER, // 37 - PE5           INT5
  NOT_ON_TIMER, // 38 - PE6           INT6
  NOT_ON_TIMER, // 39 - PE7           INT7
  NOT_ON_TIMER, // 40 - PF0 - A0
  NOT_ON_TIMER, // 41 - PF1 - A1
  NOT_ON_TIMER, // 42 - PF2 - A2
  NOT_ON_TIMER, // 43 - PF3 - A3
  NOT_ON_TIMER, // 44 - PF4 - A4
  NOT_ON_TIMER, // 45 - PF5 - A5
  NOT_ON_TIMER, // 46 - PF6 - A6
  NOT_ON_TIMER, // 47 - PF7 - A7
};

const uint8_t PROGMEM analog_pin_to_channel_PGM[8] = {
  0,  // A0   PF0 ADC0
  1,  // A1   PF1 ADC1
  2,  // A2   PF2 ADC2
  3,  // A3   PF3 ADC3
  4,  // A4   PF4 ADC4
  5,  // A5   PF5 ADC5
  6,  // A6   PF6 ADC6
  7,  // A7   PF7 ADC7
};


// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR        Serial
#define SERIAL_PORT_USBVIRTUAL     Serial
#define SERIAL_PORT_HARDWARE       Serial1
#define SERIAL_PORT_HARDWARE_OPEN  Serial1
#endif /* ARDUINO_MAIN */
#endif /* Pins_Arduino_h */
