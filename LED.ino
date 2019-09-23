boolean led;

void setup(){
  led = true;
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (led) {
    digitalWrite(0, HIGH);
    led = false;
    Serial.println("LED ON");
  } else {
    digitalWrite(0, LOW);
    led = true;
    Serial.println("LED OFF");
  }
  delay(1000);
}
