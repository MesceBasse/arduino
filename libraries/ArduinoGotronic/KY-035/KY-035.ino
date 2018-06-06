int sensorPin = A5; // Déclaration de la broche d'entrée
 
// Sortie série à 9600 bauds
void setup()
{
    Serial.begin(9600);
}
 
// Le programme mesure la valeur de tension au niveau du capteur, <br />//calcule la résistance à partir de cette valeur et de la résistance <br />//série connue et renvoie les résultats à la sortie série.
 
void loop()
{      
        // Mesure de la tension du capteur...
    int rawValue = analogRead(sensorPin);
        float voltage = rawValue * (5.0/1023) * 1000;
         
        float resistance = 10000 * ( voltage / ( 5000.0 - voltage) );
         
    // ... et envoi vers le port série
    Serial.print("Tension:");   Serial.print(voltage); Serial.print("mV");
    Serial.print(", Résistance:"); Serial.print(resistance); Serial.println("Ohm");
    Serial.println("---------------------------------------");
 
    delay(500);
}