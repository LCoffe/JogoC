#include "../../include/entes/personagens/jogador/Jogador.hpp"
#include "../../include/ObservadorJogador.hpp"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Jogador::Jogador(sf::Vector2f pos)
				: Personagem(pos, sf::Vector2f(TAM_JOGADOR_X, TAM_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador), armas(), armaAtual(0),
				pObs(new Observado::Observador::ObservadorJogador(this)), podePular(false), jogadorUm(false)
			{
				armas.clear();
				vida = VIDA_JOGADOR;
				setDano(DANO_JOGADOR);
				inicializarSprite();  // Garante inicialização do sprite
			}

			Jogador::~Jogador() {
			}

			void Jogador::pular() {
				if (colisaoChao) {
					podePular = true;
				}
			}

			void Jogador::desenhar() {
				//pGG->desenharElemento(corpo);
				sprite.desenhar();
			}

			void Jogador::atualizar() {
				if (getMorrendo()) {
					tempoMorte += 0.016f;
				}

				if (podePular) {
					velocidadeFinal.y = -sqrt(0.2f * GRAVIDADE * ALTURA_PULO);
					podePular = false;
					colisaoChao = false;
				}

				if (petrificado) {
					if (levandoDano) {
						petrificado = false;
						tempoPetrificado = 0.0f;
					}
					else{
						andando = false;
						tempoPetrificado += 0.016f;
						if (tempoPetrificado > 1.0f) {
							petrificado = false;
							tempoPetrificado = 0.0f;
						}
					}
				}

				atualizarPosicao();
				atualizarTempoAtaque();
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

			void Jogador::colisao(Entidade* ent, sf::Vector2f diferenca) {
				if (ent->getID() == IDs::IDs::guerreiraAthena) {
					Personagem* p = dynamic_cast<Personagem*>(ent);
					p->parar();
					p->atacar(true);
				}
				else if (ent->getID() == IDs::IDs::gorgona) {
					Personagem* p = dynamic_cast<Personagem*>(ent);
					sf::Vector2f posInimigo = p->getPos();
					bool direcaoInimigo = p->getDirecao();
					if (diferenca.x < -35.0f && diferenca.x > -40.0f) {
						p->parar();
						p->atacar(true);
					}
				}
				else if(ent->getID() == IDs::IDs::espadaInimigo){
					Item::Arma* arma = static_cast<Item::Arma*>(ent);
					tomarDano(arma->getDano(), nullptr);
					if (!getMorrendo()) {
						sf::Vector2f posInimigo = getPos();
						bool direcaoInimigo = arma->getPersonagem()->getDirecao();
						setPos(sf::Vector2f(direcaoInimigo ? posInimigo.x + 10.0f : posInimigo.x - 10.0f, posInimigo.y + 5.0f));
					}
				}
				else if (ent->getID() == IDs::IDs::cobrasGorgona) {
					Item::Arma* arma = static_cast<Item::Arma*>(ent);
					if (arma->getAtaquePetrificante()) {
						petrificado = true;
					}
					else {
						tomarDano(arma->getDano(), nullptr);
					}
					if (!getMorrendo()) {
						sf::Vector2f posInimigo = getPos();
						bool direcaoInimigo = arma->getPersonagem()->getDirecao();
						setPos(sf::Vector2f(direcaoInimigo ? posInimigo.x + 40.0f : posInimigo.x - 40.0f, posInimigo.y + 5.0f));
					}
				}
				else if(ent->getID() == IDs::IDs::plataforma) {
					if (diferenca.y > 0) {
						colisaoChao = true;
						velocidadeFinal.y = 0.0f;
					}
					if (diferenca.x <= 0.0f && colisaoParede) {
						andando = false;
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
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::morte, MORTE_PATH, 7);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::petrificado, PETRIFICADO_PATH, 5);
			}

			void Jogador::atualizarTempoAtaque()
			{	
				if (getAtacando() && !andando && !levandoDano && pArma->getID() == IDs::IDs::espadaJogador) {
					tempoAtaque += 0.016f;
					pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
					if (tempoAtaque > 0.9f) {
						tempoAtaque = 0.0f;
						atacar(false);
						pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
					}
					else if (tempoAtaque > 0.36f) {
						pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
					}
					else if (tempoAtaque > 0.35f) {
						setPosArma(sf::Vector2f(direcao ? pos.x + pArma->getTam().x + 30.0f : pos.x - pArma->getTam().x + 15.0f, pos.y + 10.0f));
					}
				}
				else if (andando || levandoDano) {
					tempoAtaque = 0.0f;
					if (pArma->getID() != IDs::IDs::projetil) {
						pArma->setPos(sf::Vector2f(-500.0f, -500.0f));
					}
					
					atacar(false);
				}

				if (atacando && !andando && !levandoDano && pArma->getID() == IDs::IDs::projetil) { 
					tempoAtaque += 0.016f;
					if (tempoAtaque > 0.9f) {
						if (pArma != nullptr) {
							Item::Projetil* p = static_cast<Item::Projetil*>(pArma);
							p->setPos(sf::Vector2f(direcao ? pos.x + pArma->getTam().x + 30.0f : pos.x + pArma->getTam().x + 15.0f, pos.y + 10.0f));
							p->setColidiu(false);	
							p->setVelocidade(sf::Vector2f(200.0f, 5.0f));
							p->setDirecao(direcao);
							atacando = false;
							tempoAtaque = 0.0f;
						}
					}
				}

			}

			void Jogador::trocarArma() {
				if (pArma != nullptr && !andando && !levandoDano && !atacando) {
					armaAtual++;
					if (armaAtual >= armas.size()) {
						armaAtual = 0;
					}
					pArma = armas[armaAtual];
				}
				tempoAtaque = 0.0f;
			}

			void Jogador::atualizarSprite(float dt)
			{	
				sf::Vector2f posicao = pos;
				posicao.x += TAM_JOGADOR_X / 1.55f;
				posicao.y += TAM_JOGADOR_Y / 2.7f;

				if(morrendo)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::morte, direcao, posicao, dt);
				else if (andando && colisaoChao)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::walk, direcao, posicao, dt);
				else if(!colisaoChao)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::jump, direcao, posicao, dt);
				else if (atacando)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::attack, direcao, posicao, dt);
				else if (levandoDano)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::levouDano, direcao, posicao, dt);
				else if (petrificado)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::petrificado, direcao, posicao, dt);
				else
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao, posicao,dt);
			}

			void Jogador::salvar(nlohmann::json& j) {
				j["ID"] = (int)getID();
				j["posicao"] = { {"x", pos.x}, {"y", pos.y}};
				j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
				j["velocidade"] = { {"x", velocidadeFinal.x}, {"y", velocidadeFinal.y} };
				j["direcao"] = direcao;
				j["jogadorUm"] = jogadorUm;
				j["vida"] = vida;
				j["armaAtual"] = armaAtual;
				j["tempoAtaque"] = tempoAtaque;
				j["posArma"] = { {"x", pArma->getPos().x}, {"y", pArma->getPos().y} };
				j["IDArma"] = (int)pArma->getID();
				j["atacando"] = atacando;
				j["levandoDano"] = levandoDano;
				j["tempoDano"] = tempoDano;
				j["petrificado"] = petrificado;
				j["tempoPetrificado"] = tempoPetrificado;
				j["morrendo"] = morrendo;
				j["tempoMorte"] = tempoMorte;
				j["pontuacao"] = pontuacao;
				j["colisaoChao"] = colisaoChao;

				if (pArma->getID() == IDs::IDs::projetil) {
					Item::Projetil* p = dynamic_cast<Item::Projetil*>(pArma);
					j["velocidadeArma"] = { {"x", p->getVelocidade().x}, {"y", p->getVelocidade().y} };
					j["colidiu"] = p->getColidiu();
					j["direcaoArma"] = p->getDirecao();
				}
				else {
					j["velocidadeArma"] = { {"x", 0.0f}, {"y", 0.0f} };
					j["colidiu"] = false;
					j["direcaoArma"] = false;
				}
			}
		}
	}
}