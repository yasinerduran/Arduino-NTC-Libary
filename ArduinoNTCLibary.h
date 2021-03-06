
#define ArduinoNTCLibary_H
#include <Arduino.h>


class NTC{
    private:
        float ref_max_adc;
        float ref_max_voltage;
        float ref_resistance;
       
        float ref_beta_confidency;
        float ref_r25;
        
        int adc_supply_output_pin;
        int ntc_pin ;
        int ntc_control_pin; 
        float last_temp;
        static NTC * temistor_list;
        static bool is_queue ;
    public:
        NTC();
        NTC(bool is_queue_mode);
        //Set Queue Measuring Mode
        void setQueueMeasuringMode(bool status);

        //Pin Outs and Inputs
        void setNTCPin(int _pin);

        //Pin of Probe Control
        bool getNTCStatus();

        //Series resistance's methods
        void setReferanceResistance(float _resistance);
        float getReferanceResistance();

        //MCU's or other ADC supplyers values
        void setReferanceMaxADC(int _adc);
        int  getReferanceMaxADC();

        //MCU's or other ADC supplyers values
        void setReferanceMaxVoltageOfADC(float _voltage);
        float getReferanceMaxVoltageOfADC();

        void  setReferanceBetaConfidency(float _confidency_val);
        float getReferanceBetaConfidency();
        
        void  setReferanceResistanceAt25C(float _resistance);
        float getReferanceResistanceAt25C();

        float measureNTCVoltage();
        float measureNTCVoltage(int _count);
        
        float measureNTCResistance();
        float measureNTCResistance(int _count);
        
        float measureNTCTemperature();
        float measureNTCTemperature(int _count);

        float measureNTCTemperatureCelcius();
        float measureNTCTemperatureCelcius(int _count);
};
