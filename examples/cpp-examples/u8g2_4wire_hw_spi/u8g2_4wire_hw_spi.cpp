#include <U8g2lib.h>
#include <wiringPi.h>

// By default, SPI bus /dev/spidev0.0 is used, as defined in port/U8g2lib.h
//#define OLED_SPI_PIN_RES            25
//#define OLED_SPI_PIN_DC             24

#define OLED_SPI_PIN_RES           13
#define OLED_SPI_PIN_DC  		16 

// CS pin is controlled by linux spi driver
//#define OLED_SPI_PIN_CS             8
#define OLED_SPI_PIN_CS            15 

// Check https://github.com/olikraus/u8g2/wiki/u8g2setupcpp for all supported devices
static U8G2_SSD1306_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0,
                                          /* cs=*/ OLED_SPI_PIN_CS,
                                          /* dc=*/ OLED_SPI_PIN_DC,
                                          /* reset=*/ OLED_SPI_PIN_RES);
                                          // same as the NONAME variant, but may solve the "every 2nd line skipped" problem

int main()
{
	wiringPiSetup();
    u8g2.begin();
    u8g2.clearBuffer();                         // clear the internal memory
    u8g2.setFont(u8g2_font_6x13_tr);            // choose a suitable font
    u8g2.drawStr(1, 18, "U8g2 on HW SPI");   // write something to the internal memory
    u8g2.sendBuffer();                          // transfer internal memory to the display
    u8g2.setFont(u8g2_font_unifont_t_symbols);
    u8g2.drawGlyph(112, 56, 0x2603 );
    u8g2.sendBuffer();
}
