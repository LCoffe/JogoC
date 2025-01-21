#include "../include/Personagem.hpp"
#include "../include/Arma.hpp"
#include "stdlib.h"

namespace Entidade {
	namespace Personagem {
		Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID) : 
			Entidade(pos, tam, ID), velocidadeMax(vel), velocidadeFinal(sf::Vector2f(vel, 0.0f)), tempo(0.0f), tempoAtaque(0.0f),
			andando(false), direcao(true), colisaoChao(false), atacando(false), dano(0.0f), morrendo(false), levandoDano(false), vida(0.0f), tempoDano(0.0f), pArma(nullptr){}

		Personagem::~Personagem() {}

		void Personagem::andar(const bool direcao) {
			atacando = false;
			andando = true;
			this->direcao = direcao;

			pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
			tempoAtaque = 0.0f;
		}

		void Personagem::parar() {
			andando = false;
		}

		void Personagem::atacar(const bool atacando) {
			this->atacando = atacando;
		}

		void Personagem::tomarDano(const float dano) {
			if (!levandoDano) {
				vida -= dano;
				levandoDano = true;
				if (vida <= 0.0f) {
					vida = 0.0f;
					morrendo = true;
				}
			}
		}

		void Personagem::setPosArma(const sf::Vector2f pos) {
			pArma->setPos(pos);
		}

		void Personagem::atualizarPosicao() {
			tempo = pGG->getTempo();
			sf::Vector2f soma(0.0f, 0.0f);

			if (andando) {
				soma.x = velocidadeFinal.x * tempo;
				if (!direcao) { // esquerda
					soma.x *= -1.0f;
				}
			}

			//Força da gravidade
			const float velY = velocidadeFinal.y;
			velocidadeFinal.y += GRAVIDADE * tempo;
			soma.y = velY * tempo + (GRAVIDADE * tempo * tempo) / 2.0f;

			corpo.move(soma);
			pos.x = corpo.getPosition().x;
			pos.y = corpo.getPosition().y;

			velocidadeFinal.x = velocidadeMax;

			atualizaTempoDano();
		}

		void Personagem::atualizaTempoDano() {
			if (levandoDano) {
				tempoDano += pGG->getTempo();
			}
			if (levandoDano && tempoDano > 1.0f) {
				levandoDano = false;
				tempoDano = 0.0f;
			}
		}

		void Personagem::desenhar() {
			pGG->desenharElemento(corpo);
		}
	}
}