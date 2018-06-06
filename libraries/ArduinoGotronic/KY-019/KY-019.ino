int relay = 10; // Déclaration de la broche de raccordement du relais
 
int delayTime = 1; // Délai entre 2 commutations
 
void setup ()
{
  pinMode (relay, OUTPUT); // La broche est déclarée en tant que sortie
}
 
// Le programme simule un clignotant. Il fait commuter le relais d'une position à 
// l'autre avec un délai paramétré (delayTime).
void loop ()
{
  digitalWrite (relay, HIGH); // "NO" est passant;
  delay (delayTime * 1000);
  digitalWrite (relay, LOW); // "NC" est passant;
  delay (delayTime * 1000);
}
