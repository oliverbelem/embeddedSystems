#include<Arduino.h>


volatile bool ledState = false;
// ISR Interrupt Service Routine

#define COMPILE
#ifdef COMPILE

ISR(TIMER1_COMPA_vect) {
  ledState = !ledState;         
  digitalWrite(LED_BUILTIN, ledState); 
}


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  noInterrupts();           // Desabilita interrupções
  TCCR1A = 0;               // Registra de controle do Timer1 (modo normal)
  TCCR1B = 0;
  TCNT1 = 0;                // Zera o contador do Timer1

  OCR1A = 31248;            // Valor para comparação (16 MHz / 1024 prescaler - 1 Hz)
  TCCR1B |= (1 << WGM12);   // Modo CTC (Clear Timer on Compare Match)
  TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler de 1024
  TIMSK1 |= (1 << OCIE1A);  // Habilita a interrupção de comparação do Timer1
  interrupts();             // Habilita interrupções
}


void loop() {
  Serial.println("Rodando...");
  delay(500);
}
#endif
