#define LED1 14
#define LED2 12
#define BOTAO1 5
#define BOTAO2 4
#define LED_LIGADO 0
#define LED_DESLIGADO 1
#define BOTAO_LIGADO 0
#define BOTAO_DESLIGADO 1
int estado;

void inicializa_hardware(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BOTAO1, INPUT_PULLUP);
  pinMode(BOTAO2, INPUT_PULLUP);
  digitalWrite(LED1, LED_DESLIGADO);
}

long tempo1, tempo_interrupcao;

ICACHE_RAM_ATTR void mudar_led_int(){
  if(millis() - tempo_interrupcao >= 500){
    tempo_interrupcao = millis();
    digitalWrite(LED2, !digitalRead(LED2));
  }
}
void setup() {
  inicializa_hardware();
 
  tempo1 = millis();
  tempo_interrupcao = millis();
}
void loop() {
    if(millis() - tempo1 >= 500){
    //Atualizar minha hora anotada
    tempo1 = millis();
    //Ação desejada
    digitalWrite(LED2, !digitalRead(LED2));
  }

  if(digitalRead(BOTAO1)==BOTAO_LIGADO){
   estado=!estado;
  delay(300);
  }
   if(estado==0){
    digitalWrite(LED1, LED_LIGADO);
   }else{
    digitalWrite(LED1, LED_DESLIGADO); 
  }
}
