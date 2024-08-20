# Pflanzenüberwachungssystem

Dieses Projekt wurde für Besuchertage und ähnliche Veranstaltungen im Studiengang Intelligent Systems Design an der HSHL konzipiert. Es bietet einen spielerischen Einblick in die Welt der Embedded Systems und zeigt, wie ein Arduino verwendet werden kann, um die Feuchtigkeit, Wasserpräsenz und Lichtintensität in der Umgebung einer Pflanze zu überwachen. Die Messwerte werden auf einem LCD-Display angezeigt.

## Komponenten

- **Arduino Uno**: Mikrocontroller-Board
- **Feuchtigkeitssensor**: Misst die Bodenfeuchtigkeit
- **Wassersensor**: Erkennt das Vorhandensein von Wasser
- **Lichtsensor**: Misst die Lichtintensität
- **LCD-Display (16x2) mit I2C-Modul**: Zeigt die Messwerte an
  - Wichtig: Um das LCD-Display zu steuern, muss die „LiquidCrystal_I2C“-Bibliothek installiert werden. Dies erfolgt über **Sketch > Include Library > Manage Libraries**. Dort nach „LiquidCrystal_I2C“ suchen und installieren.

## Verkabelung

Zur Verkabelung wird ein Sensor Shield verwendet. Es empfiehlt sich, Power (V) und Ground (G) des Shields mit den jeweiligen Sensoren zu verbinden. Alternativ können die Sensoren auch direkt verkabelt werden, wobei dann der Code entsprechend angepasst werden muss.

- **Feuchtigkeitssensor**:
  - VCC an V
  - GND an G
  - OUT an A2
- **Wassersensor**:
  - Plus-Symbol an V
  - Minus-Symbol an G
  - S an A3
- **Lichtsensor**:
  - VCC an V
  - GND an G
  - AO an A1
- **LCD-Display**:
  - VCC an Plus-Symbol
  - GND an Minus-Symbol
  - SDA an SDA
  - SCL an SCL

## Codeerklärung

### Setup-Funktion

Die `setup()`-Funktion initialisiert das LCD-Display und legt die Pins für die Sensoren als Eingänge fest.

```cpp
void setup() {
  lcd.init(); // LCD initialisieren
  lcd.backlight(); // Hintergrundbeleuchtung einschalten
  
  pinMode(moisturePin, INPUT); // Feuchtigkeitssensor als Eingang definieren
  pinMode(waterPin, INPUT); // Wassersensor als Eingang definieren
  pinMode(lightPin, INPUT); // Lichtsensor als Eingang definieren
}
```

### Hauptprogramm (Loop)

In der `loop()`-Funktion werden die Sensorwerte kontinuierlich ausgelesen und auf dem LCD-Display angezeigt. Jede Sensorabfrage wird mit einer Sekunde Verzögerung ausgeführt, um das Display nicht zu schnell zu aktualisieren.

```cpp
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

- **displayMoisture(int value)**: Zeigt den Feuchtigkeitswert und eine Statusmeldung („Trockene Erde“, „Feuchte Erde“, „Wasser“) an.
- **displaySensorValue(int value, String label)**: Zeigt einen beliebigen Sensorwert mit einem entsprechenden Label an (z.B. „Wasser“, „Helligkeit“).

## Konzeption

Das System eignet sich hervorragend für verschiedene Einsatzmöglichkeiten, wie beispielsweise Schulbesuche. Es ist einfach aufzubauen und ermöglicht es den Teilnehmenden, die Sensoren eigenständig zu erkunden. Besonders das Abdecken und Freigeben des Lichtsensors oder das Testen des Feuchtigkeitssensors in echter Erde finden erfahrungsgemäß großes Interesse. Der Wassersensor kann mit einer kleinen Sprühflasche benetzt werden, um seine Funktion zu demonstrieren.

Alternativ können die Teilnehmenden das System eigenständig aufbauen, um so noch tiefer in die Materie einzutauchen und die Funktionsweise der einzelnen Komponenten besser zu verstehen.
