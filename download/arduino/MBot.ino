#include <Servo.h>

const int LED_ROT = 7;
const int LED_GELB_RECHTS = 4;
const int LED_GELB_LINKS = 8;
const int LED_WEISS = 5;
const int OPTO_ON = 6;
const int OPTO_1 = A0;
const int OPTO_2 = A1;
const int OPTO_3 = A2;
const int BUMPER_RECHTS = 2;
const int BUMPER_LINKS = 3;
const int SERVO_LINKS = 10;
const int SERVO_RECHTS = 9;
const int Servo_speed = 180;

Servo RIGHT;
Servo LEFT;

bool driving = false;

void setup() {
  Serial.begin(9600);
  Serial.println("MBot startet...");
  pinMode(LED_ROT, OUTPUT);
  pinMode(LED_GELB_RECHTS, OUTPUT);
  pinMode(LED_GELB_LINKS, OUTPUT);
  pinMode(LED_WEISS, OUTPUT);
  pinMode(OPTO_ON, OUTPUT);
  pinMode(OPTO_1, INPUT);
  pinMode(OPTO_2, INPUT);
  pinMode(OPTO_3, INPUT);
  pinMode(BUMPER_RECHTS, INPUT_PULLUP);
  pinMode(BUMPER_LINKS, INPUT_PULLUP);
  RIGHT.attach(SERVO_RECHTS);
  LEFT.attach(SERVO_LINKS);
}

void loop() {
  drive();
  delay(10);
  Serial.println("Reloop");
}

void drive()
{
  int crash = crashDetected();
  if (crash == 0)
  {
    if (driving == false)
    {
      accelerate();
      resetLights();
    }
  }
  else
  {
    Serial.println("MBot crash...");
    stop();
    reverse();
    if (crash == BUMPER_RECHTS)
    {
      reverseRight();
    }
    else if (crash == BUMPER_LINKS)
    {
      reverseLeft();
    }
  }
}

void accelerate()
{
  Serial.println("MBot accelerate...");
  for (int i = 90; i < 180; i += 2)
  {
    RIGHT.write(-i);
    LEFT.write(i);
    delay(20);
  }

  driving = true;
}

void decelerate()
{
  Serial.println("MBot decelerate...");
  for (int i = 180; i > 0; i--)
  {
    RIGHT.write(i);
    LEFT.write(-i);
    delay(50);
  }
}

void stop()
{
  Serial.println("MBot stop...");
  RIGHT.write(90);
  LEFT.write(90);
  driving = false;


  digitalWrite(LED_ROT, HIGH);
  digitalWrite(LED_WEISS, LOW);
}

void reverse()
{
  Serial.println("MBot reverse...");

  RIGHT.write(180);
  LEFT.write(0);
  delay(1000);
}


void reverseLeft()
{
  Serial.println("MBot reverse left...");

  digitalWrite(LED_GELB_RECHTS, HIGH);

  for (int i = 180; i > 0; i--)
  {
    RIGHT.write(i);
    delay(10);
  }
}


void reverseRight()
{
  digitalWrite(LED_GELB_LINKS, HIGH);

  Serial.println("MBot reverse right...");
  for (int i = 0; i < 180; i++)
  {
    LEFT.write(i);
    delay(10);
  }
}

int crashDetected()
{
  int right_bumper = digitalRead(BUMPER_RECHTS);
  int left_bumper = digitalRead(BUMPER_LINKS);
  int output = 0;

  if (right_bumper == 0)
  {
    output = BUMPER_RECHTS;
  }
  if (left_bumper == 0)
  {
    output = BUMPER_LINKS;
  }

  return output;
}

void resetLights()
{
  digitalWrite(LED_ROT, LOW);
  digitalWrite(LED_GELB_RECHTS, LOW);
  digitalWrite(LED_GELB_LINKS, LOW);
  digitalWrite(LED_WEISS, HIGH);
}