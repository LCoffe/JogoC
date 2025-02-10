#pragma once

#include "../../include/elementosGraficos/animacoes/AnimacaoEstatica.hpp"
#include "../../include/Arma.hpp"

constexpr const char* const PROJETIL_PATH = "..\\Jogo\\assets\\armas\\lanca.png";
constexpr const char* const PROJETILM_PATH = "..\\Jogo\\assets\\armas\\machado.png";

#define DANO_PROJETIL 09.0f;

namespace Entidade {
	namespace Item {
		class Projetil : public Arma {
			private:
				bool direcao;
				bool colidiu;
				IDs::IDs IDPersonagem;
				sf::Vector2f velocidade;
			public:
				Projetil(Personagem::Personagem* p, sf::Vector2f tam);
				~Projetil();
				void setDirecao(const bool direcao) { this->direcao = direcao; if (!direcao) { velocidade.x *= -1; } }
				bool getDirecao() { return direcao; }
				void setVelocidade(const sf::Vector2f velocidade) { this->velocidade = velocidade; }
				sf::Vector2f getVelocidade() { return velocidade; }
				void setColidiu(const bool colidiu);
				bool getColidiu() { return colidiu; }
				void atualizarPosicao();
				void atualizarSprite(float dt);
				void inicializarSprite(IDs::IDs ID);
				void desenhar();
				void atualizar();
				void salvar(nlohmann::json& j);
				void colisao(Entidade* ent, const sf::Vector2f diferenca);
		};
	}
}