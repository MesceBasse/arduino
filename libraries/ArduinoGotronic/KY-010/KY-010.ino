int Led = 13 ;// Déclaration de la broche de sortie LED
int Sensor = 10; // Déclaration de la broche d'entrée du capteur
int val; // Déclaration de la broche d'entrée du capteur
  
void setup ()
{
  pinMode (Led, OUTPUT) ; // Initialisation de la broche de sortie
  pinMode (Sensor, INPUT) ; // Initialisation de la broche du capteur
}
  
void loop ()
{
  val = digitalRead (Sensor) ; // Lecture de la valeur du signal
  
  if (val == HIGH) // Si un signal est détecté, la diode s'allume
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}
