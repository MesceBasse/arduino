// Déclaration et initialisation des broches d'entrées
int JoyStick_X = A0; // Signal de l'axe X
int JoyStick_Y = A1; // Signal de l'axe Y
int Button = 3; // Bouton
 
void setup ()
{
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
  pinMode (Button, INPUT);
   
  // Lorsqu'on pousse sur le bouton, la mise à la masse
  // active la résistance de PullUp.
  digitalWrite(Button, HIGH);  
   
  Serial.begin (9600); // Sortie série à 9600 bauds
}
 
// Le programme lit les valeurs des broches d'entrée et les envoie à la sortie série
void loop ()
{
  float x, y;
  int Knopf;
   
  //Les valeurs sont lues, sont converties en tension...
  x = analogRead (JoyStick_X) * (5.0 / 1023.0); 
  y = analogRead (JoyStick_Y) * (5.0 / 1023.0);
  Knopf = digitalRead (Button);
   
  //... et envoyées à la sortie série.
  Serial.print ("Axe X:"); Serial.print (x, 4);  Serial.print ("V, ");
  Serial.print ("Axe Z:"); Serial.print (y, 4);  Serial.print ("V, ");
  Serial.print ("Bouton:");
 
  if(Knopf==1)
  {
      Serial.println (" pas de pression sur le bouton");
  }
  else
  {
      Serial.println (" pression sur le bouton");
  }
  delay (200);
}