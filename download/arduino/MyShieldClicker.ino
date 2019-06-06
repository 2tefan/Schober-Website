  const int a1_Pin = 4;
  const int b1_Pin = 6;
  const int c1_Pin = 2;
  const int d1_Pin = 3;
  const int e1_Pin = 5;
  const int f1_Pin = 8;
  const int g1_Pin = 7;
  const int DP1_Pin = 12;
  const int a2_Pin = 4;
  const int b2_Pin = 6;
  const int c2_Pin = 2;
  const int d2_Pin = 3;
  const int e2_Pin = 5;
  const int f2_Pin = 8;
  const int g2_Pin = 7;
  const int DP2_Pin =13;

  const int s1_pin = 16;
  const int s2_pin = 17;
  const int blueLED = 5;
  const int greenLED = 3;
  const int redLED = 6;
  const int RGBLEDKathode = 10;
  
  int count=0;

  
void setup() {
  // put your setup code here, to run once:
  pinMode(blueLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);
  pinMode(DP1_Pin,OUTPUT);
  pinMode(DP2_Pin,OUTPUT);
  pinMode(RGBLEDKathode,OUTPUT);
  digitalWrite(RGBLEDKathode,HIGH);
}

void loop() {
  
  if((count>0)&&button(s2_pin))
  {
    digitalWrite(DP1_Pin,HIGH);
    digitalWrite(DP2_Pin,HIGH);
   
    
    count = count -1;
    while(button(s2_pin))
    {
      digitalWrite(RGBLEDKathode,LOW);
      digitalWrite(greenLED,HIGH);
    }
     digitalWrite(greenLED,LOW);
    digitalWrite(RGBLEDKathode,HIGH);
    
    
  }
  else if((count<99)&&button(s1_pin))
  {
    digitalWrite(DP1_Pin,HIGH);
    digitalWrite(DP2_Pin,HIGH);
   
    
    count = count +1;
    while(button(s1_pin))
    {
      digitalWrite(RGBLEDKathode,LOW);
      digitalWrite(blueLED,HIGH);
    }
     digitalWrite(blueLED,LOW);
    digitalWrite(RGBLEDKathode,HIGH);
  }
  else if((count>=99)||(count<=0))
  {
    digitalWrite(DP1_Pin,HIGH);
    digitalWrite(DP2_Pin,HIGH);
    
    while(button(s1_pin)||button(s2_pin))
    {
      digitalWrite(RGBLEDKathode,LOW);
      digitalWrite(redLED,HIGH);
    }
     digitalWrite(redLED,LOW);
    digitalWrite(RGBLEDKathode,HIGH);
  }

   digitalWrite(DP1_Pin,LOW);
    digitalWrite(DP2_Pin,LOW);

  
   print7Segment(count, a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,DP1_Pin, a2_Pin, b2_Pin, c2_Pin, d2_Pin, e2_Pin, f2_Pin, g2_Pin, DP2_Pin,5);
}

