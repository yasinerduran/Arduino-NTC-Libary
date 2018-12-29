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
      termistor_1.setNTCPin(A0);
      termistor_1.setReferanceResistance(10000);
      termistor_1.setReferanceBetaConfidency(3900.0);
      termistor_1.setReferanceResistanceAt25C(2250.0);
      termistor_1.setReferanceMaxVoltageOfADC(4.60);
      termistor_1.setReferanceMaxADC(1024.00);
```
 
           
         


