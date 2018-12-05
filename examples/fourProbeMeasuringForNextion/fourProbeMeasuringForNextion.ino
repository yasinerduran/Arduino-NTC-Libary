#include "ArduinoNTCLibary.h"
NTC termistor_1 = NTC();
NTC termistor_2 = NTC();
NTC termistor_3 = NTC();
NTC termistor_4 = NTC();

void setup(){
    Serial.begin(9600);
    //Initialize Termistor 1
    termistor_1.setNTCPin(A0);
    termistor_1.setSupplyPin(A7);
    termistor_1.setReferanceResistance(9999);
    termistor_1.setReferanceBetaConfidency(3976.0);
    termistor_1.setReferanceResistanceAt25C(2252.0);
    termistor_1.setReferanceMaxVoltageOfADC(4.60);
    termistor_1.setReferanceMaxADC(1024.00);

    //Initialize Termistor 2
    termistor_2.setNTCPin(A1);
    termistor_2.setSupplyPin(A7);
    termistor_2.setReferanceResistance(9999);
    termistor_2.setReferanceBetaConfidency(3976.0);
    termistor_2.setReferanceResistanceAt25C(2252.0);
    termistor_2.setReferanceMaxVoltageOfADC(4.60);
    termistor_2.setReferanceMaxADC(1024.00);

    //Initialize Termistor 3
    termistor_3.setNTCPin(A2);
    termistor_3.setSupplyPin(A7);
    termistor_3.setReferanceResistance(9999);
    termistor_3.setReferanceBetaConfidency(3976.0);
    termistor_3.setReferanceResistanceAt25C(2252.0);
    termistor_3.setReferanceMaxVoltageOfADC(4.60);
    termistor_3.setReferanceMaxADC(1024.00);

    //Initialize Termistor 4
    termistor_4.setNTCPin(A3);
    termistor_4.setSupplyPin(A7);
    termistor_4.setReferanceResistance(9999);
    termistor_4.setReferanceBetaConfidency(3976.0);
    termistor_4.setReferanceResistanceAt25C(2252.0);
    termistor_4.setReferanceMaxVoltageOfADC(4.60);
    termistor_4.setReferanceMaxADC(1024.00);
}

void loop(){
    int sample_count = 100;
    
    float termistor_1_temperature = termistor_1.measureNTCTemperatureCelcius(sample_count); 
    printInteger("n0", termistor_1_temperature);
    printDecimal("n1", termistor_1_temperature);

    float termistor_2_temperature = termistor_2.measureNTCTemperatureCelcius(sample_count); 
    printInteger("n2", termistor_2_temperature);
    printDecimal("n3", termistor_2_temperature);

    float termistor_3_temperature = termistor_3.measureNTCTemperatureCelcius(sample_count); 
    printInteger("n4", termistor_3_temperature);
    printDecimal("n5", termistor_3_temperature);
    
    float termistor_4_temperature = termistor_4.measureNTCTemperatureCelcius(sample_count); 
    printInteger("n6", termistor_4_temperature);
    printDecimal("n7", termistor_4_temperature);

    delay(200);
}

void printInteger(String item, double temperature_){
   Serial.print(item + ".val=");
  String temperature = String(temperature_);
  int n = temperature.length();  
  char char_array[n+1];
  strcpy(char_array, temperature.c_str());
  Serial.print(String(char_array[0])+String(char_array[1]));
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}

void printDecimal(String item, double temperature_){
   Serial.print(item + ".val=");
  String temperature = String(temperature_);
  int n = temperature.length();  
  char char_array[n+1];
  strcpy(char_array, temperature.c_str());
  Serial.print(char_array[3]);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}