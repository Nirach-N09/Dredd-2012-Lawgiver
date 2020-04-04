//u8g2 provided by OliKraus - github.com/olikraus/u8g2

#include <FastLED.h>
#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>
#include <Wire.h>

#define LED_PIN 2
#define NUM_LEDS 1
#define BRIGHTNESS 50
#define LED_TYPE WS2812
CRGB leds[NUM_LEDS];
int lbar = 1;
boolean idcheck = true;
unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 4500;
//Button counter STATIC
const int buttonPin = 3;
//Button counter VARIABLE
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;
int FMJCounter = 25;


U8G2_SH1122_256X64_1_4W_SW_SPI u8g2(U8G2_R2, 10, 9, 12, 11, 13);

void setup(void)
{
  u8g2.begin();
  FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS );
  startMillis = millis();
  //FMJ counter button
  pinMode(buttonPin, INPUT);
}

void loop(void)
{
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState)
  {
    if (buttonState == LOW && idcheck == false)
    {
      FMJCounter--;
    }
  }
  lastButtonState = buttonState;
  if (FMJCounter == 0) FMJCounter = 25;
  currentMillis = millis();
 
  u8g2.firstPage();
  do {
    u8g2.setFontMode(0);
    u8g2.setDrawColor(1);
    //ID Check bar
    if (idcheck == true)
    {
      lbar++;
      if (lbar > 100)  lbar = 0, boolean (idcheck = false);
      u8g2.drawBox (1, 1, lbar, 15);
    }
    // ID Check LED
    if (idcheck == true)
    {
      leds[0] = CRGB(0, 255, 0);
      FastLED.show();
    }
    if (idcheck == false)
    {
      leds[0] = CRGB(255, 0, 0);
      FastLED.show();
    }
    //Text
    u8g2.setFont(u8g2_font_crox3hb_tf);
    u8g2.setCursor(2, 44);
    if (idcheck == true)
    {
      u8g2.print("DNA CHECK");
    }
    else if (currentMillis - startMillis <= period && idcheck == false)
    {
      u8g2.print("I.D OK");
    }
    u8g2.setFont(u8g2_font_crox3h_tf);
    u8g2.setCursor(188, 46);
    u8g2.print("SEMI");
    //horizontal line
    u8g2.drawLine(1, 49, 255, 49);
    //vertical lines bottom
    u8g2.drawLine(40, 63, 40, 49);
    u8g2.drawLine(75, 63, 75, 49);
    u8g2.drawLine(110, 63, 110, 49);
    u8g2.drawLine(145, 63, 145, 49);
    //angled lines top right
    u8g2.drawLine(208, 1, 205, 14);
    u8g2.drawLine(209, 1, 206, 14);
    u8g2.drawLine(211, 1, 208, 14);
    u8g2.drawLine(212, 1, 209, 14);
    u8g2.drawLine(214, 1, 211, 14);
    u8g2.drawLine(215, 1, 212, 14);
    u8g2.drawLine(217, 1, 214, 14);
    u8g2.drawLine(218, 1, 215, 14);
    //TEXT
    u8g2.setFont(u8g2_font_7x13_tf);
    //Distance-TEXT
    u8g2.setCursor(4, 62);
    u8g2.print("D:");
    //AP-TEXT
    u8g2.setCursor(58, 62);
    u8g2.print("ap");
    //IN-TEXT
    u8g2.setCursor(94, 62);
    u8g2.print("in");
    //HE-TEXT
    u8g2.setCursor(129, 62);
    u8g2.print("he");
    //DISTANCE-NUM
    u8g2.setCursor(17, 62);
    u8g2.print("0.0");
    //AP-NUM
    u8g2.setCursor(43, 62);
    u8g2.print("25");
    //IN-NUM
    u8g2.setCursor(78, 62);
    u8g2.print("25");
    //HE-NUM
    u8g2.setCursor(113, 62);
    u8g2.print("25");
    //FMJ
    u8g2.setFontMode(1);
    u8g2.setDrawColor(1);
    u8g2.drawBox(146, 49, 255, 64);
    u8g2.setFont(u8g2_font_7x13_tf);
    u8g2.setCursor(148, 62);
    u8g2.setDrawColor(0);
    u8g2.print(FMJCounter);
    u8g2.setCursor(164, 61);
    u8g2.setDrawColor(0);
    u8g2.print("fmj");

  }
  while (u8g2.nextPage() );

}
