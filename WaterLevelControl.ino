const int relay = 4;//Relay Module
const int trigPin = 9;
const int echoPin = 10;
const int buz = 7;//Buzzer
const int re = A0;//To give analog signals.
const int val = 2;//To find presents of water in pipe by reading value from A0.

long duration; 
int distance;
int count=0;
int read;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(re, INPUT);
  pinMode(val, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(count==30){
    read = analogRead(re);
    if(read<800){
    digitalWrite(relay, LOW);
  Serial.println("Relays OFF");
  for(count = 0; count < 30 ; count++)
  {
  digitalWrite(buz, HIGH);
  delay(1000);
  }}
  count=0;
  digitalWrite(buz, LOW);
  }else{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(buz, LOW);
  digitalWrite(val, HIGH);


  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance<=25){//Distance when motor need to ON.
  digitalWrite(relay, HIGH);
  Serial.println("Relays ON");
  count++;
  read = analogRead(re);
    Serial.println(read);
  }
  else if(distance>=40){//Distance when motor need to OFF.
  digitalWrite(relay, LOW);
  Serial.println("Relays OFF");
  count=0;
  }
  delay(2000);}
}
