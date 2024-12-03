#include "../include/GerenciadorEventos.hpp"
#include "../include/Subject.hpp"

#include <iostream>

using namespace std;

namespace Gerenciador {
	Subject::Subject* GerenciadorEventos::pSubject = Subject::Subject::getSubject();
	GerenciadorEventos* GerenciadorEventos::pGerenciadorEventos = nullptr;
	GerenciadorGrafico* GerenciadorEventos::pGG = GerenciadorGrafico::getGerGrafico();

	GerenciadorEventos::GerenciadorEventos(): event() {
		if (pGG == nullptr) {
			cout << "Erro ao criar gerenciador de eventos : gerenciador grafico nao foi criado" << endl;
			exit(1);
		}
		
		if (pSubject == nullptr) {
			cout << "Erro ao criar gerenciador de eventos : subject nao foi criado" << endl;
			exit(1);
		}
	}

	GerenciadorEventos::~GerenciadorEventos() {
		pGG = nullptr;
		pGerenciadorEventos = nullptr;
		pSubject = nullptr;
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

	void GerenciadorEventos::tratarKeyReleased() {
		if (event.key.code == sf::Keyboard::A) {
			pSubject->notifyKeyReleased(event.key.code);
		}
		if (event.key.code == sf::Keyboard::D) {
			pSubject->notifyKeyReleased(event.key.code);
		}
	}

	void GerenciadorEventos::tratarKeyPressed() {
		if (event.key.code == sf::Keyboard::W) {
			pSubject->notifyKeyPressed(event.key.code);
		}
		if (event.key.code == sf::Keyboard::A) {
			pSubject->notifyKeyPressed(event.key.code);
		}
		if (event.key.code == sf::Keyboard::D) {
			pSubject->notifyKeyPressed(event.key.code);
		}
		if (event.key.code == sf::Keyboard::Escape) {
			tratarEventoJanela();
		}
	}	

	const sf::Event GerenciadorEventos::getEvent() const {
		return event;
	}

	void GerenciadorEventos::tratarEventos() {
		while (pGG->getWindow()->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				tratarEventoJanela();
			}
			if (event.type == sf::Event::KeyPressed) {
				tratarKeyPressed();
			}
			if (event.type == sf::Event::KeyReleased) {
				tratarKeyReleased();
			}
		}
	}
}