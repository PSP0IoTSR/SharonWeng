//RGB 隨機
void setup(){
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
}

void loop(){
  analogWrite(15, (random(255)));
  analogWrite(16, (random(255)));
  analogWrite(17, (random(255)));
  delay(1000);
}
