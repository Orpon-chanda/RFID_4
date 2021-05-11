void break1(){
  digitalWrite(BL, HIGH);
  motor(0 * spl, 0 * spr);
  motor(-10 * spl, -10 * spr);
  delay(230);
  digitalWrite(BL, LOW);
  }
void break2(){
  digitalWrite(BL, HIGH);
  motor(0 * spl, 0 * spr);
  motor(-10 * spl, -10 * spr);
  delay(50);
  digitalWrite(BL, LOW);
  }
