Код:
#include <SD.h>

float sensor, voltage, celsius;

void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);

  if (!SD.begin(8))
  {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("microSD card is ready");
}

void loop()
{
  File dataFile = SD.open("DATA.TXT", FILE_WRITE);

  if (dataFile)
  {
    for (int a = 0; a < 5; a++)
    {
      sensor = analogRead(0);
      voltage = (sensor * 5000) / 1024;
      voltage = voltage - 500;
      celsius = voltage / 10;
      dataFile.print("Log: ");
      dataFile.print(a, DEC);
      dataFile.print(" Temperature: ");
      dataFile.print(celsius, 2);
      dataFile.println(" degrees C");
      delay(599900);
    }
    dataFile.close();
    Serial.println("Finished!");
    do {} while (1);
  }
}
