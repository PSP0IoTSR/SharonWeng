//可變電阻控制電壓輸出
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(14));
  delay(2000);
}
