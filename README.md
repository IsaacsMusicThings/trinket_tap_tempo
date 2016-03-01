# trinket_tap_tempo
A tap tempo designed around the Adafruit Trinket, and outputing CV pulse for Korg devices (Volca's, Monotribe, etc.)

Tap tempo sketch for Adafruit Trinket.  Tap a button in sync with a beat and it will create a 5v PWM output for Korg sync pulse.

Required hardware includes an Adafruit Trinket microcontroller (5V ), a momentary, normally-open pushbutton, a 1/8" mono audio jack, and a 9v battery connector. See wiring table below for connections. Optionally, a toggle switch can be wired in series on one leg of the battery connector to act as an On/Off switch.

As written, this is specifically for the 5v Trinket; would need modifications on other boards (Arduino Uno, Teensy, etc.). You need to used the 5v Trinket (or other 5v board) for this project, or else the CV pulse will be too weak to be reliably read by Korg devices.
  
Wiring table:

| Trinket                  | Gnd | Pin #0 | Pin #2 | 5v out | Bat+ |
| ------------------------ | --- | ------ | ------ | ------ | ---- |
| 1/8" Jack                | -   | +      | n/c    | n/c    | n/c  |
| NO Momentary Pushbutton  | n/c | n/c    | -      | +      | n/c  |
| 9v Battery               | -   | n/c    | n/c    | n/c    | +    |


Code is in full **alpha** untested state. Development is *ongoing*. Stay tuned for changes, more instructions, and have a look at the code in the ".ino" file to see how this thing will work.
