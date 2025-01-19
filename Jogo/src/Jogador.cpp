#include "../include/Jogador.hpp"
#include "../include/ObservadorJogador.hpp"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Jogador::Jogador(sf::Vector2f pos)
				: Personagem(pos, sf::Vector2f(TAM_JOGADOR_X, TAM_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador),
				pObs(new Observado::Observador::ObservadorJogador(this)), podePular(false), jogadorUm(false)
			{
				vida = VIDA_JOGADOR;
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

				if (getMorrendo()) {
					podeRemover();
					cout << "Tu eh ruim em pai" << endl;
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
				if (ent->getID() == IDs::IDs::guerreiraAthena) {
					Personagem* p = dynamic_cast<Personagem*>(ent);
					/*if (atacando) {
							if (!p->getMorrendo()) {
								p->tomarDano(dano);
								sf::Vector2f posInimigo = p->getPos();
								if (pos.x < posInimigo.x) {
									p->setPos(sf::Vector2f(posInimigo.x + 10.0f, posInimigo.y + 5.0f));
								}
								else {
									p->setPos(sf::Vector2f(posInimigo.x - 10.0f, posInimigo.y + 5.0f));
								}
								if (p->getMorrendo()) {
									pontuacao += 100;
								}
							}
						}*/
					p->parar();
					p->atacar(true);
				}
				else if (ent->getID() == IDs::IDs::gorgona) {
					Personagem* p = dynamic_cast<Personagem*>(ent);
					p->parar();
					p->atacar(true);
				}
				else if(ent->getID() == IDs::IDs::espadaInimigo){
					Item::Arma* arma = static_cast<Item::Arma*>(ent);
					tomarDano(arma->getDano());
					if (!getMorrendo()) {
						sf::Vector2f posInimigo = getPos();
						bool direcaoInimigo = arma->getPersonagem()->getDirecao();
						setPos(sf::Vector2f(direcaoInimigo ? posInimigo.x + 10.0f : posInimigo.x - 10.0f, posInimigo.y + 5.0f));
					}
				}
				else if(ent->getID() == IDs::IDs::plataforma) {
					if (diferenca.y > 0) {
						colisaoChao = true;
						velocidadeFinal.y = 0.0f;
					}
					if (diferenca.x <= 0.0f && !direcao) {
						velocidadeFinal.x = 0.0f;
					}
				}
			}
			void Jogador::inicializarSprite()
			{

				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, PARADO_PATH, 4);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::walk, ANDAR_PATH, 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::jump, PULO_PATH, 3);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::attack, ATAQUE_PATH, 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::levouDano, DANO_PATH, 7);
			}

			void Jogador::atualizarTempoAtaque()
			{	
				if (!getAtacando() && andando || levandoDano) {
					tempoAtaque = 0.0f;
					setPosArma(sf::Vector2f(-500.0f, -500.0f));
				}
				if (!getAtacando() && !andando && !levandoDano) {
					tempoAtaque += pGG->getTempo();
					setPosArma(sf::Vector2f(-500.0f, -500.0f));
				}
				if (tempoAtaque > 0.35f) {
					tempoAtaque -= pGG->getTempo();
					atacar(true);
					sf::Vector2f posArma;
					if (direcao) {
						posArma = sf::Vector2f(getPos().x + pArma->getTam().x + 30.0f, getPos().y + 30.0f);
					}
					else {
						posArma = sf::Vector2f(getPos().x - pArma->getTam().x - 30.0f, getPos().y) / 2.0f;
					}
					setPosArma(posArma);
				}
				else if (getAtacando()) {
					tempoAtaque -= pGG->getTempo();
					if (tempoAtaque <= 0.0f) {
						tempoAtaque = 0.0f;
						atacar(false);
						setPosArma(sf::Vector2f(-500.0f, -500.0f));
					}
				}
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
				else if (levandoDano)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::levouDano, direcao, pos, dt);
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
				j["vida"] = vida;
				j["tempoAtaque"] = tempoAtaque;
				j["posArma"] = { {"x", pArma->getPos().x}, {"y", pArma->getPos().y} };
				j["atacando"] = atacando;
				j["andando"] = andando;
				j["levandoDano"] = levandoDano;
			}
		}
	}
}