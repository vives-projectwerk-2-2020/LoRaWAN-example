# LoRaWAN-example


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