#include "../include/Jogador.hpp"
#include "../include/ObserverJogador.hpp"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Jogador::Jogador(sf::Vector2f pos) :
			Personagem(pos, sf::Vector2f(TAM_JOGADOR_X, TAM_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador),
			pObs(new Subject::Observer::ObserverJogador(this)), direcao(true){
				
			}

			Jogador::~Jogador() {}

			void Jogador::mover() {
				if (direcao) { //direita
					corpo.move(velocidadeFinal.x, 0.0f);
				}
				else { //esquerda
					corpo.move(-velocidadeFinal.x, 0.0f);
				}
			}

			void Jogador::pular() {
				corpo.move(0.0f, -velocidadeFinal.y);

			}

			void Jogador::draw() {
				pGG->drawElemento(corpo);
			}

			void Jogador::atualizar() {
				
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