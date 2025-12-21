#include <Otto.h>

// ====================
// Definição do robô
// ====================
Otto otto;

// ====================
// Pinos do hardware
// ====================
#define PIN_YL 2
#define PIN_YR 3
#define PIN_RL 4
#define PIN_RR 5
#define PIN_BUZZER 13
#define PIN_TRIG 8
#define PIN_ECHO 9

// ====================
// Estados da Rede de Petri
// ====================
enum Estado {
  INICIALIZACAO,
  AGUARDANDO_DEMANDA,
  IR_PARA_TORRE,
  VERIFICAR_DEMANDA,
  COLETAR_ENTULHO,
  DESCARTE_ENTULHO,
  RETORNO_BASE
};

Estado estadoAtual = INICIALIZACAO;

// ====================
// Setup
// ====================
void setup() {
  otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true, PIN_BUZZER);
  otto.initUltrasonic(PIN_TRIG, PIN_ECHO);

  otto.sing(S_connection);
  otto.home();
  delay(2000);
}

// ====================
// Loop principal
// ====================
void loop() {

  switch (estadoAtual) {

    // P0 – Inicialização
    case INICIALIZACAO:
      otto.home();
      delay(1000);
      estadoAtual = AGUARDANDO_DEMANDA;
      break;

    // P1 – Aguardando demanda
    case AGUARDANDO_DEMANDA:
      // Simulação de chegada de demanda
      otto.walk(2, 1000, 1);
      estadoAtual = IR_PARA_TORRE;
      break;

    // P2 – Ir para a torre
    case IR_PARA_TORRE:
      otto.walk(4, 1000, 1);
      estadoAtual = VERIFICAR_DEMANDA;
      break;

    // P3 – Verificar demanda
    case VERIFICAR_DEMANDA:
      if (otto.getDistance() < 15) {
        estadoAtual = COLETAR_ENTULHO;
      } else {
        estadoAtual = RETORNO_BASE;
      }
      break;

    // P4 – Coleta de entulho
    case COLETAR_ENTULHO:
      otto.playGesture(OttoHappy);
      delay(1500);
      estadoAtual = DESCARTE_ENTULHO;
      break;

    // P5 – Descarte de entulho
    case DESCARTE_ENTULHO:
      otto.playGesture(OttoConfused);
      delay(1500);
      estadoAtual = RETORNO_BASE;
      break;

    // P6 – Retorno à base
    case RETORNO_BASE:
      otto.walk(3, 1000, -1);
      otto.sing(S_cuddly);
      delay(2000);
      estadoAtual = AGUARDANDO_DEMANDA;
      break;
  }
}

