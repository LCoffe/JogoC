#pragma once

#include "../../include/entes/obstaculos/Obstaculo.hpp"

constexpr const char* const MAO_PATH = "..\\Jogo\\assets\\obstaculos\\maocondenados\\mao_condenados.png";

namespace Entidade {
	namespace Obstaculos {
		class MaoCondenados : public Obstaculo {
		private:
			float lentidao;
		public:
			MaoCondenados(sf::Vector2f pos, sf::Vector2f tam);
			~MaoCondenados();
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