#include <Wire.h>
#include <SPI.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "BluetoothSerial.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
//---Actuator and Relay  pin connection---
#define relay01 27 
#define relay02 26
#define buzzer 25
#define ds18b20_PIN  15 
//---Analog Sensor  pin connection---
#define sensor1 34
#define sensor2 36

const char* nama_bluetooth = "gmKKSJ";
BluetoothSerial my_bluetooth;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

OneWire oneWire(ds18b20_PIN);
DallasTemperature DS18B20(&oneWire);

float tempC; // temperature in Celsius
float tempF; // temperature in Fahrenheit
int dataSensor1;
int dataSensor2;

void setup() {
  pinMode(relay01,OUTPUT);
  pinMode(relay02,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  Serial.begin(115200); // initialize serial

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);  }
 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("ESP32 Project BOARD");
  display.setCursor(0,10);
  display.println("with Relay control");
  display.display();
  delay(500);

  //-- istihar fungsi komunikasi Bluetooth.
  my_bluetooth.begin(nama_bluetooth);

  DS18B20.begin();    // initialize the DS18B20 sensor
  delay(2000);

}

void loop() {

if(my_bluetooth.available()> 0){
    char datBth  = my_bluetooth.read();
    Serial.println(datBth);

  if (datBth == 'B')  {
    
    delay(500);
    digitalWrite(relay02,HIGH);
    Serial.println(" Belon di lepaskan");
    delay(1500);
    Serial.println(" solenoid off ");
    digitalWrite(relay02,LOW);
    
  }

  else {
    digitalWrite(relay02,LOW);
  }

}

if(Serial.available()> 0){
    char dataKibod = Serial.read();
    Serial.println(dataKibod);

  if (dataKibod == 'B')  {
    
    delay(500);
    digitalWrite(relay02,HIGH);
    Serial.println(" Belon di lepaskan");
    delay(1500);
    Serial.println(" solenoid off ");
    digitalWrite(relay02,LOW);
    
  }

  else {
    digitalWrite(relay02,LOW);
  }

 
  
  }
}
