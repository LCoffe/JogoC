#pragma once

#include "../include/Inimigo.hpp"

constexpr auto PARADOG_PATH = "..\\Jogo\\assets\\inimigos\\gorgona\\gorgona_parado.png";
constexpr auto ANDARG_PATH = "..\\Jogo\\assets\\inimigos\\gorgona\\gorgona_andar.png";

//constexpr auto PULO_PATH = "..\\Jogo\\assets\\jogador\\jogador_pulo.png";
//constexpr auto ATAQUE_PATH = "..\\Jogo\\assets\\jogador\\jogador_ataque.png";

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {

			class Gorgona : public Inimigo
			{
			public:
				Gorgona(const sf::Vector2f pos, Jogador::Jogador* pJ);
				~Gorgona();

				void atualizar() override;
				void	desenhar();
				void salvar(nlohmann::json& j) override;
				void colisao(Entidade* ent, const sf::Vector2f diferenca) override;
				void inicializarSprite() override;
				void atualizarSprite(float dt) override;

			};
		}
	}
}


