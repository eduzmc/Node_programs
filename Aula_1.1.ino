#define d5_saida_Led1 14
#define ligar_Led LOW
#define desligar_Led HIGH
#define tempo_espera 1000
void setup() {
  
  pinMode(d5_saida_Led1, OUTPUT);
  digitalWrite(d5_saida_Led1, desligar_Led);
  delay(tempo_espera);
  digitalWrite(d5_saida_Led1, ligar_Led);
  
}

void loop() {
  
}
