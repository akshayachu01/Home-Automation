#include<ESP8266WiFi.h>
WiFiServer abc(80);
void setup()
{ 
  Serial.begin(9600);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
  WiFi.mode(WIFI_AP);
  WiFi.softAP("user","87654321");
  Serial.println(WiFi.softAPIP());
  // put your setup code here, to run onc
  
  abc.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient Client1;
 while((Client1=abc.available())==0);
 Serial.println(Client1.remoteIP());
while(Client1.connected()==1&&Client1.available()==0)
{
  delay(10);
}



String request=Client1.readStringUntil('\r');
Serial.println(request);
if(request.indexOf("on1")!=-1)
digitalWrite(4,HIGH);
else if(request.indexOf("off1")!=-1)
digitalWrite(4,LOW);
if(request.indexOf("on2")!=-1)
digitalWrite(5,HIGH);
else if(request.indexOf("off2")!=-1)
digitalWrite(5,LOW);
}
