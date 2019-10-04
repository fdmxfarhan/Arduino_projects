int distance=0;

int srf(int trig,int echo){
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);
  return(pulseIn(echo, 1)*0.034/2);
}



void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  
  
}
void loop() {
  distance = srf(2,3);
  Serial.print("Distance: ");
  Serial.println(distance);
  
}
