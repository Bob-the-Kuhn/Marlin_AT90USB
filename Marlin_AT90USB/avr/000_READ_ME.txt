This is mostly a combination of the Dwenguino platform and the LUFU HID bootloader
system via scwimbush and Lincomatic.

The pins_arduino.h files have been modified to work with the Marlin software.  The
Dwengo specific items have been removed and the pin maps were changed to support the
following:
  AT90USBxx_TEENSYPP_ASSIGNMENTS flag enabled in FASTIO.h
     This is the Teensyduino pin map with the addition of assignments for ports E2 & E3
  AT90USBxx_TEENSYPP_ASSIGNMENTS flag disabled in FASTIO.h
     This is sometimes call the "standard" or "traditional" Marlin pin map (which is strange
     because it's only for the AT90USBxxx boards).

PWM0A and PWM1C share a pin.  In the Marlin software NONE of PWMs on Timer1 can be used.
Because of this we've made PWM0A available rather than PWM1C.

The only change in the core was to strip Dwengo specific items from the USBCore.cpp file.

http://www.dwengo.org/sites/default/files/package_dwengo.org_dwenguino_index.json

https://github.com/scwimbush/Printrboard-HID-Arduino-IDE-Support

http://blog.lincomatic.com/?p=548)



    TEENSYPP*      "standard"           alternate
    pin numbering  pin numbering  port  functions
    D28            D0             A0
    D29            D1             A1
    D30            D2             A2
    D31            D3             A3
    D32            D4             A4
    D33            D5             A5
    D34            D6             A6
    D35            D7             A7
    D20            D8             B0    SS
    D21            D9             B1    SCK
    D22            D10            B2    MOSI
    D23            D11            B3    MISO
    D24            D12            B4    PWM2A
    D25            D13            B5    PWM1A
    D26            D14            B6    PWM1B
    D27            D15            B7    PWM0A
    D10            D16            C0
    D11            D17            C1
    D12            D18            C2
    D13            D19            C3
    D14            D20            C4    PWM3C
    D15            D21            C5    PWM3B
    D16            D22            C6    PWM3A
    D17            D23            C7
    D0             D24            D0    PWM0B
    D1             D25            D1    PWM2B
    D2             D26            D2
    D3             D27            D3
    D4             D28            D4
    D5             D29            D5
    D6             D30            D6
    D7             D31            D7
    D8             D32            E0
    D9             D33            E1
    D46*           D34            E2
    D47*           D35            E3
    D36            D36            E4
    D37            D37            E5
    D18            D38            E6
    D19            D39            E7
    D38            D40            F0    A0
    D39            D41            F1    A1
    D40            D42            F2    A2
    D41            D43            F3    A3
    D42            D44            F4    A4
    D43            D45            F5    A5
    D44            D46            F6    A6
    D45            D47            F7    A7

 * added to the Teensyduino pin map