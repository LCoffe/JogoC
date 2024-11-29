#pragma once

#include "../stdafx/stdafx.hpp"
#include "../Personagem.hpp"

#define VELOCIDADE_JOGADOR 0.1f
#define TAM_JOGADOR_X 50.0f
#define TAM_JOGADOR_Y 50.0f

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			class Jogador : public Personagem {
			private:

			public:
				Jogador(const sf::Vector2f pos);
				~Jogador();
				void mover();
				void draw();
				void atualizar();
			};
		}
	}
}