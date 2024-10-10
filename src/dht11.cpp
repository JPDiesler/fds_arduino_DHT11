#include "DHT11.h"  // Importiere die DHT11 Bibliothek, die uns den Zugriff auf den DHT11 Sensor ermöglicht.

#define DHTPIN 2     // Definiert den digitalen Pin, an den der DHT11-Sensor angeschlossen ist (in diesem Fall Pin 2).

DHT11 dht(DHTPIN);  // Erstellt ein Objekt der DHT11 Klasse, das den Pin verwendet.

void setup() {
  Serial.begin(9600);  // Initialisiert die serielle Kommunikation mit 9600 Baud (Geschwindigkeit der Datenübertragung).
}

void loop() {
  delay(1000);  // Verzögert die Ausführung des Codes um 1 Sekunde (1000 Millisekunden), sodass der Sensor nur einmal pro Sekunde abfragt.

  int temperature, humidity;
  int chk = dht.readTemperatureHumidity(temperature, humidity);  // Liest die Temperatur und Luftfeuchtigkeit vom Sensor.

  // Überprüft, ob die Messung erfolgreich war:
  if (chk == DHT11::ERROR_TIMEOUT || chk == DHT11::ERROR_CHECKSUM) {  
    // Wenn der Sensor keine gültigen Daten liefert (z.B. wenn der Sensor falsch verdrahtet ist oder nicht antwortet),
    // gibt der Code eine Fehlermeldung aus.
    Serial.print("Fehler beim Auslesen des DHT-Sensors: ");
    Serial.println(dht.getErrorString(chk));
    return;  // Stoppt die Ausführung der Funktion, wenn keine Daten gelesen werden konnten.
  }

  // Wenn die Daten erfolgreich ausgelesen wurden, gibt der Arduino die Temperatur und Luftfeuchtigkeit auf dem seriellen Monitor aus:
  Serial.print("Temperatur: ");
  Serial.print(temperature);  // Gibt die gemessene Temperatur ohne Zeilenumbruch aus.
  Serial.print(" °C");  // Gibt das Grad Celsius-Symbol aus und bricht die Zeile um.

  // Überprüft, ob die Temperatur 25°C überschreitet und gibt eine Warnung aus:
  if (temperature > 25) {
    Serial.println("Warnung: Hohe Temperatur!");
  } else {
    Serial.println();  // Bricht die Zeile um, wenn die Temperatur unter 25°C liegt.
  }

  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(humidity);  // Gibt die gemessene Luftfeuchtigkeit ohne Zeilenumbruch aus.
  Serial.println(" %");  // Gibt das Prozent-Symbol aus und bricht die Zeile um.
}