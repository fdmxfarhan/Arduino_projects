/// Welcome to IRA
int minute;
int second;
int answer = 1101;
int buff;
void led(int a){
  if(a==0){
    digitalWrite(A2,1);
    digitalWrite(A3,0);
  }
  else if(a==1){
    digitalWrite(A2,0);
    digitalWrite(A3,1);
  }
  else if(a==2){
    digitalWrite(A2,0);
    digitalWrite(A3,0);
  }  
}
void gameover(int duration){
  led(0);
  digitalWrite(8,0);
  digitalWrite(4,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(11,0);
  digitalWrite(12,0);
  digitalWrite(3,1);
  digitalWrite(5,0);
  for(int i=0;i<duration;i++){
    digitalWrite(2,0);
    digitalWrite(9,0);
    digitalWrite(10,0);
    digitalWrite(13,0);
    for(int j=0;j<300;j++){
    digitalWrite(A1,1);
    delayMicroseconds(600);
    digitalWrite(A1,0);
    delayMicroseconds(600);
    }
    digitalWrite(2,1);
    digitalWrite(9,1);
    digitalWrite(10,1);
    digitalWrite(13,1);
    delay(300);
  }
  led(2);
}
void wrongcode(){
  for(int j=0;j<500;j++){
  digitalWrite(A1,1);
  delayMicroseconds(600);
  digitalWrite(A1,0);
  delayMicroseconds(600);
  }
  int var = (second + minute*60)/2;
  second = var % 60;
  minute = (var - second) / 60;
  
}
void rightcode(){
  led(1);
  digitalWrite(8,1);
  digitalWrite(4,1);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(11,1);
  digitalWrite(12,1);
  digitalWrite(3,1);
  digitalWrite(5,0);

  digitalWrite(2,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(13,0);
  for(int i=0;i<2;i++){
    for(int j=0;j<100;j++){
    digitalWrite(A1,1);
    delayMicroseconds(600);
    digitalWrite(A1,0);
    delayMicroseconds(600);
    }
    delay(100);
  }
  digitalWrite(2,1);
  digitalWrite(9,1);
  digitalWrite(10,1);
  digitalWrite(13,1);
  delay(5000);
  led(0);
  minute=1;
  second=59;
}
void checkcode(){
  int p1 = analogRead(A7);
  int p2 = analogRead(A6);
  int p3 = digitalRead(A5);
  int p4 = digitalRead(A4);
  if(p1 >500) p1 = 1;
  else p1 = 0;
  if(p2 >500) p2 = 1;
  else p2 = 0;
  int ans = (p1 * 1000) + (p2 * 100) + (p3 * 10) + p4;
  Serial.println(ans);
  if(ans == answer) rightcode();
  else wrongcode();
}
void seg(int a){
  if(a == 0){
    digitalWrite(8,1);
    digitalWrite(4,1);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(11,1);
    digitalWrite(12,1);
    digitalWrite(3,0);
    digitalWrite(5,0);
  }
  else if(a == 1){
    digitalWrite(8,1);
    digitalWrite(4,1);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(11,0);
    digitalWrite(12,0);
    digitalWrite(3,0);
    digitalWrite(5,0);
  }
  else if(a == 2){
    digitalWrite(8,1);
    digitalWrite(4,0);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(11,0);
    digitalWrite(12,1);
    digitalWrite(3,1);
    digitalWrite(5,0);
  }
  else if(a == 3){
    digitalWrite(8,1);
    digitalWrite(4,1);
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(11,0);
    digitalWrite(12,1);
    digitalWrite(3,1);
    digitalWrite(5,0);
  }
  else if(a == 4){
    digitalWrite(8,1);
    digitalWrite(4,1);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(11,1);
    digitalWrite(12,0);
    digitalWrite(3,1);
    digitalWrite(5,0);
  }
  else if(a == 5){
    digitalWrite(8,0);
    digitalWrite(4,1);
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(11,1);
    digitalWrite(12,1);
    digitalWrite(3,1);
    digitalWrite(5,0);
  }
  else if(a == 6){
    digitalWrite(8,0);
    digitalWrite(4,1);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(11,1);
    digitalWrite(12,1);
    digitalWrite(3,1);
    digitalWrite(5,0);
  }
  else if(a == 7){
    digitalWrite(8,1);
    digitalWrite(4,1);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(11,0);
    digitalWrite(12,1);
    digitalWrite(3,0);
    digitalWrite(5,0);
  }
  else if(a == 8){
    digitalWrite(8,1);
    digitalWrite(4,1);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(11,1);
    digitalWrite(12,1);
    digitalWrite(3,1);
    digitalWrite(5,0);
  }
  else if(a == 9){
    digitalWrite(8,1);
    digitalWrite(4,1);
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(11,1);
    digitalWrite(12,1);
    digitalWrite(3,1);
    digitalWrite(5,0);
}
}
void resetseg(){
  digitalWrite(8,0);
  digitalWrite(4,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(11,0);
  digitalWrite(12,0);
  digitalWrite(3,0);
  digitalWrite(5,0);
}
void show_second(int a){
  digitalWrite(2,0);
  digitalWrite(9,1);
  digitalWrite(10,1);
  digitalWrite(13,1);
  seg(a%10);
//  delay(1);
  resetseg();
  digitalWrite(2,1);
  digitalWrite(9,0);
  digitalWrite(10,1);
  digitalWrite(13,1);
  seg((a/10)%10);
//  delay(1);
  resetseg();
}
void show_minute(int a){
  digitalWrite(2,1);
  digitalWrite(9,1);
  digitalWrite(10,0);
  digitalWrite(13,1);
  seg(a%10);
  digitalWrite(5,1);
//  delay(1);
  resetseg();
  digitalWrite(2,1);
  digitalWrite(9,1);
  digitalWrite(10,1);
  digitalWrite(13,0);
  seg((a/10)%10);
//  delay(1);
  resetseg();
  
  
}

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A7,INPUT);
  pinMode(A6,INPUT);
  pinMode(A5,INPUT);
  pinMode(A4,INPUT);
  
  Serial.begin(9600);
  led(2);
}

void loop() {
  for(minute = 1;minute >= 0;minute-- ){
    for(second = 59; second >= 0; second--){
      for(int i=0;i < 3300;i++){
        show_second(second);
        show_minute(minute);
        buff = Serial.read();
        if(buff == 't')
          checkcode();
        else if(buff == 'r'){
          second = 59;
          minute = 1;}
      }
    }
  }
  gameover(5);
  delay(5000);
}
