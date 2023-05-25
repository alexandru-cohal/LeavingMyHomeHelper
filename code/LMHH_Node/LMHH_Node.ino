/********** Includes **********/
#include <Arduino_MKRIoTCarrier.h>

/********** Defines **********/
#define SERIAL_BAUD_RATE  9600
#define LOOP_PERIOD_MS    100
#define BUTTON_PREV_DAY   TOUCH0
#define BUTTON_NEXT_DAY   TOUCH4
#define BUTTON_HERE       TOUCH2

/********** Global Variables **********/
MKRIoTCarrier carrier;

/********** Setup Function **********/
void setup() 
{
  bool retVal = true;

  Serial.begin(SERIAL_BAUD_RATE);

  carrier.withCase();
  retVal = carrier.begin();

  if (retVal == false)
  {
    Serial.println("Carrier initialization failed");
    while(1);
  }
  else
  {
    Serial.println("Carrier initialization OK");
  }
}

/********** Loop Function **********/
void loop() 
{
  carrier.Buttons.update();

  if (carrier.Buttons.onTouchDown(BUTTON_PREV_DAY))
  {
    Serial.println("Button for previous day pressed");
  }

  if (carrier.Buttons.onTouchDown(BUTTON_NEXT_DAY))
  {
    Serial.println("Button for next day pressed");
  }

  if (carrier.Buttons.onTouchDown(BUTTON_HERE))
  {
    Serial.println("Button for here pressed");
  }

  delay(LOOP_PERIOD_MS);
}