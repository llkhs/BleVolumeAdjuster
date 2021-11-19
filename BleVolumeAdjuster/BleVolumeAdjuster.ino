
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

#define LED 2
#define KEY_UP 22
#define KEY_DOWN 23

void up_volume(){
    if(digitalRead(KEY_UP)==LOW){
        delay(20);
        if (digitalRead(KEY_UP)==LOW){
            if(bleKeyboard.isConnected()) {
                Serial.println("up key...");
                bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
                digitalWrite(LED,HIGH);
            }
        }
    }
}

void down_volume(){
    if(digitalRead(KEY_DOWN)==LOW){
        delay(20);
        if (digitalRead(KEY_DOWN)==LOW){  
            if(bleKeyboard.isConnected()) {
                Serial.println("down key...");
                bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
                digitalWrite(LED,HIGH);
            }
        }
    }
}


void setup(){
    Serial.begin(115200);
    pinMode(2,OUTPUT);
    pinMode(KEY_UP,INPUT_PULLUP);
    pinMode(KEY_DOWN,INPUT_PULLUP);
    bleKeyboard.setName("XinX's-Volume-Controller");
    bleKeyboard.begin(); 
}

void loop(){
    up_volume();
    down_volume();
    delay(100);
    digitalWrite(LED,LOW);
}



