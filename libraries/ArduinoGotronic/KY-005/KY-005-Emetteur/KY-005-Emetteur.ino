//Ajout de la librairie Arduino-IRremote...
#include <IRremote.h>
 
//...et initialisation de cette librairie
IRsend irsend;
 
// Les réglages de la sortie à prendre en charge par la librairie
// Les sorties correspondantes sont différentes selon la carte Arduino utilisée
// Arduino UNO:  sortie = D3
// Arduino MEGA: sortie = D9
// Une liste complète des sorties correspondantes est visible à la page
// http://z3t0.github.io/Arduino-IRremote/
void setup()
{
}
 
// Boucle de programme principale
void loop() {
        // L'émetteur envoie le signal A90 (en hexadécimal) en codage 'RC5'.
        // Cette opération est répétée trois fois.Ensuite, une pause de 5 secondes est mise en place.
    for (int i = 0; i < 3; i++) {
        irsend.sendRC5(0xA90, 12); // Signal à envoyer: [0xA90] | Signal de 12 Bits envoyé (hex A90=1010 1001 0000)
        delay(40);
    }
    delay(5000); //Pause de 5 secondes entre les impulsions de transmission.
}