#include "ArduinoNTCLibary.h"

// A0 Baglı olan pini temsil ediyor,
// Elimde 1 tane ntc oldugu için hepsi A0 yoksa A1,A2 
// Şeklinde devam edicek 

NTC termistor_1(A0);

void setup()
{
	Serial.begin(9600);

}

void loop(){
	// 1. Termistor için
	Serial.print("Termistor 1's Resistance =  ");
	Serial.print(termistor_1.measureResist(10));
	Serial.print(" and Temperature is = ");
	Serial.println(termistor_1.measureTemperature(10));
	
	Serial.println("###########################################################");
	delay(1000);
}
