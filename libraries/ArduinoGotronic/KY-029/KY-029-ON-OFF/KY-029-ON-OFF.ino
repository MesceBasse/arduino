int Led_Rouge = 10;
int Led_Verte = 11;
 
void setup ()
{
  // Initialisation des broches de sortie pour les LEDS
  pinMode (Led_Rouge, OUTPUT); 
  pinMode (Led_Verte, OUTPUT); 
}
 
void loop () //Boucle de programme principale
{
  digitalWrite (Led_Rouge, HIGH); // la Led s'allume
  digitalWrite (Led_Verte, LOW); // la LED commute
  delay (3000); // Délai de 3 secondes
 
  digitalWrite (Led_Rouge, LOW); // la LED commute
  digitalWrite (Led_Verte, HIGH); // la Led s'allume
  delay (3000); // Délai de 3 secondes supplémentaires pendant lequel les LEDS sont commutées
}