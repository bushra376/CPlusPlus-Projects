#include "TimerOne.h"

volatile int SignalVal;
volatile int MiddleVal;
volatile int Count=0;
volatile int InModeCount=0;
int i;
int done=0;
byte ledstate = 0;
long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;           // interval at which to blink (milliseconds)

//FEEBBACK CURRENT PINS
int EMGInput=A0;
int IndexMotorCurrent =  A1;
//int MiddleMotorCurrent = A2;
//int RingMotorCurrent =   A3;
int PinkyMotorCurrent =  A4;
int ThumbMotorCurrent =  A5;
//MOTOR LOGIC PINS
int IndexMotorLogic1=    0;
int IndexMotorLogic2=    1;
int MiddleMotorLogic1=   2;
int MiddleMotorLogic2=   4;
int RingMotorLogic1=     6;
int RingMotorLogic2=     5;
int PinkyMotorLogic1=    8;
int PinkyMotorLogic2=    7;
int ThumbMotorLogic1=    9 ;
int ThumbMotorLogic2=    10;
int Thumb_2MotorLogic1=  3;
int Thumb_2MotorLogic2=  13;
int WristMotorLogic1=    A2 ;
int WristMotorLogic2=    A3;

int LED_MODE_SELECTION = 11;  //Green
int LED_IN_MODE = 12;        //Yellow

//LEDs
//int ModeSelectLED = 13;

void setup()
{
 //CURRENT AND EMG INPUTS
  pinMode(EMGInput,INPUT);
  pinMode(IndexMotorCurrent,INPUT);
//pinMode(MiddleMotorCurrent,INPUT);
//pinMode(RingMotorCurrent,INPUT);
  pinMode(PinkyMotorCurrent,INPUT);    
  pinMode(ThumbMotorCurrent,INPUT);
  //MotorLogics
  pinMode(IndexMotorLogic1,OUTPUT);
  pinMode(IndexMotorLogic2,OUTPUT);
  pinMode(MiddleMotorLogic1,OUTPUT);
  pinMode(MiddleMotorLogic2,OUTPUT);
  pinMode(RingMotorLogic1,OUTPUT);
  pinMode(RingMotorLogic2,OUTPUT);
  pinMode(PinkyMotorLogic1,OUTPUT);
  pinMode(PinkyMotorLogic2,OUTPUT);  
  pinMode(ThumbMotorLogic1,OUTPUT);
  pinMode(ThumbMotorLogic2,OUTPUT);
  pinMode(Thumb_2MotorLogic1,OUTPUT);
  pinMode(Thumb_2MotorLogic2,OUTPUT);  
  pinMode(WristMotorLogic1,OUTPUT);
  pinMode(WristMotorLogic2,OUTPUT);  
  
  pinMode(LED_MODE_SELECTION,OUTPUT);
  pinMode(LED_IN_MODE,OUTPUT);      
   //The LED
//  pinMode(ModeSelectLED,OUTPUT);
  
   //Serial Monitor
  Serial.begin(9600);
}

void callback()
{
  done++;
  Serial.println("Timer Done");  
  //ledstate = ~ledstate;  
}

void loop()
{
  ledstate = 0;
  digitalWrite(LED_MODE_SELECTION,0); 
  digitalWrite(LED_IN_MODE,0);     
  Count=0;
  while(AvgEMG() < 120);
  Serial.println("Mode Selection");  
  Timer1.initialize(5000000);         // initialize timer1, and set a 5 second period  
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt      
  
  void start();
  
   while(done != 3)
   {
      //digitalWrite(LED_MODE_SELECTION,ledstate);     
      Blink_LED();
      GetCount();    
   }
  Serial.println("hum bahir a gai hain");  
  Serial.println(Count);  
  Timer1.detachInterrupt();
  done=0;

  //Mode Selected Shown by HIGH LED
  digitalWrite(LED_MODE_SELECTION,HIGH);       
  
  // select mode depending on the 
  // Count value:
  switch (Count) {
  case 1:    
    Serial.println("Mode 1");
    Mode_1();
    break;    
  case 2:    
    Serial.println("Mode 2");
    Mode_2();
    break;  
  case 3:    
    Serial.println("Mode 3");
    Mode_3();
    break;
  case 4:    
    Serial.println("Mode 4");
    Mode_4();
    break;
  case 5:    
    Serial.println("Mode 5");
    Mode_5();
    break;    
  case 6:    
    Serial.println("Mode 6");
    Mode_6();
    break;    
 
  }
}

