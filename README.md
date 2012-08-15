
This implements the "LiquidCrystal" library for the i2c_lcd
boards that BitWizard produces. 

See: 
   http://www.arduino.cc/en/Hacking/Libraries
for info on where to put this library directory. 
It is ~/sketchbook/libraries under Linux. 

Not all functions are implemented yet. Things like blinking cursors 
and not blanking are not yet implemented. 

Neither are extra features like adjusting the contrast and the
backlight intensity. 

To use: 

change 

  #include &lt;LiquidCrystal.h>

into

  #include &lt;i2c_lcd.h>

(for those reading this in plaintext in a cloned repository, the
&lt; is a less than sign, which is written that way to display correctly
on github.)

and change
  LiquidCrystal lcd (......);
into
  LiquidCrystal lcd;




