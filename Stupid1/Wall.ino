void wall() {
  sonar();
//  error = midpoint - sl;
//  pid_p = error * kp;
//
//  sonar();
//  error1 = midpoint - sr;
//  pid_p1 = error1 * kp1;
//
//  Serial.print(pid_p);
//  Serial.print(" ");
//  Serial.println(pid_p1);
//
//  if(pid_p == pid_p1){
//    motor(6 * spl, 6 * spr);
//    }
//  else if(pid_p > 1 && pid_p < 1){
//    motor(5 * spl, 0 * spr);
//    }  
//  else if(pid_p > 2 && pid_p < 2){
//    motor(6 * spl, 0 * spr);
//    }
//  else if(pid_p < 1 && pid_p > 1){
//    motor(0 * spl, 5 * spr);
//    }  
//  else if(pid_p < 2 && pid_p > 2){
//    motor(0 * spl, 6 * spr);
//    } 
motor(200, 200);
if(sf < 20 && sf > 0){
  motor(0, 0);
  delay(100);
  sonar();
  if(sl < 20 && sl > 0){
    motor(200,-200);
    delay(50);
  }
  else if(sr < 20 && sr > 0){
    motor(-200,200);
    delay(50);
  }
  else {
    motor(200,-200);
    delay(100);
    }
  }











 
}
