#include <ESP32Servo.h>
#include <MakerKit.h>

#define BLYNK_TEMPLATE_ID           "TMPL6xhzpsSCk"
#define BLYNK_DEVICE_NAME           "IOT"
#define BLYNK_AUTH_TOKEN            "TFqVtbo4elgTzCY4U5IdYYpKgX8dUVHf"


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "OPPO F11 Pro";
char pass[] = "Rfah20051984!";
BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,250);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,250);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V4)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,100);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,10);

  } else {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V1)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,100);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,100);

  } else {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,0);
    digitalWrite(18,LOW);
    digitalWrite(19,HIGH);
    analogWrite(15,0);

  }
}

BLYNK_WRITE(V5)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,100);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,10);

  } else {
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
    analogWrite(25,0);
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,0);

  }
}

Servo servo_23;
BLYNK_WRITE(V6)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    servo_23.write(90);

  } else {
    servo_23.write(0);

  }
}

BlynkTimer Timer1;

void Timer1_TimerEvent()
{
  Blynk.virtualWrite(V2, ultrasonic(12,27));
  Blynk.virtualWrite(V3, analogRead(39));
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(13,OUTPUT);
 pinMode(14,OUTPUT);
 pinMode(25,OUTPUT);
  pinMode(18,OUTPUT);
 pinMode(19,OUTPUT);
 pinMode(15,OUTPUT);
  servo_23.attach(23);
  pinMode(39, INPUT);
  Timer1.setInterval(300, Timer1_TimerEvent);

}

void loop() {
  Blynk.run();
  pinValue;

  Timer1.run();
}