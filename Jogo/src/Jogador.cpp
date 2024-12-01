#include "../include/Jogador.hpp"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Jogador::Jogador(const sf::Vector2f pos) :
				Personagem(pos, sf::Vector2f(TAM_JOGADOR_X, TAM_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador) {
			}

			Jogador::~Jogador() {}

			void Jogador::mover() {
				pos = corpo.getPosition();
				tam = corpo.getSize();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {  // W = cima
					if (pos.y > 0.0f) {
						corpo.move(0.0f, -velocidadeFinal.y);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // S = baixo
					if ((pos.y + tam.y) < 768.0f) {
						corpo.move(0.0f, velocidadeFinal.y);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // D = direita
					if ((pos.x + tam.x) < 1366.0f) {
						corpo.move(velocidadeFinal.x, 0.0f);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // A = esquerda
					if (pos.x > 0.0f) {
						corpo.move(-velocidadeFinal.x, 0.0f);
					}
				}
			}
			void Jogador::draw() {
				pGG->drawElemento(corpo);
			}

			void Jogador::atualizar() {
				mover();
			}

			void Jogador::colisao(Entidade* ent, const sf::Vector2f diferenca) {
				switch (ent->getID())
				{	
					case IDs::IDs::inimigo: {
						cout << "Ouch!!" << endl;
					}
					break;
					case IDs::IDs::plataforma: {
	
					}
					break;
				default:
					break;
				}
			}
		}
	}
}