#include <Arduino.h>
#include <string.h>
#include <BluetoothSerial.h> //Header File for Serial Bluetooth BluetoothSerial ESP_BT;

BluetoothSerial ESP_BT;

int incoming;
int LED_PIN = 13;
void setup()
{
  Serial.begin(9600);
  ESP_BT.begin("ESP32_LED_Control"); // Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");
  pinMode(LED_PIN, OUTPUT); // Specify that LED pin is output
}
void loop()
{
  if (ESP_BT.available())
  // Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read();
    // Read what we recevive
    Serial.print("Received:");
    Serial.println(incoming);
    if (incoming == 49)
    {
      digitalWrite(LED_PIN, HIGH);
      ESP_BT.println("LED turned ON");
    }
    if (incoming == 48)
    {
      digitalWrite(LED_PIN, LOW);
      ESP_BT.println("LED turned OFF");
    }
  }
  delay(20);
}