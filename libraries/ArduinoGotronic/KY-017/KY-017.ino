int Led = 13 ;// déclaration de la broche de sortie pour la LED
int Sensor = 10; // délaration de la broche d'entrée du capteur
int val; // variable temporaire
   
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
    digitalWrite (Led, LOW);
  }
  else
  {
    digitalWrite (Led, HIGH);
  }
}
