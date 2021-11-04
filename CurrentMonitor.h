/**********************************************************************

CurrentMonitor.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#ifndef CurrentMonitor_h
#define CurrentMonitor_h

#include "Arduino.h"

#define  CURRENT_SAMPLE_SMOOTHING   0.01
#define  CURRENT_SAMPLE_MAX_PROG         96 // ~4A

#ifdef ARDUINO_AVR_UNO                        // Configuration for UNO
  #define  CURRENT_SAMPLE_TIME        10
#else                                         // Configuration for MEGA
  #define  CURRENT_SAMPLE_TIME        1
#endif

extern int PinCounter;
extern int pins[];
extern int Apins[];
extern void SendExtInfo(byte outAddr, byte outValue);


struct CurrentMonitor{
  static long int sampleTime;
  int pin;
  int Apin;
  float current;
  float MaxCurrent;
  char *msg;
  CurrentMonitor(int, int, int, char *);
  static boolean checkTime();
  void check();
  int Counter;
  void Power(bool);
  void Reset();
  void PowerAll(bool);
  int CalcTotalCurrent();
};

#endif

