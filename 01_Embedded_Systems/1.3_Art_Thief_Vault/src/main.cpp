#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

void startLevel();
void winGame();

constexpr byte ROWS = 4;
constexpr byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte colPins[COLS] = {8, 9, 12, 13};
byte rowPins[ROWS] = {2, 3, 4, 7};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servos[4];
constexpr int servoPins[] = {11, 10, 6, 5};

constexpr int greenLed = A1;
constexpr int redLed = A2;
constexpr int buzzer = A3;

int currentLevel = 0;
int secretPassword = 00;
String inputString = "";

void setup()
{
  lcd.init();
  lcd.backlight();
  for (int i = 0; i < 4; i++)
  {
    servos[i].attach(servoPins[i]);
    servos[i].write(0);
  }
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  startLevel();
}

void startLevel()
{
  secretPassword = random(10, 99);
  inputString = "";
  lcd.clear();
  lcd.print("Level ");
  lcd.print(currentLevel + 1);
  lcd.setCursor(0, 1);
  lcd.print("Enter Code: ");
}

void loop()
{
  char key = keypad.getKey();

  if (!key)
  return;

  if (key >= '0' && key <= '9')
  {

    if (inputString.length() < 2)
    {

      inputString += key;

      lcd.setCursor(12, 1);
      lcd.print("  ");
      lcd.setCursor(12, 1);
      lcd.print(inputString);
    }
  }  

  else if (key == '#')
  {

    if (inputString.length() == 0)
    return;

    int guess = inputString.toInt();

    if (guess == secretPassword)
    {

      servos[currentLevel].write(90);
      digitalWrite(greenLed, HIGH);
      tone(buzzer, 1000, 500);

      lcd.clear();
      lcd.print("CORRECT!");

      delay(1000);

      digitalWrite(greenLed, LOW);

      inputString = "";
      currentLevel++;

      if (currentLevel < 4)
      startLevel();
      
      else
      winGame();
    }
    
    else
    {

      inputString = "";

      lcd.clear();
      lcd.print(guess > secretPassword ? "HIGH!" : "LOW!");

      digitalWrite(redLed, HIGH);
      tone(buzzer, 300, 300);

      delay(1000);

      digitalWrite(redLed, LOW);

      lcd.clear();
      lcd.print("Level ");
      lcd.print(currentLevel + 1);
      lcd.setCursor(0, 1);
      lcd.print("Enter Code:");
    }
  }

  else if (key == '*')
  {

    inputString = "";

    lcd.setCursor(12, 1);
    lcd.print("  ");
    lcd.setCursor(12, 1);
  }

}

void winGame()
{
  lcd.clear();
  lcd.print("VAULT OPEN!");
  lcd.setCursor(0,1);
  lcd.print("*# to Reset");

  bool waitingForReset = true;
  while(waitingForReset)
  {
    char key = keypad.getKey();
    if(key == '*')
    {
      while(keypad.getKey() != '#');
      currentLevel = 0;
      for (int i = 0; i < 4; i++)
      {
        servos[i].write(0);
      }
      waitingForReset = false;
      startLevel();
      
    }
  }
  
}