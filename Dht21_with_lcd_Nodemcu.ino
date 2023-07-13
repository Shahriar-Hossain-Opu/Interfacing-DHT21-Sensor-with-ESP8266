
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#define DHT_SENSOR_PIN  2 // ESP32 pin GIOP23 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT21

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x3F, 16 column and 2 rows
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup() {
  dht_sensor.begin(); // initialize the DHT sensor
  lcd.begin();         // initialize the lcd
  lcd.backlight();    // open the backlight
}

void loop() {
  float humi  = dht_sensor.readHumidity();    // read humidity
  float tempC = dht_sensor.readTemperature(); // read temperature

  lcd.clear();
  // check whether the reading is successful or not
  if (isnan(tempC) || isnan(humi)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed");
  } else {
    lcd.setCursor(0, 0);  // display position
    lcd.print("Temp: ");
    lcd.print(tempC);     // display the temperature
    lcd.print("°C");

    lcd.setCursor(0, 1);  // display position
    lcd.print("Humi: ");
    lcd.print(humi);      // display the humidity
    lcd.print("%");
  }

  // wait a 2 seconds between readings
  delay(2000);
}
