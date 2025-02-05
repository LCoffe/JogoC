#include "../include/ObservadorJogador.hpp"

namespace Observado {
	namespace Observador {
		ObservadorJogador::ObservadorJogador(Entidade::Personagem::Jogador::Jogador* pJog) : Observador(), pJogador(pJog),
		tempoAtaque(0.0f){
			if (pJogador == nullptr) {
				//cout << "Erro ao criar observer do jogador : jogador nao foi criado" << endl;
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
					if (!pJogador->getPetrificado() && !pJogador->getLevandoDano())
						pJogador->andar(false);
				}
				if (tecla == sf::Keyboard::D) {
					if (!pJogador->getPetrificado() && !pJogador->getLevandoDano())
						pJogador->andar(true);
				}
				if (tecla == sf::Keyboard::E) {
					pJogador->atacar(true);
				}
			}
			else {
				if (tecla == sf::Keyboard::Up) {
					pJogador->pular();
				}
				if (tecla == sf::Keyboard::Left) {
					if (!pJogador->getPetrificado() && !pJogador->getLevandoDano())
						pJogador->andar(false);
				}
				if (tecla == sf::Keyboard::Right && !pJogador->getLevandoDano()) {
					if (!pJogador->getPetrificado())
						pJogador->andar(true);
				}
				if (tecla == sf::Keyboard::L) {
					pJogador->atacar(true);
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
				if (tecla == sf::Keyboard::R) {
					if (pJogador->getTamanhoArmas() > 1) {
						if (pJogador->getArma()->getID() == IDs::IDs::projetil && !pJogador->getArma()->getAtivo()) {
							pJogador->trocarArma();
						}
						else if(pJogador->getArma()->getID() == IDs::IDs::espadaJogador) {
							pJogador->trocarArma();
						}
					}	
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