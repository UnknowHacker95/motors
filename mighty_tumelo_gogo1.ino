#define p_motor 6
#define p_photo A0

void setup() {
  pinMode(p_motor, OUTPUT);
}

void loop() {
  int v = map(analogRead(p_photo), 0, 1023, 0, 255);
  analogWrite(p_motor, v);
}