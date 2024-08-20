# Pflanzenüberwachungssystem

Dieses Projekt verwendet einen Arduino, um die Feuchtigkeit, Wasserpräsenz und Lichtintensität in der Umgebung einer Pflanze zu überwachen und die Messwerte auf einem LCD-Display anzuzeigen.

## Komponenten

- Arduino Uno: Mikrocontroller-Board
- Feuchtigkeitssensor: Misst die Bodenfeuchtigkeit
- Wassersensor: Erkennt das Vorhandensein von Wasser
- Lichtsensor: Misst die Lichtintensität
- LCD-Display (16x2) mit I2C-Modul: Zeigt die Messwerte an

## Verkabelung

Zur Verkabelung wird ein Sensor Shield verwendet. Es empfiehlt sich, dort, wo die Ausgänge der Sensoren verdrahtet werden, ebenfalls Power (V) und Ground (G) mit dem jeweiligen Sensor zu verkabeln. Natürlich können die Sensoren auch anders verkabel werden, jedoch muss in diesem Falle der Code angepasst werden. 

- Feuchtigkeitssensor:
	- OUT an A2 
- Wassersensor:
  	- S an A3 
- Lichtsensor:
  	- AO an A1 
- LCD-Display:
	- SDA an SDA 
	- SCL an SCL  

## Codeerklärung

### Setup-Funktion

Die setup()-Funktion initialisiert das LCD-Display und legt die Pins für die Sensoren als Eingänge fest.

```
void setup() {
  lcd.init(); // LCD initialisieren
  lcd.backlight(); // Hintergrundbeleuchtung einschalten
  
  pinMode(moisturePin, INPUT); // Feuchtigkeitssensor als Eingang definieren
  pinMode(waterPin, INPUT); // Wassersensor als Eingang definieren
  pinMode(lightPin, INPUT); // Lichtsensor als Eingang definieren
}
```

### Hauptprogramm (Loop)

In der loop()-Funktion werden die Sensorwerte kontinuierlich ausgelesen und auf dem LCD-Display angezeigt. Jede Sensorabfrage wird mit einer Sekunde Verzögerung ausgeführt, um das Display nicht zu schnell zu aktualisieren.

```
void loop() {
  moistureValue = analogRead(moisturePin); // Feuchtigkeitswert auslesen
  displayMoisture(moistureValue); // Feuchtigkeitswert anzeigen
  delay(1000); // Warte eine Sekunde

  waterValue = analogRead(waterPin); // Wasserwert auslesen
  displaySensorValue(waterValue, "Wasser"); // Wasserwert anzeigen
  delay(1000); // Warte eine Sekunde

  lightValue = analogRead(lightPin); // Lichtwert auslesen
  displaySensorValue(lightValue, "Helligkeit"); // Lichtwert anzeigen
  delay(1000); // Warte eine Sekunde
}
```

### Display-Funktionen

Es gibt zwei Funktionen, die die Sensorwerte auf dem LCD anzeigen:

* displayMoisture(int value): Zeigt den Feuchtigkeitswert und eine Statusmeldung (“Trockene Erde”, “Feuchte Erde”, “Wasser”) an. 
* displaySensorValue(int value, String label): Zeigt einen beliebigen Sensorwert mit einem entsprechenden Label an (z.B. “Wasser”, “Helligkeit”).

