int AvgEMG()
{
      for(i=0; i<10; i++)
      {
        SignalVal=analogRead(EMGInput);
        SignalVal += SignalVal;       
      }
      SignalVal = SignalVal/10;  
      return SignalVal;
}

/*
int AvgMiddle()
{
      for(i=0; i<10; i++)
      {
        MiddleVal=analogRead(MiddleMotorCurrent);
        MiddleVal += MiddleVal;       
      }
      MiddleVal = MiddleVal/10;  
      return MiddleVal;
}
*/
//******************************************

void GetCount()
{
  
    if(AvgEMG() > 120)
    {   
      digitalWrite(LED_IN_MODE,HIGH);      
      delay(1000);
      Count++;
      Serial.println(SignalVal);  
    }
    digitalWrite(LED_IN_MODE,LOW);  
/*
    int keep = 0;
    while(AvgEMG() > 120)
    {
      digitalWrite(LED_IN_MODE,HIGH);       
      if(keep == 0)
      { 
         Count++; 
         Serial.println(SignalVal);           
      }
      keep++;      
    }
    digitalWrite(LED_IN_MODE,LOW);   
  */  
}

void Mode_1()  //POWER MODE
{
    Serial.println("Mode 1 Entered");    
    while(AvgEMG() < 120); //wait for pulse
    Serial.println("bubbLEgum");    

    ThumbMotorIn();  //Move Left
    delay(3000);    
    ThumbMotorStop();
    
    //MOVE MOTORS/FINGERS INWARDS
    PinkyMotorIn();
    MiddleMotorIn();
    IndexMotorIn(); 
    RingMotorIn();
    
    
    Serial.println("bEFORE");    
    //while( (analogRead( PinkyMotorCurrent) < 180));  // wait for fingers to open
    while( (analogRead( IndexMotorCurrent) < 180));  // wait for fingers to open
    Serial.println("AFTER"); 

    IndexMotorStop();
    MiddleMotorStop();
    RingMotorStop();
    PinkyMotorStop();

    Thumb_2MotorIn();    // Moves Forward/Inwards
    Serial.println("BEFOREThumb");     
    while(analogRead(ThumbMotorCurrent) < 180) ; 
    Serial.println("AFTERThumb");     
    
    //TURN MOTORS OFF
    Thumb_2MotorStop();
    ThumbMotorStop();    
    delay(100);    
        
    while(AvgEMG() < 120); //wait for pulse    
    
    Open_Hand();
}

void Mode_2()  //FINGER POINT
{
  Serial.println("Mode 2 Entered");
  while(AvgEMG() < 120);  //wait for pulse
  
  //MOVE MOTORS/FINGERS INWARDS
  PinkyMotorIn();
  MiddleMotorIn();
  RingMotorIn();
  
  Serial.println("bEFORE");
  while(analogRead(PinkyMotorCurrent) < 180);  // wait for fingers to open
  Serial.println("AFTER");
    
  //TURNS MOTORS OFF
  MiddleMotorStop();  
  RingMotorStop();
  PinkyMotorStop();
  
  ThumbMotorIn();  //Move Left
  delay(3000);
  ThumbMotorStop();    
  
  delay(1000);
  
  Wrist_Clock();
  delay(1000);  
  Wrist_Stop();  
  
  Wrist_AntiClock();  
  delay(2000);  
  Wrist_Stop();    
  
  Wrist_Clock();
  delay(1000);  
  Wrist_Stop();      
  '--
  while(AvgEMG() < 120);  //wait for pulse
  
  Open_Hand_Mode2();
    
}

