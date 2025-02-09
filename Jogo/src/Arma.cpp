#include "../include/Arma.hpp"

namespace Entidade {
	namespace Item {
		Arma::Arma(Personagem::Personagem* p, sf::Vector2f tam, const IDs::IDs ID) : Entidade(sf::Vector2f(-500.0f, -500.0f), tam, ID), dano(0.0f), pPersonagem(p), ataquePetrificante(false), ativo(false) {
			if (pPersonagem != nullptr) {
				dano = pPersonagem->getDano() + DANO_ARMA;
			}
			pPersonagem->setArma(this);
			//corpo.setFillColor(sf::Color::Red);
		}
		Arma::~Arma() { pPersonagem = nullptr; }
		void Arma::desenhar() {
			pGG->desenharElemento(corpo);
		}

		void Arma::atualizar() {}

		void Arma::inicializarSprite() {}
		
		void Arma::colisao(Entidade* ent, const sf::Vector2f diferenca) {
			if (ID == IDs::IDs::espadaJogador) {
				if (ent->getID() == IDs::IDs::guerreiraAthena || ent->getID() == IDs::IDs::gorgona || ent->getID() == IDs::IDs::minotauro) {
					Personagem::Personagem* p = dynamic_cast<Personagem::Personagem*>(ent);
					if (!p->getMorrendo()) {
						p->tomarDano(dano, pPersonagem);
						if (p->getMorrendo()) {
							//Morreu
						}
					}
				}
			}
		}

		void Arma::salvar(nlohmann::json& j) {
		}
	}
}