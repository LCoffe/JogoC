#pragma once

#include "../../include/entes/Entidade.hpp"
#include "../../include/entes/personagens/jogador/Jogador.hpp"
#include "../../include/entes/personagens/Inimigos/Inimigo.hpp"
#include "../../include/elementosGraficos/animacoes/AnimacaoEstatica.hpp"

namespace Entidade {
	namespace Obstaculos {
		class Obstaculo : public Entidade {
		protected:
			ElementosGraficos::AnimacaoEstatica sprite;
		public:
			Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
			~Obstaculo();
			virtual void colisao(Entidade* ent, const sf::Vector2f diferenca) = 0;
			void colisaoObs(Personagem::Personagem* persona, sf::Vector2f diferenca);
			virtual void desenhar() = 0;
			virtual void atualizar() = 0;
			virtual void inicializar() = 0;
			virtual void salvar(nlohmann::json& j) = 0;
			
		};
	}
}