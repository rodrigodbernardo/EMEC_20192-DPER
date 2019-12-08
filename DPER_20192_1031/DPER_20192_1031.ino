#include <VirtualWire.h>
int token = 0;//token=0 ninguem tem a ficha , token=1 eu tenho a ficha , token=2 outro tem a ficha
 uint8_t buf[VW_MAX_MESSAGE_LEN];
 uint8_t buflen = VW_MAX_MESSAGE_LEN;
 const char *msg = "12 ";
void setup()
{
    pinMode(13,OUTPUT);
    Serial.begin(9600);  // Debugging only
    Serial.println("setup");

    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);  // Bits per sec

    vw_rx_start();       // Start the receiver PLL running
    while((millis()<1000)&&(token==0)){
      if (vw_get_message(buf, &buflen)) // Non-blocking
    {
  int i;

        digitalWrite(13, true); 
  
  for (i = 0; i < buflen; i++)
  {
      Serial.print(buf[i], HEX);
      Serial.print(" ");
  }
  if((buf[1]==0x31))
  {
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone 
    token=1;
  }
  
  digitalWrite(13, false);
    }
     }
}

void loop()
{
   

    
    digitalWrite(13, HIGH); // Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, LOW);
    delay(200);
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
  int i;

        digitalWrite(13, true); // Flash a light to show received good message
  // Message with a good checksum received, dump it.
//  Serial.print("Got: ");
  
  for (i = 0; i < buflen; i++)
  {
      Serial.print(buf[i], HEX);
      Serial.print(" ");
  }
  Serial.println("");
        digitalWrite(13, false);
    }
}
