int Sensor = 10; // Déclaration de la broche d'entrée du capteur
   
void setup ()
{
  Serial.begin(9600); // Sortie série à 9600 bauds
  pinMode (Sensor, INPUT) ; // Initialisation de la broche d'entrée du capteur
}
   
// Le programme lit l'état des broches du capteur et envoie <br />//l'information de suivi (ou non) d'une ligne dans la console. 
void loop ()
{
  bool val = digitalRead (Sensor) ; // Lecture de la valeur du signal
   
  if (val == HIGH) // Si un signal est détecté, la diode s'allume
  {
    Serial.println("Le suiveur de ligne se trouve sur une ligne");
  }
  else
  {
    Serial.println("Le suiveur de ligne ne se trouve pas sur une ligne");
  }
  Serial.println("------------------------------------");
  delay(500); // pause de 500ms entre les mesures
}