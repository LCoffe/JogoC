#pragma once

#include "../stdafx/stdafx.hpp"
#include "../Personagem.hpp"

#define VELOCIDADE_JOGADOR 80.0f
#define ALTURA_PULO 900.0f
#define TAM_JOGADOR_X 50.0f
#define TAM_JOGADOR_Y 50.0f

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
			public:
				Jogador(const sf::Vector2f pos);
				~Jogador();
				void pular();
				void desenhar();
				void atualizar();
				void colisao(Entidade* ent, const sf::Vector2f diferenca);
			};
		}
	}
}