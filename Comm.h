

/**********************************************************************

Comm.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#include "Config.h"

#if COMM_TYPE == 1                 // Ethernet Shield Card Selected

  #if COMM_INTERFACE == 1
    #define COMM_SHIELD_NAME      "ARDUINO-CC ETHERNET SHIELD (WIZNET 5100)"
    #include <Ethernet.h>         // built-in Arduino.cc library
    extern EthernetServer INTERFACE;
      
  #elif COMM_INTERFACE == 2
    #define COMM_SHIELD_NAME      "ARDUINO-ORG ETHERNET-2 SHIELD (WIZNET 5500)"
    #include <Ethernet2.h>        // https://github.com/arduino-org/Arduino
    extern EthernetServer INTERFACE;
      
  #elif COMM_INTERFACE == 3
    #define COMM_SHIELD_NAME      "SEEED STUDIO ETHERNET SHIELD (WIZNET 5200)"
    #include <EthernetV2_0.h>     // https://github.com/Seeed-Studio/Ethernet_Shield_W5200
    extern EthernetServer INTERFACE;
    
  #elif COMM_INTERFACE == 4
    #define COMM_SHIELD_NAME      "adafruit-atwinc1500 WiFi module"
    #include <SPI.h>
    #include <WiFi101.h>             // uses the WiFi101 library
    //#include "arduino_secrets.h"     // https://github.com/arduino-libraries/WiFi101
    extern WiFiServer INTERFACE;
  #endif


#endif
