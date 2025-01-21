#pragma once

#include "../include/Inimigo.hpp"

constexpr auto PARADOG_PATH = "..\\Jogo\\assets\\inimigos\\gorgona\\gorgona_parado.png";
constexpr auto ANDARG_PATH = "..\\Jogo\\assets\\inimigos\\gorgona\\gorgona_andar.png";
constexpr auto DANOG_PATH = "..\\Jogo\\assets\\inimigos\\gorgona\\gorgona_machucado.png";
constexpr auto ATAQUEG_PATH = "..\\Jogo\\assets\\inimigos\\gorgona\\gorgona_ataque.png";

#define DANO_GORGONA 10.0f
#define VIDA_GORGONA 100.0f
#define TAMANHO_GORGONA_X 50.0f
#define TAMANHO_GORGONA_Y 50.0f

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {

			class Gorgona : public Inimigo
			{
				private:
					bool ataquePetrificante;

					void inicializarSprite();
					void atualizarSprite(float dt);
				public:
					Gorgona(const sf::Vector2f pos, Jogador::Jogador* pJ);
					Gorgona(const sf::Vector2f pos, Jogador::Jogador* pJ, Jogador::Jogador* pJ2);
					~Gorgona();
					void setAtaquePetrificante(bool ataquePetrificante) { this->ataquePetrificante = ataquePetrificante; }
					bool getAtaquePetrificante() { return ataquePetrificante; }
					void desenhar();
					void atualizarTempoAtaque();
					void salvar(nlohmann::json& j);
			};
		}
	}
}


