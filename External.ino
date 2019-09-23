boolean led;
void setup() {
  led = true;
  pinMode(2,OUTPUT);
}

void loop() {
  if(led){
    led = false;
    digitalWrite(2,HIGH);
    printf("LED 亮");
  }else{
    led = true;
    digitalWrite(2,LOW);
    printf("LED　暗");
  }
  delay(1000);
}
