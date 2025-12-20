
//COMPILADOR C++ 
// https://www.onlinegdb.com/online_c++_compiler


//INICIO DA PROGRAMAÇÃO

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Estados do robô
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

// Torres
enum Torre {
    TORRE_A,
    TORRE_B
};

// Demandas
enum Demanda {
    ENTULHO,
    MATERIAL
};

// Funções de ação
void testesIniciais() {
    cout << "Testes iniciais do robô concluídos.\n";
}

void moverPara(string local) {
    cout << "Movendo para: " << local << endl;
}

void coletarEntulho() {
    cout << "Abaixando pá e coletando entulho...\n";
}

void descartarEntulho() {
    cout << "Despejando entulho na caixa estacionária.\n";
}

void buscarMaterial() {
    cout << "Coletando material no almoxarifado.\n";
}

void entregarMaterial(string torre) {
    cout << "Entregando material na " << torre << endl;
}

bool falhaDetectada() {
    return rand() % 2; // 50% chance de falha
}

void manutencaoPreventiva() {
    cout << "Manutenção preventiva realizada.\n";
}

int main() {
    srand(time(NULL)); // inicializa aleatoriedade

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
                 << (torreSolicitante == TORRE_A ? "Torre A" : "Torre B") << endl;
            estadoAtual = IR_PARA_TORRE;
            break;

        case IR_PARA_TORRE:
            moverPara(torreSolicitante == TORRE_A ? "Torre A" : "Torre B");
            estadoAtual = VERIFICAR_DEMANDA;
            break;

        case VERIFICAR_DEMANDA:
            demanda = (rand() % 2 == 0) ? ENTULHO : MATERIAL;
            estadoAtual = (demanda == ENTULHO) ? COLETAR_ENTULHO : BUSCAR_MATERIAL;
            break;

        case COLETAR_ENTULHO:
            coletarEntulho();
            estadoAtual = DESCARTE_ENTULHO;
            break;

        case DESCARTE_ENTULHO:
            moverPara("Caixa Estacionária");
            descartarEntulho();
            estadoAtual = falhaDetectada() ? MANUTENCAO : RETORNO_BASE;
            break;

        case BUSCAR_MATERIAL:
            moverPara("Almoxarifado");
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

        case RETORNO_BASE:
            moverPara("Posição Inicial");
            estadoAtual = FINALIZADO;
            break;
        }
    }

    cout << "Ciclo de operação finalizado.\n";
    return 0;
}
