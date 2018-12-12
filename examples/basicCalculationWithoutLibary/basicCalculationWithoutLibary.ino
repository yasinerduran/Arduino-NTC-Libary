//http://www.giangrandi.ch/electronics/ntc/ntc.shtml
#include "math.h"

float ref_adc = 1024.00;
float ref_voltage = 4.60;
float ref_resistance = 9999;

int adc_ref_output = A7;
int adc_ref_input = A6;



int ntc = A0;
float ntc_beta_confidency = 3927.0;
float ntc_r25 = 2248.0;



void setup()
{
    Serial.begin(9600);
	pinMode(adc_ref_output, OUTPUT);
    pinMode(adc_ref_input, INPUT);
}

void loop()
{
	analogWrite(adc_ref_output,255);
    float adc_ref_input_value = analogRead(adc_ref_input);
    float adc_ref_input_voltage = (ref_voltage * adc_ref_input_value) / ref_adc;
    Serial.print("Referance Voltage => ");
    Serial.println(adc_ref_input_voltage);

    float ntc_adc = analogRead(ntc);
    float ntc_voltage = (ref_voltage * ntc_adc) / ref_adc;
    Serial.print("NTC Voltage => ");
    Serial.println(ntc_voltage);
    
    float ntc_resistance = ref_resistance * (ntc_voltage / (ref_voltage-ntc_voltage));
    Serial.print("NTC Resistance => ");
    Serial.println(ntc_resistance);

    float ntc_temperature = 1 / ( (log(ntc_resistance / ntc_r25) / ntc_beta_confidency) + (1.00 / 298.15));
    Serial.print("NTC Temperature Kelvin => ");
    Serial.println(ntc_temperature);

    ntc_temperature -= 273.15f;
    Serial.print("NTC Temperature Celcius => ");
    Serial.println(ntc_temperature); 
    delay(1000);



}
