#pragma once

#include "../stdafx/stdafx.hpp"
#include "../include/Entidade.hpp"

#define GRAVIDADE 120.0f

namespace Entidade {
	namespace Personagem {
		class Personagem : public Entidade {
		protected:
			bool andando;
			bool direcao;
			bool colisaoChao;
			const float velocidadeMax;
			float tempo;
			sf::Vector2f velocidadeFinal;
		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID);
			~Personagem();
			void setVelocidade(sf::Vector2f vel) { velocidadeFinal = vel; }
			const sf::Vector2f& getVelocidade() const { return velocidadeFinal; }
			void atualizarPosicao();
			virtual void desenhar();
			void andar(const bool direcao);
			void estaPulando();
			void parar();
			void setDirecao(const bool direcao) { this->direcao = direcao; } //Direita = true, Esquerda = false
			const bool getDirecao() const { return direcao; }
			void setColisaoChao(const bool colisaoChao) { this->colisaoChao = colisaoChao; }
			const bool getColisaoChao() const { return colisaoChao; }
			virtual void atualizar() = 0;
			virtual void colisao(Entidade* ent, const sf::Vector2f diferenca) = 0;
			virtual void inicializarSprite() = 0;
			virtual void atualizarSprite(float dt) = 0;
		};
	}
}