/*******************************************************************
  Tap tempo sketch for Adafruit Trinket.  Tap a button in sync with
  a beat and it will create a 5v PWM output for Korg sync pulse.
 
  Required hardware includes an Adafruit Trinket microcontroller
  (5V ), a momentary, normally-open pushbutton, a 1/8" mono audio
  jack, a 9v battery connector, and a toggle switch.
 
  As written, this is specifically for the Trinket; would need
  modifications on other boards (Arduino Uno, etc.).
 
  Trinket  :   Gnd   Pin #0
  1/8" Jack:    -      +
 
  Pushbutton between Pin #2 (Analog 1) and 5V/3V.
 *******************************************************************/
 
#include <avr/power.h>
 
unsigned long
  prevBeat = 0L, // Time of last button tap
uint8_t
  prevButton;    // Value of last digitalRead()
int 
  korgPin = 0; 	// Korg pulse pin set to  pin 0
int 
  ledPin = 2; 	// LED pulse pin set to  pin 2
int
  pulseWidth = 10;  // Length of the Korg pulse in mS
uint16_t
  numPulse   = 0;  // Number of pulses counted
 
void setup() {
  if(F_CPU == 16000000) clock_prescale_set(clock_div_1);
  prevButton = digitalRead(1);		// Read digital input.
  pinMode(korgPin, OUTPUT);		// initialize pin 0 as an output.
  analogWrite (korgPin, 0);		// set Korg pin as low output to start
  pinMode(ledPin, OUTPUT);		// set LED pin as output
  analogWrite(ledPin, 255);		// Turn the LED on to start with
}
 
static unsigned long debounce() { // Waits for change in button state
  uint8_t       b;
  unsigned long start, last;
 
  start = micros();
 
  for(;;) {
    last = micros();
    while((b = digitalRead(1)) != prevButton) { // Button changed?
      if((micros() - last) > 25000L) {          // Sustained > 25 mS?
        prevButton = b;                         // Save new state
        return last;                            // Return time of change
      }
    } // Else button unchanged...do other things...
  }
}
 
void loop() {		// loops over and over :)
  unsigned long t;  // time
  uint16_t      b;  // beat interval
  uint16_t		p;  // korg pulse interval
 
  t = debounce(); // Wait for new button state
 
  if(prevButton == HIGH) {             // Low-to-high (button tap)?
    if(prevBeat) {                     // Button tapped before?
      b = (t - prevBeat);		// Find time per tap
      p = (b / 4);				// Divide for korg pulse freq. (4 per beat)
    }
    prevBeat = t;               // Record time of last tap
  }
  numPulse++;					// count the pulses
  analogWrite (korgPin, 255);  // pulse the korg pulse pin to High
  if(p * numPulse) == b) {		//Pulse LED on the beat
    analogWrite (ledPin, 255);  // pulse the LED pulse pin to High
  }
  delay (pulseWidth);         // for this long
  analogWrite (korgPin, 0);   // and then set korg pin back Low
  analogWrite (ledPin, 0);   // also led pin back Low (even if low already)
  delay (p);                 // wait this long and then do the next pulse
  if(numPulse == 4) {		// if we are back on the beat, reset pulse count
    numPulse	= 0;
  }
}
