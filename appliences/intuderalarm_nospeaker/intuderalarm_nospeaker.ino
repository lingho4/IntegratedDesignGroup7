const int trig_pin = 9;
const int echo_pin= 10;


void setup() {
  // put your setup code here, to run once:
pinMode(trig_pin,OUTPUT);
pinMode (echo_pin, INPUT);
Serial.begin(9600);
}

void loop() {
long dur;
int dist;
  // put your main code here, to run repeatedly:
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  dur= pulseIn(echo_pin,HIGH);
  dist= ((0.034*dur)/2);
  Serial.print("Diatance: ");
  Serial.println(dist);
  Serial.print("cm");
}
