int Buzzer = 13;
 
void setup ()
{
  pinMode (Buzzer, OUTPUT); // Initialisation comme broche de sortie
}
 
void loop () //boucle de programme principale
{
  digitalWrite (Buzzer, HIGH); // le buzzer est actionné
  delay (4000); // délai de 4 secondes
  digitalWrite (Buzzer, LOW); // le buzzer est à l'arrêt
  delay (2000); // délai de 2 secondes
}
