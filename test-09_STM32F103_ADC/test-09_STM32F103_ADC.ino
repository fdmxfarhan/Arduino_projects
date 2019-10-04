void setup() {
  Serial.begin(9600);
  pinMode(PA0, INPUT);
}
void loop() {
  Serial.print("Analog value: ");
  Serial.println(analogRead(PA0));
}
