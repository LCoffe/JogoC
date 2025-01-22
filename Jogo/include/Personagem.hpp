#pragma once

#include "../stdafx/stdafx.hpp"
#include "../include/Entidade.hpp"

#define GRAVIDADE 120.0f

namespace Entidade {
	namespace Item
	{
		class Arma;
	}
	namespace Personagem {
		class Personagem : public Entidade {
		protected:
			Item::Arma* pArma;
			bool andando;
			bool direcao;
			bool colisaoChao;
			bool atacando;
			bool levandoDano;
			bool morrendo;
			float tempoAtaque;
			float tempoMorte;
			float tempoDano;
			float vida;
			const float velocidadeMax;
			float tempo;
			float dano;
			sf::Vector2f velocidadeFinal;
		public:
			Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID);
			~Personagem();
			void setVelocidade(sf::Vector2f vel) { velocidadeFinal = vel; }
			const sf::Vector2f& getVelocidade() const { return velocidadeFinal; }
			void atualizarPosicao();
			virtual void desenhar();
			void andar(const bool direcao);
			void parar();
			void setDirecao(const bool direcao) { this->direcao = direcao; } //Direita = true, Esquerda = false
			const bool getDirecao() const { return direcao; }
			void setColisaoChao(const bool colisaoChao) { this->colisaoChao = colisaoChao; }
			const bool getColisaoChao() const { return colisaoChao; }
			const bool getLevandoDano() const { return levandoDano; }
			void atacar(const bool atacando);
			const bool getAtacando() const { return atacando; }
			const float getTempoMorte() const { return tempoMorte; }
			void setDano(const float dano) { this->dano = dano; }
			void setVida(const float vida) { this->vida = vida; }
			void setTempoAtaque(const float tempoAtaque) { this->tempoAtaque = tempoAtaque; }
			void setLevandoDano(const bool levandoDano) { this->levandoDano = levandoDano; }
			virtual void tomarDano(const float dano);
			void atualizaTempoDano();
			void setMorrendo(const bool morrendo) { this->morrendo = morrendo; }
			const bool getMorrendo() const { return morrendo; }
			const float getDano() const { return dano; }
			void setArma(Item::Arma* pArma) { this->pArma = pArma;}
			Item::Arma* getArma() { return pArma; }
			void setPosArma(const sf::Vector2f pos);
			virtual void atualizar() = 0;
			virtual void colisao(Entidade* ent, sf::Vector2f diferenca) = 0;
			virtual void inicializarSprite() = 0;
			virtual void atualizarSprite(float dt) = 0;
			virtual void salvar(nlohmann::json& j) = 0;
		};
	}
}