void Mode_3()  //TRIPOD GRIP
{
  Serial.println("Mode 3 Entered");
  while(AvgEMG() < 120);  //wait for pulse

  //Move Thumb Left
  ThumbMotorIn();
  delay(3000);
  ThumbMotorStop();

  // MOVE FINGERS AND THUMB INWARDS
  IndexMotorIn();
  MiddleMotorIn();  
    
  Serial.println("bEFORE");
  while ((analogRead(IndexMotorCurrent) < 180));
  Serial.println("AFTER");
    
  //TURN MOTORS OFF
  IndexMotorStop();
  MiddleMotorStop();
  
  Thumb_2MotorIn();    
  while ((analogRead(ThumbMotorCurrent) < 150)); 
  Thumb_2MotorStop(); 
  
  while(AvgEMG() < 120);  //wait for pulse
  
  Open_Hand_Mode3();
  
}

void Mode_4()  //PINCH GRIP
{
  Serial.println("Mode 4 Entered");
  while(AvgEMG() < 120);  //wait for pulse
  
  //Move thumb left
  ThumbMotorIn();
  delay(3000);  
  ThumbMotorStop();
  
  IndexMotorIn();  

  Serial.println("bEFORE");
  while ((analogRead(IndexMotorCurrent) < 180));
  Serial.println("AFTER");  
    
  //TURNS MOTORS OFF
  Thumb_2MotorStop();
  IndexMotorStop();
  
  Thumb_2MotorIn();  
  while(analogRead(ThumbMotorCurrent) < 180);  //wait for fingers to open  
  
  while(AvgEMG() < 120);  //wait for pulse
  
  Open_Hand_Mode4();
}

void Mode_6()  //YO GRIP
{
  Serial.println("Mode 6 Entered");
  while(AvgEMG() < 120);  //wait for pulse
  
  //MOVE MOTORS/FINGERS INWARDS
  MiddleMotorIn();
  RingMotorIn();  
/*  
  Serial.println("bEFORE");
  while(analogRead(RingMotorCurrent) < 190);  //wait for fingers to open
  Serial.println("AFTER");
*/
  delay(3000);
  
  //TURN MOTORS OFF
  MiddleMotorStop();
  RingMotorStop();
  
  while(AvgEMG() < 120);  //wait for pulse
  
  Open_Hand_Mode6();
  
}

void Mode_5()  //LATERAL GRIP
{
  Serial.println("Mode 5 Entered");
  while(AvgEMG() < 120);  //wait for pulse
  
  //MOVE MOTORS/FINGERS INWARDS
  PinkyMotorIn();
  IndexMotorIn();
  MiddleMotorIn();
  RingMotorIn();
  
  Serial.println("bEFORE");
  while(analogRead(PinkyMotorCurrent) < 180);  //wait for fingers to open
  Serial.println("AFTER");
  
  //TURN MOTORS OFF
  IndexMotorStop();
  MiddleMotorStop();
  RingMotorStop();
  PinkyMotorStop();
  
  Thumb_2MotorIn();
  while(analogRead(ThumbMotorCurrent) < 180);  
  Thumb_2MotorStop();
    
  while(AvgEMG() < 120);  //wait for pulse
  
  Open_Hand_Mode5();
  
}


