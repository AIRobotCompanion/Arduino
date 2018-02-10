const int s=A0,r=12,g=13;	//Red & Green LED
void setup(){
	Serial.begin(9600);
	pinMode(s,INPUT);
	pinMode(r,OUTPUT);
	pinMode(g,OUTPUT);
}
void loop(){
	float x=analogRead(s);
	Serial.println(x);
	if(x>170)
		digitalWrite(r,HIGH);
	else
		digitalWrite(g,HIGH);
	delay(1000);
	digitalWrite(r,LOW);
	digitalWrite(g,LOW);
}
