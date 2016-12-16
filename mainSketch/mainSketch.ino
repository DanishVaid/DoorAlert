//Laser Sensor and Text Code

/*
 * Danish Vaid
 * DoorAlert Project
 * Summer 2016
 */

#include <Bridge.h>
#include <Temboo.h>
#include <SoftwareSerial.h>
#include "myAccounts.h"


int photoRes = 0;      // Input for laser
int laser = 4;         // Controller for photoResistor
int ledControl = 13;   // Controller for LED

void setup() {
  Serial.begin(9600);
  pinMode(photoRes, INPUT);
  pinMode(laser, OUTPUT);

  delay(1000);
  Bridge.begin();
  Serial.println("--- Sensor Mode Initiated ---");
}

void loop() {
  digitalWrite(laser, HIGH);
  delay(50);                                                       //Small Delay to not clutter up the serial monitor

  Serial.println("Checking . . . ");
  if (analogRead(photoRes) < 400) {
    Serial.println("Trip Wire Triggered");
    digitalWrite(ledControl, HIGH);
    Serial.println("Sending text Notification...");

    Serial.println("Sending SMS");

    TembooChoreo SendSMSChoreo;

      // Setting up the Temboo Client
    SendSMSChoreo.begin();
    SendSMSChoreo.setAccountName(TEMBOO_ACCOUNT);
    SendSMSChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendSMSChoreo.setAppKey(TEMBOO_APP_KEY);

      // Run Choreo
      SendSMSChoreo.addInput("AuthToken", AUTH_TOKEN);              //  AUTH TOKEN
      SendSMSChoreo.addInput("To", textTo);                         // cell number that your want the text to go to
      SendSMSChoreo.addInput("From", textFrom);                     // Twilio phone number
      SendSMSChoreo.addInput("Body", "Laser Trip Wire Alert");      // Message
      SendSMSChoreo.addInput("AccountSID", accSSID);                // Account SID
      SendSMSChoreo.setChoreo("/Library/Twilio/SMSMessages/SendSMS");
      SendSMSChoreo.run();
      SendSMSChoreo.close();

      Serial.println("Waiting For Reset...");
      delay(10000);                                                  // wait 10 seconds between SMS signals
      Serial.println("--- Reset ---");

  }

  digitalWrite(ledControl, LOW);
}

