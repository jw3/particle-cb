#pragma once

#include <JsonParserGeneratorRK.h>

struct Receiver
{
   explicit Receiver(USARTSerial& serial) : serial(serial) {}

   void begin(int baudrate) {
      serial.begin(baudrate);
   }

   void transmit(const char* e, const char* d) {
      p.addString(d);
      if(p.parse() && Id() && X() && Y()) {
         serial.printlnf("%s/%s:%s:%s", e, id.c_str(), x.c_str(), y.c_str());
         p.clear();
      }
   }
private:
   USARTSerial& serial;
   JsonParserStatic<256, 20> p;
   String id, x, y;

   bool Id() { return p.getOuterValueByKey("id", id); }
   bool X() { return p.getOuterValueByKey("x", x); }
   bool Y() { return p.getOuterValueByKey("y", y); }
};
