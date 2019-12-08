void setup() {
  Serial.begin(9600);
  
}

void loop() {
  int a0 = analogRead(A0);
  int a1 = analogRead(A1);
  int a2 = analogRead(A2);
  int a3 = analogRead(A3);
  int a4 = analogRead(A4);
  int a5 = analogRead(A5);
  int a6 = analogRead(A6);
  int a7 = analogRead(A7);

  //Serial.print("Arduino: \n");
  Serial.print("Porta A0: "+(String)a0+"\n");
  Serial.print("Porta A1: "+(String)a1+"\n");
  Serial.print("Porta A2: "+(String)a2+"\n");
  Serial.print("Porta A3: "+(String)a3+"\n");
  Serial.print("Porta A4: "+(String)a4+"\n");
  Serial.print("Porta A5: "+(String)a5+"\n");
  Serial.print("Porta A6: "+(String)a6+"\n");
  Serial.print("Porta A7: "+(String)a7+"\n");
  Serial.print("\n");

  delay(5000);
}
