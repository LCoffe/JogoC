#include "../include/Jogo.hpp"

Gerenciador::GerenciadorEventos* Jogo::pGE = Gerenciador::GerenciadorEventos::getGerEventos();
Gerenciador::GerenciadorGrafico* Jogo::pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();
Gerenciador::GerenciadorEstado* Jogo::pGEst = Gerenciador::GerenciadorEstado::getGerEstado();

Jogo::Jogo() : evento() {
	if (pGG == nullptr) {
		cout << "Erro ao criar o Gerenciador Grafico" << endl;
		exit(1);
	}

	if (pGE == nullptr) {
		cout << "Erro ao criar o Gerenciador de Eventos" << endl;
		exit(1);
	}

	if (pGEst == nullptr) {
		cout << "Erro ao criar o Gerenciador de Estados" << endl;
		exit(1);
	}

	pGEst->incluiEstado(IDs::IDs::estadoMenuPrincipal, IDs::IDs::nulo, false);
	executar();
}	

Jogo::~Jogo() {}

void Jogo::executar() {
	while (pGG->estaAberto()) {
		pGG->limpar();
		pGE->tratarEventos();
		pGEst->executar();
		pGG->mostrarElementos();
		pGG->resetarRelogio();
	}
}