#include <OneWire.h>
#include <DallasTemperature.h>


// On utilise la pin D4 de la carte pour la réception des données du capteur
#define ONE_WIRE_BUS 4

// Création des objets pour accéder au bus '1-Wire' et plus spécifiquement au capteur sur ce bus ('Dallas' est le nom du constructeur du ds12b80)
// On peut avoir plusieurs capteurs sur le même bus et l'objet 'sensors' permet de tous les lire.
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

/**
 * Initialisation du programme
 */
void setup(void) {
  // Configuration du port série pour les logs
  Serial.begin(9600);
  
  // Initialisation du capteur
  sensors.begin();
}

/**
 * Méthode principale, appelée en boucle
 */
void loop(void) {
  Serial.println("Reading temperature...");
  sensors.requestTemperatures(); // Envoi de la demande de lecture

  Serial.print("Value is: ");
  Serial.println(sensors.getTempCByIndex(0)); // Récupération de l'objet 0 (vu qu'on n'en a qu'un)

  delay(1000); // Temporisation avant le prochain tour de boucle
}
