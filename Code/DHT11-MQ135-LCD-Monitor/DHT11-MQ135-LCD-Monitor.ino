#include <Wire.h>
#include <LiquidCrystal_I2C.h>  //https://github.com/marcoschwartz/LiquidCrystal_I2C/archive/master.zip
#include <DHT.h>

#define DHTPIN 2  // Digital pin connected to the DHT11 sensor
#define DHTTYPE DHT11

#define MQ135 A1  // MQ135 pin
#define VCC2 5    // VCC pin for MQ135

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3F, 20, 4);

void setup() {
  pinMode(VCC2, OUTPUT);
  digitalWrite(VCC2, HIGH);
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   LCD ACTIVATED!   ");
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(5000);  // Wait a few seconds between measurements.

  float h = dht.readHumidity();
  float t = dht.readTemperature();      // Read temperature as Celsius (the default)
  float f = dht.readTemperature(true);  // Read temperature as Fahrenheit (isFahrenheit = true)

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);   // Compute heat index in Celsius (isFahreheit = false)
  
  int mq135Val;
  mq135Val = analogRead(MQ135);

  //Printing on the Serial Monitor
  Serial.print("Air Quality= ");
  Serial.print(mq135Val, DEC);
  Serial.print(" PPM");
  Serial.print(F(" Humidity= "));
  Serial.print(h);
  Serial.print(F("%  Temperature= "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index= "));
  Serial.print(hic);
  Serial.print(F("C "));

  delay(1000);
  //Printing on the LCD
  lcd.setCursor(0, 0);
  lcd.print("A.Q=");
  lcd.setCursor(4, 0);
  lcd.print(mq135Val, DEC);
  lcd.setCursor(7, 0);
  lcd.print("PPM");

  lcd.setCursor(12, 0);
  lcd.print("H=");
  lcd.setCursor(14, 0);
  lcd.print(h);
  lcd.setCursor(19, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Feels like=");
  lcd.setCursor(11, 1);
  lcd.print(hic);
  lcd.setCursor(16, 1);
  lcd.print("C");

  lcd.setCursor(0, 2);
  lcd.print("T=");
  lcd.setCursor(2, 2);
  lcd.print(t);
  lcd.setCursor(7, 2);
  lcd.print("C");
  lcd.setCursor(11, 2);
  lcd.print(f);
  lcd.setCursor(16, 2);
  lcd.print("F");
  delay(1000);
  lcd.clear();
}
