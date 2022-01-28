/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <ESP8266WiFi.h>

const char* ssid     = "jash_TStar";
const char* password = "asd700502";

const char* host = "192.168.0.191";
const char* streamId   = "....................";
const char* privateKey = "....................";

int Blue=D4;//D4 有連接WIFI指示燈
int Green=D5;//D5 命令對應燈
int Red=D6;//D6 命令對應燈


void setup() {
  //---
  //設定燈號腳位工作模式
  pinMode(Blue, OUTPUT); 
  pinMode(Green, OUTPUT); 
  pinMode(Red, OUTPUT); 
  //---設定燈號腳位工作模式
  
  //---
  //等待取得網路IP時，設定三燈全亮
  digitalWrite(Blue, HIGH);
  digitalWrite(Green, HIGH);
  digitalWrite(Red, HIGH);
  //---等待取得網路IP時，設定三燈全亮
  Serial.begin(9600);
  delay(50);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(50);
    Serial.print(".");
  }
  
  //---
  //取得網路IP時，所有燈熄滅
  digitalWrite(Blue, LOW);//digitalWrite(Blue, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Red, LOW);
  //---取得網路IP時，所有燈熄滅
  
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
}

int value = 0;

void loop() {
  value=random(10,50);

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 8080;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    client.stop();
    digitalWrite(Blue, HIGH);
    return;
  }
  else
  {
    digitalWrite(Blue, LOW);
  }
  
  // We now create a URI for the request
  //String url = "/php_code/val.php";
  String url = "/jash_web/val2DB.php";
  url += "?string=";
  url += value;
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
               
  unsigned long timeout = millis();
  while (client.available() == 0) 
  {
    if (millis() - timeout > 5000)
    {
      
      Serial.println(">>> Client Timeout(5sec)!");
      Serial.println("");
      client.stop();
      digitalWrite(Blue, HIGH);
      return;
    }
    else
    {
      digitalWrite(Blue, LOW);
    }
  }
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available())
  {
    String line = client.readStringUntil('\r');
    int index=line.indexOf("get data=");//搜尋資料列
    if(index!=-1)
    {
      digitalWrite(Blue, LOW);
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
          digitalWrite(Red, HIGH);
          digitalWrite(Green,LOW);
          break;
        case 1:
          Serial.println("Red off & Green on");
          digitalWrite(Red, LOW);
          digitalWrite(Green,HIGH);          
          break;  
      }
      break;
    }   
  }
  
  client.stop();
  Serial.println("closing connection");
  Serial.println("");
  delay(1000);  
}
