#include "../include/Jogador.hpp"
#include "../include/ObservadorJogador.hpp"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Jogador::Jogador(sf::Vector2f pos)
				: Personagem(pos, sf::Vector2f(TAM_JOGADOR_X, TAM_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador),
				pObs(new Observado::Observador::ObservadorJogador(this))
			{
				inicializarSprite();  // Garante inicialização do sprite
			}

			Jogador::~Jogador() {}

			void Jogador::pular() {
			
				if (colisaoChao) {
					velocidadeFinal.y = -sqrt(0.2f * GRAVIDADE * ALTURA_PULO);
					colisaoChao = false;

				}
			}

			bool Jogador::estaPulando()
			{
				if (!colisaoChao)
					return true;
				else
					return false;
			}


			void Jogador::desenhar() {
				sprite.desenhar();
			}

			void Jogador::atualizar() {
				atualizarSprite(tempo);
				atualizarPosicao();
			}

			void Jogador::colisao(Entidade* ent, const sf::Vector2f diferenca) {
				switch (ent->getID())
				{	
					case IDs::IDs::inimigo: {
						
					}
					break;
					case IDs::IDs::plataforma: {
		
					}
					break;
				default:
					break;
				}
			}
			void Jogador::inicializarSprite()
			{

				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, ".\\assets\\jogador\\jogador_parado.png", 4);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::walk, ".\\assets\\jogador\\jogador_andar.png", 8);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::jump, ".\\assets\\jogador\\jogador_pulo.png", 6);

			}
			void Jogador::atualizarSprite(float dt)
			{
				if (andando && !estaPulando())
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::walk, direcao, pos, dt);

				else if(estaPulando())
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::jump, direcao, pos, dt);

				else 
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao,pos,dt);

			}
		}
	}
}