
int TrigerPin=9 ; // output
int ReadPin=A0; 
int delayTime=100;
int WarningLightPin=8;
int WorkingPin=13;
int MotorPin1=2;
int MotorPin2=3;
int MotorPin3=4;
int MotorPin4=5;
double threhold=15;
double duration,range;

void DonotTouchMe();
void Fine();
void Backward();
void Stop();
void setup(){
  Serial.begin(9600);
  pinMode(TrigerPin,OUTPUT);
  pinMode(MotorPin1,OUTPUT);
  pinMode(MotorPin2,OUTPUT);
  pinMode(WarningLightPin,OUTPUT);
  pinMode(WorkingPin,OUTPUT);
}


void loop() {
  digitalWrite(TrigerPin,HIGH);
  delay(10);
  digitalWrite(TrigerPin,LOW);
  duration = pulseIn(ReadPin, HIGH);
  range= duration/2/29.1;
  //digitalWrite(MotorPin,HIGH);
  //digitalWrite(WorkingPin,HIGH);
  //Serial.println(range);
  if(range< threhold) DonotTouchMe();
  else Fine();
  

  delay(delayTime); 
}


void DonotTouchMe()
{
    Serial.println("Don't touch me!\n");
    Backward();
    digitalWrite(WarningLightPin,HIGH);
    digitalWrite(WorkingPin,LOW);
}


void Fine()
{
  Serial.println("Fine\n");
  Stop();
  digitalWrite(WarningLightPin,LOW);
  digitalWrite(WorkingPin,HIGH);
}

void Backward()
{
  digitalWrite(MotorPin1,HIGH);
  digitalWrite(MotorPin2,HIGH);
  digitalWrite(MotorPin3,HIGH);
  digitalWrite(MotorPin4,HIGH);
  
}
void Stop()
{
  digitalWrite(MotorPin1,LOW);
  digitalWrite(MotorPin2,LOW);
  digitalWrite(MotorPin3,LOW);
  digitalWrite(MotorPin4,LOW);
  
}

