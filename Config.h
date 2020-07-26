/**********************************************************************

Config.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE MOTOR_SHIELD_TYPE ACCORDING TO THE FOLLOWING TABLE:
//
//  0 = ARDUINO MOTOR SHIELD          (MAX 18V/2A PER CHANNEL)
//  1 = POLOLU MC33926 MOTOR SHIELD   (MAX 28V/3A PER CHANNEL)

#define MOTOR_SHIELD_TYPE   0

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE NUMBER OF MAIN TRACK REGISTER

#define MAX_MAIN_REGISTERS 12

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE COMMUNICATIONS INTERFACE
//
//  0 = Built-in Serial Port
//  1 = Arduino.cc Ethernet/SD-Card Shield
//  2 = Arduino.org Ethernet/SD-Card Shield
//  3 = Seeed Studio Ethernet/SD-Card Shield W5200
//  4 = adafruit-atwinc1500 WiFi module

#define COMM_INTERFACE   4

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE STATIC IP ADDRESS *OR* COMMENT OUT TO USE DHCP
//

//#define IP_ADDRESS { 192, 168, 1, 200 }

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE PORT TO USE FOR ETHERNET COMMUNICATIONS INTERFACE
//

#define ETHERNET_PORT 2560

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE MAC ADDRESS ARRAY FOR ETHERNET COMMUNICATIONS INTERFACE
//

#define MAC_ADDRESS {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEF }

/////////////////////////////////////////////////////////////////////////////////////
// Options for Travis Farmer's code changes
//

// timer for reset checking, in milliseconds
// NOTE: this is a GLOBAL timer. it doesn't reset X milliseconds after a short,
// it resets when the global timer, set below, comes around to check for a reset.
#define MAIN_LINE_RESET_DELAY 3000

// how many times the circuit will reset before the main power must be recycled
#define MAIN_LINE_RESET_MAX 3

#define USE_MCP_IO 1 // 1 = active. replace Arduino pin I/O, with MCP I/O.
#define USE_CT_SENSE 0 // 1 = active. use for bipolar current sensing, with 2.5V bias
#define USE_ACK_FOLLOW_PIN 0 // 0 = inactive, otherwise, enter output pin number.
// #define USE_IIC_LCD 0
