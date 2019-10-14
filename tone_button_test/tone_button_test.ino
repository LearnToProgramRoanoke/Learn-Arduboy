/*
 * tone_button_test 
 * Author: Darrell Little
 * Date: 10/12/2019
 * This sketch demonstrates the use of the ArduboyTones library
 * by playing a tone when a button is pressed.
 * 
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */
 
#include <Arduboy2.h>
#include <ArduboyTones.h>

// Instantiate both of the imported libraries
Arduboy2 myArduboy;
ArduboyTones sound(myArduboy.audio.enabled);

// Create a function for each tone
// To play a tone use this format: sound.tone(freq1, dur1, freq2, dur2, freq3, dur3);
// It can have up to three (frequency, duration) combinations
void toneYes() {
  sound.tone(987,160,1318,400);
}

void toneNo() {
  sound.tone(1318,160,987,400);
}

void setup() {
  // Put your setup code here, to run once
  // These starts myArduboy, sets the video frame rate, 
  // enables audio and prints Hello World to the screen
  myArduboy.boot();
  myArduboy.setFrameRate(30);
  myArduboy.audio.on();
  myArduboy.setCursor(10, 15);
  myArduboy.print("Hello World");
  myArduboy.display();
  delay(1500);
} // end of setup()

void loop() {
  // Put your main code here, to run repeatedly:
  // Waits until the next video frame is to be displayed
  if (!(myArduboy.nextFrame()))
    return;
    
  // Waits for button presses and clears the screen
  myArduboy.pollButtons();
  myArduboy.clear();
  
  // Prints a message to the screen with instructions
  myArduboy.setCursor(10, 15);
  myArduboy.print("Press A or B");
  myArduboy.setCursor(10, 25);
  myArduboy.print("for a Tone");
  myArduboy.display();

  // Determines which button was pressed and then calls a function
  if (myArduboy.justPressed(A_BUTTON))
      {
        myArduboy.setCursor(10, 35);
        myArduboy.print("You pressed A");
        myArduboy.display();
        toneYes();
        delay(500);
      }
      else if (myArduboy.justPressed(B_BUTTON))
      {
        myArduboy.setCursor(10, 35);
        myArduboy.print("You pressed B");
        myArduboy.display();
        toneNo();
        delay(500);
      }
} // end of loop()
