#include "Nokia-5110-LCD/Nokia5110.h"
#include "screen.h"
#include "screens/watchface.h"
#include "pins.h"

int main() {
    Nokia5110 lcd(LCD_CE, LCD_RST, LCD_DC, LCD_MOSI, LCD_CLK);
    lcd.init(0x2C, 4);
    lcd.clear_buffer();
    Watchface watchface(&lcd);
    watchface.draw();
}
