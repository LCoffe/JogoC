#pragma once

#include "../../include/entes/obstaculos/Obstaculo.hpp"

constexpr const char* const CAIXA_PARADO_PATH = "..\\Jogo\\assets\\obstaculos\\caixa\\caixa_parado.png";
constexpr const char* const CAIXA_ARRASTADO_PATH = "..\\Jogo\\assets\\obstaculos\\caixa\\caixa_arrastado.png";

namespace Entidade {
	namespace Obstaculos {
		class Caixa : public Obstaculo {
			private:
				bool colisaoParede;
				bool arrastado;
				float lentidao;
				//ElementosGraficos::AnimacaoMovimento sprite;

				void inicializar();
				void atualizarSprite(float dt);
			public:
				Caixa(sf::Vector2f pos, sf::Vector2f tam);
				~Caixa();
				void setArrastado(bool arrastado) { this->arrastado = arrastado; }
				bool getArrastado() { return arrastado; }
				void setColisaoParede(bool colisaoParede) { this->colisaoParede = colisaoParede; }
				bool getColisaoParede() { return colisaoParede; }
				void colisao(Entidade* ent, const sf::Vector2f diferenca);
				void colisaoObs(Personagem::Personagem* persona, sf::Vector2f diferenca);
				void colisaoPlataforma(Entidade* ent, const sf::Vector2f diferenca);
				void desenhar();
				void atualizar();
				void salvar(nlohmann::json& j);
		};
	}
}