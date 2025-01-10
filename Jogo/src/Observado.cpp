#include "../include/Observado.hpp"

namespace Observado {
	Observado* Observado::pObservado = nullptr;

	Observado::Observado() : observadores(), it() {}

	bool Observado::inicializaIt() {
		if (!observadores.empty()) {
			return true;
		}
		return false;
	}

	Observado::~Observado() {
		for (auto& it : observadores) {
			if (it) {
				delete it;
			}
			it = nullptr;
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
		for (auto it = observadores.begin(); it != observadores.end(); it++) {
			if (*it == observador) {
				observadores.erase(it);
				break;
			}
		}
	}

	void Observado::notificaTeclaPressionada(sf::Keyboard::Key tecla) {
		if (!inicializaIt()) return;
		for (it = 0; it < (int)observadores.size(); it++) {
			if (observadores[it]) {
				if (observadores[it]->getAtivar()) {
					observadores[it]->attTeclaPressionada(tecla);
				}
			}
		}
	}

	void Observado::notificaTeclaUnica(sf::Keyboard::Key tecla) {
		if (!inicializaIt()) return;
		for (it = 0; it < (int)observadores.size(); it++) {
			if (observadores[it]) {
				if (observadores[it]->getAtivar()) {
					observadores[it]->attTeclaUnica(tecla);
				}
			}
		}
	}
}