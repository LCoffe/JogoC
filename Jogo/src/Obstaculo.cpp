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
			sf::Vector2f personaVelFinal = persona->getVelocidade();
			
			persona->setColisaoChao(false);			
			if (diferenca.x < 0.0f && diferenca.y < 0.0f) { //houve colisao
				if (diferenca.x > diferenca.y) {
					if (personaPos.x < pos.x) { //colisao em x
						personaPos.x += diferenca.x; //colisao para a direita
					}
					else {
						personaPos.x -= diferenca.x; //colisao para a esquerda
					}
					personaVelFinal.x = 0.0f;
				}
				else {
					if (personaPos.y < pos.y) { //colisao em y
						personaPos.y += diferenca.y;
					}
					else {
						personaPos.y -= diferenca.y;
					}
					personaVelFinal.y = 0.0f;
					persona->setColisaoChao(true);
				}
			}
			persona->setPos(personaPos);
			persona->setVelocidade(personaVelFinal);
		}
	}
}