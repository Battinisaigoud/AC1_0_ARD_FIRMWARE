#ifndef _EVSE_CP_IN_H
#define _EVSE_CP_IN_H
#include "stdint.h"
#include <Arduino.h>
#include <esp_adc_cal.h>
#include <esp32-hal-adc.h>

#define CP_IN_PIN (35)
// #define CP_AVR_VALUE (100)
#define CP_AVR_VALUE (250)
// #define CP_AVR_VALUE (300)//ac1_0

class CP_IN
{
public:
    uint32_t read_cp_in(void);
    // int32_t CP_IN:: read_cp_in(void)
    void read_cp_init(void);
};
#endif