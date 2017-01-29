#ifndef OSHWATCH_MAINSCREEN_H
#define OSHWATCH_MAINSCREEN_H

#include "Screen.h"
#include "Watchface.h"

namespace OSHWatch {

class Mainscreen : public Screen {
public:
    Mainscreen();

    void draw();

    void processInput(uint8_t button);

private:
    Watchface _watchface;
};
}
#endif //OSHWATCH_MAINSCREEN_H
