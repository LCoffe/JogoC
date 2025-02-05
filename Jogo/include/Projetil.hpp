#pragma once

#include "../../include/elementosGraficos/animacoes/AnimacaoEstatica.hpp"
#include "../../include/Arma.hpp"

constexpr const char* const PROJETIL_PATH = "res/imagens/projetil.png";

#define DANO_PROJETIL 25.0f;

namespace Entidade {
	namespace Item {
		class Projetil : public Arma {
			private:
				bool direcao;
				bool colidiu;
				sf::Vector2f velocidade;
			public:
				Projetil(Personagem::Personagem* p, sf::Vector2f tam);
				~Projetil();
				void setDirecao(const bool direcao) { this->direcao = direcao; if (!direcao) { velocidade.x *= -1; } }
				void setVelocidade(const sf::Vector2f velocidade) { this->velocidade = velocidade; }
				void setColidiu(const bool colidiu);
				void atualizarPosicao();
				void atualizarSprite(float dt);
				void inicializarSprite();
				void desenhar();
				void atualizar();
				void salvar(nlohmann::json& j);
				void colisao(Entidade* ent, const sf::Vector2f diferenca);
		};
	}
}