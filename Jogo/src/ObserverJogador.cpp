#include "../include/ObserverJogador.hpp"

namespace Subject {
	namespace Observer {
		ObserverJogador::ObserverJogador(Entidade::Personagem::Jogador::Jogador* pJog) : Observer(), pJogador(pJog) {
			if (pJogador == nullptr) {
				cout << "Erro ao criar observer do jogador : jogador nao foi criado" << endl;
				exit(1);
			}
		}
		ObserverJogador::~ObserverJogador() {
			pJogador = nullptr;
		}

		void ObserverJogador::upKeyPressed(sf::Keyboard::Key tecla) {
			if (tecla == sf::Keyboard::W) {
				pJogador->pular();
			}
			if (tecla == sf::Keyboard::A) {
				pJogador->setDirecao(false);
				pJogador->mover();
			}
			if (tecla == sf::Keyboard::D) {
				pJogador->setDirecao(true);
				pJogador->mover();
			}
		}

		void ObserverJogador::upKeyReleased(sf::Keyboard::Key tecla) {
			if (tecla == sf::Keyboard::A) {
				pJogador->setDirecao(false);
			}
			if (tecla == sf::Keyboard::D) {
				pJogador->setDirecao(true);
			}
		}
	}
}