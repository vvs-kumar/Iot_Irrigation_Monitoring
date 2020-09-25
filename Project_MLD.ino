#include <LiquidCrystal.h>
/* Create object named lcd of the class LiquidCrystal */
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);  /* For 8-bit mode */
//LiquidCrystal lcd(9, 8, 7, 6, 5, 4, 3);  /* For 4-bit mode */

unsigned char Character1[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F }; /* Custom Character 1 */
unsigned char Character2[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 }; /* Custom Character 2 */

int Moisture=0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
 lcd.begin(16,2);  /* Initialize 16x2 LCD *//* Clear the LCD */
 lcd.setCursor(0,0);
 lcd.print("IOT IRRIGATION ");
 lcd.setCursor(0,1);
 lcd.print("MONITORING AND");
 delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
 lcd.print("CONTROLLING");
 delay(1000);
  // put your setup code here, to run once:

}


void loop() 
{
  Moisture=digitalRead(A0);
  Serial.println(Moisture);
  if(Moisture==0)
  {
    Serial.println("Moisture is present");
    digitalWrite(2,LOW);
  lcd.clear();
  lcd.setCursor(0,0); /* Set cursor to column 0 row 0 */
  lcd.print("Moisture is "); /* Print data on display */
  lcd.setCursor(0,1);  
  lcd.print("Present Fan OFF");
  }

    else
    {Serial.println("Moisture is ");
  digitalWrite(2,HIGH);
   lcd.clear();
  lcd.setCursor(0,0); /* Set cursor to column 0 row 0 */
  lcd.print("Moisture is "); /* Print data on display */
  lcd.setCursor(0,1);  
  lcd.print("absent Fan ON");
  }
  
  // put your main code here, to run repeatedly:

}
