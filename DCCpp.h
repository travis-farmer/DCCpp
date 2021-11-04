/**********************************************************************

DCCpp.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#include "Config.h"

#ifndef DCCpp_Uno_h
#define DCCpp_Uno_h

/////////////////////////////////////////////////////////////////////////////////////
// RELEASE VERSION
/////////////////////////////////////////////////////////////////////////////////////

#define VERSION "1.2.1+TJF004"

/////////////////////////////////////////////////////////////////////////////////////
// AUTO-SELECT ARDUINO BOARD
/////////////////////////////////////////////////////////////////////////////////////

#ifdef ARDUINO_AVR_MEGA                   // is using Mega 1280, define as Mega 2560 (pinouts and functionality are identical)
  #define ARDUINO_AVR_MEGA2560
#endif

#if defined  ARDUINO_AVR_UNO

  #define ARDUINO_TYPE    "UNO"

  #define DCC_SIGNAL_PIN_MAIN 10          // Ardunio Uno  - uses OC1B
  #define DCC_SIGNAL_PIN_PROG 5           // Arduino Uno  - uses OC0B

  #if COMM_INTERFACE != 0                 // Serial was not selected

    #error CANNOT COMPILE - DCC++ FOR THE UNO CAN ONLY USE SERIAL COMMUNICATION - PLEASE SELECT THIS IN THE CONFIG FILE

  #endif

#else

  #error CANNOT COMPILE - DCC++ ONLY WORKS WITH AN ARDUINO UNO OR AN ARDUINO MEGA 1280/2560

#endif

/////////////////////////////////////////////////////////////////////////////////////
// SELECT MOTOR SHIELD
/////////////////////////////////////////////////////////////////////////////////////

#if MOTOR_SHIELD_TYPE == 0

  #define MOTOR_SHIELD_NAME "ARDUINO MOTOR SHIELD"

  #define SIGNAL_ENABLE_PIN_MAIN 3
  #define SIGNAL_ENABLE_PIN_PROG 11

  #define CURRENT_MONITOR_PIN_MAIN A0
  #define CURRENT_MONITOR_PIN_PROG A1

  #define DIRECTION_MOTOR_CHANNEL_PIN_A 9 //12
  #define DIRECTION_MOTOR_CHANNEL_PIN_B 13

#else

  #error CANNOT COMPILE - PLEASE SELECT A PROPER MOTOR SHIELD TYPE

#endif

/////////////////////////////////////////////////////////////////////////////////////
// SELECT COMMUNICATION INTERACE
/////////////////////////////////////////////////////////////////////////////////////

#if COMM_INTERFACE == 0

  #define COMM_TYPE 0
  #define INTERFACE Serial


#else

  #error CANNOT COMPILE - Please select a proper value for COMM_INTERFACE in CONFIG.H file

#endif

/////////////////////////////////////////////////////////////////////////////////////
// SET WHETHER TO SHOW PACKETS - DIAGNOSTIC MODE ONLY
/////////////////////////////////////////////////////////////////////////////////////

// If SHOW_PACKETS is set to 1, then for select main operations track commands that modify an internal DCC packet register,
// if printFlag for that command is also set to 1, DCC++ BASE STATION will additionally return the
// DCC packet contents of the modified register in the following format:

//    <* REG: B1 B2 ... Bn CSUM / REPEAT>
//
//    REG: the number of the main operations track packet register that was modified
//    B1: the first hexidecimal byte of the DCC packet
//    B2: the second hexidecimal byte of the DCC packet
//    Bn: the nth hexidecimal byte of the DCC packet
//    CSUM: a checksum byte that is required to be the final byte in any DCC packet
//    REPEAT: the number of times the DCC packet was re-transmitted to the tracks after its iniital transmission

#define SHOW_PACKETS  0       // set to zero to disable printing of every packet for select main operations track commands

/////////////////////////////////////////////////////////////////////////////////////

#endif
