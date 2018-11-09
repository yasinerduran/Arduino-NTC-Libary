
#define ArduinoNTCLibary_H
#include <Arduino.h>
class NTC{
    private:

    public:
        NTC(int pin, float seriesResistor=10000);
        ~NTC();
        int pin;
        float seriesResistor;
        float measureTemperature(int sample_count);
        float measureResist(int sample_count);
        float calculateResistance();
        float resistToTemp(float resistance);
};

#include "NtcTables/2K2Tables.h"
