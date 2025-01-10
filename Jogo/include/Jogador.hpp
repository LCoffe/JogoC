#pragma once

#include "../stdafx/stdafx.hpp"
#include "Personagem.hpp"
#include "../include/json.hpp"

#define VELOCIDADE_JOGADOR 80.0f
#define ALTURA_PULO 900.0f
#define TAM_JOGADOR_X 50.0f
#define TAM_JOGADOR_Y 50.0f
#define DANO_JOGADOR 10.0f

constexpr auto PARADO_PATH = "..\\Jogo\\assets\\jogador\\jogador.png";
constexpr auto ANDAR_PATH = "..\\Jogo\\assets\\jogador\\jogador_andar.png";
constexpr auto PULO_PATH = "..\\Jogo\\assets\\jogador\\jogador_pulo.png";
constexpr auto ATAQUE_PATH = "..\\Jogo\\assets\\jogador\\jogador_ataque.png";

namespace Observado {
	namespace Observador {
		class ObservadorJogador;
	}
}

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			class Jogador : public Personagem {
			private:
				Observado::Observador::ObservadorJogador* pObs;
				bool podePular;
				bool jogadorUm;
			public:
				Jogador(const sf::Vector2f pos);
				~Jogador();
				void pular();
				void setJogadorUm(bool jogadorUm) { this->jogadorUm = jogadorUm; }
				bool getJogadorUm() { return jogadorUm; }
				void desenhar();
				void atualizar();
				void colisao(Entidade* ent, const sf::Vector2f diferenca);
				void setAtivoObs(const bool ativo);
				void inicializarSprite();
				void atualizarSprite(float dt);
				void salvar(nlohmann::json& j);
			};
		}
	}
}