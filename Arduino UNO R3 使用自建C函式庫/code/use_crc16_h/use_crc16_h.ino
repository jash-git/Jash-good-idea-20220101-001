//---
//引用純C的方法 ~ C:\Users\student(windows使用者)\Documents\Arduino\libraries\crc16
extern "C"{
#include "crc16.h"
};
//---引用純C的方法

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t data = CalculateCRC16("<09M", 4);
  String StrData="CalculateCRC16(\"<09M\", 4) = ";
  Serial.print(StrData);
  Serial.println(data);
  delay(5000);
}
