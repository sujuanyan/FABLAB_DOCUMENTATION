
int TrigerPin=9 ; // output
int ReadPin=A0; 
int delayTime=100;
int WarningLightPin=8;
int WorkingPin=13;
double threhold=15;
double duration,range;
void setup(){
  Serial.begin(9600);
  pinMode(TrigerPin,OUTPUT);
  pinMode(WarningLightPin,OUTPUT);
  pinMode(WorkingPin,OUTPUT);
}

void DonotTouchMe()
{
    digitalWrite(WarningLightPin,HIGH);
    digitalWrite(WorkingPin,LOW);
}

void Fine()
{
  digitalWrite(WarningLightPin,LOW);
  digitalWrite(WorkingPin,HIGH);
}

void loop() {
  digitalWrite(TrigerPin,HIGH);
  delay(10);
  digitalWrite(TrigerPin,LOW);
  duration = pulseIn(ReadPin, HIGH);
  range= duration/2/29.1;
  //Serial.println(range);
  if(range< threhold) DonotTouchMe();
  else Fine();
  delay(delayTime);
  
  
}
