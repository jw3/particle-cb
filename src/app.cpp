#include <application.h>
#include "rx.h"

constexpr int rxBr = 9600;
Receiver rx(Serial1);

void setup(){
   rx.begin(rxBr);
   Particle.subscribe("M", &Receiver::transmit, &rx, MY_DEVICES);
}

void loop(){
}
