extern "C"{
#include "Arduino_Base64_C_lib.h"
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char inputbuf []="123456789";
  int output_len;
  char *outputbuf='\0';
  int output_len01;
  char *outputbuf01='\0';
  output_len = b64_encode (inputbuf, (sizeof(inputbuf)-1));// (sizeof(inputbuf)-1) 不要計算字串結束符號
  outputbuf = (char *) malloc(sizeof(char) * output_len);
  get_encode(outputbuf);  
  Serial.print("Encoded string is:\t");
  Serial.println(inputbuf);  
  delay(5000);  
}

