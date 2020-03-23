# LoRaWAN-example

## Testing sleep/standby modes
For this test it is assumed the "LoRaWAN + EEPROM shield by Sille VL" is used.

No other sensors have to be connected, arbitrary values are used.
1. `git clone git@github.com:vives-projectwerk-2-2020/LoRaWAN-example.git`
2. `cd LoRaWAN-example`
2. `git checkout sleep-modes`
3. `mbed deploy`
3. use the `settings.example.h` file to create your custom `settings.h` file (contact Maxim to be added as a project collaborator to the TTN application)
4. `mbed compile -f` (with nucleo board connected)

## How to setup a new project
+ create a new mbed project and add both libraries and mbed-os as dependecies
+ add your keys and pin-out in a settings.h file (as per example in settings.example.h)


## Dependencies

### Simple LoRaWAN library (by sillevl)

[https://github.com/sillevl/mbed-Simple-LoRaWAN](https://github.com/sillevl/mbed-Simple-LoRaWAN)

### LoRaWAN Serialization library (by sillevl)

[https://github.com/sillevl/mbed-lorawan-serialization](https://github.com/sillevl/mbed-lorawan-serialization)

This library has been extended to use the following functions to add measurements:
+ addTemperature()
+ addHumidity()
+ addPressure()
+ addPM()