#include "../../include/gerenciadores/GerenciadorEventos.hpp"
#include "../../include/Observado.hpp"

#include <iostream>

using namespace std;

namespace Gerenciador {
	Observado::Observado* GerenciadorEventos::pObservado = Observado::Observado::getObservado();
	GerenciadorEventos* GerenciadorEventos::pGE = nullptr;
	GerenciadorGrafico* GerenciadorEventos::pGG = GerenciadorGrafico::getGerGrafico();

	GerenciadorEventos::GerenciadorEventos(): evento() {
		if (pGG == nullptr) {
			//cout << "Erro ao criar gerenciador de eventos : gerenciador grafico nao foi criado" << endl;
			exit(1);
		}
		
		if (pObservado == nullptr) {
			//cout << "Erro ao criar gerenciador de eventos : subject nao foi criado" << endl;
			exit(1);
		}
	}

	GerenciadorEventos::~GerenciadorEventos() {
		pGG = nullptr;
		pGE = nullptr;
		pObservado = nullptr;
	}

	GerenciadorEventos* GerenciadorEventos::getGerEventos() {
		if (pGE == nullptr) {
			pGE = new GerenciadorEventos();
		}

		return pGE;
	}

	void GerenciadorEventos::tratarEventoJanela() {
		pGG->fechar();
	}

	void GerenciadorEventos::tratarTeclaUnica() {
		if (evento.key.code >= sf::Keyboard::A && evento.key.code <= sf::Keyboard::Z) {
			pObservado->notificaTeclaUnica(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::Left) {
			pObservado->notificaTeclaUnica(evento.key.code);
		}	
		if (evento.key.code == sf::Keyboard::Right) {
			pObservado->notificaTeclaUnica(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::Up) {
			pObservado->notificaTeclaUnica(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::Down) {
			pObservado->notificaTeclaUnica(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::Return) {
			pObservado->notificaTeclaUnica(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::Escape) {
			pObservado->notificaTeclaUnica(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::BackSpace) {
			pObservado->notificaTeclaUnica(evento.key.code);
		}
	}

	void GerenciadorEventos::tratarTeclaPressionada() {
		if (evento.key.code >= sf::Keyboard::A && evento.key.code <= sf::Keyboard::Z) {
			pObservado->notificaTeclaPressionada(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::Up) {
			pObservado->notificaTeclaPressionada(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::Left) {
			pObservado->notificaTeclaPressionada(evento.key.code);
		}
		if (evento.key.code == sf::Keyboard::Right) {
			pObservado->notificaTeclaPressionada(evento.key.code);
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