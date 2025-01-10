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
					tempoAtaque = 0.0f;
				}
				if (tecla == sf::Keyboard::A) {
					pJogador->andar(false);
					tempoAtaque = 0.0f;
				}
				if (tecla == sf::Keyboard::D) {
					pJogador->andar(true);
					tempoAtaque = 0.0f;
				}
				if (tecla == sf::Keyboard::E) {
					if (!pJogador->getAtacando()) {
						tempoAtaque += pGG->getTempo();
					}
					if (tempoAtaque > 0.2f) {
						tempoAtaque -= pGG->getTempo();
						pJogador->atacar(true);
					}
					else if (pJogador->getAtacando()) {
						tempoAtaque -= 0.016f;
						if (tempoAtaque <= 0.0f) {
							tempoAtaque = 0.0f;
							pJogador->atacar(false);
						}
					}
				}
			}
			else {
				if (tecla == sf::Keyboard::Up) {
					pJogador->pular();
					tempoAtaque = 0.0f;
				}
				if (tecla == sf::Keyboard::Left) {
					pJogador->andar(false);
					tempoAtaque = 0.0f;
				}
				if (tecla == sf::Keyboard::Right) {
					pJogador->andar(true);
					tempoAtaque = 0.0f;
				}
				if (tecla == sf::Keyboard::L) {
					if (!pJogador->getAtacando()) {
						tempoAtaque += pGG->getTempo();
					}
					if (tempoAtaque > 0.2f) {
						tempoAtaque -= pGG->getTempo();
						pJogador->atacar(true);
					}
					else if (pJogador->getAtacando()) {
						tempoAtaque -= 0.016f;
						if (tempoAtaque <= 0.0f) {
							tempoAtaque = 0.0f;
							pJogador->atacar(false);
						}
					}
				}
			}
		}

		void ObservadorJogador::attTeclaUnica(sf::Keyboard::Key tecla) {
			if (pJogador->getJogadorUm()) {
				if (tecla == sf::Keyboard::A) {
					pJogador->parar();
					tempoAtaque = 0;
				}
				if (tecla == sf::Keyboard::D) {
					pJogador->parar();
					tempoAtaque = 0;
				}
				if (tecla == sf::Keyboard::E) {
					pJogador->atacar(false);
					tempoAtaque = 0;
				}
			}
			else{
				if (tecla == sf::Keyboard::Left) {
					pJogador->parar();
					tempoAtaque = 0;
				}
				if (tecla == sf::Keyboard::Right) {
					pJogador->parar();
					tempoAtaque = 0;
				}
				if (tecla == sf::Keyboard::L) {
					pJogador->atacar(false);
					tempoAtaque = 0;
				}
			}
		}
	}
}