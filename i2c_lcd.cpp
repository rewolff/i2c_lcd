/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// include core Wiring API
#include "WProgram.h"

// include this library's description file
#include "i2c_lcd.h"

// include description files for other libraries used (if any)
#include <inttypes.h>

#include "Wire.h"
#include "Print.h"


#define I2C_LCD_ADDR (0x82>>1)


LiquidCrystal::LiquidCrystal()
{
  init (I2C_LCD_ADDR);
}

LiquidCrystal::LiquidCrystal(uint8_t addr)
{
  init (addr);
}


void LiquidCrystal::init(uint8_t addr)
{
  _addr = addr;
  Wire.begin();
  begin (16, 2);
}


void LiquidCrystal::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) 
{
  _currline = 0;
  _numlines = lines;
}


void LiquidCrystal::setregval (uint8_t reg, uint8_t val)
{
  Wire.beginTransmission(_addr); // transmit to lcd
  Wire.send (reg);           // Send register
  Wire.send (val);           // send value.
  Wire.endTransmission();    // stop transmitting
}


void LiquidCrystal::clear()
{
  setregval (0x10, 0xaa /* dummy */);
}

                           
void LiquidCrystal::setCursor(uint8_t col, uint8_t row)
{
  setregval (0x11, (row << 5) | (col & 0x1f));
}

void LiquidCrystal::home()
{
  setCursor (0,0);
}


void LiquidCrystal::write(uint8_t val)
{
  setregval (0, val);
}

void LiquidCrystal::noDisplay() {
  // Not yet implemented. 
}

void LiquidCrystal::display() {
  // Not yet implemented. 
}
                           
void LiquidCrystal::noCursor() {
  // Not yet implemented. 
}
                           
void LiquidCrystal::cursor() {
  // Not yet implemented. 
}


void LiquidCrystal::noBlink() {
  // Not yet implemented. 
}
                           
void LiquidCrystal::blink() {
  // Not yet implemented. 
}

// These commands scroll the display without changing the RAM
void LiquidCrystal::scrollDisplayLeft(void) {
  // Not yet implemented. 
}
void LiquidCrystal::scrollDisplayRight(void) {
  // Not yet implemented. 
}

// This is for text that flows Left to Right
void LiquidCrystal::leftToRight(void) {
  // Not yet implemented. 
}

// This is for text that flows Right to Left
void LiquidCrystal::rightToLeft(void) {
  // Not yet implemented. 
}

// This will 'right justify' text from the cursor
void LiquidCrystal::autoscroll(void) {
  // Not yet implemented. 
}

// This will 'left justify' text from the cursor
void LiquidCrystal::noAutoscroll(void) {
  // Not yet implemented. 
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void LiquidCrystal::createChar(uint8_t location, uint8_t charmap[]) {
  // Not yet implemented. 
}


                           