void Open_Hand()
{
    //OPEN THE CLOSED FINGERS
    Thumb_2MotorBack();  //Moves Back/OUT
    while(analogRead(ThumbMotorCurrent) < 180); // wait while thumb is opening
    Thumb_2MotorStop();   
    
    PinkyMotorBack();
    MiddleMotorBack();
    IndexMotorBack();
    RingMotorBack();
    
    while(analogRead(PinkyMotorCurrent) < 200); // wait while fingers are opening
    
    //TURN MOTORS OFF
    IndexMotorStop();
    MiddleMotorStop();
    RingMotorStop();
    PinkyMotorStop();
    Thumb_2MotorStop(); 
   
    ThumbMotorBack();    // Moves Right
    delay(3200);    
    ThumbMotorStop();      
    
    loop();  
}

void Open_Hand_Mode2()
{
    PinkyMotorBack();
    MiddleMotorBack();
    RingMotorBack();
    
    while(analogRead(PinkyMotorCurrent) < 200); // wait while fingers are opening
    
    //TURN MOTORS OFF
    MiddleMotorStop();
    RingMotorStop();
    PinkyMotorStop();
    Thumb_2MotorStop(); 
   
    ThumbMotorBack();    // Moves Right
    delay(3200);    
    ThumbMotorStop();      
    
    loop();  
}

void  Open_Hand_Mode3()
{
    //OPEN THE CLOSED FINGERS
    Thumb_2MotorBack();  //Moves Back/OUT
    while(analogRead(ThumbMotorCurrent) < 150); // wait while thumb is opening
    Thumb_2MotorStop();   
    
    MiddleMotorBack();
    IndexMotorBack();    
    
    //while(analogRead(MiddleMotorCurrent) < 280); // wait while fingers are opening
    while(analogRead(IndexMotorCurrent) < 200); // wait while fingers are opening
    
    //TURN MOTORS OFF
    MiddleMotorStop();
    IndexMotorStop();
   
    ThumbMotorBack();    // Moves Right
    delay(3200);    
    ThumbMotorStop();      
    
    loop();  
}

void Open_Hand_Mode4()
{
    //OPEN THE CLOSED FINGERS
    Thumb_2MotorBack();  //Moves Back/OUT
    while(analogRead(ThumbMotorCurrent) < 180); // wait while thumb is opening
    Thumb_2MotorStop();   
    
    IndexMotorBack();    
    
    while(analogRead(IndexMotorCurrent) < 220); // wait while fingers are opening
    
    //TURN MOTORS OFF
    IndexMotorStop();
   
    ThumbMotorBack();    // Moves Right
    delay(3200);    
    ThumbMotorStop();      
    
    loop();  
}  

void Open_Hand_Mode5()
{
  //OPEN THE CLOSED FINGERS
    Thumb_2MotorBack();  //Moves Back/OUT
    while(analogRead(ThumbMotorCurrent) < 180); // wait while thumb is opening
    Thumb_2MotorStop();   
    
    PinkyMotorBack();
    MiddleMotorBack();
    IndexMotorBack();
    RingMotorBack();
    
    while(analogRead(PinkyMotorCurrent) < 200); // wait while fingers are opening
    
    //TURN MOTORS OFF
    IndexMotorStop();
    MiddleMotorStop();
    RingMotorStop();
    PinkyMotorStop();
    
    loop();    
  
}

void Open_Hand_Mode6()
{    
    MiddleMotorBack();
    RingMotorBack();
    
    delay(3000);
    
    //TURN MOTORS OFF
    MiddleMotorStop();
    RingMotorStop();
    
    loop();    
  
}

void IndexMotorIn()
{
    digitalWrite(IndexMotorLogic1,HIGH);
    delay(100);        
    digitalWrite(IndexMotorLogic2,LOW);
    delay(100);   
}

void IndexMotorBack()
{
    digitalWrite(IndexMotorLogic1,LOW);
    delay(100);         
    digitalWrite(IndexMotorLogic2,HIGH);
    delay(100);        
}

void IndexMotorStop()
{
    digitalWrite(IndexMotorLogic1,LOW);
    delay(100);                
    digitalWrite(IndexMotorLogic2,LOW);
    delay(100);      
}

