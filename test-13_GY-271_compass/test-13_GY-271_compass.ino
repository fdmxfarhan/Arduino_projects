
#include <Wire.h>
#include <QMC5883LCompass.h>

QMC5883LCompass qmc;
void setup(){
  Wire.begin();
  qmc.init();
  qmc.setMode(0,ODR_200Hz,RNG_8G,OSR_512);
}
void loop() {
  int x,y,z;

  qmc.read(&x,&y,&z);
}
