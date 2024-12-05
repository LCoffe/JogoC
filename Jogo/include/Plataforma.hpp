#pragma once

#include "../include/Obstaculo.hpp"

#define TAM_PLATAFORMA_X 250.0f
#define TAM_PLATAFORMA_Y 50.0f

namespace Entidade {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {
			protected:
			
			public:
				Plataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
				~Plataforma();
				void colisao(Entidade* ent, const sf::Vector2f diferenca);
				virtual void desenhar();
				virtual void atualizar();
		};
	}
}