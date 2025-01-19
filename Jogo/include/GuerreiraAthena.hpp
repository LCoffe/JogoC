#pragma once

#include "../include/Inimigo.hpp"

#define DANO_GUERREIRA_ATHENA 10.0f

#define TAMANHO_GUERREIRA_ATHENA_X 50.0f
#define TAMANHO_GUERREIRA_ATHENA_Y 50.0f

#define VIDA_GUERREIRA_ATHENA 100.0f

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			class GuerreiraAthena : public Inimigo {
				private:
					void inicializarSprite();
					void atualizarSprite(float dt);
				public:
					GuerreiraAthena(const sf::Vector2f pos, Jogador::Jogador* pJ);
					GuerreiraAthena(const sf::Vector2f pos, Jogador::Jogador* pJ, Jogador::Jogador* pJ2);
					~GuerreiraAthena();
					void desenhar();
					void salvar(nlohmann::json& j);
			};
		}
	}
}