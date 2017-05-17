#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7,8);
int cmd[100];
int LED2 = 3;
int LED1 = 4;
int LED3 = 5;

const uint64_t pipe = 0xDEDEDEDEE7LL;

void setup(void){
 Serial.begin(115200);
 radio.begin();
 radio.setChannel(108); 
 radio.setPALevel(RF24_PA_MAX);
 radio.setDataRate(RF24_250KBPS);
 radio.openReadingPipe(1,pipe);
 radio.startListening();
 pinMode(LED1, OUTPUT);
 pinMode(LED2,OUTPUT);
 pinMode(LED3,OUTPUT);
}
void loop(void){
 if (radio.available()){
  digitalWrite(LED1,HIGH);
 // digitalWrite(LED3, LOW);
   while (radio.available()){
     radio.read(&cmd,sizeof(cmd));      
     Serial.println(cmd[0]);
     if (cmd[0] == 'A')digitalWrite(LED2, HIGH);
     else {digitalWrite(LED2, LOW);}
      }
 }
 else{Serial.println("No radio available");
       digitalWrite(LED1, LOW);
      // digitalWrite(LED3, HIGH);
      }}
