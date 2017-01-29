#include "Mainscreen.h"

namespace OSHWatch {

Mainscreen::Mainscreen() {
    _watchface = Watchface();
}

void Mainscreen::draw() {
    _watchface.draw();
}

void Mainscreen::processInput(uint8_t button) {
}
}
