# Project Overview
This project is a module for the TrailCurrent solution that is a remote control and guage display for all items various modules report. The primary use case is to have a display that can be placed inside a vehicle 
that is towing a trailer and remotely monitor what is happening inside the trailer while traveling down the 
road.

## Getting Started
You must first create a secrets.h file and place contents like below...
Replace the 0x00's with the MAC address of the device that will be used as the gateway.
```
uint8_t broadcastAddress[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
```