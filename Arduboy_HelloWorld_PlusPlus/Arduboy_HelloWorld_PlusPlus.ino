/*
Hello World Plus Plus
Adding new code as part of the "Learn Arduboy" workshop
Author: Darrell Little
Date: 10/9/2019
Based on the original Hello, World! example
June 11, 2015
Copyright (C) 2015 David Martinez
All rights reserved.
This code is the most basic barebones code for writing a program for Arduboy.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
*/

#include <Arduboy2.h>

// make an instance of arduboy
Arduboy2 myArduboy;

// Create variables for starting coordinates
int x;
int y;

void intro() {
    x = 4;
    y = 9;
    // Use a loop to let the phrase scroll down the screen
    for(int i = 0; i < 20; i++) {
    // first we clear our screen to black
    myArduboy.clear();

   // we set our cursor 5 pixels to the right and 10 down from the top
   // (positions start at 0, 0) 
    myArduboy.setCursor(x, y);

   // then we print to screen what is in the Quotation marks ""
    myArduboy.print(F("Hello, world!"));

   // then we finaly we tell the arduboy to display what we just wrote to the display
    myArduboy.display();
    x++;
    y++;
    // needs a short pause
    delay(75);
  }
}

void pressed_A() {
    x = 4;
    y = 9;
    // Use a loop to let the phrase scroll down the screen
    for(int i = 0; i < 20; i++) {
    // first we clear our screen to black
    myArduboy.clear();

   // we set our cursor 5 pixels to the right and 10 down from the top
   // (positions start at 0, 0) 
    myArduboy.setCursor(x, y);

   // then we print to screen what is in the Quotation marks ""
    myArduboy.print(F("You pressed A"));

   // then we finaly we tell the arduboy to display what we just wrote to the display
    myArduboy.display();
    x++;
    y++;
    // needs a short pause
    delay(75);
  }
}

void pressed_B() {
    x = 4;
    y = 9;
    // Use a loop to let the phrase scroll down the screen
    for(int i = 0; i < 20; i++) {
    // first we clear our screen to black
    myArduboy.clear();

   // we set our cursor 5 pixels to the right and 10 down from the top
   // (positions start at 0, 0) 
    myArduboy.setCursor(x, y);

   // then we print to screen what is in the Quotation marks ""
    myArduboy.print(F("You pressed B"));

   // then we finaly we tell the arduboy to display what we just wrote to the display
    myArduboy.display();
    x++;
    y++;
    // needs a short pause
    delay(75);
  }
}

// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  // initiate arduboy instance
  myArduboy.boot();

  // here we set the framerate to 15, we do not need to run at
  // default 60 and it saves us battery life
  myArduboy.setFrameRate(15);
  // Call the function for scroll down intro
  intro();
  // Pause 1 seconds before going on
  delay(1000);
}


// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  // pause render until it's time for the next frame
  if (!(myArduboy.nextFrame()))
    return;

  myArduboy.pollButtons();

  myArduboy.clear();

  myArduboy.setCursor(20,29);
  myArduboy.print(F("Press a button"));
  myArduboy.display();

  if(myArduboy.justPressed(A_BUTTON)) {
    pressed_A();
    delay(500);
  }

  if(myArduboy.justPressed(B_BUTTON)) {
    pressed_B();
    delay(500);
  }

}
