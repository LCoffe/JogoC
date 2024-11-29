#include "../include/Personagem.hpp"

namespace Entidade {
	namespace Personagem {
		Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID) : 
			Entidade(pos, tam, ID), velocidade(sf::Vector2f(vel, vel)) {}

		Personagem::~Personagem() {}

		void Personagem::draw() {
			pGG->drawElemento(corpo);
		}
	}
}