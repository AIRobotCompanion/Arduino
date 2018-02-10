const int p=2;
void setup(){
  pinMode(p,OUTPUT);
}
void loop(){
  rf_send('D');
  rf_send('A');
  rf_send('T');
  rf_send('A');
  rf_send(' ');
  rf_send('S');
  rf_send('E');
  rf_send('N');
  rf_send('T');
  rf_send(' ');
  rf_send('#');
  delay(5000);
}
void rf_send(byte input){
  int i;
  for(i=0;i<20;i++){
    digitalWrite(p,HIGH);
    delayMicroseconds(500);
    digitalWrite(p,LOW);
    delayMicroseconds(500);
  }
  digitalWrite(p,HIGH);
  delayMicroseconds(3000);
  digitalWrite(p,LOW);
  delayMicroseconds(500);
  for(i=0;i<8;i++){
    if(bitRead(input,i)==1)
      digitalWrite(p,HIGH);
    else
      digitalWrite(p,LOW);
    delayMicroseconds(500);
    if(bitRead(input,i)==1)
      digitalWrite(p,LOW);
    else
      digitalWrite(p,HIGH);
    delayMicroseconds(500);
  }
  digitalWrite(p,LOW);
}
