# Arduino-NTC-Libary
This libary calculates NTC's resistance and temperature.
http://www.giangrandi.ch/electronics/ntc/ntc.shtml
Formulations basis from this paper.

__Connection Schematic:__

![Connection Wiring](https://raw.githubusercontent.com/yasinerduran/ArduinoNTCLibary/master/schematics/schematic.PNG)


__Using:__
* Import Libary
```c
      #include "ArduinoNTCLibary.h"
```
* Construct Object
```c
      NTC termistor_1 = NTC();`
```
* Configure NTC's params 
```c
      termistor_1.setNTCPin(A0); // Input sensor pin.
      termistor_1.setReferanceResistance(10000); // Referance resistance value
      termistor_1.setReferanceBetaConfidency(3900.0); // Can calculate with paper.
      termistor_1.setReferanceResistanceAt25C(2250.0); // Can find datasheet of NTC.
      termistor_1.setReferanceMaxVoltageOfADC(4.60); // ADC's supply voltage. Measure 5V pin.  
      termistor_1.setReferanceMaxADC(1024.00); // ADC reding bit value. 
```
* Measuring
   * Voltage Measuring :
   ```c
      termistor_1.measureNTCVoltage() // This method gets pin of input's voltage value.
      termistor_1.measureNTCVoltage(10) // Sampled instance method.  
   ```
   * Resistance Measuring :
   ```c
      termistor_1.measureNTCResistance() // This method gets NTC's Reistance value with calculating voltage.
      termistor_1.measureNTCResistance(10) // Sampled instance method.  
   ```
   * Temperature Measuring :
   ```c
      termistor_1.measureNTCTemperatureCelcius()   // NTC's Temperature's value calculates with 
                                                   // voltage and resitance.
      termistor_1.measureNTCTemperatureCelcius(10) // Sampled instance method.  
      termistor_1.measureNTCTemperature() // Fahrenait version
   ```
           
         


