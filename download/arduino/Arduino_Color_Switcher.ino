#include <Arduino.h>

int red_led = 6;
int blue_led = 5;
int green_led = 3;

int rgb_kathode = 10;
int Sevseg_kathode = 12;
int Sevseg_kathode2 = 13;

int poti = 14;

int type = 0;
int modi = 8;

int potenziometer() {
  pinMode(poti, INPUT);

  int value = analogRead(poti);
  int returnInt = 0;

  for (int i = modi; i > 0; i--) {
    if (value >= 1023 - i * (1024 / modi)) {
      returnInt = i;
    }
  }
  return returnInt;
}

void setup() {
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);

  pinMode(rgb_kathode, OUTPUT);
  pinMode(Sevseg_kathode, OUTPUT);
  pinMode(Sevseg_kathode2, OUTPUT);
}

void loop() {
  digitalWrite(rgb_kathode, LOW);
  digitalWrite(Sevseg_kathode, HIGH);
  digitalWrite(Sevseg_kathode2, HIGH);

  int potiInt = potenziometer();
  Serial.println(potiInt);

  switch (potiInt) {
  case 1:
    digitalWrite(red_led, HIGH);
    digitalWrite(blue_led, LOW);
    digitalWrite(green_led, LOW);
    break;

  case 2:
    digitalWrite(red_led, HIGH);
    digitalWrite(blue_led, HIGH);
    digitalWrite(green_led, LOW);
    break;
  case 3:
    digitalWrite(red_led, LOW);
    digitalWrite(blue_led, HIGH);
    digitalWrite(green_led, LOW);
    break;
  case 4:
    digitalWrite(red_led, LOW);
    digitalWrite(blue_led, HIGH);
    digitalWrite(green_led, HIGH);
    break;
  case 5:
    digitalWrite(red_led, LOW);
    digitalWrite(blue_led, LOW);
    digitalWrite(green_led, HIGH);
    break;
  case 6:
    digitalWrite(red_led, HIGH);
    digitalWrite(blue_led, LOW);
    digitalWrite(green_led, HIGH);
    break;
  case 7:
    digitalWrite(red_led, HIGH);
    digitalWrite(blue_led, HIGH);
    digitalWrite(green_led, HIGH);
    break;
  case 8:
    digitalWrite(red_led, LOW);
    digitalWrite(blue_led, LOW);
    digitalWrite(green_led, LOW);
    break;
  }
}
