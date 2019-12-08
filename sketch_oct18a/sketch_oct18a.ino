//DPER 2019.2 - Pratica 02
//Rodrigo D. Bernardo de Araujo

int sinal;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  sinal = map(analogRead(A0),0,1023,0,255); //sem fazer o map tambem funciona.
  analogWrite(3, 255-sinal);
  delay(10);
}
