#define trig 2
#define echo 4
long time;
int distance;
const int ledPin = 12;
const int ldrPin = A2;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(irdoor,INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(irwindow,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


digitalWrite(trig,HIGH);
    delayMicroseconds (10);
    digitalWrite (trig, LOW);
    time = pulseIn (echo, HIGH);
    distance = (time * 0.034) / 2;
  if (distance > 150) 
  { 

    digitalWrite(buzz,HIGH);
    delay(50);
  }
  else {
    digitalWrite(buzz,LOW);
    delay(50);

  }
 Serial.println(distance);
 delay(100);
  int ldrStatus = analogRead(ldrPin);
 if (ldrStatus >450  || (digitalRead(irdoor)==1 && digitalRead(irwindow)==1 )) {
  digitalWrite(buzz,HIGH);
  Serial.println(ldrStatus);
}
 else if(ldrStatus <400 ||(digitalRead(irdoor)==1 && digitalRead(irwindow)==1 )){
     digitalWrite(buzz,LOW);
     Serial.println(ldrStatus);
}
}
