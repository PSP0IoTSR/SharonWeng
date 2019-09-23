//可變電阻控制電壓輸出數值
int pin;
void setup() {
  Serial.begin(9600);
}

void loop() {
  pin = analogRead(14)*2500+4096;
  Serial.println("輸入電壓:");
  Serial.println(pin);
  Serial.println("mV");
  delay(2000);
}
