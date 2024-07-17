#define BLUE 3 // defining output branch for blue component of RGB led
#define GREEN 5
#define RED 6
#define delayTime 500

#include <stdio.h>
#include <stdlib.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
};

// fonction pour "write " sur les RGB est analogWrite
int rdint () {
  return (int)random()%256;
};

void rgbToColorUpdate(int r, int g, int b) {
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
  delay(delayTime);
};

void france() {
  rgbToColorUpdate(0, 0, 255);
  rgbToColorUpdate(255, 255, 255);
  rgbToColorUpdate(255, 0, 0);
};


void loop() {
  france();
};
