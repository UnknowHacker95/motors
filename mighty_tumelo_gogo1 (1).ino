#define p_motor_l 5
#define p_photo_l A0
#define p_motor_r 6
#define p_photo_r A1
void setup() {
  pinMode(p_motor_r, OUTPUT);
  pinMode(p_motor_l, OUTPUT);
}

void loop() {
  int vr = map(analogRead(p_photo_r), 0, 1023, 0, 255);
  int vl = map(analogRead(p_photo_l), 0, 1023, 0, 255);
  int v0 = 122;
  int delta, k = 2;
  if(vr > vl){
    if(vr - vl < 5){
      vl = vr = v0;
    } else{
      delta = vr - vl;
      vr = v0 + delta * k;
      vl = v0 - delta * k;
    }
  }else{
    if(vl - vr < 5){
      vl = vr = v0;
    } else{
      delta = vl - vr;
      vl = v0 + delta * k;
      vr = v0 - delta * k;
    }
  }
  analogWrite(p_motor_r, vr);
  analogWrite(p_motor_l, vl);
}