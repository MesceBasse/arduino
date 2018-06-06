int Led = 13;
 
void setup ()
{
  pinMode (Led, OUTPUT); // Initialisation de la broche de sortie de la LED
}
 
void loop () //Boucle de programme principale
{
  digitalWrite (Led, HIGH); // la LED est allumé
  delay (4000); // délai de 4 secondes
  digitalWrite (Led, LOW); // la LED est éteinte
  delay (2000); // délai de 2 secondes
}
