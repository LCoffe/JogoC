 #include "../include/Inimigo.hpp"
#include <math.h>

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador::Jogador* pJ, const IDs::IDs ID) :
				Personagem(pos, tam, VELOCIDADE_INIMIGO, ID), pJog(pJ), pJog2(nullptr), tempoAtaque(0.0f){
			}

			Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam ,Jogador::Jogador* pJ, Jogador::Jogador* pJ2, const IDs::IDs ID) :
				Personagem(pos, tam, VELOCIDADE_INIMIGO, ID), pJog(pJ), pJog2(pJ2), tempoAtaque(0.0f) {
			}

			Inimigo::~Inimigo() { pJog = nullptr; pJog2 = nullptr; }

			void Inimigo::desenharInimigo() {
				sprite.desenhar();
			}

			Jogador::Jogador* Inimigo::procuraJogador() {
				if (pJog != nullptr && pJog2 != nullptr) {
					sf::Vector2f posInim = getPos();
					if (fabs(pJog->getPos().x - posInim.x) < fabs(pJog2->getPos().x - posInim.x)) {
						sf::Vector2f posJog1 = pJog->getPos();
						if (fabs(posJog1.x - posInim.x) <= RAIO_VISAO_X && fabs(posJog1.y - posInim.y) <= RAIO_VISAO_Y) {
							return pJog;
						}
					}
					else {
						sf::Vector2f posJog2 = pJog2->getPos();
						if (fabs(posJog2.x - posInim.x) <= RAIO_VISAO_X && fabs(posJog2.y - posInim.y) <= RAIO_VISAO_Y) {
							return pJog2;
						}
					}
				}
				else if (pJog != nullptr) {
					sf::Vector2f posJog = pJog->getPos();
					sf::Vector2f posInim = getPos();
					if (fabs(posJog.x - posInim.x) <= RAIO_VISAO_X && fabs(posJog.y - posInim.y) <= RAIO_VISAO_Y) {
						return pJog;
					}
				}
				return nullptr;
			}

			void Inimigo::mover() {
				if (!levandoDano && !atacando && !getMorrendo()) {
					Jogador::Jogador* aux = procuraJogador();
					if (aux != nullptr) { // se achou jogador, segue jogador (caso 2 jogares pega o mais proximo)
						sf::Vector2f posJog = aux->getPos();
						sf::Vector2f posInim = getPos();
						sf::Vector2f tamInim = getTam();
						if (posJog.x - posInim.x >= 10.0f) {
							direcao = true;
							andar(direcao); // direita
						}
						else {
							direcao = false;
							andar(direcao); // esquerda
						}
					}
					else { // movimento "aleatorio", se nao achou jogador segue em uma linha reta até chegar em um limite.
						if (direcao) {
							andar(true);
						}
						else {
							andar(false);
						}
					}
				}
			}

			void Inimigo::tomarDano(const float dano) {
				if (!getMorrendo()) {
					vida -= dano;
					levandoDano = true;
					andando = false;
					if (vida <= 0.0f) {
						vida = 0.0f;
						setMorrendo(true);
					}
				}
			}

			void Inimigo::atualizarTempoAtaque() {
				if (getAtacando() && !andando && !levandoDano) {
					tempoAtaque += 0.016f;
					pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
					if (tempoAtaque > 1.15f) {
						tempoAtaque = 0.0f;
						atacar(false);
						pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
					}
					else if (tempoAtaque > 1.05f) {
						setPosArma(sf::Vector2f(direcao ? pos.x + pArma->getTam().x + 40.0f : pos.x - pArma->getTam().x, pos.y + 10.0f));
					}
					else if (tempoAtaque > 1.10f) {
						setPosArma(sf::Vector2f(-500.0f, -500.0f));
					}
				}
				else if (andando || levandoDano) {
					tempoAtaque = 0.0f;
					pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
					atacar(false);
				}
			}

			void Inimigo::atualizar() {
				if (getMorrendo()) {
					tempoMorte += 0.016f;
					morrendo = true;
					if (tempoMorte > 1.25f) {
						podeRemover();
					}
				}
				mover();
				atualizarPosicao();
				atualizarTempoAtaque();
				atualizarSprite(pGG->getTempo());
			}

			void Inimigo::colisao(Entidade* ent, sf::Vector2f diferenca) {
				if (ent->getID() == IDs::IDs::jogador) {
				}
				switch (ent->getID())
				{
					case IDs::IDs::jogador: {
					}
					break;
					case IDs::IDs::plataforma: {
						
					}
					break;
					default:
						break;
				}
			}
			void Inimigo::inicializarSprite()
			{
			}
			void Inimigo::atualizarSprite(float dt)
			{
			}
		}
	}
}