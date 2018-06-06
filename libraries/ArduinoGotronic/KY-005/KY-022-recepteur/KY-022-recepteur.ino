// Ajout de la librairie Arduino-IRremote
#include <IRremote.h>
 
// La broche d'entrée correspondante peut être déclarée pour le signal de sortie du KY-022
int RECV_PIN = 11;
 
// La livrairie Arduino-IRremote est initialisée
IRrecv irrecv(RECV_PIN);
decode_results results;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Le récepteur infrarouge démarre
}
 
// Boucle de programme principale
void loop() {
   
  // On vérifie si un signal est reçu sur le récepteur
  if (irrecv.decode(&results)) {
    //Lors de la réception d'un signal, celui-ci est décodé et envoyé dans la console
    Serial.println(results.value, HEX);
    irrecv.resume(); 
  }
}

