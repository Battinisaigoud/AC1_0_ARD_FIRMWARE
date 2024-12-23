/*******************************************************************************
 *
 * program : evse_gfci.cpp
 * author  :rakesh & pream
 *
 *
 * Description :
 *
 *
 *******************************************************************************/


#include "evse_cp_in.h"


void CP_IN::read_cp_init(void)
{

  analogReadResolution(12);
  // Optional for ESP32: Set the resolution to 9-12 bits (default is 12 bits)
  // analogContinuousSetWidth(12);
  pinMode(CP_IN_PIN, INPUT);  //GPIO35
  // Optional: Set different attenaution (default is ADC_11db)
  // analogContinuousSetAtten(ADC_11db);
  adcAttachPin(CP_IN_PIN);    //GPIO35
}

uint32_t CP_IN::read_cp_in(void)
{
#if 1
  int ADC_Result = 0;
  for (uint16_t index = 0; index < CP_AVR_VALUE; index++)
  {

    // ADC_Result += analogRead(CP_IN_PIN);
    ADC_Result += adc1_get_raw(ADC1_CHANNEL_7);
    delayMicroseconds(10); // pauses for 10 microseconds
  }
#endif

  //  return analogRead(CP_IN_PIN);
#if 1
  ADC_Result = (ADC_Result / CP_AVR_VALUE);
  return (uint32_t)ADC_Result;
#endif
}
