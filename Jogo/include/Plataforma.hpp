#pragma once

#include "../include/Obstaculo.hpp"
constexpr const char* const PLATAFORMA_PATH = "..\\Jogo\\assets\\obstaculos\\plataforma.png";

#define TAM_PLATAFORMA_X 250.0f
#define TAM_PLATAFORMA_Y 50.0f

namespace Entidade {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {
			protected:

				sf::Texture textura;
				sf::Sprite sprite;

				void inicializarSprite();
				
			public:
				Plataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
				~Plataforma();
				void colisao(Entidade* ent, sf::Vector2f diferenca);
				void desenhar();
				void atualizar();
				void salvar(nlohmann::json& j);
		};
	}
}