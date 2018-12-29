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
      termistor_1.setReferanceMaxADC(1024.00); // ADC reading bit value. 
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
      termistor_1.measureNTCTemperature() // Fahreneit version
   ```
   * NTC's pin connection status :
   ```c
      if(termistor_1.getNTCStatus()){
            // NTC Connected.
      }
      else{
            // NTC Not Connected.
      }
   ```
* Example Code 
 ```c
      // You can find this sketch in path /examples/basicCalculation/basicCalculation.ino
      #include "ArduinoNTCLibary.h"
      NTC termistor_1 = NTC();

      void setup(){
            Serial.begin(9600);
            termistor_1.setNTCPin(A0);
            termistor_1.setReferanceResistance(10000);
            termistor_1.setReferanceBetaConfidency(3900.0);
            termistor_1.setReferanceResistanceAt25C(2250.0);
            termistor_1.setReferanceMaxVoltageOfADC(4.60);
            termistor_1.setReferanceMaxADC(1024.00);
      }

      void loop(){
            int sample_count = 10;
            
            delay(1000);
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
      }
   ```
 * Depencies
   * Statistic Libary https://github.com/yasinerduran/statistics


