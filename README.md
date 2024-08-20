# Pflanzenüberwachungssystem

Dieses Projekt verwendet einen Arduino, um die Feuchtigkeit, Wasserpräsenz und Lichtintensität in der Umgebung einer Pflanze zu überwachen und die Messwerte auf einem LCD-Display anzuzeigen.

## Komponenten

- Arduino Uno: Mikrocontroller-Board
- Feuchtigkeitssensor: Misst die Bodenfeuchtigkeit
- Wassersensor: Erkennt das Vorhandensein von Wasser
- Lichtsensor: Misst die Lichtintensität
- LCD-Display (16x2) mit I2C-Modul: Zeigt die Messwerte an
	- Wichtig: Um das LCD-Display zu steuern, benötigt man die „LiquidCrystal_I2C“-Bibliothek. **Sketch > Include Library > Manage Libraries** und nach „LiquidCrystal_I2C“ suchen. 

## Verkabelung

Zur Verkabelung wird ein Sensor Shield verwendet. Es empfiehlt sich, dort, wo die Ausgänge der Sensoren verdrahtet werden, ebenfalls Power (V) und Ground (G) mit dem jeweiligen Sensor zu verkabeln. Natürlich können die Sensoren auch anders verkabel werden, jedoch muss in diesem Falle der Code angepasst werden. 

- Feuchtigkeitssensor:
	- VCC an V
 	- GND an G 	 		 
	- OUT an A2 
- Wassersensor:
  	- + an V
 	- - an G 	
  	- S an A3 
- Lichtsensor:
	- VCC an V
 	- GND an G 	
  	- AO an A1 
- LCD-Display:
  	- VCC an +
 	- GND an -  	
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

## Konzeption 

Das System eignet sich hervorragend für verschiedene Einsatzmöglichkeiten, wie beispielsweise Schulbesuche. Es lässt sich unkompliziert aufbauen, sodass Studieninteressierte die Sensoren selbst erkunden können. Besonders das Abdecken und Freigeben des Lichtsensors oder das Reiben des Feuchtigkeitssensors stoßen erfahrungsgemäß auf großes Interesse. Der Feuchtigkeitssensor kann zudem in echte Erde gesteckt werden, um praxisnah getestet zu werden. Ebenso kann der Wassersensor mit einer kleinen Sprühflasche benetzt werden, um seine Funktion zu demonstrieren.

Alternativ besteht die Möglichkeit, dass die Studieninteressierten das System eigenständig aufbauen, um so noch tiefer in die Materie einzutauchen.
















