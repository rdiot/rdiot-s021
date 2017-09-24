/* Multifunctional Digital Temperature Sensor Module LM393 (KY-028) [S021] : http://rdiot.tistory.com/49 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int bitNTCsensor = A0;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
  
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("S021:KY-028");
 
  int realVal = analogRead(bitNTCsensor);
  double temp = Thermistor(realVal);
 
  lcd.setCursor(0,1);
  lcd.print("Analog=" + (String)realVal);
 
  lcd.setCursor(0,2);
  lcd.print("Temperature=" + (String)temp + "'C");
 
  delay(1000); 
}
 
double Thermistor(int RawADC) {
  double Temp;
  Temp = log(10000.0 * ((1024.0/RawADC-1)));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
  Temp = Temp - 273.15;
  //Temp = (Temp *9.0) /5.0 + 32.0;
  return Temp;
}
