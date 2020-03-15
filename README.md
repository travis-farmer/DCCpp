# DCCpp
My own changes to the DCC++ Base Station

Original DCC++ source came from https://github.com/DccPlusPlus/BaseStation/tree/master-2.0 all rights belong to the original author, with the exception of any changes i have made.
All files with the commit label Base  Level Copy, are the original files.

Important note: this code may not work for you unless you are using the same hardware that i am using. and as it is under construction, it may not work anyway, given my limited testing prototype.

Arduino Mega 2560

Arduino Ethernet shield (W5100 chipset)

or

Adafruit ATWINC1500 breakout for WiFi ( https://www.adafruit.com/product/2999 )

IBT_2 (BTS7960) motor drivers (from eBay)

the eagle CAD schematic (base-station-v1.sch and base-station-v1.pdf) describes the connections.

I have added support for an MCP23017, in place of the Arduino pins for i/o functions. so far, it supports up to 8, and requires my MCP23017 library.


Some code is original, most from https://github.com/atanisoft , with some modifications that i have done, and to my understanding, it is based on work i did in the past.
