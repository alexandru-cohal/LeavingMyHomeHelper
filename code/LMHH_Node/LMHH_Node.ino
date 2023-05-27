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
float pressure;
float humidity;
float temperature;

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

  carrier.display.setTextColor(ST77XX_BLACK);
  carrier.display.setTextSize(3);
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

  pressure = carrier.Pressure.readPressure();
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" kPa");

  humidity = carrier.Env.readHumidity();
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  temperature = carrier.Env.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  carrier.display.fillScreen(ST77XX_RED);
  carrier.display.setCursor(10, 100);
  carrier.display.print("Temperature: ");
  carrier.display.print(temperature);
  carrier.display.print(" deg C");

  delay(LOOP_PERIOD_MS);
}