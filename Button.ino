void setup(){
  pinMode(2, INPUT); //按鈕腳位
  Serial.begin(9600);
  pinMode(8, OUTPUT); //LED腳位8
}

void loop(){
  if (HIGH == digitalRead(2)) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
  delay(100);
}
