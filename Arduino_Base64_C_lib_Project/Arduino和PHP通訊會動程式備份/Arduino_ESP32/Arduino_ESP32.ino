/*
  Rui Santos
  Complete project details at Complete project details at https://RandomNerdTutorials.com/esp32-http-get-post-arduino/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <WiFi.h>
#include <HTTPClient.h>

int value = 0;
const char* ssid = "jash_TStar";
const char* password = "asd700502";

//Your Domain name with URL path or IP address with path
String serverName = "http://192.168.0.191:8080/jash_web/val2DB.php";
//String serverName = "http://192.168.0.191:8080/php_code/val.php";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;

void setup() {
  Serial.begin(115200); 

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

    value=random(10,50);
    String serverPath = serverName;
    serverPath += "?string=";
    serverPath += value;
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        //Serial.print("HTTP Response code: ");
        //Serial.println(httpResponseCode);
        String line = http.getString();
        Serial.println(line);
        int index=line.indexOf("get data=");//搜尋資料列
        if(index!=-1)
        {
          //----
          //過濾不需要資料
          int value=line.length();
          char Buf[100];
          line.toCharArray(Buf, 100);
          line="";      
          //Serial.println(value);
          for(int i=0;i<value;i++)
          {
            if((Buf[i]>=48)&&(Buf[i]<=57))//只留數字範圍
            {
              line+=Buf[i];
            }
          }
          //----過濾不需要資料
          switch(line.toInt())
          {
            case 0:
              Serial.println("Red on & Green off");
              //digitalWrite(Red, HIGH);
              //digitalWrite(Green,LOW);
              break;
            case 1:
              Serial.println("Red off & Green on");
              //digitalWrite(Red, LOW);
              //digitalWrite(Green,HIGH);          
            break;  
          }//switch
        }//if(index!=-1)      
      }//if (httpResponseCode>0)
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
