// Kode stammer fra: https://github.com/ControlEverythingCommunity/HMC5883/blob/master/Particle/HMC5883.ino 
// Der blevet tilføjet koden med API data. 
// Kan bruges med cloud compile og cloud flash med ønsket output i terminal. 
// På Particle.Console ses flere data som danner baggrund for de informationer der ses i terminal. 
// Der er sorteret informationer fra i Webhook settings. 

#include <application.h>
#include <spark_wiring_i2c.h>
#include <math.h>
//#include <particle.h>

// HMC5883 I2C address is 0x1E(30)
#define Addr 0x1E

int xMag = 0, yMag =  0, zMag = 0;
double heading;
String TrackingData;

void myHandler(const char *event, const char *data){        // This function prints when triggered
  TrackingData = data;
  Serial.printf("The ISS space station is currently at: \n ");
  Serial.printf(data);
  Serial.println();
  }

void setup()
{
    // Set variables for Particle Cloud access 
    Particle.variable("i2cdevice", "HMC5883");
    Particle.variable("xMag", xMag);
    Particle.variable("yMag", yMag);
    Particle.variable("zMag", zMag);
    Particle.variable("Heading", heading);

    Particle.subscribe("hook-response/Tracking", myHandler, MY_DEVICES); //connected to API data code 
  
    // Initialise I2C communication as MASTER
    Wire.begin();
    // Initialise Serial Communication, set baud rate = 9600
    Serial.begin(9600);
    
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select configure register A
    Wire.write(0x00);
    // Set normal measurement configuration, data output rate = 0.75Hz
    Wire.write(0x60);
    // Stop I2C Transmission
    Wire.endTransmission();
    
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select Mode register
    Wire.write(0x02);
    // Set continuous measurement
    Wire.write(0x00);
    // Stop I2C Transmission
    Wire.endTransmission();
    delay(300);
}
    
void loop()
{
    unsigned int data[6];
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select data register
    Wire.write(0x03);
    // Stop I2C Transmission
    Wire.endTransmission();

    // Request 6 bytes of data
    Wire.requestFrom(Addr, 6);

    // Read 6 bytes of data
    // xMag msb, xMag lsb, zMag msb, zMag lsb, yMag msb, yMag lsb
    if(Wire.available() == 6)
    {
        data[0] = Wire.read();
        data[1] = Wire.read();
        data[2] = Wire.read();
        data[3] = Wire.read();
        data[4] = Wire.read();
        data[5] = Wire.read();
    }
    delay(300);
      
    // Convert the data from sensor readings
    xMag = ((data[0] * 256) + data[1]);
    if(xMag > 32767)
    {
        xMag -= 65536;
    }
    zMag = ((data[2] * 256) + data[3]);
    if(zMag > 32767)
    {
        zMag -= 65536;
    }
    yMag = ((data[4] * 256) + data[5]);
    if(yMag > 32767)
    {
        yMag -= 65536;
    }
     // calculate the heading
    heading = atan2(yMag,xMag) * (180.0 / M_PI);
    if (heading < 0)
    {
        heading += 360.0;
    }
        // calculate cardinal direction
    String direction;
    if (heading >= 315 || heading < 45)
    {
        direction = "North";
    }
    else if (heading >= 45 && heading < 135)
    {
        direction = "East";
    }
    else if (heading >= 135 && heading < 225)
    {
        direction = "South";
    }
    else
    {
        direction = "West";
    }
    
    // Output data to dashboard
    Particle.publish("Magnetic Field in X-Axis : ", String(xMag));
    delay(1000);
    Particle.publish("Magnetic Field in Y-Axis : ", String(yMag));
    delay(1000);
    Particle.publish("Magnetic Field in Z-Axis : ", String(zMag));
    delay(1000);
    Particle.publish("Heading: ", String(heading));
    delay(1000);
    Particle.publish("Direction: ", direction);
    delay(1000);
    Serial.print("Current direction of the sensor is: ");
    Serial.println(direction);

    String trackingData = TrackingData;     // These two lines connected to API data 
    Particle.publish("Tracking", trackingData, PRIVATE);
}