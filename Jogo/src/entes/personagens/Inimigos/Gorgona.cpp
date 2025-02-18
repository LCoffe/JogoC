#include "../../include/entes/personagens/inimigos/Gorgona.hpp"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Gorgona::Gorgona(const sf::Vector2f pos, Jogador::Jogador* pJ)
                : Inimigo(pos, sf::Vector2f(TAMANHO_GORGONA_X, TAMANHO_GORGONA_Y), pJ, IDs::IDs::gorgona), ataquePetrificante(false), ataqueBasico(false) {
				vida = VIDA_GORGONA;
				setDano(DANO_GORGONA);
                inicializarSprite();
            }

            Gorgona::Gorgona(const sf::Vector2f pos, Jogador::Jogador* pJ, Jogador::Jogador* pJ2)
                : Inimigo(pos, sf::Vector2f(TAMANHO_GORGONA_X, TAMANHO_GORGONA_Y), pJ, pJ2, IDs::IDs::gorgona) {
                vida = VIDA_GORGONA;
                setDano(DANO_GORGONA);
                inicializarSprite();
            }

            Gorgona::~Gorgona() {}

            void Gorgona::desenhar() {
               //pGG->desenharElemento(corpo);
                if (!remover)
                    desenharInimigo();
            }

            void Gorgona::atualizarTempoAtaque() {
                float aux = static_cast<float>(rand() % 100);

                //15% de chance de ataque petrificante
                if (!ataquePetrificante && aux <= 15 && getAtacando() && !ataqueBasico) {
                    ataquePetrificante = true;
					pArma->setAtaquePetrificante(true);
                }
                else if (ataquePetrificante) {
                    ataqueBasico = false;
                }
				else if (aux > 5 && getAtacando()) {
					ataqueBasico = true;
				}

               if (getAtacando() && !andando && !levandoDano) {
                    tempoAtaque += 0.016f;
                    pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
                    if (tempoAtaque > 1.35f) {
                        tempoAtaque = 0.0f;
                        atacar(false);
                        pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
						ataquePetrificante = false;
                        ataqueBasico = false;
						pArma->setAtaquePetrificante(false);
                    }
                    else if (tempoAtaque > 1.25f) {
                        pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
                    }
                    else if (tempoAtaque > 1.20f) {
                        if (ataquePetrificante) {
                            setPosArma(sf::Vector2f(direcao ? pos.x + pArma->getTam().x + 30.0f : pos.x - pArma->getTam().x - 10.0f, pos.y + 10.0f));
                        }
                        else {
                            setPosArma(sf::Vector2f(direcao ? pos.x + pArma->getTam().x + 15.0f : pos.x - pArma->getTam().x + 3.0f, pos.y + 10.0f));
                        }
                    }
                }
                else if (andando || levandoDano) {
                    tempoAtaque = 0.0f;
                    pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
                    atacar(false);
					ataqueBasico = false;
					if (ataquePetrificante) {
						ataquePetrificante = false;
						pArma->setAtaquePetrificante(false);
					}
                }
            }

            void Gorgona::salvar(nlohmann::json& j)
            {
                j["ID"] = (int)getID();
                j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
                j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
                j["velocidade"] = { {"x", velocidadeFinal.x}, {"y", velocidadeFinal.y} };
                j["direcao"] = direcao;
                j["vida"] = vida;
                j["tempoAtaque"] = tempoAtaque;
                j["posArma"] = { {"x", pArma->getPos().x}, {"y", pArma->getPos().y} };
                j["atacando"] = atacando;
				j["ataquePetrificante"] = ataquePetrificante;
				j["ataqueBasico"] = ataqueBasico;
				j["levandoDano"] = levandoDano;
				j["tempoDano"] = tempoDano;
				j["morrendo"] = morrendo;
                j["tempoMorte"] = tempoMorte;
                j["pontuacao"] = 0;
				j["colisaoChao"] = colisaoChao;
            }

            void Gorgona::inicializarSprite() {
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, PARADOG_PATH, 7);
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::walk, ANDARG_PATH, 13);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::attack, ATAQUEG_PATH, 16);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::levouDano, DANOG_PATH, 3);
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::morte, MORTEG_PATH, 7);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::especialGorgona, ESPECIALG_PATH, 5);
            }

            void Gorgona::atualizarSprite(float dt) {
				sf::Vector2f posicao = pos;
                posicao.x += TAMANHO_GORGONA_X / 2.15f;
                posicao.y += TAMANHO_GORGONA_Y / 2.7f;
                
                if (morrendo) {
                    sprite.atualizar(ElementosGraficos::ID_ANIMACAO::morte, direcao, posicao, dt);
                }
                else if (andando && colisaoChao) {
                    sprite.atualizar(ElementosGraficos::ID_ANIMACAO::walk, direcao, posicao, dt);
				}
                else if (ataquePetrificante && atacando && !andando) {
                    sprite.atualizar(ElementosGraficos::ID_ANIMACAO::especialGorgona, direcao, posicao, dt);
                }
				else if (atacando && ataqueBasico && !andando) {
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::attack, direcao, posicao, dt);
				}
				else if (levandoDano) {
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::levouDano, direcao, posicao, dt);
				}
                else
                    sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao, posicao, dt);

            }

        }
    }
}
