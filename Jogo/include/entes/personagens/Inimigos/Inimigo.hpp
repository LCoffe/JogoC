#pragma once

#include "../../stdafx/stdafx.hpp"
#include "../../include/entes/personagens/Personagem.hpp"
#include "../../include/entes/personagens/jogador/Jogador.hpp"
#include "../../include/Arma.hpp"

#define RAIO_VISAO_X 200.f
#define RAIO_VISAO_Y 200.f

#define VELOCIDADE_INIMIGO 50.0f

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			class Inimigo : public Personagem {
			protected:
				Jogador::Jogador* pJog;
				Jogador::Jogador* pJog2;
				float tempoAtaque;

				virtual void mover();
				virtual void atualizarTempoAtaque();
				virtual void inicializarSprite() = 0;
				virtual void atualizarSprite(float dt);
				virtual Jogador::Jogador* procuraJogador();
			public:
				Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* pJ, const IDs::IDs ID);
				Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* pJ, Jogador::Jogador* pJ2, const IDs::IDs ID);
				~Inimigo();
				void setJogador(Jogador::Jogador* pJog) { this->pJog = pJog; }
				void setJogador2(Jogador::Jogador* pJog2) { this->pJog2 = pJog2; }
				virtual void tomarDano(const float dano);
				void desenharInimigo();
				void atualizar();
				void colisao(Entidade* ent, sf::Vector2f diferenca);
				
				virtual void salvar(nlohmann::json& j) = 0;
			};
		}
	}
}