#pragma once

#include "../include/Entidade.hpp"
#include "../include/Jogador.hpp"
#include "../include/Inimigo.hpp"

namespace Entidade {
	namespace Obstaculos {
		class Obstaculo : public Entidade {
		protected:
			
		public:
			Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
			~Obstaculo();
			virtual void colisao(Entidade* ent, const sf::Vector2f diferenca) = 0;
			virtual void colisaoObs(Personagem::Personagem* persona, sf::Vector2f diferenca);
			virtual void desenhar() = 0;
			virtual void atualizar() = 0;
			virtual void salvar(nlohmann::json& j) = 0;
			void inicializarSprite();
			void atualizarSprite(float dt);
		};
	}
}