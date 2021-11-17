#include <BleKeyboard.h>
BleKeyboard bleKeyboard;

unsigned int a=0;

void setup()
{
    Serial.begin(115200);
    pinMode(2,OUTPUT);
    pinMode(22,INPUT_PULLUP);
    pinMode(23,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(22),up_volume,FALLING);
    attachInterrupt(digitalPinToInterrupt(23),down_volume,FALLING);
    bleKeyboard.setName("XinX's Volume Controller");
    bleKeyboard.begin(); 
}

void up_volume(){
    if(bleKeyboard.isConnected()) {
        Serial.println("up key...");
        bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
        digitalWrite(2,1);
    }
}

void down_volume(){
    if(bleKeyboard.isConnected()) {
        Serial.println("down key...");
        bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
        digitalWrite(2,1);
    }
}

void loop(){
    digitalWrite(2,0);
}
