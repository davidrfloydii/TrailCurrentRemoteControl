#pragma once
#include "globals.h"
#include "secrets.h"
// Using the struct similar to ESP32 TWAI driver as a message format. Since all messages
// will be coming from the CAN bus, this makes it easier to parse and use the data and
// expand functionality later.
typedef struct
{
    // *NOTE: Not handling extended frames or CAN FD frames at this time.
    // The order of these bits must match deprecated message flags for compatibility reasons
    uint32_t identifier;
    uint8_t data_length_code; /**< Data length code max value of 8 */
    byte dateByte0;
    byte dateByte1;
    byte dateByte2;
    byte dateByte3;
    byte dateByte4;
    byte dateByte5;
    byte dateByte6;
    byte dateByte7;
} twai_message_t;

esp_now_peer_info_t peerInfo;
// Create a struct_message to hold incoming CAN message
twai_message_t incomingMessage;

uint32_t incomingIdentifier = 0;
uint8_t incomingDLC = 0;
byte incomingDataByte0 = 0;
byte incomingDataByte1 = 0;
byte incomingDataByte2 = 0;
byte incomingDataByte3 = 0;
byte incomingDataByte4 = 0;
byte incomingDataByte5 = 0;
byte incomingDataByte6 = 0;
byte incomingDataByte7 = 0;

// Variable to store if sending data was successful
String success;

namespace espNowHelper
{
    // Callback when data is received
    void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
    {
        memcpy(&incomingMessage, incomingData, sizeof(incomingMessage));
        debug("Bytes received: ");
        debugln(len);
        // Set variables based on incoming data for indicators as to which pdm devices are
        // currently turned on or have a value > 255
        if (incomingIdentifier == 27)
        {
            if(incomingDataByte0 == 0) {
                // TODO: Call set variable to indicate PDM1 is off
            } else {
                // TODO: Call set variable to indicate PDM1 is on
            }
        }
    }

    // Callback when data is sent
    void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
    {
        debug("\r\nLast Packet Send Status:\t");
        debugln(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
        if (status == 0)
        {
            success = "Delivery Success :)";
        }
        else
        {
            success = "Delivery Fail :(";
        }
    }

    uint8_t getMacAddress(uint8_t *mac)
    {
        return esp_wifi_get_mac(WIFI_IF_STA, mac);
    }

    void initialize()
    {
        WiFi.mode(WIFI_STA);
        // Init ESP-NOW
        if (esp_now_init() != ESP_OK)
        {
            Serial.println("Error initializing ESP-NOW");
            return;
        }

        // Once ESPNow is successfully Init, we will register for Send CB to
        // get the status of Trasnmitted packet
        esp_now_register_send_cb(esp_now_send_cb_t(OnDataSent));

        // Register peer
        memcpy(peerInfo.peer_addr, broadcastAddress, 6);
        peerInfo.channel = 0;
        peerInfo.encrypt = false;

        // Add peer
        if (esp_now_add_peer(&peerInfo) != ESP_OK)
        {
            Serial.println("Failed to add peer");
            return;
        }
        // Register for a callback function that will be called when data is received
        esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
    }
}