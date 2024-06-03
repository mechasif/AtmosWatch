#include <Wire.h>                      
#include <LiquidCrystal_I2C.h> //https://github.com/marcoschwartz/LiquidCrystal_I2C/archive/master.zip  

LiquidCrystal_I2C lcd(0x3F,20,4);     

void setup()

{
  lcd.init();
  lcd.backlight();                
  lcd.setCursor(0,0);           
  lcd.print("Test Line 1");
  lcd.setCursor(1,0);             
  lcd.print("Test Line 2");
  lcd.setCursor(2,0);            
  lcd.print("Test Line 3");
  lcd.setCursor(3,0);             
  lcd.print("Test Line 4");
}

void loop()
{

}
