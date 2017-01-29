#include "pins.h"
#include "peripherals.h"
#include "datetime.h"
#include <Nokia5110.h>
#include <BQ32000.h>
#include <mbed.h>

namespace OSHWatch {

Nokia5110 *display = new Nokia5110(LCD_CE, LCD_RST, LCD_DC, LCD_MOSI, LCD_CLK);
BQ32000   *rtc     = new BQ32000(SDA, SCL);
}
