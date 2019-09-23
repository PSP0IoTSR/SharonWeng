//兩顆LED 輪流亮
boolean led;
void setup() {
  led = true;
  pinMode(2,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  if(led){
    led = false;
    digitalWrite(2,HIGH);
    digitalWrite(8,LOW);
  }else{
    led = true;
    digitalWrite(2,LOW);
    digitalWrite(8,HIGH);
  }
  delay(1000);
}
