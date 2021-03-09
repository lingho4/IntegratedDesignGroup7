int Photocell= 0;

void setup() {
Serial.begin(9600);
pinMode(13, OUTPUT);
}

void loop() {
Photocell= analogRead(0);
Serial.println(Photocell);
//digitalWrite(13,HIGH);
// turning on and off night light conditions

if ( Photocell> 600)
digitalWrite(13, HIGH);

else 
digitalWrite(13,LOW);
  
delay (500);

}
