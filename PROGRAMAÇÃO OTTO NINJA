#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// =======================
// Estados do Robô OTTO
// =======================
enum Estado {
    INICIALIZACAO,
    AGUARDANDO_SOLICITACAO,
    IR_PARA_TORRE,
    VERIFICAR_DEMANDA,
    COLETAR_ENTULHO,
    DESCARTE_ENTULHO,
    BUSCAR_MATERIAL,
    ENTREGA_MATERIAL,
    MANUTENCAO,
    RETORNO_BASE,
    FINALIZADO
};

// =======================
// Torres do canteiro
// =======================
enum Torre {
    TORRE_A,
    TORRE_B
};

// =======================
// Tipo de demanda
// =======================
enum Demanda {
    ENTULHO,
    MATERIAL
};

// =======================
// Funções do OTTO Ninja
// =======================

// Testes iniciais do robô
void testesIniciais() {
    cout << "OTTO Ninja inicializando...\n";
    cout << "Testando pernas, braço e pá ninja.\n";
    cout << "Testes concluídos.\n\n";
}

// Movimento do robô (pernas)
void moverOtto(string destino) {
    cout << "OTTO Ninja caminhando até: " << destino << endl;
}

// Controle do braço (pá ninja)
void abaixarBraco() {
    cout << "Braço abaixado - pá posicionada para coleta.\n";
}

void levantarBraco() {
    cout << "Braço levantado - pá elevada.\n";
}

void girarBracoDescarte() {
    cout << "Braço girando - descarte do material.\n";
}

// Coleta de entulho
void coletarEntulho() {
    abaixarBraco();
    cout << "Coletando entulho com a pá ninja...\n";
    levantarBraco();
}

// Descarte de entulho
void descartarEntulho() {
    cout << "Posicionando pá sobre a caixa estacionária...\n";
    girarBracoDescarte();
    cout << "Entulho descartado.\n";
}

// Buscar material
void buscarMaterial() {
    cout << "OTTO Ninja coletando material no almoxarifado.\n";
}

// Entrega de material
void entregarMaterial(string torre) {
    cout << "Entregando material na " << torre << " usando o braço.\n";
}

// Simulação de falha
bool falhaDetectada() {
    return rand() % 4 == 0; // 25% de chance de falha
}

// Manutenção
void manutencaoPreventiva() {
    cout << "Manutenção preventiva do OTTO Ninja em andamento...\n";
    cout << "Verificando motores, braço e pá.\n";
}

// =======================
// Programa principal
// =======================
int main() {

    srand(time(NULL));

    Estado estadoAtual = INICIALIZACAO;
    Torre torreSolicitante;
    Demanda demanda;

    while (estadoAtual != FINALIZADO) {

        switch (estadoAtual) {

        case INICIALIZACAO:
            testesIniciais();
            estadoAtual = AGUARDANDO_SOLICITACAO;
            break;

        case AGUARDANDO_SOLICITACAO:
            torreSolicitante = (rand() % 2 == 0) ? TORRE_A : TORRE_B;
            cout << "Solicitação recebida da "
                 << (torreSolicitante == TORRE_A ? "Torre A" : "Torre B") << "\n\n";
            estadoAtual = IR_PARA_TORRE;
            break;

        case IR_PARA_TORRE:
            moverOtto(torreSolicitante == TORRE_A ? "Torre A" : "Torre B");
            estadoAtual = VERIFICAR_DEMANDA;
            break;

        case VERIFICAR_DEMANDA:
            demanda = (rand() % 2 == 0) ? ENTULHO : MATERIAL;
            cout << "Demanda identificada: "
                 << (demanda == ENTULHO ? "Remoção de entulho\n" : "Entrega de material\n");
            estadoAtual = (demanda == ENTULHO) ? COLETAR_ENTULHO : BUSCAR_MATERIAL;
            break;

        case COLETAR_ENTULHO:
            coletarEntulho();
            estadoAtual = DESCARTE_ENTULHO;
            break;

        case DESCARTE_ENTULHO:
            moverOtto("Caixa Estacionária");
            descartarEntulho();
            estadoAtual = falhaDetectada() ? MANUTENCAO : RETORNO_BASE;
            break;

        case BUSCAR_MATERIAL:
            moverOtto("Almoxarifado");
            buscarMaterial();
            estadoAtual = ENTREGA_MATERIAL;
            break;

        case ENTREGA_MATERIAL:
            entregarMaterial(torreSolicitante == TORRE_A ? "Torre A" : "Torre B");
            estadoAtual = falhaDetectada() ? MANUTENCAO : RETORNO_BASE;
            break;

        case MANUTENCAO:
            manutencaoPreventiva();
            estadoAtual = RETORNO_BASE;
            break;
