/*
 * EightBallMagic2
 * Author: Darrell Little
 * Blog: https://learntoprogramroanoke.github.io/
 * Repository: https://github.com/LearnToProgramRoanoke/Learn-Arduboy
 * 
 * Ask the Eight Ball anything, it will tell you no lies!
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * Updated: 10/12/2019 
 * Refreshed code using new Arduboy2 library and Arduino IDE 1.8.8
 * Added ArduboyTones library for tones
 */

// Include the Arduboy2 and ArduboyTones libraries
#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "bitmaps.h"

Arduboy2 myArduboy;
ArduboyTones sound(myArduboy.audio.enabled);

// Store answers in an array
char* answers[] = {
  "It is certain", "Reply hazy try again",
  "It is decidedly so", "Ask again later",
  "Without a doubt", "Better not tell you",
  "Yes, definately", "Cannot predict now",
  "You may rely on it", "Ask again later",
  "As I see it, yes", "Do not count on it",
  "Most likely", "My reply is no",
  "Outlook good", "My sources say no",
  "Yes", "Outlook not so good",
  "Signs point to yes", "Very doubtful"
};

// the number of answers in the array
int answerCount = sizeof(answers)/sizeof(char*);

// Create variable to hold the randomly selected answer from the array
char* answer;

void intro() {
  for(int i = -8; i < 45; i = i + 2)
  {
    myArduboy.clear();
    myArduboy.setCursor(20, i);
    myArduboy.print("THIS IS ARDUBOY!");
    myArduboy.display();
    // Need small delay, scrolls too fast!
    delay(75);
  }
  toneYes();
  delay(1500);
  eightBall();
}

void toneYes() {
  sound.tone(987,160,1318,400);
}

void toneNo() {
  sound.tone(1318,160,987,400);
}

void thinking(){
  myArduboy.clear();
  myArduboy.drawSlowXYBitmap(0,5,small,56,56,1);
  myArduboy.setCursor(57,45);
  myArduboy.print("   Thinking   ");
  myArduboy.display();
  delay(1500);
}

void theAnswer() {
  thinking();
  answer = answers[random(answerCount)];
  
  for(int i = -8; i < 36; i = i + 2)
  {
    myArduboy.clear();
    myArduboy.setCursor(8, i);
    myArduboy.print(answer);
    myArduboy.display();
    // Need small delay, scrolls too fast!
    delay(75);
  }
  toneYes();
  delay(1500);
}

void eightBall() {
  myArduboy.clear();
  myArduboy.drawSlowXYBitmap(0,0,eightball,128,46,1);
  myArduboy.setCursor(10,56);
  myArduboy.print("Eight Ball Magic");
  myArduboy.display();
  delay(3000);
}

void askQuestion() {
  myArduboy.clear();
  myArduboy.setCursor(1, 12);
  myArduboy.print("Think Of A Question");
  myArduboy.setCursor(1, 32);
  myArduboy.print("To Ask the 8-Ball");
  myArduboy.setCursor(1, 52);
  myArduboy.print("Press the A Button");
  myArduboy.display();
  }

void setup() {
  myArduboy.boot();
  myArduboy.setFrameRate(30);
  myArduboy.initRandomSeed();
  myArduboy.audio.on();
  myArduboy.setCursor(28, 5);
  myArduboy.print("Hello World!");
  myArduboy.display();
  delay(1500);
  intro();
} // end of setup()

void loop() {
  
 if (!(myArduboy.nextFrame()))
    return;

  myArduboy.pollButtons();

  if (!(myArduboy.justPressed(A_BUTTON)))
      {
        askQuestion();
      }
  else
      {
        theAnswer();
      }
} // end of loop()
