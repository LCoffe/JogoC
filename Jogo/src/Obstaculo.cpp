#include "../include/Obstaculo.hpp"

namespace Entidade {
	namespace Obstaculos {
		Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) : Entidade(pos, tam, ID) {
			this->setTam(tam);
			this->setPos(pos);
		}

		Obstaculo::~Obstaculo() {}

		void Obstaculo::colisaoObs(Personagem::Personagem* persona, const sf::Vector2f diferenca) {
			sf::Vector2f personaPos = persona->getPos();
			sf::Vector2f personaTam = persona->getTam();
			if (diferenca.x < 0.0f && diferenca.y < 0.0f) { //houve colisao
				if (diferenca.x > diferenca.y) {
					if (personaPos.x < pos.x) { //colisao em x
						personaPos.x += diferenca.x; //colisao para a direita
					}
					else {
						personaPos.x -= diferenca.x; //colisao para a esquerda
					}
				}
				else {
					if (personaPos.y < pos.y) { //colisao em y
						personaPos.y += diferenca.y;
						//fazer o pulo do jogador
					}
					else {
						personaPos.y -= diferenca.y;
					}
				}
			}
			persona->setPos(personaPos);
		}
	}
}