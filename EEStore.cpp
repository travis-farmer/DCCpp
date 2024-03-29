/**********************************************************************

EEStore.cpp
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#include "DCCpp.h"
#include "EEStore.h"
#include "Accessories.h"
#include <EEPROM.h>

///////////////////////////////////////////////////////////////////////////////

void EEStore::init(){


  eeStore=(EEStore *)calloc(1,sizeof(EEStore));

  EEPROM.get(0,eeStore->data);                                       // get eeStore data

  if(strncmp(eeStore->data.id,EESTORE_ID,sizeof(EESTORE_ID))!=0){    // check to see that eeStore contains valid DCC++ ID
    sprintf(eeStore->data.id,EESTORE_ID);                           // if not, create blank eeStore structure (no turnouts, no sensors) and save it back to EEPROM
    eeStore->data.nTurnouts=0;
    eeStore->data.serverID=0;
    EEPROM.put(0,eeStore->data);
  }

  reset();            // set memory pointer to first free EEPROM space
  Turnout::load();    // load turnout definitions
  //DccServer::load();  // load DCC++ server definitions
}

///////////////////////////////////////////////////////////////////////////////

void EEStore::clear(){

  sprintf(eeStore->data.id,EESTORE_ID);                           // create blank eeStore structure (no turnouts, no sensors) and save it back to EEPROM
  eeStore->data.nTurnouts=0;
  eeStore->data.serverID=0;
  EEPROM.put(0,eeStore->data);

}

///////////////////////////////////////////////////////////////////////////////

void EEStore::store(){
  reset();
  Turnout::store();

  //DccServer::store();
  EEPROM.put(0,eeStore->data);
}

///////////////////////////////////////////////////////////////////////////////

void EEStore::advance(int n){
  eeAddress+=n;
}

///////////////////////////////////////////////////////////////////////////////

void EEStore::reset(){
  eeAddress=sizeof(EEStore);
}
///////////////////////////////////////////////////////////////////////////////

int EEStore::pointer(){
  return(eeAddress);
}
///////////////////////////////////////////////////////////////////////////////

EEStore *EEStore::eeStore=NULL;
int EEStore::eeAddress=0;

