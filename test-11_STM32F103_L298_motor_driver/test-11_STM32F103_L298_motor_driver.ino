void setup() {
  pinMode(PA1,PWM);
  pinMode(PA2,OUTPUT);
  pinMode(PA3,PWM);
  pinMode(PA4,OUTPUT);
  
}

void loop() {
  /*
  pwmWrite(PA1,65535);
  digitalWrite(PA2,0);
  pwmWrite(PA3,65535);
  digitalWrite(PA4,0);*/
  
  for(int i = 0; i<65535; i+=10){
    pwmWrite(PA1,i);
    digitalWrite(PA2,0);
    pwmWrite(PA3,i);
    digitalWrite(PA4,0);
    delay(1);
  }
  for(int i = 65535; i>0; i-=10){
    pwmWrite(PA1,i);
    digitalWrite(PA2,0);
    pwmWrite(PA3,i);
    digitalWrite(PA4,0);
    delay(1);
  }
  
  
}
