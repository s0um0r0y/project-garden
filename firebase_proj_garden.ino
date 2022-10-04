#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArdruino.h>
#include <ESP8266HTTPClient.h>

#define FIREBASE_HOST "https://proj-garden-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "CcNh3536AjqWlcdULwgFtZre6tym9EyUx9wD0k5x"
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

int dt=500;

float volts,celsius,farenheit;
int tempPin = 0;
int temp,Moisture__dig_signal = 4; //Define the Digital Input on the Arduino for the sensor signal
int Sensor_State = 1; 
int ledpin=13;
int ldrpin=1;

void setup()
{ 
  pinMode(ledpin, OUTPUT);
  pinMode(ldrpin, INPUT);
  pinMode(Moisture__dig_signal, INPUT); //Step pin as input
  Serial.begin(9600); // Start the serial communication
}
void surrounding_temperature()
{
  temp = analogRead(tempPin);
   // read analog volt from sensor and save to variable temp
    
   volts= (temp / 1024.0) *5000; // convert to Kelvin
   celsius = volts/10; // convert to celsius
 
   farenheit = (celsius * 1.8) +32; // convert to farenheit
  
   // convert the analog volt to its temperature equivalent
   Serial.println("TEMPERATURE of surrounding in celsius");
   Serial.println(celsius);
   Serial.println();
   Serial.println("TEMPERATURE of surrounding in farenheit");
   Serial.println(farenheit);
   delay(1000);
    // update sensor reading each one second
} 
void soil_moisture_level(){
  Serial.println("Soil Moisture Level: ");
  Sensor_State = digitalRead(Moisture__dig_signal);
  if (Sensor_State == 1) {
    Serial.println("Wet");
  }
  else {
    Serial.println("Dry");
  }
  delay(200);
}
void plant_temperature()
{
  temp = analogRead(tempPin);
   // read analog volt from sensor and save to variable temp
    
   volts= (temp / 1024.0) *5000; // convert to Kelvin
   celsius = volts/10; // convert to celsius
 
   farenheit = (celsius * 1.8) +32; // convert to farenheit
  
   // convert the analog volt to its temperature equivalent
   Serial.println("TEMPERATURE of plant in celsius");
   Serial.println(celsius);
   Serial.println();
   Serial.println("TEMPERATURE of plant in farenheit");
   Serial.println(farenheit);
   delay(1000);
    // update sensor reading each one second
} 
void sunlight()
{
 int ldrStatus = analogRead(ldrpin);

if (ldrStatus <= 200) {

digitalWrite(ledpin, HIGH);

Serial.println("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus);

} else {

digitalWrite(ledpin, LOW);

Serial.println("Its BRIGHT, Turn off the LED : ");

Serial.println(ldrStatus);
 
void loop(){
  int a;
  Serial.println("enter your choice of case");
  while(Serial.available()==0){
  }
  a=Serial.parseInt();
  switch(a){
    case 1:
          plant_temperature();
          break;
    case 2:
          surrounding_temperature();
          break;
    case 3:
          soil_moisture_level();
          break;
    case 4:
           sunlight();
           break;
    case 5:
           plant_temperature();
           surrounding_temperature();
           soil_moisture_level();
           sunlight();
           break;
    default:
            Serial.println("please choose a number");
  }
  }


void loop() {
  //sending data to firebase from ardruino

  //handling error
  if (Firebase.failed()){
    Serial.print("    ");
    Serial.println(Firebase.error());
    return;


  //collecting data from the firebase
  }
}
