void lcd_check() {
  lcd.clear();
  delay(1);
}

void analog_read() {
  while (digitalRead(button) == HIGH) {
    for (int i = 0; i < 6; i++) {
      s[i] = analogRead(5 - i);
      lcd_check();
      lcd.setCursor(0, 0);
      lcd.print(s[0]);
      lcd.setCursor(5, 0);
      lcd.print(s[1]);
      lcd.setCursor(10, 0);
      lcd.print(s[2]);
      lcd.setCursor(0, 1);
      lcd.print(s[3]);
      lcd.setCursor(5, 1);
      lcd.print(s[4]);
      lcd.setCursor(10, 1);
      lcd.print(s[5]);
      delay(50);
    }
    lcd_check();
  }
  while (digitalRead(button) == LOW);
}

void sonar_read() {
  while (digitalRead(button) == HIGH) {
    lcd.setCursor(5, 0);
    lcd.print("Sonar");
    sf = sonarf.ping_cm();
    lcd.setCursor(7, 1);
    lcd.print(sf);
    delay(50);
    sl = sonarl.ping_cm();
    lcd.setCursor(1, 1);
    lcd.print(sl);
    delay(200);
    sr = sonarr.ping_cm();
    lcd.setCursor(13, 1);
    lcd.print(sr);
    delay(250);
    lcd_check();
  }
  while (digitalRead(button) == LOW);
}

void digital_read() {
  while (digitalRead(button) == HIGH) {
    check();
    lcd_check();
    lcd.setCursor(2, 0);
    lcd.print(s[5]);
    lcd.setCursor(4, 0);
    lcd.print(s[4]);
    lcd.setCursor(6, 0);
    lcd.print(s[3]);
    lcd.setCursor(8, 0);
    lcd.print(s[2]);
    lcd.setCursor(10, 0);
    lcd.print(s[1]);
    lcd.setCursor(12, 0);
    lcd.print(s[0]);
    delay(200);
  }
  while (digitalRead(button) == LOW);
}
