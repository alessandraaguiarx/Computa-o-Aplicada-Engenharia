#include <iostream>
using namespace std;

// Estados possíveis do robô
enum Estado {
    INICIALIZACAO,
    AGUARDANDO_SOLICITACAO,
    VERIFICAR_DEMANDA,
    COLETAR_ENTULHO,
    BUSCAR_MATERIAL,
    DESCARTE_ENTULHO,
    ENTREGA_MATERIAL,
    MANUTENCAO,
    RETORNO_BASE,
    FINALIZADO
};

// Torres possíveis
enum Torre {
    TORRE_A,
    TORRE_B
};

// Tipos de demanda
enum Demanda {
    ENTULHO,
    MATERIAL
};

// Funções simulando ações do robô
void testesIniciais() {
    cout << "Realizando testes iniciais do robô...\n";
}

void moverPara(string local) {
    cout << "Movendo para: " << local << endl;
}

void coletarEntulho() {
    cout << "Coletando entulho...\n";
}

void descartarEntulho() {
    cout << "Descartando entulho na caixa estacionária...\n";
}

void buscarMaterial() {
    cout << "Buscando material no almoxarifado...\n";
}

void entregarMaterial(string torre) {
    cout << "Entregando material na " << torre << endl;
}

bool manutencaoNecessaria() {
    return rand() % 2; // simula decisão
}

void manutencaoPreventiva() {
    cout << "Realizando manutenção preventiva...\n";
}

int main() {
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
            cout << "Solicitação recebida.\n";
            torreSolicitante = TORRE_A;   // Exemplo
            demanda = ENTULHO;            // Exemplo
            estadoAtual = VERIFICAR_DEMANDA;
            break;

        case VERIFICAR_DEMANDA:
            if (demanda == ENTULHO)
                estadoAtual = COLETAR_ENTULHO;
            else
                estadoAtual = BUSCAR_MATERIAL;
            break;

        case COLETAR_ENTULHO:
            moverPara(torreSolicitante == TORRE_A ? "Torre A" : "Torre B");
            coletarEntulho();
            estadoAtual = DESCARTE_ENTULHO;
            break;

        case DESCARTE_ENTULHO:
            moverPara("Caixa Estacionária");
            descartarEntulho();
            estadoAtual = MANUTENCAO;
            break;

        case BUSCAR_MATERIAL:
            moverPara("Almoxarifado");
            buscarMaterial();
            estadoAtual = ENTREGA_MATERIAL;
            break;

        case ENTREGA_MATERIAL:
            entregarMaterial(torreSolicitante == TORRE_A ? "Torre A" : "Torre B");
            estadoAtual = MANUTENCAO;
            break;

        case MANUTENCAO:
            if (manutencaoNecessaria())
                manutencaoPreventiva();
            estadoAtual = RETORNO_BASE;
            break;

        case RETORNO_BASE:
            moverPara("Base Inicial");
            estadoAtual = FINALIZADO;
            break;
        }
    }

    cout << "Ciclo finalizado.\n";
    return 0;
}

