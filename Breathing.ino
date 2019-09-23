int led;
int f;
void setup() {
  pinMode(2,OUTPUT);
  led = 0;
  f = -5;
  digitalWrite(2,LOW);
  Serial.begin(9600);
}

void loop() {
  analogWrite(2,led);
  led = led+f;
  if(led<=0){
    f = 5;
  }else if(led>=255){
    f = -5;
  }
  Serial.print(led);
  delay(20);
}
