#include "ArduinoNTCLibary.h"
NTC termistor_1 = NTC();


void setup(){
    Serial.begin(9600);
    termistor_1.setNTCPin(A0);
    termistor_1.setReferanceResistance(9999);
    termistor_1.setReferanceBetaConfidency(3927.0);
    termistor_1.setReferanceResistanceAt25C(2248.0);
    termistor_1.setReferanceMaxVoltageOfADC(4.60);
    termistor_1.setReferanceMaxADC(1024.00);
}

void loop(){
    int sample_count = 100;


    Serial.print("NTC Voltage >> ");
    Serial.print(termistor_1.measureNTCVoltage());
    Serial.print(" >> Sampled >>");
    Serial.println(termistor_1.measureNTCVoltage(sample_count));

    Serial.print("NTC Resistance >> ");
    Serial.print(termistor_1.measureNTCResistance());
    Serial.print(" >> Sampled >>");
    Serial.println(termistor_1.measureNTCResistance(sample_count));

    Serial.print("NTC Temperature >> ");
    Serial.print(termistor_1.measureNTCTemperatureCelcius());
    Serial.print(" >> Sampled >>");
    Serial.println(termistor_1.measureNTCTemperatureCelcius(sample_count));

    Serial.println("------------------------------------------------");
    delay(1000);
}