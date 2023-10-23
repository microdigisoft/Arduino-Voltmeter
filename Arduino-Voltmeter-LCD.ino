#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,16,2);

float input_voltage = 0.0;
float temp=0.0;
float r1 = 100000.00; // resistance of r1 (100K) 
float r2= 10000.00; // resistance of r2 (10K) 


void setup()
{
   Serial.begin(9600);     //  opens serial port, sets data rate to 9600 bps
   lcd.init();
     
      lcd.backlight();      //// set up the LCD's number of columns and rows: 
   lcd.print(" VOLTMETER");
}
void loop()
{
   
//Conversion formula

   int analog_value = analogRead(A0);
    temp = (analog_value * 9.0) / 1024.0; 
   input_voltage = temp / (r2/(r1+r2));
   
   if (input_voltage < 0.1) 
   {
     input_voltage=0.0;
   } 
    Serial.print("v= ");
    Serial.println(input_voltage);
    lcd.setCursor(0, 1);
    lcd.print("Voltage= ");
    lcd.print(input_voltage);
    delay(300);
}
