#include <dht11.h>
#define DHT11PIN 4
dht11 DHT11;

int L = 5; //Light Pin
int F = 7;  //Fan Pin
int P = 8;  //Pump Pin

void  setup()
{
  Serial.begin(9600);
  pinMode(L, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(P, OUTPUT);
  digitalWrite(L, LOW);
  digitalWrite(F, LOW);
  digitalWrite(P, LOW);
 
}

void loop()
{
  //Reading from temperature and humidity sensor
  int chk = DHT11.read(DHT11PIN);
  float hum = (float)DHT11.humidity;
  float temp = (float)DHT11.temperature;
  //Temp and Hum output
  Serial.print("Humidity (%): ");
  Serial.println(hum, 2);
  Serial.print("Temperature  (C): ");
  Serial.println(temp, 2);
  // Initial Conditions
  digitalWrite(L, 0); // Lights On
  delay(10);
  digitalWrite(F, 1); // Fan Off
  delay(10);
  digitalWrite(P, LOW); // Pump On
  // Periodic 0.5 second Checks
  for(int idx = 0; idx < 3; idx++){
    delay(500);
    checks(hum, temp);
  }
  delay(500);

  digitalWrite(P, HIGH);
  //2 Seconds
  delay(3000);
  //5 Seconds
  checks(hum, temp);
  delay(5000);
  checks(hum, temp);
  delay(5000);
  checks(hum, temp);
  delay(5000);
  checks(hum, temp);
  delay(5000);
  //25 seconds
  checks(hum, temp);
  delay(5000);
  checks(hum, temp);
  delay(5000);
  checks(hum, temp);
  delay(5000);
  //40 seconds
  digitalWrite(L, 1);
  digitalWrite(F, 0);
  
  delay(20000);
  //60 seconds

}
// turn off pump if humidity too high 
void checks(int h, int t) {
  /*
  if ( h > 60) {
    digitalWrite(P,0);
  }
  if (t > 70) {
    digitalWrite(L, 0);
    digitalWrite(F, 1);
  }
  */
}

