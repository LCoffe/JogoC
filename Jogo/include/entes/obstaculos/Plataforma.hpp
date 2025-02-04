#pragma once

#include "../../include/entes/obstaculos/Obstaculo.hpp"
constexpr const char* TILESET1_PATH = "..\\Jogo\\assets\\tilesets\\babylon.png";

#define TAM_PLATAFORMA_X 250.0f
#define TAM_PLATAFORMA_Y 250.0f

namespace Entidade {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {
		protected:
			ElementosGraficos::AnimacaoEstatica sprite;
			static sf::Texture texturaTileset;

		public:
			Plataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
			~Plataforma();
			void colisao(Entidade* ent, sf::Vector2f diferenca);
			void desenhar();
			void atualizar();
			void inicializar();
			void salvar(nlohmann::json& j);
		};
	}
}