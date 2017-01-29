#ifndef OSHWATCH_PERIPHERALS_H
#define OSHWATCH_PERIPHERALS_H

#include "datetime.h"
#include <Nokia5110.h>
#include <BQ32000.h>
#include <mbed.h>

namespace OSHWatch {

extern Nokia5110   *display;
extern BQ32000     *rtc;

extern datetime_t  *curr_datetime;
}

#endif //OSHWATCH_PERIPHERALS_H
