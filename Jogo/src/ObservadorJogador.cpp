#include "../include/ObservadorJogador.hpp"

namespace Observado {
	namespace Observador {
		ObservadorJogador::ObservadorJogador(Entidade::Personagem::Jogador::Jogador* pJog) : Observador(), pJogador(pJog),
		tempoAtaque(0.0f){
			if (pJogador == nullptr) {
				cout << "Erro ao criar observer do jogador : jogador nao foi criado" << endl;
				exit(1);
			}
		}
		ObservadorJogador::~ObservadorJogador() {
			pJogador = nullptr;
		}

		void ObservadorJogador::attTeclaPressionada(sf::Keyboard::Key tecla) {
			if (pJogador->getJogadorUm()) {
				if (tecla == sf::Keyboard::W) {
					pJogador->pular();
				}
				if (tecla == sf::Keyboard::A) {
					pJogador->andar(false);
				}
				if (tecla == sf::Keyboard::D) {
					pJogador->andar(true);
				}
				if (tecla == sf::Keyboard::E) {
					pJogador->atualizarTempoAtaque();
				}
			}
			else {
				if (tecla == sf::Keyboard::Up) {
					pJogador->pular();
				}
				if (tecla == sf::Keyboard::Left) {
					pJogador->andar(false);
				}
				if (tecla == sf::Keyboard::Right) {
					pJogador->andar(true);
				}
				if (tecla == sf::Keyboard::L) {
					pJogador->atualizarTempoAtaque();
				}
			}
		}

		void ObservadorJogador::attTeclaUnica(sf::Keyboard::Key tecla) {
			if (pJogador->getJogadorUm()) {
				if (tecla == sf::Keyboard::A) {
					pJogador->parar();
				}
				if (tecla == sf::Keyboard::D) {
					pJogador->parar();
				}
				if (tecla == sf::Keyboard::E) {
					pJogador->atacar(false);
				}
			}
			else{
				if (tecla == sf::Keyboard::Left) {
					pJogador->parar();
				}
				if (tecla == sf::Keyboard::Right) {
					pJogador->parar();
				}
				if (tecla == sf::Keyboard::L) {
					pJogador->atacar(false);
				}
			}
		}
	}
}