#include "MCP23008.h"

// MCP23008 Register Addresses
#define IODIR 0x00 // Direction register (1 = input, 0 = output)
#define GPIO 0x09  // GPIO register (reads the pin states)
#define OLAT 0x0A  // Output latch register (controls output pins)

MCP23008 mcp(0x27); // Create MCP23008 object with default address 0x27

// Constructor
MCP23008::MCP23008(uint8_t address)
{
    _address = address;
}

// Initialize I2C and MCP23008
void MCP23008::begin()
{
    Wire.begin(21, 22);         // ESP32: SDA = GPIO 21, SCL = GPIO 22
    writeRegister(IODIR, 0xFF); // Set all pins as inputs by default
}

// Set pin mode
void MCP23008::pinMode(uint8_t pin, uint8_t mode)
{
    uint8_t iodir = readRegister(IODIR);
    if (mode == OUTPUT)
    {
        iodir &= ~(1 << pin); // Clear the bit for output
    }
    else
    {
        iodir |= (1 << pin); // Set the bit for input
    }
    writeRegister(IODIR, iodir);
}

// Write HIGH or LOW to a pin
void MCP23008::digitalWrite(uint8_t pin, uint8_t value)
{
    uint8_t olat = readRegister(OLAT);
    if (value == HIGH)
    {
        olat |= (1 << pin); // Set the pin HIGH
    }
    else
    {
        olat &= ~(1 << pin); // Set the pin LOW
    }
    writeRegister(OLAT, olat);
}

// Read the state of a pin
uint8_t MCP23008::digitalRead(uint8_t pin)
{
    uint8_t gpio = readRegister(GPIO);
    return (gpio & (1 << pin)) ? HIGH : LOW;
}

// Write to a MCP23008 register
void MCP23008::writeRegister(uint8_t reg, uint8_t value)
{
    Wire.beginTransmission(_address);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

// Read from a MCP23008 register
uint8_t MCP23008::readRegister(uint8_t reg)
{
    Wire.beginTransmission(_address);
    Wire.write(reg);
    Wire.endTransmission();

    Wire.requestFrom(_address, (uint8_t)1);
    return Wire.read();
}
