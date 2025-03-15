//Default PASSWORD is 942
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <LCD_I2C.h>
//Attach Red LED to Arduino Pin #12
//Attach Green LED to Arduino Pin #13
//After Lock is Open Press * / # / Start / Stop to LOCK again



//===========================================================================

char* password = "942";  // Set your password here, just pick any 3 numbers

//===========================================================================



int position = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int RedpinLock = 11;
int GreenpinUnlock = 10;

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
 lcd.init();
 lcd.backlight();
pinMode(RedpinLock, OUTPUT);
pinMode(GreenpinUnlock, OUTPUT);
LockedPosition(true);
}

void loop()
{
 lcd.setCursor(0,0);
 lcd.print("Enter Password");

char key = keypad.getKey();
if (key == '*' || key == '#')
{
position = 0;
LockedPosition(true);
lcd.print("Invalid Password");
lcd.setCursor(0,1);
lcd.print("Try Again");
}
if (key == password[position])
{
position ++;
}
if (position == 3)
{
lcd.print("Accessed");
lcd.setCursor(0,1); 
lcd.print("welcome");
LockedPosition(false);

}
delay(100);
}
void LockedPosition(int locked)
{
if (locked)
{
digitalWrite(RedpinLock, LOW);
digitalWrite(GreenpinUnlock, HIGH);
}
else
{ 
digitalWrite(RedpinLock, HIGH);
digitalWrite(GreenpinUnlock, LOW);

}

}
