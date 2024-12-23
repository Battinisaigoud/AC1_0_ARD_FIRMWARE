#ifndef MCP23008_H
#define MCP23008_H

#include <Arduino.h>
#include <Wire.h>

#define EMERGENCY_PIN (2)
#define EARTH_PRESENCE_PIN (3)
#define BUZZER_PIN (4)
#define RELAY_DROP_PIN (6)
#define BATTERY_CONTROL (5)

class MCP23008
{
public:
    MCP23008(uint8_t address = 0x27);              // Default I2C address
    void begin();                                  // Initialize the I2C interface and MCP23008
    void pinMode(uint8_t pin, uint8_t mode);       // Set pin mode (INPUT or OUTPUT)
    void digitalWrite(uint8_t pin, uint8_t value); // Write HIGH or LOW to a pin
    uint8_t digitalRead(uint8_t pin);              // Read the state of a pin (HIGH or LOW)

private:
    uint8_t _address;                               // I2C address of MCP23008
    void writeRegister(uint8_t reg, uint8_t value); // Write to a MCP23008 register
    uint8_t readRegister(uint8_t reg);              // Read from a MCP23008 register
};

extern MCP23008 mcp; // Create MCP23008 object with default address 0x27

#endif
