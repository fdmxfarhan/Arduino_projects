#include <LiquidCrystal.h>
//int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int rs = PA1, en = PA2, d4 = PA3, d5 = PA4, d6 = PA5, d7 = PA6;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int thisChar = 'a';

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello");
}

void loop() {

  
  /*
  ////////Scroll Display
  for (int positionCounter = 0; positionCounter < 11; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  for (int positionCounter = 0; positionCounter < 11; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  */

  /*
  ////////a to z print
  if (thisChar == 'q')
    lcd.setCursor(0,1);
  if (thisChar != 'z'+1) {
    lcd.write(thisChar);
    delay(100);
    thisChar++;
  }
  */
  
  /*
  ////////Text Blink
  lcd.setCursor(0,0);
  //lcd.home();
  lcd.print("Hello");
  
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
  */
  
  /*
  /////////Line Blink
  lcd.noCursor();
  delay(500);
  // Turn on the cursor:
  lcd.cursor();
  delay(500);
  */
  /*
  ////////Blink
  lcd.noBlink();
  delay(3000);
  lcd.blink();
  delay(3000);
  */
}
