void setup() {
  pinMode(PA1,OUTPUT);
  pinMode(PA2,OUTPUT);
  pinMode(PA3,OUTPUT);
  pinMode(PA6,OUTPUT);
  pinMode(PA7,OUTPUT);
  pinMode(PB0,OUTPUT);
  
  digitalWrite(PA1, 1);
  delay(100);
  digitalWrite(PA2, 1);
  delay(100);
  digitalWrite(PA3, 1);
  delay(100);
  digitalWrite(PA6, 1);
  delay(100);
  digitalWrite(PA7, 1);
  delay(100);
  digitalWrite(PB0, 1);
  delay(100);
  
  digitalWrite(PA1, 0);
  delay(100);
  digitalWrite(PA2, 0);
  delay(100);
  digitalWrite(PA3, 0);
  delay(100);
  digitalWrite(PA6, 0);
  delay(100);
  digitalWrite(PA7, 0);
  delay(100);
  digitalWrite(PB0, 0);
  delay(100);
  
  
}

void loop() {
  for(int i=0;i<255;i++){
    analogWrite(PA1, i);
    analogWrite(PA2, i);
    analogWrite(PA3, i);
    analogWrite(PA6, i);
    analogWrite(PA7, i);
    analogWrite(PB0, i);
    
    delay(10);
  }
  for(int i=255;i>0;i--){
    analogWrite(PA1, i);
    analogWrite(PA2, i);
    analogWrite(PA3, i);
    analogWrite(PA6, i);
    analogWrite(PA7, i);
    analogWrite(PB0, i);
    delay(10);
  }
  
}
