#include "../include/Arma.hpp"

namespace Entidade {
	namespace Item {
		Arma::Arma(Personagem::Personagem* p, sf::Vector2f tam, const IDs::IDs ID) : Entidade(sf::Vector2f(-500.0f, -500.0f), tam, ID), dano(0.0f), pPersonagem(p) {
			if (pPersonagem != nullptr) {
				dano = pPersonagem->getDano();
			}
			pPersonagem->setArma(this);
			corpo.setFillColor(sf::Color::Red);
		}
		Arma::~Arma() { pPersonagem = nullptr; }
		void Arma::desenhar() {
			pGG->desenharElemento(corpo);
		}

		void Arma::atualizar() {}

		void Arma::inicializarSprite() {}
		
		void Arma::colisao(Entidade* ent, const sf::Vector2f diferenca) {
			if (ID == IDs::IDs::espadaJogador) {
				if (ent->getID() == IDs::IDs::guerreiraAthena || ent->getID() == IDs::IDs::gorgona) {
					Personagem::Personagem* p = dynamic_cast<Personagem::Personagem*>(ent);
					if (!p->getMorrendo()) {
						sf::Vector2f posInimigo = p->getPos();
						p->setPos(sf::Vector2f(pPersonagem->getDirecao() ? posInimigo.x + 10.0f : posInimigo.x - 10.0f, posInimigo.y + 5.0f));
						p->tomarDano(dano);
						if (p->getMorrendo()) {
							Personagem::Jogador::Jogador* pJog = dynamic_cast<Personagem::Jogador::Jogador*>(pPersonagem);
							pJog->addPontuacao(100);
							//add xp outra hora
						}
					}
				}
			}
			else if (ID == IDs::IDs::espadaInimigo) {
				/*if (ent->getID() == IDs::IDs::jogador) {
					Personagem::Jogador::Jogador* p = dynamic_cast<Personagem::Jogador::Jogador*>(ent);
					if (!p->getMorrendo()) {
						p->tomarDano(dano);
						if (!p->getMorrendo()) {
							sf::Vector2f posJogador = p->getPos();
							if (pPersonagem->getDirecao()) {
								p->setPos(sf::Vector2f(posJogador.x + 10.0f, posJogador.y + 5.0f));
							}
							else {
								p->setPos(sf::Vector2f(posJogador.x - 10.0f, posJogador.y + 5.0f));
							}
						}
					}
				}*/
			}
		}

		void Arma::salvar(nlohmann::json& j) {}
	}
}