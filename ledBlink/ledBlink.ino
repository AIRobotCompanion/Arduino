const int p=10; //Pulse Width Modulation
void setup(){
  Serial.begin(9600);  
}
void loop() {
  digitalWrite(p,HIGH);
  delay(500);
  digitalWrite(p,LOW);
  delay(1000);
  for(int i=0;i<256;i++){
    analogWrite(p,i);
    delay(500);
  }
}
