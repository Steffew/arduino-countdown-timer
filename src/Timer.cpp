#include <Arduino.h>
#include <Display.h>

#define PIN_BUTTON_1 8
#define PIN_BUTTON_2 9
#define PIN_LED_BLUE 6
#define PIN_LED_GREEN 5
#define PIN_BUZZER 3
#define PIN_KNOB A0

int buttonState_1 = 0;
int buttonState_2 = 0;

unsigned long previousTime = 0;
const long interval = 1000;
int countDownTime = 0;
bool counting = false;

  void Beep(int frequency, int duration, int interval, int beepAmount)
  {
    for (int i = 0; i < beepAmount; i++)
    {
      tone(PIN_BUZZER, frequency, duration);
      delay(interval);
    }
  }

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP);
  pinMode(PIN_BUTTON_2, INPUT_PULLUP);

  tone(PIN_BUZZER,500,10);
}

void loop()
{
  int analogKnobValue = analogRead(PIN_KNOB);
  int setTimeSpeed = map(analogKnobValue, 0, 1023, 5, 150);
  countDownTime = min(86400, max(0, countDownTime));
  unsigned long currentTime = millis();

  buttonState_1 = digitalRead(PIN_BUTTON_1);
  buttonState_2 = digitalRead(PIN_BUTTON_2);
  
  Display.show(String(countDownTime));

  if (currentTime - previousTime >= interval)
  {
    previousTime = currentTime;
    
    if (counting)
    {
      countDownTime--;
      
      if (countDownTime == 0)
      {
        counting = false;
        Display.show("End");
        Beep(1000,250,500,3);
      }
    }
  }

  if (buttonState_2 == LOW && !counting)
  {
    tone(PIN_BUZZER,500,1);
    countDownTime--;
    delay(setTimeSpeed);
  }

  if (buttonState_1 == LOW && !counting)
  {
    tone(PIN_BUZZER,700,1);
    countDownTime++;
    delay(setTimeSpeed);
  }

  if (buttonState_1 == LOW && buttonState_2 == LOW)
  {
    if (!counting)
    {
      delay(250);
      Beep(600, 50, 100, 2);
      counting = true;
    }
    else 
    {
      delay(250);
      Beep(300, 50, 100, 2);
      counting = false;
    }
  }
}