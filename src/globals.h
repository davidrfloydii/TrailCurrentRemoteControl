#pragma once
#include <Arduino.h>
#include <lvgl.h>
#include <Wire.h>
#include "touch.h"
// EZZ
#include "ui/ui.h"
#include "ui/screens.h"
#include <WiFi.h>
#include <esp_wifi.h>
#include <esp_now.h>

//#define LV_DISPLAY_ROTATION_270 3 // landscape USB left side

#define DEBUG 1
// Conditional definition for debugging if DEBUG is 1 then it will print to serial port.
// If DEBUG = 0 then the lines will be removed by the compiler.
#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#define debugf(fmt, ...) Serial.printf((fmt), ##__VA_ARGS__)
#define debugg(x, y, z) Serial.printf(x, y, z)
#else
#define debug(x)
#define debugln(x)
#define debugf(fmt, ...)
#define debugg(x, y, z)
#endif