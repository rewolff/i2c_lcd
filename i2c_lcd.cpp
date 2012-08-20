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

#include <Wire.h>
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
  _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;  
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



// Turn the display on/off (quickly)
void LiquidCrystal::noDisplay() {
  _displaycontrol &= ~LCD_DISPLAYON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::display() {
  _displaycontrol |= LCD_DISPLAYON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void LiquidCrystal::noCursor() {
  _displaycontrol &= ~LCD_CURSORON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::cursor() {
  _displaycontrol |= LCD_CURSORON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor
void LiquidCrystal::noBlink() {
  _displaycontrol &= ~LCD_BLINKON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::blink() {
  _displaycontrol |= LCD_BLINKON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM
void LiquidCrystal::scrollDisplayLeft(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}
void LiquidCrystal::scrollDisplayRight(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// This is for text that flows Left to Right
void LiquidCrystal::leftToRight(void) {
  _displaymode |= LCD_ENTRYLEFT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This is for text that flows Right to Left
void LiquidCrystal::rightToLeft(void) {
  _displaymode &= ~LCD_ENTRYLEFT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'right justify' text from the cursor
void LiquidCrystal::autoscroll(void) {
  _displaymode |= LCD_ENTRYSHIFTINCREMENT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor
void LiquidCrystal::noAutoscroll(void) {
  _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
  command(LCD_ENTRYMODESET | _displaymode);
}




// Allows us to fill the first 8 CGRAM locations
// with custom characters
void LiquidCrystal::createChar(uint8_t location, uint8_t charmap[]) {
  // Not yet implemented. 
}




inline void LiquidCrystal::command(uint8_t value) {
  setregval (1, value);
}

