#include <math.h>

int sensorPin = A5; // Déclaration de la broche d'entrée

// Cette fonction convertit la valeur analogique lue en température en °C
double Thermistor(int RawADC)
{
	double Temp;
	Temp = log(10000.0 * ((1024.0 / RawADC - 1)));
	Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
	Temp = Temp - 273.15;            // conversion de degrés Kelvin en °C
	return Temp;
}

// Sortie série à 9600 bauds
void setup()
{
	Serial.begin(9600);
}

// le programme mesure la valeur de tension continue à la CTN et convertit le résultat en ° C pour la sortie série
void loop()
{
	int readVal = analogRead(sensorPin);
	double temp =  Thermistor(readVal);

	// Sortie vers l'interface série
	Serial.print("La temperature actuelle est:");
	Serial.print(temp); 
        Serial.print(char(186)); //Impression du symbole <°>
	Serial.println("C");
	Serial.println("---------------------------------------");

	delay(500);
}