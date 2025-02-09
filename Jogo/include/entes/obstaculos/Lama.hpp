#pragma once

#include "../../include/entes/obstaculos/Obstaculo.hpp"

constexpr const char* const LAMA_PATH = "res/imagens/obstaculos/lama.png";

namespace Entidade {
	namespace Obstaculos {
		class Lama : public Obstaculo {
		private:
			ElementosGraficos::AnimacaoEstatica animaEstatica;
			float lentidao;
		public:
			Lama(sf::Vector2f pos, sf::Vector2f tam);
			~Lama();
			void inicializar();
			void inicializarSprite();
			void colisao(Entidade* ent, const sf::Vector2f diferenca);
			void colisaoPlataforma(Entidade* ent, const sf::Vector2f diferenca);
			void colisaoObs(Personagem::Personagem* persona, sf::Vector2f diferenca);
			void desenhar();
			void atualizar();
			void salvar(nlohmann::json& j);
		};
	}
}