#include "../include/Observado.hpp"

namespace Observado {
	Observado* Observado::pObservado = nullptr;

	Observado::Observado() : it(), observadores() {}

	Observado::~Observado() {
		for (it = observadores.begin(); it != observadores.end(); it++) {
			if (*it) {
				delete* it;
			}
			*it = nullptr;
		}
		observadores.clear();
	}

	Observado* Observado::getObservado() {
		if (pObservado == nullptr) {
			pObservado = new Observado();
		}

		return pObservado;
	}

	void Observado::incluirObservador(Observador::Observador* observador) {
		observadores.push_back(observador);
	}

	void Observado::removerObservador(Observador::Observador* observador) {
		for (it = observadores.begin(); it != observadores.end(); it++) {
			if (*it == observador) {
				observadores.erase(it);
				break;
			}
		}
	}

	void Observado::notificaTeclaPressionada(sf::Keyboard::Key tecla) {
		for (it = observadores.begin(); it != observadores.end(); it++) {
			(*it)->upTeclaPressionada(tecla);
		}
	}

	void Observado::notificaTeclaUnica(sf::Keyboard::Key tecla) {
		for (it = observadores.begin(); it != observadores.end(); it++) {
			(*it)->upTeclaUnica(tecla);
		}
	}
}