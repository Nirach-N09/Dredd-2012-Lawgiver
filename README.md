# Dredd-2012-Lawgiver
Arduino code for a Dredd Lawgiver with addressable LED, 256x64 SH1122 OLED, and a button for ammo alteration
Primarily using OliKraus' u8g2 library, fastled used for the addressable led

The font choices are best guesses, and could possibly be improved upon.

It should be self explanitory code wise - I'm pretty new to it all, so it won't be complex.

256x64 Screen pin mapping

GND
VCC
SCL	D10
SDA	D9
RES	D13
DC	D11
CS	D12

Screen info

1. LCD Size: 2.08 inches
2. Dot Matrix Size: 256*64
3. LCD Color: Blue
4. Hardware Interface: IIC interface, SPI interface
5. Driver IC: SH1122
6. Operating Temperature: -40 - 70
8. Working Power Supply: 3.3V
9. PIN NO.: 7P
10. Display Area: 51.18*12.78mm
11. Size: 72.5*27.24mm

  
LED Pin mapping (WS2812 RGB)
GND	GND
Din	D2
5V	5V


Button Pin Mapping (4pin)
RED	5v
BLK	GND
GRN	D3
