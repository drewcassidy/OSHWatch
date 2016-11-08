#include "../screen.h"
#include "watchface.h"

Watchface::Watchface(Nokia_5110* display) {
    _display = display;
}

void Watchface::draw() {
    _display->drawWBitmap(Digit0, 5, 5);
    _display->display();
}

const uint8_t* Watchface::getDigit(uint8_t value) {
    switch(value) {
        default:
        case 0: return Digit0;
                break;
        case 1: return Digit1;
                break;
        case 2: return Digit2;
                break;
        case 3: return Digit3;
                break;
        case 4: return Digit4;
                break;
        case 5: return Digit5;
                break;
        case 6: return Digit6;
                break;
        case 7: return Digit7;
                break;
        case 8: return Digit8;
                break;
        case 9: return Digit9;
                break;
    }
}

void Watchface::processInput(uint8_t button) {

}
