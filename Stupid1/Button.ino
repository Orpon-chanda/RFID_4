int switch1 () {
  int t = 0, cl = 0, list = 8;
a:  while (digitalRead(button) == LOW) {
    delay(1);
    digitalWrite(mli, HIGH);
    t++;
  }
  digitalWrite(mli, LOW);

  while (t > 15) {
    if (cl != menu) {
      cl = menu;
      if (cl == 1) {
        lcd_check();
        lcd.setCursor(2, 0);
        lcd.print("Line Follwer");
        lcd.setCursor(0, 1);
        lcd.print("C:");
        lcd.setCursor(4, 1);
        lcd.print(counter);
       
      }
      else if (cl == 2)  {
        lcd_check();
        lcd.setCursor(2, 0);
        lcd.print("Calibration");
      }
      else if (cl == 3) {
        lcd.setCursor(2, 0);
        lcd.print("Analog Read");
      }
       else if (cl == 4) {
          lcd_check();
        lcd.setCursor(2, 0);
        lcd.print("digital_read");
      }
    
      else if (cl == 5) {
        lcd_check();
        lcd.setCursor(1, 0);
        lcd.print("Robot Position");
      }
      else if (cl == 6) {
        lcd_check();
        lcd.setCursor(5, 0);
        lcd.print("SONAR");
      }
      else if (cl == 7) {
        lcd_check();
        lcd.setCursor(1, 0);
        lcd.print("MOtor Speed");
         lcd.setCursor(0, 1);
        lcd.print("spr:");
        lcd.setCursor(4, 1);
        lcd.print(spr);
        lcd.setCursor(7, 1);
        lcd.print("spl:");
        lcd.setCursor(12, 1);
        lcd.print(spl);
      }
    }
    if (digitalRead(button2) == LOW) {
      if (menu < list) menu++;
      while (digitalRead(button2) == LOW);

    }
    else if (digitalRead(button1) == LOW) {
      if (menu > 1) menu--;
      while (digitalRead(button1) == LOW);
    }

    else if (digitalRead(button) == LOW) {
      t = 0;
      while (digitalRead(button) == LOW) {
        delay(1);
        t++;
        if (t > 500) {
          digitalWrite(mli, 1);
          digitalWrite(lli, 1);
          while (digitalRead(button) == LOW);
          digitalWrite(mli, 0);
          digitalWrite(lli, 0);
          return list+1;
        }
      }
      return cl;

    }
  }


  return cl;
}

int switch2 () {
  int t = 0, cl = 0;
a:  while (digitalRead(button1) == LOW) {
    delay(1);
    digitalWrite(rli, HIGH);
    t++;
  }
  digitalWrite(rli, LOW);

  if (t > 15) {
    cl ++;
    t = 0;
    while (digitalRead(button1) == HIGH) {
      delay(1);
      t++;
      if (t > 500) {
        digitalWrite(mli, 1);
        digitalWrite(lli, 1);
        delay(250);
        digitalWrite(mli, 0);
        digitalWrite(lli, 0);
        return cl ;
      }
    }
    goto a;
  }

  return cl;
}

int switch3 () {
  int t = 0, cl = 0;
a:  while (digitalRead(button2) == LOW) {
    delay(1);
    digitalWrite(lli, HIGH);
    t++;
  }
  digitalWrite(lli, LOW);

  if (t > 15) {
    cl ++;
    t = 0;
    while (digitalRead(button2) == HIGH) {
      delay(1);
      t++;
      if (t > 500) {
        digitalWrite(mli, 1);
        digitalWrite(lli, 1);
        delay(250);
        digitalWrite(mli, 0);
        digitalWrite(lli, 0);
        return cl ;
      }
    }
    goto a;
  }

  return cl;
}
