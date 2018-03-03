//Digital Humidity Temperature(DHT)_11
#include <dht.h>
dht DHT;
#define DHT11_PIN A0
void setup(){
	Serial.begin(9600);
}
void loop(){
	int chk = DHT.read11(DHT11_PIN);
	Serial.print("Temp = ");
	Serial.print(DHT.temperature);
	Serial.print("\tHumid = ");
	Serial.println(DHT.humidity);
	delay(2000);
}
