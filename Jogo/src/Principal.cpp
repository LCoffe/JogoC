#include "../include/Principal.hpp"

Gerenciador::GerenciadorEventos* Principal::pGE = Gerenciador::GerenciadorEventos::getGerenciadorEventos();
Gerenciador::GerenciadorGrafico* Principal::pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();

Principal::Principal(): evento(), fase() {
	if (pGG == nullptr) {
		cout << "Erro ao criar o Gerenciador Grafico" << endl;
		exit(1);
	}

	if (pGE == nullptr) {
		cout << "Erro ao criar o Gerenciador de Eventos" << endl;
		exit(1);
	}
}

Principal::~Principal(){}

void Principal::executar() {
	while (pGG->estaAberto()) {
		pGG->limpar();
		pGE->tratarEventos();
		fase.executar();
		pGG->mostrarElementos();
	}
}