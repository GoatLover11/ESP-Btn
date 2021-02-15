
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Hiba!
#endif

BluetoothSerial SerialBT;

const int pushBtn [] = {1};         //megfelelő bekötés
const int switchBtn [] = {1};       //megfelelő bekötés

void setup() {
  
  Serial.begin(115200);
  SerialBT.begin("ESP_Button_Core");
  Serial.println("Start!");
  SerialBT.write("Start!");

  for (int i = 0; i < sizeof(pushBtn); i++)
  {
    pinMode(pushBtn[i], OUTPUT);
  }

  for (int i = 0; i < sizeof(switchBtn); i++)
  {
    pinMode(switchBtn[i], OUTPUT);
  }
  
}

void loop() {

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }

  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }

  int pushBtnS [] = {1};          //megfelelő bekötés
  int switchBtnS [] = {1};        //megfelelő bekötés
    
  for (int i = 0; i < sizeof(pushBtn); i++)
  {
    pushBtnS [i] = digitalRead(pushBtn [i]);
    SerialBT.write(pushBtnS [i]);
  }

  for (int i = 0; i < sizeof(switchBtn); i++)
  {
    switchBtnS [i] = digitalRead(switchBtn [i]);
    SerialBT.write(switchBtnS [i]);
  }

  delay(20);
}

