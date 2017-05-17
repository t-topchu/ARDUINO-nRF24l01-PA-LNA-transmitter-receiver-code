#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7,8);
int cmd[100];
int SW1 = 4;
int led1=2;

const uint64_t pipe = 0xDEDEDEDEE7LL;

void setup(void){
 Serial.begin(115200);
 radio.begin();
 radio.setChannel(108);
 radio.setPALevel(RF24_PA_MIN);
 radio.setDataRate(RF24_250KBPS);
 radio.openWritingPipe(pipe);
 pinMode(led1,OUTPUT);
 pinMode(3,OUTPUT);
 digitalWrite(led1,LOW);
}

void loop(void){
 digitalWrite(3,HIGH);
 int pok=digitalRead(SW1);
 if(pok==HIGH)cmd[0]='A';
 else cmd[0]=0;
 radio.write(&cmd,sizeof(cmd));
}