void MiddleMotorIn()
{
    digitalWrite(MiddleMotorLogic1,HIGH);
    delay(100);        
    digitalWrite(MiddleMotorLogic2,LOW);
    delay(100);   
}

void MiddleMotorBack()
{
    digitalWrite(MiddleMotorLogic1,LOW);
    delay(100);       
    digitalWrite(MiddleMotorLogic2,HIGH);
    delay(100);      
}

void MiddleMotorStop()
{
    digitalWrite(MiddleMotorLogic1,LOW);
    delay(100);              
    digitalWrite(MiddleMotorLogic2,LOW);
    delay(100);      
}

void RingMotorIn()
{
    digitalWrite(RingMotorLogic1,HIGH);
    delay(100);        
    digitalWrite(RingMotorLogic2,LOW);
    delay(100);   
}

void RingMotorBack()
{
    digitalWrite(RingMotorLogic1,LOW);
    delay(100);          
    digitalWrite(RingMotorLogic2,HIGH);
    delay(100);      
}

void RingMotorStop()
{
    digitalWrite(RingMotorLogic1,LOW);
    delay(100);           
    digitalWrite(RingMotorLogic2,LOW);
    delay(100);      
}

void PinkyMotorIn()
{
    digitalWrite(PinkyMotorLogic1,HIGH);
    delay(100);         
    digitalWrite(PinkyMotorLogic2,LOW);
    delay(100);      
}

void PinkyMotorBack()
{
    digitalWrite(PinkyMotorLogic1,LOW);
    delay(100);         
    digitalWrite(PinkyMotorLogic2,HIGH);
    delay(100);      
}

void PinkyMotorStop()
{
    digitalWrite(PinkyMotorLogic1,LOW);
    delay(100);           
    digitalWrite(PinkyMotorLogic2,LOW);
    delay(100);      
}

void ThumbMotorIn()
{
    digitalWrite(ThumbMotorLogic1,LOW);
    delay(100);         
    digitalWrite(ThumbMotorLogic2,HIGH);
    delay(100);      
}

void ThumbMotorBack()
{
    digitalWrite(ThumbMotorLogic1,HIGH);
    delay(100);       
    digitalWrite(ThumbMotorLogic2,LOW);
    delay(100); 
}

void ThumbMotorStop()
{
    digitalWrite(ThumbMotorLogic1,LOW);
    delay(100);           
    digitalWrite(ThumbMotorLogic2,LOW);
    delay(100);      
}

void Thumb_2MotorIn()
{
    digitalWrite(Thumb_2MotorLogic1,LOW);
    delay(100);       
    digitalWrite(Thumb_2MotorLogic2,HIGH);
    delay(100);      
}

void Thumb_2MotorBack()
{
    digitalWrite(Thumb_2MotorLogic1,HIGH);
    delay(100);       
    digitalWrite(Thumb_2MotorLogic2,LOW);
    delay(100);      
}

void Thumb_2MotorStop()
{
    digitalWrite(Thumb_2MotorLogic1,LOW);
    delay(100);           
    digitalWrite(Thumb_2MotorLogic2,LOW);
    delay(100);      
}

void Wrist_Clock()
{
    analogWrite(WristMotorLogic1,0);
    delay(100);       
    analogWrite(WristMotorLogic2,255);
    delay(100);      
}

void Wrist_AntiClock()
{
    analogWrite(WristMotorLogic1,255);
    delay(100);       
    analogWrite(WristMotorLogic2,0);
    delay(100);        
}

void Wrist_Stop()
{
    analogWrite(WristMotorLogic1,0);
    delay(100);       
    analogWrite(WristMotorLogic2,0);
    delay(100);        
}

void Blink_LED()
{
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) 
  {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    ledstate = ~ledstate;


    // set the LED with the ledState of the variable:
    digitalWrite(LED_MODE_SELECTION,ledstate);
  }  
}
