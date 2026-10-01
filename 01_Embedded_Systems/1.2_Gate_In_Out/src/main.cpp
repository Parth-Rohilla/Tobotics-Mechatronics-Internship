#include <Arduino.h>
#include <Adafruit_LiquidCrystal.h>

constexpr int LCD_D4 = 13;
constexpr int LCD_D5 = 12;
constexpr int LCD_D6 = 11;
constexpr int LCD_D7 = 10;

constexpr int LCD_E = 8;
constexpr int LCD_RS = 9;

constexpr int USS_1_trig = 7;
constexpr int USS_1_echo = 6;

constexpr int USS_2_trig = 4;
constexpr int USS_2_echo = 3;

constexpr int LED_pin = 2;

Adafruit_LiquidCrystal lcd(LCD_RS,LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7);

int visitorCount = 0;
constexpr int threshold = 50;

bool isEntryBlocked = false;
bool isExitBlocked = false;

void setup() 
{
  lcd.begin(16,2);

  pinMode(USS_1_trig, OUTPUT);
  pinMode(USS_1_echo, INPUT);
  pinMode(USS_2_trig, OUTPUT);
  pinMode(USS_2_echo, INPUT);

  pinMode(LED_pin, OUTPUT);
  digitalWrite(LED_pin, LOW);

  lcd.setCursor(0, 0);
  lcd.print("2-Door System");
  delay(1500);
  lcd.clear();
}

int distance(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  int distance = (duration * 0.034) / 2;

  return distance;
}

void loop() 
{
  int distIn = distance(USS_1_trig, USS_1_echo);
  int distOut = distance(USS_2_trig, USS_2_echo);

  if (distIn < threshold && isEntryBlocked == false)
  {
    isEntryBlocked = true;
    visitorCount++;
    delay(50);
  }
  else if (distIn >= threshold && isEntryBlocked == true)
  {
    isEntryBlocked = false;
    delay(50);
  }
  
  if (distOut < threshold && isExitBlocked == false)
  {
    isExitBlocked = true;
    if (visitorCount > 0)
    {
      visitorCount--;
    }
    delay(50);
  }
  
  else if (distOut >= threshold && isExitBlocked == true)
  {
    isExitBlocked = false;
    delay(50);
  }

  if (visitorCount > 0)
  {
    digitalWrite(LED_pin, HIGH);
  }
  else
  {
    digitalWrite(LED_pin, LOW);
  }

  lcd.setCursor(0, 0);
  lcd.print("Count: ");
  lcd.print(visitorCount);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  if (visitorCount >0)
  {
    lcd.print("Status: LED ON ");
  }
  else 
  {
    lcd.print("Status: LED OFF");
  }

  delay(50);
}
