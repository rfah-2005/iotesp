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
#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0xff0000);
    pixels.setPixelColor(1, 0xff0000);
    pixels.setPixelColor(2, 0xff0000);
    pixels.setPixelColor(3, 0xff0000);
    pixels.setPixelColor(4, 0xff0000);
    pixels.show();
    pixels.show();

  }
}

BLYNK_WRITE(V1)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0x3366ff);
    pixels.setPixelColor(1, 0x3366ff);
    pixels.setPixelColor(2, 0x3366ff);
    pixels.setPixelColor(3, 0x3366ff);
    pixels.setPixelColor(4, 0x3366ff);
    pixels.show();
    pixels.show();

  }
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pixels.begin();

}

void loop() {
  Blynk.run();
}