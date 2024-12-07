#include "../include/Jogo.hpp"

Gerenciador::GerenciadorEventos* Jogo::pGE = Gerenciador::GerenciadorEventos::getGerEventos();
Gerenciador::GerenciadorGrafico* Jogo::pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();

Jogo::Jogo(): evento(), fase() {
	if (pGG == nullptr) {
		cout << "Erro ao criar o Gerenciador Grafico" << endl;
		exit(1);
	}

	if (pGE == nullptr) {
		cout << "Erro ao criar o Gerenciador de Eventos" << endl;
		exit(1);
	}
}

Jogo::~Jogo(){}

void Jogo::executar() {
	while (pGG->estaAberto()) {
		pGG->limpar();
		pGE->tratarEventos();
		fase.executar();
		pGG->mostrarElementos();
	}
}