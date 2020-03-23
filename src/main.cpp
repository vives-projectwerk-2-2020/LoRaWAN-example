#pragma once

#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "AmbiantSensorMessage.h"
#include "settings.h"
#include <ctime>

Serial pc(USBTX, USBRX, 115200);

SimpleLoRaWAN::Node node(keys, pins);

int main(void)
{
  pc.baud(115200);
  pc.printf("\r\n[Sleep-Mode-Test] Loading Firmware ...\r\n");

  // Get time to show time interval between send actions
  time_t now = time(0);
  tm *ltm = localtime(&now);
  
  double temperature = 22.64;  // value in °C
  double humidity = 9.55;      // value in %
  double pressure = 1013.5;    // value in hPa
  double pm25 = 12.3;          // value in µg/m³
  double pm10 = 23.4;          // value in µg/m³

  while(true) {
    ParticulaLora::AmbiantSensorMessage message;

    message.addTemperature(temperature);
    message.addHumidity(humidity);
    message.addPressure(pressure);
    message.addPM(pm25);
    message.addPM(pm10);

    pc.printf("[Sleep-Mode-Test] Sending message ...\r\n");
    // Implementing standby mode (warm start - radio config is saved - higher currect draw - 600nA)
    node.send(message.getMessage(), message.getLength());
    pc.printf("[Sleep-Mode-Test] [%d:%d:%d] Going to standby mode (warm start) ...\r\n",(1 + ltm->tm_hour), (1 + ltm->tm_min), (1 + ltm->tm_sec));
    pc.printf("[Sleep-Mode-Test] Theoretical current draw: 600nA ...\r\n");
    wait(1); // Seems not to work without this
    node.warm_start();
    wait(60.0);

    pc.printf("[Sleep-Mode-Test] Sending message ...\r\n");
    // Implementing sleep mode (cold start - radio config is not saved - lower current draw - 160nA)
    node.send(message.getMessage(), message.getLength());
    pc.printf("[Sleep-Mode-Test] [%d:%d:%d] Going to sleep mode (cold start) ...\r\n",(1 + ltm->tm_hour), (1 + ltm->tm_min), (1 + ltm->tm_sec));
    pc.printf("[Sleep-Mode-Test] Theoretical current draw: 160nA ...\r\n");
    wait(1); // Seems not to work without this
    node.cold_start();
    wait(60.0);
  }
}