#pragma once

#include "../stdafx/stdafx.hpp"
#include "../include/Entidade.hpp"


namespace Entidade {
	namespace Personagem {
		class Personagem : public Entidade {
		protected:
			sf::Vector2f velocidade;
		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID);
			~Personagem();
			void setVelocidade(sf::Vector2f vel) { velocidade = vel; }
			const sf::Vector2f& getVelocidade() const { return velocidade; }
			virtual void draw();
			virtual void mover() = 0;
			virtual void atualizar() = 0;
			virtual void colisao(Entidade* ent, const sf::Vector2f diferenca) = 0;
		};
	}
}