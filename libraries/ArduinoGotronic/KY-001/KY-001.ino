// Importation des librairies requises
#include <DallasTemperature.h>  
#include <OneWire.h>         
 
// Déclaration de la broche d'entrée du capteur
#define KY001_Signal_PIN 4
 
// Configuration des libraries
OneWire oneWire(KY001_Signal_PIN);          
DallasTemperature sensors(&oneWire);   
 
 
void setup() {
 
    // Initialisation de l'interface série
    Serial.begin(9600);
    Serial.println("KY-001 Capteur de temperature");
     
    // Le capteur est initialisé
    sensors.begin();  
}
 
//Boucle de programme principale
void loop()
{
    // Début de la mesure de la température
    sensors.requestTemperatures(); 
    // ... et affichage de la température mesurée
    Serial.print("Temperature: ");
    Serial.print(sensors.getTempCByIndex(0));
    Serial.write(176); // Code UniCodepour le symbole "°"
    Serial.println("C");
         
    delay(1000);    // 5s de pause avant la mesure suivante
}
