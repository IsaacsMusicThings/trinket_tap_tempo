# trinket_tap_tempo
A tap tempo designed around the Adafruit Trinket, and outputing CV pulse for Korg devices (Volca's, Monotribe, etc.)

Tap tempo sketch for Adafruit Trinket.  Tap a button in sync with a beat and it will create a 5v PWM output for Korg sync pulse.

Required hardware includes an Adafruit Trinket microcontroller (5V ), a momentary, normally-open pushbutton, a 1/8" mono audio jack, a 9v battery connector, and a toggle switch.

As written, this is specifically for the Trinket; would need modifications on other boards (Arduino Uno, Teensy, etc.).
  
You need to used the 5v Trinket for this, or else the CV pulse will not be strong enough.
  
Wiring table:

| Trinket                  | Gnd | Pin #0 | Pin #2 | 5v out | Bat+ |
| ------------------------ | --- | ------ | ------ | ------ | ---- |
| 1/8" Jack                | -   | +      | n/c    | n/c    | n/c  |
| NO Momentary Pushbutton  | n/c | n/c    | -      | +      | n/c  |
| 9v Battery               | -   | n/c    | n/c    | n/c    | +    |


Stay tuned for more instructions, and have a look at the code in the ".ino" file..
