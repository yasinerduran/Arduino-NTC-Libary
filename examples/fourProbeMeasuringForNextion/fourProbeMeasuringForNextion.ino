#include "ArduinoNTCLibary.h"
NTC termistor_1 = NTC();
NTC termistor_2 = NTC();
NTC termistor_3 = NTC();
NTC termistor_4 = NTC();

void setup(){
    Serial.begin(9600);
    //Initialize Termistor 1
    termistor_1.setNTCPin(A0);
    termistor_1.setReferanceResistance(9999);
    termistor_1.setReferanceBetaConfidency(3976.0);
    termistor_1.setReferanceResistanceAt25C(2252.0);
    termistor_1.setReferanceMaxVoltageOfADC(4.60);
    termistor_1.setReferanceMaxADC(1024.00);

    //Initialize Termistor 2
    termistor_2.setNTCPin(A1);
    termistor_2.setReferanceResistance(9999);
    termistor_2.setReferanceBetaConfidency(3976.0);
    termistor_2.setReferanceResistanceAt25C(2252.0);
    termistor_2.setReferanceMaxVoltageOfADC(4.60);
    termistor_2.setReferanceMaxADC(1024.00);

    //Initialize Termistor 3
    termistor_3.setNTCPin(A2);
    termistor_3.setReferanceResistance(9999);
    termistor_3.setReferanceBetaConfidency(3976.0);
    termistor_3.setReferanceResistanceAt25C(2252.0);
    termistor_3.setReferanceMaxVoltageOfADC(4.60);
    termistor_3.setReferanceMaxADC(1024.00);

    //Initialize Termistor 4
    termistor_4.setNTCPin(A3);
    termistor_4.setReferanceResistance(9999);
    termistor_4.setReferanceBetaConfidency(3976.0);
    termistor_4.setReferanceResistanceAt25C(2252.0);
    termistor_4.setReferanceMaxVoltageOfADC(4.60);
    termistor_4.setReferanceMaxADC(1024.00);
}

void loop(){
    int sample_count = 100;
    if(termistor_1.getNTCStatus()){
        printProbeStatus("va1", 1);
        float termistor_1_temperature = termistor_1.measureNTCTemperatureCelcius(sample_count); 
        printInteger("n0", termistor_1_temperature);
        printDecimal("n1", termistor_1_temperature);
    }
    else{
        printProbeStatus("va1", 0);
    }
    
    if(termistor_2.getNTCStatus()){
        printProbeStatus("va2", 1);
        float termistor_2_temperature = termistor_2.measureNTCTemperatureCelcius(sample_count); 
        printInteger("n3", termistor_2_temperature);
        printDecimal("n2", termistor_2_temperature);
    }
    else{
        printProbeStatus("va2", 0);
    }
    
    if(termistor_3.getNTCStatus()){
        printProbeStatus("va3", 1);
        float termistor_3_temperature = termistor_3.measureNTCTemperatureCelcius(sample_count); 
        printInteger("n5", termistor_3_temperature);
        printDecimal("n4", termistor_3_temperature);
    }
    else{
        printProbeStatus("va3", 0);
    }
    
    if(termistor_4.getNTCStatus()){
        printProbeStatus("va4", 1);
        float termistor_4_temperature = termistor_4.measureNTCTemperatureCelcius(sample_count); 
        printInteger("n7", termistor_4_temperature);
        printDecimal("n6", termistor_4_temperature);
    }
    else{
        printProbeStatus("va4", 0);
    }
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

void printProbeStatus(String item, int probe_val){
  if(probe_val == 0){
      Serial.print(item + ".val=0");
  }
  else{
      Serial.print(item + ".val=1");
  }
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}