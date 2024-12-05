#include "../include/Jogador.hpp"
#include "../include/ObservadorJogador.hpp"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Jogador::Jogador(sf::Vector2f pos) :
			Personagem(pos, sf::Vector2f(TAM_JOGADOR_X, TAM_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador),
			pObs(new Observado::Observador::ObservadorJogador(this)){
				
			}

			Jogador::~Jogador() {}

			void Jogador::pular() {
				if (colisaoChao) {
					velocidadeFinal.y = -sqrt(0.2f * GRAVIDADE * ALTURA_PULO);
					colisaoChao = false;
					cout << "pulou" << endl;
				}
			}

			void Jogador::desenhar() {
				pGG->desenharElemento(corpo);
			}

			void Jogador::atualizar() {
				atualizarPosicao();
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