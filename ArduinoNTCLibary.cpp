#include "ArduinoNTCLibary.h"

/*0-> 2200K NTC Temperature Table*/

NTC :: NTC(int pin_ , float seriesResistor_ = 10000){
    pin = pin_;
    seriesResistor = seriesResistor_;
}

NTC ::~NTC(){

}

float  NTC :: measureTemperature(int sample_count = 10){
    float average_temperature = 0;
    for(int i = 0; i < sample_count; i++){
        float resistance = calculateResistance();
        average_temperature += resistToTemp(resistance);
    }
    average_temperature = average_temperature/sample_count;
    return average_temperature;
}


float  NTC :: measureResist(int sample_count = 10){
    float average_resist = 0;
    for(int i = 0; i < sample_count; i++){
        float resistance = calculateResistance();
        average_resist += resistance;
    }
    average_resist = average_resist/sample_count;
    return average_resist;
}



float NTC :: calculateResistance(){
    float reading = analogRead(pin);
    // convert the value to resistance
    reading = (1023 / reading)  - 1;     // (1023/ADC - 1) 
    return (seriesResistor / reading);
}

float NTC ::  resistToTemp(float resistance){
    for(int i =0; i<=sizeof(resist2200); i++){
        if(resist2200[i][1]<resistance){
            float range = resist2200[i][1] - resist2200[i+1][1];
            float dfiRange = resistance - resist2200[i][1];
            float minmax = (dfiRange - 0)/(range - 0);
            return resist2200[i-1][0]+(1-minmax) ; 
        }
    }
}