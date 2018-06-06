#define Echo_EingangsPin 7 // Broche d'entrée Echo
#define Trigger_AusgangsPin 8 // Broche de sortie Trigger
 
// Définition des variables nécessaires
int maximumRange = 300; 
int minimumRange = 2; 
long Distance;
long Duree;
 
void setup() {
 pinMode(Trigger_AusgangsPin, OUTPUT);
 pinMode(Echo_EingangsPin, INPUT);
 Serial.begin (9600);
}
 
void loop() {
 
 // Le début de la mesure est lancé par un signal de 10µs sur Trigger
 digitalWrite(Trigger_AusgangsPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(Trigger_AusgangsPin, LOW);
  
 // Attente à l'entrée Echo jusqu'à ce que le signal soit activé
 // et mesure de la durée
 Duree = pulseIn(Echo_EingangsPin, HIGH);
  
 // Calcul de la distance en fonction du temps enregistré
 Distance = Duree/58.2;
  
 // On vérifie si le signal se trouve dans la plage de mesure du capteur
 if (Distance >= maximumRange || Distance <= minimumRange)
 {
    // Si ce n'est pas le cas, affichage d'un signal d'erreur
      Serial.println("Distance en-dehors de la portee");
      Serial.println("-----------------------------------");
 }  
  
 else
 {
    // La distance calculée est envoyée vers la sortie série
      Serial.print("La distance mesure:");
      Serial.print(Distance);
      Serial.println("cm");
      Serial.println("-----------------------------------");
 }
  // Pause entre les mesures
 delay(500);
}