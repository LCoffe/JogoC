#pragma once

#include "../stdafx/stdafx.hpp"
#include "../include/Personagem.hpp"
#include "../include/Jogador.hpp"

#define RAIO_VISAO_X 200.f
#define RAIO_VISAO_Y 200.f

#define TAM_INIMIGO_X 50.0f
#define TAM_INIMIGO_Y 50.0f

#define VELOCIDADE_INIMIGO 0.01f

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			class Inimigo : public Personagem {
			private:
				Jogador::Jogador* pJog;
				bool sentidoMovi; // true = direita, false = esquerda
			public:
				Inimigo(const sf::Vector2f pos, Jogador::Jogador* pJ);
				~Inimigo();
				void setJogador(Jogador::Jogador* pJog) { this->pJog = pJog; }
				bool procuraJogador();
				void draw();
				void mover();
				void atualizar();
				void colisao(Entidade* ent, const sf::Vector2f diferenca);
			};
		}
	}
}