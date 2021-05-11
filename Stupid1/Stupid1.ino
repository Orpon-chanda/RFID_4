#include <EEPROM.h>
#include<NewPing.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int lmf = 4, lmb = 5, rmf = 2, rmb = 3;
int s[6];
int midpoint = 10;
int error = 0;
int pid_p = 0;
double kp = 0.5;

int menu = 1;

int error1 = 0;
int pid_p1 = 0;
double kp1 = 0.5;
//int button = A7;
int tht = 120;
int trash[] = {0, 0, 0, 0, 0, 0};
int lcd_cursor1[6] = {0, 5, 10, 0, 5, 10};
int lcd_cursor2[6] = {0, 0, 0, 1, 1, 1};
int sum , data;
int binary[] = {1, 2, 4, 8, 16, 32};
int dt = 15;
int r;
int counter = 0;
int spl = 23, spr = 23;
int dh = 20;
int turn = 0, cross = 0, k = 0 , m = 0;
long int mi1, mi2, mi3, mi4, mi5, mi6;
int maximum [] = {0, 0, 0, 0, 0, 0};
int minimum [] = {1024, 1024, 1024, 1024, 1024, 1024};
int k90 = 0;
int k30 = 0;
int BL = 50;
int button = 10;
int button1 = 11;
int button2 = 12;
int bazzar = 52;
int mli = 7;
int lli = 6;
int rli = 13;
int trigl = 23;
int trigf = 47;
int trigr = 53;
int echof = 49;
int echor = 51;
int echol = 25;
int sr = 0;
int sl = 0;
int sf = 0;
//String manu[10] = {"Checkmate","Line Follower", "Calibration", "Analog Read","Sonar"};
int buttonState = 0;
int cl = 0;
int cl1 = 0;


NewPing sonarl(trigl, trigl, 50);
NewPing sonarf(trigf, echof, 90);
NewPing sonarr(trigr, trigr, 50);

void setup() {
  Serial.begin(9600);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(BL, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(echol, INPUT);
  pinMode(echor, INPUT);
  lcd.init();
  lcd.init();
  lcd.backlight();

  for (int i = 0; i < 6; i++) trash[i] = EEPROM.read(i) * 5;
  counter = EEPROM.read(8);
//  spr = EEPROM.read(9);
//spl = EEPROM.read(9);
  lcd_check();
  lcd.setCursor(4, 0);
  lcd.print("**Robot**");
  lcd.setCursor(1, 1);
  lcd.print("#...Stupid...#");
}

void loop() {

  //  lcd1();
  check();
  debug();
  int r = switch1();
  if (r != 0) {
    if (r == 1) line_follower();
    else if (r == 2) cal();
    else if (r == 3) analog_read();
    else if (r == 4)digital_read();
    else if (r == 5) motor(10 * spl, 10 * spr);
    else if (r == 6) sonar_read();


    lcd_check();
    lcd.setCursor(5, 0);
    lcd.print("**SPI**");
    lcd.setCursor(2, 1);
    lcd.print("#Checkmate#");

    lcd_check();
  }


  r = switch2();
  if (r != 0) {
    counter = r - 1;
    EEPROM.write(8, counter);
  }

//  r = switch3();
//  if (r != 0) {
//    spr = r - 1;
//    spl = r - 1;
//    EEPROM.write(9,  spr & spl);
//  }
}
