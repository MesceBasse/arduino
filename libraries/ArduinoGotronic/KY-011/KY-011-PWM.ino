int Led_Rouge = 10;
int Led_Verte = 11;
 
int val;
 
void setup () {
  // Initialisation des broches de sortie pour les LEDS
  pinMode (Led_Rouge, OUTPUT); 
  pinMode (Led_Verte, OUTPUT); 
}
void loop () {
   // Dans une boucle For, différentes valeurs PWM sont envoyées aux 2 LEDS
   for (val = 255; val> 0; val--)
      {
      analogWrite (Led_Verte, val);
      analogWrite (Led_Rouge, 255-val);
      delay (15);
   }
   // Dans cette seconde boucle For, les valeurs sont inversées
   for (val = 0; val <255; val++)
      {
      analogWrite (Led_Verte, val);
      analogWrite (Led_Rouge, 255-val);
      delay (15);
   }
}