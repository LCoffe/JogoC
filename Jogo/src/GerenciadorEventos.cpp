#include "../include/GerenciadorEventos.hpp"
#include "../include/Observado.hpp"

#include <iostream>

using namespace std;

namespace Gerenciador {
	Observado::Observado* GerenciadorEventos::pObservado = Observado::Observado::getObservado();
	GerenciadorEventos* GerenciadorEventos::pGerenciadorEventos = nullptr;
	GerenciadorGrafico* GerenciadorEventos::pGG = GerenciadorGrafico::getGerGrafico();

	GerenciadorEventos::GerenciadorEventos(): evento() {
		if (pGG == nullptr) {
			cout << "Erro ao criar gerenciador de eventos : gerenciador grafico nao foi criado" << endl;
			exit(1);
		}
		
		if (pObservado == nullptr) {
			cout << "Erro ao criar gerenciador de eventos : subject nao foi criado" << endl;
			exit(1);
		}
	}

	GerenciadorEventos::~GerenciadorEventos() {
		pGG = nullptr;
		pGerenciadorEventos = nullptr;
		pObservado = nullptr;
	}

	GerenciadorEventos* GerenciadorEventos::getGerenciadorEventos() {
		if (pGerenciadorEventos == nullptr) {
			pGerenciadorEventos = new GerenciadorEventos();
		}

		return pGerenciadorEventos;
	}

	void GerenciadorEventos::tratarEventoJanela() {
		pGG->fechar();
	}

	void GerenciadorEventos::tratarTeclaUnica() {
		if (evento.key.code == sf::Keyboard::A) {
			pObservado->notificaTeclaUnica(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::D) {
			pObservado->notificaTeclaUnica(evento.key.code);
		}
	}

	void GerenciadorEventos::tratarTeclaPressionada() {
		if (evento.key.code == sf::Keyboard::W) {
			pObservado->notificaTeclaPressionada(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::A) {
			pObservado->notificaTeclaPressionada(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::D) {
			pObservado->notificaTeclaPressionada(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::Escape) {
			tratarEventoJanela();
		}
	}	

	const sf::Event GerenciadorEventos::getEvento() const {
		return evento;
	}

	void GerenciadorEventos::tratarEventos() {
		while (pGG->getJanela()->pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				tratarEventoJanela();
			}
			if (evento.type == sf::Event::KeyPressed) {
				tratarTeclaPressionada();
			}
			if (evento.type == sf::Event::KeyReleased) {
				tratarTeclaUnica();
			}
		}
	}
}