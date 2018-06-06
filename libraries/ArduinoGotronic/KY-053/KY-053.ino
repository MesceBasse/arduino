#include <Wire.h>
#include <Adafruit_ADS1015.h>
 
// Initialisation du module ADS1115. Toutes les opérations avec
// l'ADC peuvent être réalisées à l'aide de l'objet ads
Adafruit_ADS1115 ads; 
 
void setup(void) 
{
  Serial.begin(9600);
   
  Serial.println("Lecture des tensions aux bornes A0 a A3 du circuit ADS1115 (A0..A3) en envoi vers la liaison serie");
  Serial.println("Plage ADC: +/- 6.144V (1 bit = 0.1875mV)");
   
  // Ce module présente un amplificateur de signal à ses entrées analogiques
  // dont le gain peut être configuré comme décrit ci-dessous.
  // Ceci est utilie lorque par exemple on s'attend à obtenir un résultat dans une
  // certaine plage de mesure mais que le résultat est plus grand que prévu.
  // Le gain par défaut est Gain=[2/3] et peut être modifié simplement en enlevant les // de commentaires.
  //                                                                ADS1115
  //                                                                -------  
  ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 0.1875mV 
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.0078125mV
   
  ads.begin();
}
 
void loop(void) 
{
  uint16_t adc0, adc1, adc2, adc3;
  float voltage0, voltage1, voltage2, voltage3;
  float gain_conversion_factor;
   
  // La commande "ads.readADC_SingleEnded(0)" est la fonction principale quifait démarrer la mesure dans l'ADC.
  // Le "0" en tant que variable pour cette fonction définit le canal à mesurer.
  // Si on voulait mesurer sur le troisième canal, on aurait chané le "0" en "2"
  adc0 = ads.readADC_SingleEnded(0); 
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);
   
  // Cette valeur est nécessaire pour la conversion en une tension. 
  // La valeur appropriée pour le gain doit être reprise dans la table ci-dessus
  gain_conversion_factor= 0.1875;
   
  // Conversion des valeurs enregistrées en tension
  voltage0 = (adc0 * gain_conversion_factor);
  voltage1 = (adc1 * gain_conversion_factor);
  voltage2 = (adc2 * gain_conversion_factor);
  voltage3 = (adc3 * gain_conversion_factor);
   
  // Envoi des valeurs vers l'interface série
  Serial.print("Entree analogique 0: "); Serial.print(voltage0);Serial.println("mV");
  Serial.print("Entree analogique 1: "); Serial.print(voltage1);Serial.println("mV");
  Serial.print("Entree analogique 2: "); Serial.print(voltage2);Serial.println("mV");
  Serial.print("Entree analogique 3: "); Serial.print(voltage3);Serial.println("mV");
  Serial.println("------------------------");
   
  delay(1000);
}