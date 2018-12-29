#include "ArduinoNTCLibary.h"
#include "math.h"
#include "Statistics.h"

NTC :: NTC(){
    last_temp = 0;
}

NTC :: NTC(bool is_queue_mode){
    is_queue= is_queue_mode;
    if(is_queue){

    }
}

void NTC :: setNTCPin(int _pin){
    ntc_pin = _pin;
    pinMode(ntc_pin,INPUT);
}


//Pin of Probe Control
bool NTC :: getNTCStatus(){
    double resistance = measureNTCResistance(3);
    if(resistance<5000.00){
        return true;
    }
    return false;
}

//Series resistance's methods
void  NTC :: setReferanceResistance(float _resistance){
    ref_resistance = _resistance;
}

float NTC :: getReferanceResistance(){
    return ref_resistance;
}

//MCU's or other ADC supplyers values
void NTC :: setReferanceMaxADC(int _adc){
    ref_max_adc = _adc;
}

int  NTC :: getReferanceMaxADC(){
    return ref_max_adc;
}

//MCU's or other ADC supplyers values
void NTC :: setReferanceMaxVoltageOfADC(float _voltage){
    ref_max_voltage = _voltage;
}

float NTC :: getReferanceMaxVoltageOfADC(){
    return ref_max_voltage;
}

//
void  NTC :: setReferanceBetaConfidency(float _confidency_val){
    ref_beta_confidency = _confidency_val;
}

float NTC :: getReferanceBetaConfidency(){
    return ref_beta_confidency;
}

//
void  NTC :: setReferanceResistanceAt25C(float _resistance){
    ref_r25 = _resistance;
}

float NTC :: getReferanceResistanceAt25C(){
    return ref_r25;
}

//
float NTC :: measureNTCVoltage(){
    float voltage = 0;
    for(int i=0; i<10; i++){
        voltage += analogRead(ntc_pin);
    }
    voltage = voltage / 10;
    voltage = (ref_max_voltage * voltage) / ref_max_adc;
    return voltage;
}

float NTC :: measureNTCVoltage(int _count){
    float summary = 0;
    for(int i =0; i < _count; i++){
        summary +=  measureNTCVoltage();
    }
    float mean = summary / _count;
    return mean;
}

//    
float NTC :: measureNTCResistance(){
    float ntc_voltage = measureNTCVoltage();
    return ref_resistance * ( ntc_voltage / (ref_max_voltage - ntc_voltage));
}

//
float NTC :: measureNTCResistance(int _count){
    float summary = 0;
    for(int i =0; i < _count; i++){
        summary +=  measureNTCResistance();
    }
    float mean = summary / _count;
    return mean;
}

//
float NTC :: measureNTCTemperature(){
    digitalWrite(adc_supply_output_pin,HIGH);
    float ntc_resistance = measureNTCResistance();
    return 1 / ( (log(ntc_resistance / ref_r25) / ref_beta_confidency) + (1.00 / 298.15));
}

float NTC :: measureNTCTemperature(int _count){
    Statistics stats(_count);
    for(int i =0; i < _count; i++){
          stats.addData(measureNTCTemperature());
    }
    float data = stats.mod();
    stats.reset();
    return data;
}

//
float NTC :: measureNTCTemperatureCelcius(){
    return measureNTCTemperature() - 273.15;
}

float NTC :: measureNTCTemperatureCelcius(int _count){
    Statistics stats(_count);
    for(int i =0; i < _count; i++){
          stats.addData(measureNTCTemperature());
    }
    float data = stats.mod();
    last_temp = data;
    stats.reset();
    return data - 273.15;
    
    
}
