int buzzer = 8 ; // Déclaration de la broche de sortie vers le buzzer
 
void setup ()
{
  pinMode (buzzer, OUTPUT) ;// Initialisation comme broche de sortie
}
 
 
void loop ()
{
  unsigned char i;
  while (1)
  {
    // Dans ce programme, le buzzer est alimenté en alternance avec deux fréquences différentes.
    // Le signal a la forme d'une tension rectangulaire.
    // Le buzzer émet un son qui correspond alternativement à chaque fréquance.
     
    //Fréquence 1
    for (i = 0; i <80; i++) 
    {
      digitalWrite (buzzer, HIGH) ;
      delay (1) ;
      digitalWrite (buzzer, LOW) ;
      delay (1) ;
    }
    //Fréquence 2
    for (i = 0; i <100; i++) 
    {
      digitalWrite (buzzer, HIGH) ;
      delay (2) ;
      digitalWrite (buzzer, LOW) ;
      delay (2) ;
    }
  }
}