#include <Arduino.h>
#include <IRLremote.h>

const uint8_t PIN_IR = 2;

CNec remote;
void getIRCode()
{
  if (remote.available())
  {
    auto data = remote.read();

    Serial.print(data.address);
    Serial.print(" ");
    Serial.println(data.command);
  }
}

void setup()
{
  Serial.begin(9600);

  if (!remote.begin(PIN_IR))
  {
    Serial.println("Failed to initailise IR");
    while (1);
  }
}

void loop()
{
  getIRCode();
}
