int i,good,k;
byte d;//data
const int ip=3,op=13;
void setup(){
  attachInterrupt(1,data_incoming,RISING);
  pinMode(ip,INPUT);
  pinMode(op,OUTPUT);
  Serial.begin(115200);
}
void loop(){

}
void data_incoming(){
  for(i=0;i<100;i++){
    delayMicroseconds(20);
    good=1;
    if(digitalRead(ip)==LOW){
      good=0;
      i=100;
    }
  } 
  if(good==1){
    detachInterrupt(1);
    while(1){
      if(digitalRead(ip)==LOW){
        delayMicroseconds(750);
        for(i=0;i<8;i++){
          if(digitalRead(ip)==HIGH)
            bitWrite(d,i,1);
          else
            bitWrite(d,i,0);
          delayMicroseconds(1000);
        }
        if(d=='#')
          Serial.println("");
        else
          Serial.print(char(d));
        break;//secondtwhile
      }//low kickoff
    }//second while
  }//good check
  attachInterrupt(1,data_incoming,RISING);
}//routine
