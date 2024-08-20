#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialisierung des LCDs mit der I2C-Adresse 0x27 für ein 16x2 Display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definition der analogen Pins für die Sensoren
int moisturePin = A2;  // Feuchtigkeitssensor
int waterPin = A3;     // Wassersensor
int lightPin = A1;     // Lichtsensor

// Variablen zum Speichern der Sensorwerte
int moistureValue;
int waterValue;
int lightValue;

void setup() {
  // Initialisierung des LCDs
  lcd.init();
  lcd.backlight(); // Hintergrundbeleuchtung einschalten
  
  // Pins als Eingänge definieren
  pinMode(moisturePin, INPUT);
  pinMode(waterPin, INPUT);
  pinMode(lightPin, INPUT);
}

void loop() {
  // Feuchtigkeitssensor auslesen und anzeigen
  moistureValue = analogRead(moisturePin);
  displayMoisture(moistureValue);
  delay(1000); // Warte eine Sekunde

  // Wassersensor auslesen und anzeigen
  waterValue = analogRead(waterPin);
  displaySensorValue(waterValue, "Wasser");
  delay(1000); // Warte eine Sekunde

  // Lichtsensor auslesen und anzeigen
  lightValue = analogRead(lightPin);
  displaySensorValue(lightValue, "Helligkeit");
  delay(1000); // Warte eine Sekunde
}

// Funktion zur Anzeige des Feuchtigkeitswertes und der entsprechenden Statusmeldung
void displayMoisture(int value) {
  lcd.clear(); // LCD-Bildschirm löschen
  lcd.setCursor(0, 0);
  lcd.print("Wert: ");
  lcd.setCursor(6, 0);
  lcd.print(value); // Feuchtigkeitswert anzeigen
  
  lcd.setCursor(0, 1);
  // Statusmeldung je nach Feuchtigkeitswert anzeigen
  if (value < 300) {
    lcd.print("Trockene Erde");
  } else if (value <= 700) {
    lcd.print("Feuchte Erde");
  } else {
    lcd.print("Wasser");
  }
}

// Funktion zur Anzeige eines allgemeinen Sensorwertes mit einem Label
void displaySensorValue(int value, String label) {
  lcd.clear(); // LCD-Bildschirm löschen
  lcd.setCursor(0, 0);
  lcd.print("Wert: ");
  lcd.setCursor(6, 0);
  lcd.print(value); // Sensorwert anzeigen
  
  lcd.setCursor(0, 1);
  lcd.print(label); // Label anzeigen (z.B. "Wasser" oder "Helligkeit")
}