void print7Segment(int value
    ,int a1_Pin,int b1_Pin,int c1_Pin,int d1_Pin,int e1_Pin,int f1_Pin,int g1_Pin,int DP1_Pin
,int a2_Pin,int b2_Pin,int c2_Pin,int d2_Pin,int e2_Pin,int f2_Pin,int g2_Pin,int DP2_Pin
,int times)
{
  int zenerstelle;
  int einerstelle;
  pinMode(a1_Pin,OUTPUT);
  pinMode(b1_Pin,OUTPUT);
  pinMode(c1_Pin,OUTPUT);
  pinMode(d1_Pin,OUTPUT);
  pinMode(e1_Pin,OUTPUT);
  pinMode(f1_Pin,OUTPUT);
  pinMode(g1_Pin,OUTPUT);
  pinMode(DP1_Pin,OUTPUT);
  pinMode(a2_Pin,OUTPUT);
  pinMode(b2_Pin,OUTPUT);
  pinMode(c2_Pin,OUTPUT);
  pinMode(d2_Pin,OUTPUT);
  pinMode(e2_Pin,OUTPUT);
  pinMode(f2_Pin,OUTPUT);
  pinMode(g2_Pin,OUTPUT);
  pinMode(DP2_Pin,OUTPUT);
    if((value>=0)&&(value<=99))
    {
        for(int i = 0; i<times; i+=1)
        {
      
          zenerstelle = value/10;
          einerstelle = value%10; 
          digitalWrite(DP2_Pin,HIGH);
          digitalWrite(DP1_Pin,LOW);
          printSevenSegmentNumber(zenerstelle, a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin, DP1_Pin);
          delay(5);
          digitalWrite(DP2_Pin,LOW);
          digitalWrite(DP1_Pin,HIGH);
          printSevenSegmentNumber(einerstelle, a2_Pin, b2_Pin, c2_Pin, d2_Pin, e2_Pin, f2_Pin, g2_Pin, DP2_Pin); 
          delay(5); 
          digitalWrite(DP2_Pin,HIGH);
          digitalWrite(DP1_Pin,HIGH);
        }
         printSevenSegmentNumber(99, a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin, DP1_Pin);
    }
}
void printSevenSegmentNumber(int number,int a_Pin,int b_Pin,int c_Pin,int d_Pin,int e_Pin,int f_Pin,int g_Pin,int DP_Pin)
{
    switch(number)
    {
        case 0: 
                digitalWrite(a_Pin,HIGH);
                digitalWrite(b_Pin,HIGH);
                digitalWrite(c_Pin,HIGH);
                digitalWrite(d_Pin,HIGH);
                digitalWrite(e_Pin,HIGH);
                digitalWrite(f_Pin,HIGH);
                digitalWrite(g_Pin,LOW);
                digitalWrite(DP_Pin,LOW);
        break;
        case 1:
                digitalWrite(a_Pin,LOW);
                digitalWrite(b_Pin,HIGH);
                digitalWrite(c_Pin,HIGH);
                digitalWrite(d_Pin,LOW);
                digitalWrite(e_Pin,LOW);
                digitalWrite(f_Pin,LOW);
                digitalWrite(g_Pin,LOW);
                digitalWrite(DP_Pin,LOW);
                break;
        case 2:
                digitalWrite(a_Pin,HIGH);
                digitalWrite(b_Pin,HIGH);
                digitalWrite(c_Pin,LOW);
                digitalWrite(d_Pin,HIGH);
                digitalWrite(e_Pin,HIGH);
                digitalWrite(f_Pin,LOW);
                digitalWrite(g_Pin,HIGH);
                digitalWrite(DP_Pin,LOW);
        break;
        case 3:
                digitalWrite(a_Pin,HIGH);
                digitalWrite(b_Pin,HIGH);
                digitalWrite(c_Pin,HIGH);
                digitalWrite(d_Pin,HIGH);
                digitalWrite(e_Pin,LOW);
                digitalWrite(f_Pin,LOW);
                digitalWrite(g_Pin,HIGH);
                digitalWrite(DP_Pin,LOW);
        break;
        case 4:
                digitalWrite(a_Pin,LOW);
                digitalWrite(b_Pin,HIGH);
                digitalWrite(c_Pin,HIGH);
                digitalWrite(d_Pin,LOW);
                digitalWrite(e_Pin,LOW);
                digitalWrite(f_Pin,HIGH);
                digitalWrite(g_Pin,HIGH);
                digitalWrite(DP_Pin,LOW);
        break;
        case 5:
                digitalWrite(a_Pin,HIGH);
                digitalWrite(b_Pin,LOW);
                digitalWrite(c_Pin,HIGH);
                digitalWrite(d_Pin,HIGH);
                digitalWrite(e_Pin,LOW);
                digitalWrite(f_Pin,HIGH);
                digitalWrite(g_Pin,HIGH);
                digitalWrite(DP_Pin,LOW);
        break;
        case 6:
                digitalWrite(a_Pin,HIGH);
                digitalWrite(b_Pin,LOW);
                digitalWrite(c_Pin,HIGH);
                digitalWrite(d_Pin,HIGH);
                digitalWrite(e_Pin,HIGH);
                digitalWrite(f_Pin,HIGH);
                digitalWrite(g_Pin,HIGH);
                digitalWrite(DP_Pin,LOW);
        break;
        case 7: 
                digitalWrite(a_Pin,HIGH);
                digitalWrite(b_Pin,HIGH);
                digitalWrite(c_Pin,HIGH);
                digitalWrite(d_Pin,LOW);
                digitalWrite(e_Pin,LOW);
                digitalWrite(f_Pin,LOW);
                digitalWrite(g_Pin,LOW);
                digitalWrite(DP_Pin,LOW);
        break;
        case 8:
                digitalWrite(a_Pin,HIGH);
                digitalWrite(b_Pin,HIGH);
                digitalWrite(c_Pin,HIGH);
                digitalWrite(d_Pin,HIGH);
                digitalWrite(e_Pin,HIGH);
                digitalWrite(f_Pin,HIGH);
                digitalWrite(g_Pin,HIGH);
                digitalWrite(DP_Pin,LOW);
        break;
        case 9:
                digitalWrite(a_Pin,HIGH);
                digitalWrite(b_Pin,HIGH);
                digitalWrite(c_Pin,HIGH);
                digitalWrite(d_Pin,HIGH);
                digitalWrite(e_Pin,LOW);
                digitalWrite(f_Pin,HIGH);
                digitalWrite(g_Pin,HIGH);
                digitalWrite(DP_Pin,LOW);
        break;
        default:
                digitalWrite(a_Pin,LOW);
                digitalWrite(b_Pin,LOW);
                digitalWrite(c_Pin,LOW);
                digitalWrite(d_Pin,LOW);
                digitalWrite(e_Pin,LOW);
                digitalWrite(f_Pin,LOW);
                digitalWrite(g_Pin,LOW);
                digitalWrite(DP_Pin,LOW);
        break;    
    }
}
bool button(int buttonPin)
{
  pinMode(buttonPin,INPUT);
  int i =analogRead(buttonPin);
  bool b;
  if(analogRead(buttonPin)> 511)
  {
    b = true;
  }
  else
  {
    b=false;
  }

  return b;
}
