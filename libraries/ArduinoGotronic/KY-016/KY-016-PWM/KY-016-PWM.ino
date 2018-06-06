int Led_Rouge = 10;
int Led_Verte = 11;
int Led_Bleue = 12;
 
int val;
 
void setup () {
  // Initialisation des broches de sortie pour les LEDS
  pinMode (Led_Rouge, OUTPUT); 
  pinMode (Led_Verte, OUTPUT); 
  pinMode (Led_Bleue, OUTPUT); 
}
void loop () {
   // Dans une boucle For, différentes valeurs PWM sont envoyées aux 3 LEDS
   for (val = 255; val> 0; val--)
      {
       analogWrite (Led_Bleue, val);
       analogWrite (Led_Verte, 255-val);
       analogWrite (Led_Rouge, 128-val);
       delay (1);
   }
   // Les signaux sont ensuite inversés
   for (val = 0; val <255; val++)
      {
      analogWrite (Led_Bleue, val);
      analogWrite (Led_Verte, 255-val);
      analogWrite (Led_Rouge, 128-val);
      delay (1);
   }
}