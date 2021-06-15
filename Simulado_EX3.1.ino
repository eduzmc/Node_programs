#define LED1 14
#define LED2 12
#define LED_LIGADO 0
#define LED_DESLIGADO 1
#define BOTAO1 5
#define BOTAO2 4
#define BOTAO_LIGADO 0
#define BOTAO_DESLIGADO 1
int estado;
void inicializa_hardware(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LED_DESLIGADO);
  //digitalWrite(LED2, LED_DESLIGADO);
  pinMode(BOTAO1, INPUT_PULLUP);
  pinMode(BOTAO2, INPUT_PULLUP);
}

long tempo1, tempo_interrupcao;

ICACHE_RAM_ATTR void mudar_led_int(){
  if(millis() - tempo_interrupcao >= 500){
    tempo_interrupcao = millis();
    digitalWrite(LED2, !digitalRead(LED2));
  }

void setup() {
  inicializa_hardware();
  tempo1 = millis();
  tempo_interrupcao = millis();
}
void loop() {
    
    }
