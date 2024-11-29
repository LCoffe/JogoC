#include "../include/Principal.hpp"

Gerenciador::GerenciadorGrafico* Principal::pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();

Principal::Principal(): event(), fase() {
	if (pGG == nullptr) {
		cout << "Erro ao criar o Gerenciador Grafico" << endl;
		exit(1);
	}
}

Principal::~Principal(){}

void Principal::executar() {
	while(pGG->estaAberto()) {
		while (pGG->getWindow()->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				pGG->fechar();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					pGG->fechar();
				}
			}
		}

		pGG->limpar();
		fase.executar();
		pGG->mostrarElementos();
	}
}