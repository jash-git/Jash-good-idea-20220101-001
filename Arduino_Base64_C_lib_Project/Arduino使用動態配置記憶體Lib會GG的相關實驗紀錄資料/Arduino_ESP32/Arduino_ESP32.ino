extern "C"{
#include "Arduino_Base64_C_lib.h"
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  char inputbuf []="123456789";
  int output_len;
  output_len = b64_encode (inputbuf, (sizeof(inputbuf)-1));
  char outputbuf[output_len];
  get_encode(outputbuf);
  Serial.print("Encoded string is:\t");
  Serial.println(outputbuf);  
  delay(5000);  
}
