int motorPin1 = 6;
int motorPin2 = 7;

int pwm = 9;
//Controls speed of motor, can take values from 0 - 255

void setup() {
  // put your setup code here, to run once:

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  pinMode(pwm, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(pwm, 100);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(1000);

  //analogWrite(pwm, 200);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(1000);

}
