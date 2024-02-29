const int pinTrig = 3, pinEcho = 4, pinT = 5;

const float Vel_Som = 0.000340;

void setup()
{
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  digitalWrite(pinEcho, LOW);
  analogWrite(pinT, 0); 
}

void loop()
{
  DisparaTrig();
  float tempo = pulseIn(pinEcho, HIGH);
  float dist = CalculaDistancia(tempo);
  dist = dist * 100;
  Serial.println(dist);
  int temp = map(dist, 0, 255, 0, 330);
  analogWrite(pinT, temp);
}

void DisparaTrig()
{
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
}

float CalculaDistancia(float tempo)
{
  float dist = (tempo * Vel_Som) / 2;
  return dist;
}