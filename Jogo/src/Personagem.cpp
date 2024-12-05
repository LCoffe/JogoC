#include "../include/Personagem.hpp"
#include "stdlib.h"

namespace Entidade {
	namespace Personagem {
		Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID) : 
			Entidade(pos, tam, ID), velocidadeMax(vel), velocidadeFinal(sf::Vector2f(vel, 0.0f)), tempo(0.0f), 
			andando(false), direcao(true), colisaoChao(true){}

		Personagem::~Personagem() {}

		void Personagem::andar(const bool direcao) {
			andando = true;
			this->direcao = direcao;
		}

		void Personagem::parar() {
			andando = false;
		}

		void Personagem::atualizarPosicao() {
			pGG->resetarRelogio();
			tempo = pGG->getTempo();
			sf::Vector2f soma(0.0f, 0.0f);

			if (andando) {
				soma.x = velocidadeFinal.x * tempo;
				if (!direcao) { // esquerda
					soma.x *= -1.0f;
				}
			}

			const float velY = velocidadeFinal.y;
			velocidadeFinal.y += GRAVIDADE * tempo;
			soma.y = velY * tempo + (GRAVIDADE * tempo * tempo) / 2.0f;

			corpo.move(soma);
			pos.x = corpo.getPosition().x;
			pos.y = corpo.getPosition().y;
		
			velocidadeFinal.x = velocidadeMax;
		}

		void Personagem::desenhar() {
			pGG->desenharElemento(corpo);
		}
	}
}