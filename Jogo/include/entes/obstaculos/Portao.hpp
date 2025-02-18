#pragma once

#include "../../include/entes/obstaculos/Obstaculo.hpp"

constexpr const char* const PORTAO_PATH = "..\\Jogo\\assets\\obstaculos\\portao\\portao.png";

namespace Entidade {
	namespace Obstaculos {
		class Portao : public Obstaculo {
		private:
			bool aberto;
		public:
			Portao(sf::Vector2f pos, sf::Vector2f tam);
			~Portao();
			void setAberto(bool aberto) { this->aberto = aberto; }
			bool getAberto() { return aberto; }
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