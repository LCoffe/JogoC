#include "../include/Jogador.hpp"
#include "../include/ObservadorJogador.hpp"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Jogador::Jogador(sf::Vector2f pos)
				: Personagem(pos, sf::Vector2f(TAM_JOGADOR_X, TAM_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador),
				pObs(new Observado::Observador::ObservadorJogador(this)), podePular(false), jogadorUm(false)
			{
				setDano(DANO_JOGADOR);
				inicializarSprite();  // Garante inicialização do sprite
			}

			Jogador::~Jogador() {}

			void Jogador::pular() {
				if (colisaoChao) {
					podePular = true;
				}
			}

			void Jogador::desenhar() {
				sprite.desenhar();
			}

			void Jogador::atualizar() {
				if (podePular) {
					velocidadeFinal.y = -sqrt(0.2f * GRAVIDADE * ALTURA_PULO);
					podePular = false;
					colisaoChao = false;
				}
				atualizarPosicao();
				atualizarSprite(pGG->getTempo());
			}

			void Jogador::setAtivoObs(const bool ativo) {
				if (ativo) {
					pObs->setAtivar(true);
				}
				else {
					pObs->setAtivar(false);
				}
			}

			void Jogador::colisao(Entidade* ent, const sf::Vector2f diferenca) {
				switch (ent->getID())
				{	
					case IDs::IDs::inimigo: {
						Personagem* p = dynamic_cast<Personagem*>(ent);
						if (atacando) {
							if (!p->getMorrendo()) {
								p->setMorrendo(true);
							}
						}
					}
					break;
					case IDs::IDs::plataforma: {
						if (diferenca.y > 0) {
							colisaoChao = true;
							velocidadeFinal.y = 0.0f;
						}
						if (diferenca.x <= 0.0f && !direcao) {
							velocidadeFinal.x = 0.0f;
						}
					}
					break;
				default:
					break;
				}
			}
			void Jogador::inicializarSprite()
			{

				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, PARADO_PATH, 1);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::walk, ANDAR_PATH, 8);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::jump, PULO_PATH, 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::attack, ATAQUE_PATH, 5);
			}
			void Jogador::atualizarSprite(float dt)
			{

				pos.x += TAM_JOGADOR_X / 2.4f;
				pos.y += TAM_JOGADOR_Y / 2.7f;

				if (andando && colisaoChao)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::walk, direcao, pos, dt);

				else if(!colisaoChao)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::jump, direcao, pos, dt);
				else if (atacando)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::attack, direcao, pos, dt);
				else 
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao,pos,dt);
			}

			void Jogador::salvar(nlohmann::json& j) {
				j["ID"] = (int)getID();
				j["posicao"] = { {"x", pos.x}, {"y", pos.y}};
				j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
				j["velocidade"] = { {"x", velocidadeFinal.x}, {"y", velocidadeFinal.y} };
				j["direcao"] = direcao;
				j["jogadorUm"] = jogadorUm;
			}
		}
	}
}