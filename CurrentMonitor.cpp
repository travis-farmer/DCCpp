/**********************************************************************

CurrentMonitor.cpp
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#include "DCCpp.h"
#include "CurrentMonitor.h"
#include "Comm.h"

///////////////////////////////////////////////////////////////////////////////

CurrentMonitor::CurrentMonitor(int pin, int Apin,int csm, char *msg){
    this->pin=pin;
    this->Apin=Apin;
    this->msg=msg;
    current=0;
    Counter=0;
    this->MaxCurrent = csm;
    pinMode(pin,OUTPUT);
    pins[PinCounter] = pin;
    Apins[PinCounter] = Apin;
    PinCounter++;
  } // CurrentMonitor::CurrentMonitor

boolean CurrentMonitor::checkTime(){
  if(millis()-sampleTime<CURRENT_SAMPLE_TIME)            // no need to check current yet
    return(false);
  sampleTime=millis();                                   // note millis() uses TIMER-0.  For UNO, we change the scale on Timer-0.  For MEGA we do not.  This means CURENT_SAMPLE_TIME is different for UNO then MEGA
  return(true);
} // CurrentMonitor::checkTime

void CurrentMonitor::check(){
    //current=map(analogRead(pin)*CURRENT_SAMPLE_SMOOTHING+current*(1.0-CURRENT_SAMPLE_SMOOTHING),512,1023,0,1023);        // compute new exponentially-smoothed current
  current=(calcADCforCT(analogRead(Apin))*CURRENT_SAMPLE_SMOOTHING+current*(1.0-CURRENT_SAMPLE_SMOOTHING));
  if(current>MaxCurrent){                    // current overload and Prog Signal is on (or could have checked Main Signal, since both are always on or off together)
    if (digitalRead(pin) == HIGH)
    {
      digitalWrite(pin,LOW);
      INTERFACE.print(msg);
      Counter++;
    }
  }
} // CurrentMonitor::check

void CurrentMonitor::Power(bool enable)
{
  digitalWrite(pin,enable);
  if (enable == false)
  {
    Counter = 0;
  }
}

void CurrentMonitor::Reset()
{
  if (Counter > 0 && Counter <= MAIN_LINE_RESET_MAX)
  {
    digitalWrite(pin, HIGH);
  }
}

void CurrentMonitor::PowerAll(bool enable)
{
  for (int I = 0; I < PinCounter; I++)
  {
    digitalWrite(pins[I],enable);
    if (enable == true)
    {
      //SendExtInfo(0x00,0x01);
      //SendExtInfo(0x01,0x01);
    }
    else
    {
      Counter = 0;
      //SendExtInfo(0x00,0x00);
      //SendExtInfo(0x01,0x00);
    }
  }
}

int CurrentMonitor::CalcTotalCurrent()
{
  int OutVal = 0;
  for (int I = 0; I < PinCounter; I++)
  {
    OutVal = (OutVal + analogRead(Apins[I]));
  }
  return (OutVal);
}

long int CurrentMonitor::sampleTime=0;

