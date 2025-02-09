#pragma once

#include "../../include/entes/obstaculos/Obstaculo.hpp"

constexpr const char* const ESPINHO_PATH = "res/assets/obstaculos/espinho.png";

#define DANO_ESPINHO 30.0f

namespace Entidade {
	namespace Obstaculos {
		class Espinho : public Obstaculo {
		private:
			ElementosGraficos::AnimacaoEstatica animaEstatica;

			float dano;
		public:
			Espinho(sf::Vector2f poos, sf::Vector2f tam);
			~Espinho();
			void inicializarSprite();
			void colisao(Entidade* ent, const sf::Vector2f diferenca);
			void colisaoPlataforma(Entidade* ent, const sf::Vector2f diferenca);
			void desenhar();
			void atualizar();
			void inicializar();
			void salvar(nlohmann::json& j);
		};
	}
}