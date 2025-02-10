#include "../../include/entes/personagens/Inimigos/Minotauro.hpp"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Minotauro::Minotauro(const sf::Vector2f pos, Jogador::Jogador* pJog) : Inimigo(pos, sf::Vector2f(TAMANHO_MINOTAURO_X, TAMANHO_MINOTAURO_Y), pJog, IDs::IDs::minotauro) {
				vida = VIDA_MINOTAURO;
				setDano(DANO_MINOTAURO);
				inicializarSprite();
			}

			Minotauro::Minotauro(const sf::Vector2f pos, Jogador::Jogador* pJog1, Jogador::Jogador* pJog2) : Inimigo(pos, sf::Vector2f(TAMANHO_MINOTAURO_X, TAMANHO_MINOTAURO_Y), pJog1, pJog2, IDs::IDs::minotauro) {
				vida = VIDA_MINOTAURO;
				setDano(DANO_MINOTAURO);
				inicializarSprite();
			}

			Minotauro::~Minotauro() {}

			Jogador::Jogador* Minotauro::procuraJogador() {
				if (pJog != nullptr && pJog2 != nullptr) {
					sf::Vector2f posInim = getPos();
					if (fabs(pJog->getPos().x - posInim.x) < fabs(pJog2->getPos().x - posInim.x)) {
						sf::Vector2f posJog1 = pJog->getPos();
						if (fabs(posJog1.x - posInim.x) <= RAIO_VISAO_MINOTAURO_X && fabs(posJog1.y - posInim.y) <= RAIO_VISAO_MINOTAURO_Y) {
							return pJog;
						}
					}
					else {
						sf::Vector2f posJog2 = pJog2->getPos();
						if (fabs(posJog2.x - posInim.x) <= RAIO_VISAO_MINOTAURO_X && fabs(posJog2.y - posInim.y) <= RAIO_VISAO_MINOTAURO_Y) {
							return pJog2;
						}
					}
				}
				else if (pJog != nullptr) {
					sf::Vector2f posJog = pJog->getPos();
					sf::Vector2f posInim = getPos();
					if (fabs(posJog.x - posInim.x) <= RAIO_VISAO_MINOTAURO_X && fabs(posJog.y - posInim.y) <= RAIO_VISAO_MINOTAURO_Y) {

						return pJog;
					}
				}
				return nullptr;
			}

			void Minotauro::mover() {
				if (!levandoDano && !atacando && !getMorrendo()) {
					Jogador::Jogador* aux = procuraJogador();
					if (aux != nullptr) { // se achou jogador, segue jogador (caso 2 jogares pega o mais proximo)
						sf::Vector2f posJog = aux->getPos();
						sf::Vector2f posInim = getPos();
						sf::Vector2f tamInim = getTam();
						
						if (posJog.x - posInim.x <= 170.0f) {
							parar();
							atacar(true);
						}
						else{
							direcao = true;
							andar(direcao);
						}
						
						if (posJog.x - posInim.x >= -150.0f) {
							parar();
							atacar(true);
						}
						else {
							direcao = false;
							andar(direcao);
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

			void Minotauro::atualizarTempoAtaque() {
				if (atacando && !andando && !levandoDano) {
					if (!pArma->getAtivo()) {
						tempoAtaque += 0.016f;
					}
					else {
						tempoAtaque = 0.0f;
						atacando = false;
					}
					if (tempoAtaque > 0.9f) {
						if (pArma != nullptr) {
							Item::Projetil* p = static_cast<Item::Projetil*>(pArma);
							p->setPos(sf::Vector2f(direcao ? pos.x + pArma->getTam().x + 30.0f : pos.x + pArma->getTam().x + 15.0f, pos.y + 20.0f));
							p->setColidiu(false);
							p->setAtivo(true);
							p->setVelocidade(sf::Vector2f(200.0f, 5.0f));
							p->setDirecao(direcao);
							atacando = false;
							tempoAtaque = 0.0f;
						}
					}
				}
			}

			void Minotauro::inicializarSprite() {
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, PARADOM_PATH, 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::walk, ANDARM_PATH, 8);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::attack, ATAQUEM_PATH, 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::levouDano, DANOM_PATH, 5);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::morte, MORTEM_PATH, 6);
			}

			void Minotauro::atualizarSprite(float dt) {
				sf::Vector2f posicao = pos;
				if (direcao) {
					posicao.x += tam.x / 1.35f;
					posicao.y += tam.y / 2.4f;
				}
				else {
					posicao.x += tam.x / 3.35f;
					posicao.y += tam.y / 2.4f;
				}
				
				if (getMorrendo()) {
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::morte, direcao, posicao, dt);
				}
				else if (andando && colisaoChao) {
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::walk, direcao, posicao, dt);
				}
				else if (levandoDano) {
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::levouDano, direcao, posicao, dt);
				}
				else if (atacando) {
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::attack, direcao, posicao, dt);
				}
				else {
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao, posicao, dt);
				}
			}

			void Minotauro::desenhar() {
				if(!remover)
					desenharInimigo();
			}

			void Minotauro::salvar(nlohmann::json& j) {
				j["ID"] = (int)getID();
				j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
				j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
				j["vida"] = vida;
				j["tempoAtaque"] = tempoAtaque;
				j["posArma"] = { {"x", pArma->getPos().x}, {"y", pArma->getPos().y} };
				j["IDArma"] = (int)pArma->getID();
				j["atacando"] = atacando;
				j["levandoDano"] = levandoDano;
				j["tempoDano"] = tempoDano;
				j["morrendo"] = getMorrendo();
				j["tempoMorrendo"] = getTempoMorte();
				j["colisaoChao"] = colisaoChao;

				Item::Projetil* p = dynamic_cast<Item::Projetil*>(pArma);
				j["velocidadeArma"] = { {"x", p->getVelocidade().x}, {"y", p->getVelocidade().y} };
				j["colidiu"] = p->getColidiu();
				j["direcaoArma"] = p->getDirecao();
				j["ativo"] = p->getAtivo();
			}
		}
	}
}