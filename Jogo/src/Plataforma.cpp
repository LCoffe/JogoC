#include "../include/Plataforma.hpp"

namespace Entidade {
	namespace Obstaculos {
		Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) : Obstaculo(pos, tam, ID) {
			corpo.setFillColor(sf::Color::Red);
			corpo.setSize(tam);
			corpo.setPosition(pos);
		}

		Plataforma::~Plataforma() {}

		void Plataforma::desenhar() {
			pGG->desenharElemento(corpo);
		}

		void Plataforma::atualizar(){}

		void Plataforma::colisao(Entidade* ent, sf::Vector2f diferenca) {
			if (ent->getID() == IDs::IDs::jogador){
				colisaoObs(dynamic_cast<Personagem::Personagem*>(ent), diferenca);
			}
			else if (ent->getID() == IDs::IDs::inimigo) {
				Personagem::Personagem* pp = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(pp, diferenca);
				if (pp->getPos().x < pos.x && pp->getDirecao()) { //se a plataforma estiver a direita do inimigo e ele estiver indo para a direita
					pp->setDirecao(false);
				}
				else if (pp->getPos().x < pos.x && !pp->getDirecao()) { //se a plataforma estiver a esquerda do inimigo e ele estiver indo para a esquerda
					pp->setDirecao(true);
				}
			}
		}
	}
}