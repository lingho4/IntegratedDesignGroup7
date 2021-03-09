int ThermistorPin = 0;
int AC_LED = 13;
int Vt;
float R1 = 10000;
float logRt, Rt, T;
float c1 = 1.4424e-03, c2 = 1.8405444e-04, c3 = 3.16196e-07;
float Vn;


void setup() 
{
  Serial.begin(9600);
  pinMode(AC_LED,OUTPUT);
}

void loop() 
{

  Vt = analogRead(ThermistorPin);
  Vn= Vt*0.0049;
  Rt = R1 * (5 / (float)Vn - 1.0);
  logRt = log(Rt);
  T = (1.0 / (c1 + c2*logRt + c3*logRt*logRt*logRt));
  T = T - 273.15;
  //T = (T * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" C "); 
  //digitalWrite (AC_LED, HIGH);

delay(500);
  if ( T> 30.0)
{
    digitalWrite(AC_LED, HIGH);
}
  else 
{
  digitalWrite(AC_LED, LOW);
}
    delay(500);
  
}
