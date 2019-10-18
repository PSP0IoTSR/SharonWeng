#include <LRemote.h>
#include <SPI.h>
#include <MFRC522.h>

//RFID pin p10-13
int SetPasswd = 1019; //You can set the number
int PhonePasswd = 0; //Input number
int c = 0; //input count
int Led = 2; //led pin is P2
int Buzzer = 3; //bzz pin is P3

String S1 = "   *   ";
String S2 = "  **   ";
String S3 = "  ***  ";
String S4 = " **** ";
String RFIDON = "";
String RFID[] = {"6678DFdf34"}; //Read RFID　and write ,讀完RFID知道卡片的ID，在寫入這個ID庫

LRemoteLabel label1;
LRemoteButton button0;
LRemoteButton button1;
LRemoteButton button2;
LRemoteButton button3;
LRemoteButton button4;
LRemoteButton button5;
LRemoteButton button6;
LRemoteButton button7;
LRemoteButton button8;
LRemoteButton button9;
LRemoteButton button10;

MFRC522 rfid(/*SS_PIN*/ 10, /*RST_PIN*/ UINT8_MAX);

String mfrc522_readID() {
  String ret;
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
    for (byte i = 0; i < rfid.uid.size; i++) {
      ret += (rfid.uid.uidByte[i] < 0x10 ? "0" : "");
      ret += String(rfid.uid.uidByte[i], HEX);
    }
  }
  // Halt PICC
  rfid.PICC_HaltA();
  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  return ret;
}

void setup() {
  SPI.begin();
  rfid.PCD_Init();
  Serial.begin(9600);

  pinMode(Led, OUTPUT);
  digitalWrite(Led, LOW);
  pinMode(Buzzer, OUTPUT);

  //Remote use interface
  LRemote.setName("7697-1");
  LRemote.setOrientation(RC_PORTRAIT);
  LRemote.setGrid(3, 5);

  label1.setPos(0, 0);
  label1.setText("Input Password");
  label1.setSize(3, 1);
  label1.setColor(RC_ORANGE);
  LRemote.addControl(label1);

  button1.setPos(0, 1);
  button1.setText("1");
  button1.setSize(1, 1);
  button1.setColor(RC_BLUE);
  LRemote.addControl(button1);

  button2.setPos(1, 1);
  button2.setText("2");
  button2.setSize(1, 1);
  button2.setColor(RC_GREEN);
  LRemote.addControl(button2);

  button3.setPos(2, 1);
  button3.setText("3");
  button3.setSize(1, 1);
  button3.setColor(RC_BLUE);
  LRemote.addControl(button3);

  button4.setPos(0, 2);
  button4.setText("4");
  button4.setSize(1, 1);
  button4.setColor(RC_GREEN);
  LRemote.addControl(button4);

  button5.setPos(1, 2);
  button5.setText("5");
  button5.setSize(1, 1);
  button5.setColor(RC_BLUE);
  LRemote.addControl(button5);

  button6.setPos(2, 2);
  button6.setText("6");
  button6.setSize(1, 1);
  button6.setColor(RC_GREEN);
  LRemote.addControl(button6);

  button7.setPos(0, 3);
  button7.setText("7");
  button7.setSize(1, 1);
  button7.setColor(RC_BLUE);
  LRemote.addControl(button7);

  button8.setPos(1, 3);
  button8.setText("8");
  button8.setSize(1, 1);
  button8.setColor(RC_GREEN);
  LRemote.addControl(button8);

  button9.setPos(2, 3);
  button9.setText("9");
  button9.setSize(1, 1);
  button9.setColor(RC_BLUE);
  LRemote.addControl(button9);


  button0.setPos(0, 4);
  button0.setText("0");
  button0.setSize(1, 1);
  button0.setColor(RC_GREEN);
  LRemote.addControl(button0);

  button10.setPos(1, 4);
  button10.setText("Clear");
  button10.setSize(2, 1);
  button10.setColor(RC_ORANGE);
  LRemote.addControl(button10);
  LRemote.begin();
}


void loop() {
  RFIDON = mfrc522_readID();
  if (RFIDON != "") {
    Serial.println("read");
    Serial.print("Code is:");
    Serial.println(RFIDON);
    delay(500);
  }

  //Remote code
  LRemote.process();
  if (button0.isValueChanged()) {
    if (button0.getValue() == 1) {
      c++;
      if (c == 1) {
        PhonePasswd = PhonePasswd + 1;
      }
    }
  } else if (button1.isValueChanged()) {
    if (button1.getValue() == 1) {
      c++;
      if (c == 2) {
        PhonePasswd = PhonePasswd + 2;
      }
    }
  } else if (button2.isValueChanged()) {
    if (button2.getValue() == 1) {
      c++;
      if (c == 3) {
        PhonePasswd = PhonePasswd + 3;
      }
    }
  } else if (button3.isValueChanged()) {
    if (button3.getValue() == 1) {
      c++;
      if (c == 4) {
        PhonePasswd = PhonePasswd + 4;
      }
    }
  } else if (button4.isValueChanged()) {
    if (button4.getValue() == 1) {
      c++;
    }
  } else if (button5.isValueChanged()) {
    if (button5.getValue() == 1) {
      c++;
    }
  } else if (button6.isValueChanged()) {
    if (button6.getValue() == 1) {
      c++;
    }
  } else if (button7.isValueChanged()) {
    if (button7.getValue() == 1) {
      c++;
    }
  } else if (button8.isValueChanged()) {
    if (button8.getValue() == 1) {
      c++;
    }
  } else if (button9.isValueChanged()) {
    if (button9.getValue() == 1) {
      c++;
    }
  } else if (button10.isValueChanged()) {
    if (button10.getValue() == 1) {
      label1.updateText("Input Psaawd");
      c = 0;
      PhonePasswd = 0;
    }
  }
  if (c == 1) {
    label1.updateText(String(S1));
  } else if (c == 2) {
    label1.updateText(String(S2));
  } else if (c == 3) {
    label1.updateText(String(S3));
  } else if (c == 4) {
    label1.updateText(String(S4));
    delay(500);
    if (SetPasswd == PhonePasswd) {
      label1.updateText("Opening Door");
      digitalWrite(Led, HIGH);
      delay(5000);
      digitalWrite(Led, LOW);
      for (int i = 0; i < 10; i++) {
        tone(Buzzer, 500);
        delay(50);
      }
    } else {
      label1.updateText("Passwd Error");
      label1.setColor(RC_PINK);
      for (int i = 0; i < 10; i++) {
        tone(Buzzer, 1000);
        delay(50);
      }
      delay(5000);
    }
    label1.updateText("Input Psaawd");
    c = 0;
    PhonePasswd = 0;
  }

  //RFID code
  for (int i = 0; i < sizeof(RFID)+1; i++) {
    if (RFIDON == RFID[i]) {
      label1.updateText("Opening Door");
      digitalWrite(Led, HIGH);
      delay(5000);
      digitalWrite(Led, LOW);
      for (int i = 0; i < 10; i++) {
        tone(Buzzer, 500);
        delay(50);
      }
    } else {
      label1.updateText("Illegal card");
      label1.setColor(RC_PINK);
      for (int i = 0; i < 10; i++) {
        tone(Buzzer, 1000);
        delay(50);
      }
      delay(5000);
    }
  }
   delay(1000);
}
