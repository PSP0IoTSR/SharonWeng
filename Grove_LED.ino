#include <Grove_LED_Bar.h>

Grove_LED_Bar b2(3,2,0);

void setup() {
  b2.begin();
}

void loop() {
  for(int i=0;i<=10;i++){
    b2.setLevel(i);
    delay(1000);
  }
  delay(1000);
}
