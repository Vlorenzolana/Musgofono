#include <CapacitiveSensor.h>

/*
* CapSense Library  
* Paul Badger 2008
* IMI version for 12 sensors and send to Max/MSP (use regexp to decode)
*/

/*
Use a 1 M resistor for an absolute touch to activate.
With a 10 M resistor for 4-6 inches away.
With a 40 M resistor for 12-24 inches away.

Also experiment with small capacitors (100pf – .01uf) to ground, on the sense pin.
They will improve stability of the sensor.
*/

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

void setup()
{
  
Serial.begin(115200);
delay (10);

}

void loop()
{
  
long start = millis();
long a =  cs_4_2.capacitiveSensor(30);
long b =  cs_4_6.capacitiveSensor(30);
long c =  cs_4_8.capacitiveSensor(30);

if (a>0) {
  
    if (a<10000) {
   // a = map(cs_4_2.capacitiveSensor(30), 0, 100000, 0, 255);
    Serial.print("a");
    Serial.print("\t"); 
    Serial.println(a);

    
  }
  else { a=0; }
}

if (b>0) {
  
    if (b<10000) {
//    b = map(cs_4_6.capacitiveSensor(30), 0, 7000, 0, 255);
    Serial.print("b");
    Serial.print("\t"); 
    Serial.println(b);

  }
  else { b=0; }
}


if (c>0) {
  
    if (c<10000) {
//    c = map(cs_4_2.capacitiveSensor(30), 0, 7000, 0, 255);
    Serial.print("c");
    Serial.print("\t"); 
    Serial.println(c);

  }
  else { c=0; }
}

}


