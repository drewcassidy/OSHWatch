#include "mbed-nokia-5110-lcd/Nokia_5110.h"

void app_start(int, char *[]) {
    Nokia_5110 lcd(LCD_CE, LCD_RST, LCD_DC, LCD_MOSI, LCD_CLK);
    lcd.init(0x30, 4);
    lcd.clearBuffer();
    lcd.printString("Hello", 0, 0);
    lcd.printString("World!", 3, 9);
    lcd.display();
}