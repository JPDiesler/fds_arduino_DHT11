#include "DHT.h"  // Importiere die DHT Bibliothek, die uns den Zugriff auf den DHT11 Sensor ermöglicht.

#define DHTPIN 2     // Definiert den digitalen Pin, an den der DHT11-Sensor angeschlossen ist (in diesem Fall Pin 2).
#define DHTTYPE DHT11   // Definiert den Sensortyp (DHT11). Falls du einen DHT22 verwenden würdest, müsstest du hier DHT22 angeben.

DHT dht(DHTPIN, DHTTYPE);  // Erstellt ein Objekt der DHT Klasse, das den Pin und den Sensortyp verwendet.

void setup() {
  Serial.begin(9600);  // Initialisiert die serielle Kommunikation mit 9600 Baud (Geschwindigkeit der Datenübertragung).
  dht.begin();  // Initialisiert den DHT-Sensor. Ohne diesen Befehl funktioniert der Sensor nicht.
}

void loop() {
  delay(1000);  // Verzögert die Ausführung des Codes um 1 Sekunde (1000 Millisekunden), sodass der Sensor nur einmal pro Sekunde abfragt.

  float temperature = dht.readTemperature();  // Liest die Temperatur in Celsius vom Sensor und speichert sie als Gleitkommazahl (float) in der Variable "temperature".

  // Überprüft, ob die Messung erfolgreich war:
  if (isnan(temperature)) {  
    // Wenn der Sensor keine gültigen Daten liefert (z.B. wenn der Sensor falsch verdrahtet ist oder nicht antwortet),
    // gibt der Code eine Fehlermeldung aus.
    Serial.println("Fehler beim Auslesen des DHT-Sensors!");
    return;  // Stoppt die Ausführung der Funktion, wenn keine Daten gelesen werden konnten.
  }

  // Wenn die Daten erfolgreich ausgelesen wurden, gibt der Arduino die Temperatur auf dem seriellen Monitor aus:
  Serial.print("Temperatur: ");
  Serial.print(temperature);  // Gibt die gemessene Temperatur ohne Zeilenumbruch aus.
  Serial.println(" °C");  // Gibt das Grad Celsius-Symbol aus und bricht die Zeile um.
}