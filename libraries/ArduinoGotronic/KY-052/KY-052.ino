// Les bibliothèques requises sont définies et configurées
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
Adafruit_BMP085_Unified BMPSensor = Adafruit_BMP085_Unified(10085);
  
void setup(void) 
{
  Serial.begin(9600);
   
  Serial.println("KY-052 Test du capteur:");
   
  // Si le capteur ne détecte rien, une erreur s'affiche
  if(!BMPSensor.begin())
  {
    Serial.println("KY-052-Capteur non reconnu!");
    Serial.print("Verifier la connexion");
    while(1);
  }
}
  
void loop(void) 
{
  // Initialisation de la bibliothèque Adafruit BMP
  sensors_event_t event;
  BMPSensor.getEvent(&event);
  
  // Initialisation de la mesure quand le capteur est prêt
  if (event.pressure)
  {
    Serial.println("------------------------");
     
    // Mesure de la pression de l'air
    Serial.print("Pression atmospherique:    ");
    Serial.print(event.pressure);
    Serial.println(" hPa");
     
    // Mesure de la température
    float temperature;
    BMPSensor.getTemperature(&temperature);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.write(176); // Code Unicode pour le symbole "°"
    Serial.println(" C");
  
    // Calcul de la hauteur au-dessus du niveau de la mer,
    // à partir des données enregistrées (SLP=1013.25 hPa)
    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    Serial.print("Hauteur par rapport au niveau de la mer:    "); 
    Serial.print(BMPSensor.pressureToAltitude(seaLevelPressure,
                                        event.pressure,
                                        temperature)); 
    Serial.println(" m");
    Serial.println("------------------------");
    Serial.println("");
  }
  // Message d'erreur si le capteur est inaccessible 
  else
  {
    Serial.println("Erreur de capteur");
  }
  delay(1000);
}