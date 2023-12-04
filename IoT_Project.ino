/* 
This code is working as of 1/12 and prints latitude and longitude of the ISS spacestation.
The myHandler function gets called and prints the values listed.
The webhooks has been formated to only show latitude and longitude.
*/
#include <Particle.h>
#include <JsonParserGeneratorRK.h>

String TrackingData;

void myHandler(const char *event, const char *data){
  TrackingData = data;
  Serial.printf("The ISS space station is currently at: \n ");
  Serial.printf(data);
  Serial.println();
  }

void setup() {
    //Particle.subscribe("Tracking", myHandler, MY_DEVICES);    # This is a original line
  Serial.begin(9600); // Serial comm. start with bitrate 
  Particle.subscribe("hook-response/Tracking", myHandler, MY_DEVICES);
}
void loop() {
    // Get some data
  String data = TrackingData;
  // Trigger the integration
  Particle.publish("Tracking", data, PRIVATE); // Trigger webhook and publish Lo, La, Vi to Events
  // Wait 10 seconds
  delay(10000);
  }



