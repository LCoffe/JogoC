#include "../include/Inimigo.hpp"
#include <math.h>


namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Inimigo::Inimigo(const sf::Vector2f pos, Jogador::Jogador* pJ) :
				Personagem(pos, sf::Vector2f(TAM_INIMIGO_X, TAM_INIMIGO_Y), VELOCIDADE_INIMIGO, IDs::IDs::inimigo), pJog(pJ), sentidoMovi(true) {
			}

			Inimigo::~Inimigo() { pJog = nullptr; }

			bool Inimigo::procuraJogador() {
				if (pJog != nullptr) {
					sf::Vector2f posJog = pJog->getPos();
					sf::Vector2f posInim = getPos();
					if (fabs(posJog.x - posInim.x) <= RAIO_VISAO_X && fabs(posJog.y - posInim.y) <= RAIO_VISAO_Y) {
						return true;
					}
				}
				return false;
			}

			void  Inimigo::mover() {
				if (procuraJogador()) {
					sf::Vector2f posJog = pJog->getPos();
					sf::Vector2f posInim = getPos();
					sf::Vector2f tamInim = getTam();
					sf::Vector2f vel = getVelocidade();
					if (posJog.x - posInim.x > 0.0f) {
						corpo.move(vel.x, 0.0f);
						sentidoMovi = true; // direita
					}
					else {
						corpo.move(-vel.x, 0.0f);
						sentidoMovi = false; // esquerda
					}
				}
				else { // movimento "aleatorio", se nao achou jogador segue em uma linha reta até chegar em um limite.
					sf::Vector2f vel = getVelocidade();
					sf::Vector2f posInim = getPos();
					if (sentidoMovi) {
						corpo.move(vel.x, 0.0f);
					}
					else {
						corpo.move(-vel.x, 0.0f);
					}
				}
			}

			void Inimigo::draw() {
				pGG->drawElemento(corpo);
			}

			void Inimigo::atualizar() {
				mover();
			}

			void Inimigo::colisao(Entidade* ent, const sf::Vector2f diferenca) {
				if (ent->getID() == IDs::IDs::jogador) {
					cout << "achou jogador" << endl;
				}
				switch (ent->getID())
				{
					case IDs::IDs::jogador: {
						cout << "Mamou!" << endl;
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