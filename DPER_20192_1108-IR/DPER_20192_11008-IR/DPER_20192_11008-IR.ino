
#include <IRremoteESP8266.h>

int khz = 38;
int RECV_PIN = 11;
bool ativaMenu = 1;
char menuP, comando;
String upVol,downVol,onOff;

IRrecv irrecv(RECV_PIN);
IRsend irsend(D1);

decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {

    Serial.println("\n\nO que deseja fazer?");
    Serial.println("1-Gravar novo comando");
    Serial.println("2-Controlar Aparelho");
    //Serial.println("");
    while(!Serial.available());
    menuP = Serial.read();
    
    if (menuP == '1'){
      grava();
    }else if(menuP == '2'){
      controla();
    }
}
 

void grava(){
  Serial.println("1-Gravar novo comando");
  while (!irrecv.decode(&results)) {}
    
    Serial.println(results.value, HEX);

    Serial.println("\nComando Capturado. O que significa?\n");
    Serial.println("1-Aumentar temperatura");
    Serial.println("2-Diminuir temperatura");
    Serial.println("3-Ligar/Desligar\n");
    
    while(!Serial.available());
    comando = Serial.read();
    
    if(comando == '1'){
      upVol = results.value;
      Serial.println("1-Aumentar temperatura. Comando Salvo!");
    }else if(comando == '2'){
      upVol = results.value;
      Serial.println("2-Diminuir temperatura. Comando Salvo!");
    }else if(comando == '3'){
      onOff = results.value;
      Serial.println("3-Ligar/Desligar. Comando Salvo!");
    }
    delay(2000);
    irrecv.resume(); // Receive the next value
    
  
  delay(100);
}  

void controla(){
  unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
  
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
  
  delay(5000);
}
