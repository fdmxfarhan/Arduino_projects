  int distance=0;

int srf(int pin){
  pinMode(pin,OUTPUT);
  digitalWrite(pin,1);
  delayMicroseconds(10);
  digitalWrite(pin,0);
  pinMode(pin,INPUT);
  return(pulseIn(pin, 1)*0.034/2);
}


void setup() {
  Serial.begin(9600);
  
  
}
void loop() {
  distance = srf(2);
  Serial.print("Distance: ");
  Serial.println(distance);
  
}
