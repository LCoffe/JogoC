#pragma once

#include "../../include/entes/personagens/Inimigos/Inimigo.hpp"

constexpr const char* const PARADOM_PATH = "..\\Jogo\\assets\\inimigos\\minotauro\\minotauro_parado.png";
constexpr const char* const	ANDARM_PATH = "..\\Jogo\\assets\\inimigos\\minotauro\\minotauro_andar.png";
constexpr const char* const DANOM_PATH = "..\\Jogo\\assets\\inimigos\\minotauro\\minotauro_machucado.png";
constexpr const char* const ATAQUEM_PATH = "..\\Jogo\\assets\\inimigos\\minotauro\\minotauro_ataque.png";
constexpr const char* const MORTEM_PATH = "..\\Jogo\\assets\\inimigos\\minotauro\\minotauro_morte.png";

#define VIDA_MINOTAURO 200.0f
#define DANO_MINOTAURO 13.0f
#define TAMANHO_MINOTAURO_X 85.0f
#define TAMANHO_MINOTAURO_Y 85.0f
#define RAIO_VISAO_MINOTAURO_X 300.f
#define RAIO_VISAO_MINOTAURO_Y 200.f

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			class Minotauro : public Inimigo {
				public:
					Minotauro(const sf::Vector2f pos, Jogador::Jogador* pJog);
					Minotauro(const sf::Vector2f pos, Jogador::Jogador* pJog1, Jogador::Jogador* pJog2);
					~Minotauro();

					void mover();
					void desenhar();
					void atualizarTempoAtaque();
					void inicializarSprite();
					void atualizarSprite(float dt);
					Jogador::Jogador* procuraJogador();
					void salvar(nlohmann::json& j);
			};
		}
	}
}
