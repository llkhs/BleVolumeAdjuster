#include <BleKeyboard.h>
BleKeyboard bleKeyboard;

#define LED 2
#define KEY_UP 22
#define KEY_DOWN 23

void up_volume(){
    if(bleKeyboard.isConnected()) {
        Serial.println("up key...");
        bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
        digitalWrite(LED,HIGH);
    }
}

void down_volume(){
    if(bleKeyboard.isConnected()) {
        Serial.println("down key...");
        bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
        digitalWrite(LED,HIGH);
    }
}

void setup()
{
    Serial.begin(115200);
    pinMode(LED,OUTPUT);
    pinMode(KEY_UP,INPUT_PULLUP);
    pinMode(KEY_DOWN,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(KEY_UP),up_volume,RISING);
    attachInterrupt(digitalPinToInterrupt(KEY_DOWN),down_volume,RISING);
    bleKeyboard.setName("llkhs's Volume Controller");
    bleKeyboard.begin(); 
}

void loop(){
    digitalWrite(LED,LOW);
}
