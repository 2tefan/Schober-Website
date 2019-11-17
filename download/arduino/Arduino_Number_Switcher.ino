#include <Arduino.h>

int cathode_led = 10;
int cathode_digit1 = 12;
int cathode_digit2 = 13;

int poti = 14;

int seven_seg_a = 4;
int seven_seg_b = 6;
int seven_seg_c = 2;
int seven_seg_d = 3;
int seven_seg_e = 5;
int seven_seg_f = 8;
int seven_seg_g = 7;

int potenziometer(int length) {
  pinMode(poti, INPUT);

  int value = analogRead(poti);
  int returnInt = 0;

  for (int i = 0; i < length; i++) {
    if (value >= i * 1024 / length) {
      returnInt = i;
    }
  }

  return returnInt;
}

void printSevenSegment(int number) {
  switch (number) {
  case 0:
    digitalWrite(seven_seg_a, HIGH);
    digitalWrite(seven_seg_b, HIGH);
    digitalWrite(seven_seg_c, HIGH);
    digitalWrite(seven_seg_d, HIGH);
    digitalWrite(seven_seg_e, HIGH);
    digitalWrite(seven_seg_f, HIGH);
    digitalWrite(seven_seg_g, LOW);
    break;
  case 1:
    digitalWrite(seven_seg_a, LOW);
    digitalWrite(seven_seg_b, HIGH);
    digitalWrite(seven_seg_c, HIGH);
    digitalWrite(seven_seg_d, LOW);
    digitalWrite(seven_seg_e, LOW);
    digitalWrite(seven_seg_f, LOW);
    digitalWrite(seven_seg_g, LOW);
    break;
  case 2:
    digitalWrite(seven_seg_a, HIGH);
    digitalWrite(seven_seg_b, HIGH);
    digitalWrite(seven_seg_c, LOW);
    digitalWrite(seven_seg_d, HIGH);
    digitalWrite(seven_seg_e, HIGH);
    digitalWrite(seven_seg_f, LOW);
    digitalWrite(seven_seg_g, HIGH);
    break;
  case 3:
    digitalWrite(seven_seg_a, HIGH);
    digitalWrite(seven_seg_b, HIGH);
    digitalWrite(seven_seg_c, HIGH);
    digitalWrite(seven_seg_d, HIGH);
    digitalWrite(seven_seg_e, LOW);
    digitalWrite(seven_seg_f, LOW);
    digitalWrite(seven_seg_g, HIGH);
    break;
  case 4:
    digitalWrite(seven_seg_a, LOW);
    digitalWrite(seven_seg_b, HIGH);
    digitalWrite(seven_seg_c, HIGH);
    digitalWrite(seven_seg_d, LOW);
    digitalWrite(seven_seg_e, LOW);
    digitalWrite(seven_seg_f, HIGH);
    digitalWrite(seven_seg_g, HIGH);
    break;
  case 5:
    digitalWrite(seven_seg_a, HIGH);
    digitalWrite(seven_seg_b, LOW);
    digitalWrite(seven_seg_c, HIGH);
    digitalWrite(seven_seg_d, HIGH);
    digitalWrite(seven_seg_e, LOW);
    digitalWrite(seven_seg_f, HIGH);
    digitalWrite(seven_seg_g, HIGH);
    break;
  case 6:
    digitalWrite(seven_seg_a, HIGH);
    digitalWrite(seven_seg_b, LOW);
    digitalWrite(seven_seg_c, HIGH);
    digitalWrite(seven_seg_d, HIGH);
    digitalWrite(seven_seg_e, HIGH);
    digitalWrite(seven_seg_f, HIGH);
    digitalWrite(seven_seg_g, HIGH);
    break;
  case 7:
    digitalWrite(seven_seg_a, HIGH);
    digitalWrite(seven_seg_b, HIGH);
    digitalWrite(seven_seg_c, HIGH);
    digitalWrite(seven_seg_d, LOW);
    digitalWrite(seven_seg_e, LOW);
    digitalWrite(seven_seg_f, LOW);
    digitalWrite(seven_seg_g, LOW);
    break;
  case 8:
    digitalWrite(seven_seg_a, HIGH);
    digitalWrite(seven_seg_b, HIGH);
    digitalWrite(seven_seg_c, HIGH);
    digitalWrite(seven_seg_d, HIGH);
    digitalWrite(seven_seg_e, HIGH);
    digitalWrite(seven_seg_f, HIGH);
    digitalWrite(seven_seg_g, HIGH);
    break;
  case 9:
    digitalWrite(seven_seg_a, HIGH);
    digitalWrite(seven_seg_b, HIGH);
    digitalWrite(seven_seg_c, HIGH);
    digitalWrite(seven_seg_d, HIGH);
    digitalWrite(seven_seg_e, LOW);
    digitalWrite(seven_seg_f, HIGH);
    digitalWrite(seven_seg_g, HIGH);
    break;
  default:
    digitalWrite(seven_seg_a, LOW);
    digitalWrite(seven_seg_b, LOW);
    digitalWrite(seven_seg_c, LOW);
    digitalWrite(seven_seg_d, LOW);
    digitalWrite(seven_seg_e, LOW);
    digitalWrite(seven_seg_f, LOW);
    digitalWrite(seven_seg_g, LOW);
    break;
  }
}

void printSevenSeg1(int number) {
  digitalWrite(cathode_led, HIGH);
  digitalWrite(cathode_digit1, HIGH);
  digitalWrite(cathode_digit2, LOW);

  printSevenSegment(number);
}

void printSevenSeg2(int number) {
  digitalWrite(cathode_led, HIGH);
  digitalWrite(cathode_digit1, LOW);
  digitalWrite(cathode_digit2, HIGH);

  printSevenSegment(number);
}

void formatSevenSegment(int number) {
  String tempString = String(number);
  int tempNumber[tempString.length()];

  for (int i = 0; i < tempString.length(); i++) {
    tempNumber[i] = tempString.substring(i, i + 1).toInt();
  }
  Serial.print(potenziometer(tempString.length()));

  printSevenSeg1(tempNumber[tempString.length() - 1 -
                            potenziometer(tempString.length() - 1)]);
  delay(1);
  printSevenSeg2(tempNumber[tempString.length() - 2 -
                            potenziometer(tempString.length() - 1)]);
  delay(1);
}
void setup() {
  Serial.begin(9600);

  pinMode(cathode_led, OUTPUT);
  pinMode(cathode_digit1, OUTPUT);
  pinMode(cathode_digit2, OUTPUT);
}

void loop() { formatSevenSegment(25126); }