#include "../include/Plataforma.hpp"

namespace Entidade {
	namespace Obstaculos {
		Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) : Obstaculo(pos, tam, ID) {
			corpo.setFillColor(sf::Color::Red);
			corpo.setSize(tam);
			corpo.setPosition(pos);
		}

		Plataforma::~Plataforma() {}

		void Plataforma::draw() {
			pGG->drawElemento(corpo);
		}

		void Plataforma::atualizar(){}

		void Plataforma::colisao(Entidade* ent, sf::Vector2f diferenca) {
			if (ent->getID() == IDs::IDs::jogador ||
				ent->getID() == IDs::IDs::inimigo) {
				colisaoObs(dynamic_cast<Personagem::Personagem*>(ent), diferenca);
			}
		}
	}
}