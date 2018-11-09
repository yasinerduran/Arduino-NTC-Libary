
#define ArduinoNTCLibary_H
#include <Arduino.h>

class NTC{
    private:
        float series_resistor;
        int pin;
        double * ntc_table [][2];

    public:
        NTC(int pin);
        NTC(int pin, float series_resistor_);
        ~NTC();

        void setSeriesResistor(float series_resistor_);
        float measureTemperature(int sample_count);
        float measureResist(int sample_count);
        float calculateResistance();
        float resistToTemp(float resistance);
        bool setNTCKind(float ntc_resistance);
};

//NTC Tables 

/*0-> 2200K NTC Temperature Table*/
#include "NtcTables/2K2Tables.h"
