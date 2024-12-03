#pragma once

#include "../stdafx/stdafx.hpp"
#include "../Personagem.hpp"

#define VELOCIDADE_JOGADOR 3.0f
#define TAM_JOGADOR_X 50.0f
#define TAM_JOGADOR_Y 50.0f

namespace Subject {
	namespace Observer {
		class ObserverJogador;
	}
}

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			class Jogador : public Personagem {
			private:
				bool direcao; // true = direita, false = esquerda
				Subject::Observer::ObserverJogador* pObs;
			public:
				Jogador(const sf::Vector2f pos);
				~Jogador();
				void setDirecao(bool dir) { direcao = dir; }
				const bool getDirecao() const { return direcao; }
				void mover();
				void pular();
				void draw();
				void atualizar();
				void colisao(Entidade* ent, const sf::Vector2f diferenca);
			};
		}
	}
}