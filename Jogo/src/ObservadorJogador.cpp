#include "../include/ObservadorJogador.hpp"

namespace Observado {
	namespace Observador {
		ObservadorJogador::ObservadorJogador(Entidade::Personagem::Jogador::Jogador* pJog) : Observador(), pJogador(pJog) {
			if (pJogador == nullptr) {
				cout << "Erro ao criar observer do jogador : jogador nao foi criado" << endl;
				exit(1);
			}
		}
		ObservadorJogador::~ObservadorJogador() {
			pJogador = nullptr;
		}

		void ObservadorJogador::upTeclaPressionada(sf::Keyboard::Key tecla) {
			if (tecla == sf::Keyboard::W) {
				pJogador->pular();
				
			}
			if (tecla == sf::Keyboard::A) {
				pJogador->andar(false);
			}
			if (tecla == sf::Keyboard::D) {
				pJogador->andar(true);
			}
		}

		void ObservadorJogador::upTeclaUnica(sf::Keyboard::Key tecla) {
			if (tecla == sf::Keyboard::A) {
				pJogador->parar();
			}
			if (tecla == sf::Keyboard::D) {
				pJogador->parar();
			}
		}
	}
}