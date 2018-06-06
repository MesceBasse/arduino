////////////////////////////////////////////////////////////////////////
/// Copyright (c)2015 Dan Truong
/// Permission is granted to use this software under the MIT
/// licence, with my name and copyright kept in source code
/// http://http://opensource.org/licenses/MIT
///
/// KY039 Arduino Heartrate Monitor V1.0 (April 02, 2015)
////////////////////////////////////////////////////////////////////////
 
/// Commentaires en français de GO TRONIC
///
////////////////////////////////////////////////////////////////////////
/// @param[in] IRSensorPin broche analogique à laquelle est raccordé le capteur
/// @param[in] delay (msec) Le délai entre les appels de la fonction de balayage.
/// Les meilleurs résultats sont obtenus si vous appelez la fonction 5 fois/pulsation
/// Pas plus lent que 150 ms pour environ 70 pulsations/min.
/// Un délai de 60 ms ou plus rapide pour aller lusqu'à 200 pulsations/min.
///
///
/// @Résumé
/// Sortie Vraie si une pulsation est détectée
/// Ce code détecte seulement les impulsions, il ne donne
/// pas la forme d'onde des impulsions cardiaques.
///
///
////////////////////////////////////////////////////////////////////////
 
int rawValue;
 
 
bool heartbeatDetected(int IRSensorPin, int delay)
{
  static int maxValue = 0;
  static bool isPeak = false;
   
   
  bool result = false;
  Serial.println(rawValue);
  rawValue = analogRead(IRSensorPin);
  // La tension au phototransistor est lue et stockée dans la variable rawValue
  rawValue *= (1000/delay);
 
  // Si la valeur de la dernière mesure dévie trop 
 // (par exemple parce que le doigt a été enlevé ou a bougé)
 // maxValue se réinitialisee.
  if (rawValue * 4L < maxValue) {    maxValue = rawValue * 0.8;
  }
   
  // Detect new peak
  if (rawValue > maxValue - (1000/delay)) {
    // Détection de l'impulsion. Si la nouvelle rawValue est plus grande
    // que la dernière valeur maximale, elle sera prise en compte en enregistrée
    if (rawValue > maxValue) {
      maxValue = rawValue;
    }
    // Attribution des pulsations
    if (isPeak == false) {
      result = true;
    }
    isPeak = true;
  } else if (rawValue < maxValue - (3000/delay)) {
    isPeak = false;
    // La valeur maximale est légèrement diminuée à chaque passage.
    // Cela peut prendre plusieurs secondes pour détecter de nouveau
    // le signal lorsque le doigt a bougé ou que le capteur est devant
    // une partie osseuse du doigt. On peut aussi vérifier le délai
    // depuis la dernière pulsation et s'il excède 1 seconde, on
    // rénitialise maxValue
    maxValue-=(1000/delay);
 }
  return result;
}
 
 
////////////////////////////////////////////////////////////////////////
// Arduino main code
////////////////////////////////////////////////////////////////////////
int ledPin=13;
int analogPin=0;
 
void setup()
{
  // La LED Arduino intégrée (Digital 13) est utilisée pour la sortie
  pinMode(ledPin,OUTPUT);
   
  // Initialisation du moniteur série
  Serial.begin(9600);
  Serial.println("Heartbeat detection examplecode.");
}
 
const int delayMsec = 60; // 100msec per sample
 
// Le programme principal a deux sorties:
// - Si un battement de coeur est détecté, le voyant clignote
// - L'impulsion est calculée et envoyée vers la sortie série.
 
void loop()
{
  static int beatMsec = 0;
  int heartRateBPM = 0;
  if (heartbeatDetected(analogPin, delayMsec)) {
    //heartRateBPM = 60000 / beatMsec;
    // Sortie LED par impulsion
    digitalWrite(ledPin,1);
 
    // Envoi des données série
    Serial.println("Heartrate: coucou");
    //Serial.println(heartRateBPM);
     
    beatMsec = 0;
  } else {
    digitalWrite(ledPin,0);
  }
  delay(delayMsec);
  beatMsec += delayMsec;
}
