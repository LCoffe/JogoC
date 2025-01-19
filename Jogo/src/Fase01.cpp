#include "../include/Fase01.hpp"

namespace Fase {
	Fase01::Fase01(): Fase(IDs::IDs::fase01){
	}

	Fase01::~Fase01() {
		pListaObstaculo->limparLista();
		pListaPersona->limparLista();
	}

	void Fase01::iniciaFase(bool doisJogadres) {
		criarMapa(doisJogadres);
		executar();
	}

	void Fase01::carregaFase() {
		pGS->carregarJogo(*this);
		executar();
	}

	void Fase01::criarMapa(bool doisJogadores) {
		// Criar jogador
		criaPersonagem(sf::Vector2f(50, 350), IDs::IDs::jogador, true);
		if (doisJogadores) {
			criaPersonagem(sf::Vector2f(30, 350), IDs::IDs::jogador, false);
		}

		// Criar inimigos
		//criaPersonagem(sf::Vector2f(600, 768 - 101), IDs::IDs::guerreiraAthena, false);
		criaPersonagem(sf::Vector2f(400, 768 - 101), IDs::IDs::gorgona, false);
		//criaPersonagem(sf::Vector2f(400, 768 - 101), IDs::IDs::guerreiraAthena, false);

		// Criar plataformas
		criaPlataforma(sf::Vector2f(0, 768 - 100), sf::Vector2f(1366, 100), IDs::IDs::plataforma);
		criaPlataforma(sf::Vector2f(1366, 768 - 100), sf::Vector2f(1366, 100), IDs::IDs::plataforma);
		criaPlataforma(sf::Vector2f(800, 768 - 188), sf::Vector2f(100, 138), IDs::IDs::plataforma);
	}

	void Fase01::carregar() {
		nlohmann::json json = pGS->carregarPersonagem(*this);
		nlohmann::json::iterator it = json.begin();
		Entidade::Entidade* aux = nullptr;
		for (auto& it : json) {
			IDs::IDs ID = static_cast<IDs::IDs>(it["ID"]);
			sf::Vector2f pos(it["posicao"]["x"], it["posicao"]["y"]);
			sf::Vector2f tam(it["tamanho"]["x"], it["tamanho"]["y"]);
			sf::Vector2f vel(it["velocidade"]["x"], it["velocidade"]["y"]);
			bool direcao = it["direcao"];
			bool atacando = it["atacando"];
			bool andando = it["andando"];
			float vida = it["vida"];
			float tempoAtaque = it["tempoAtaque"];
			sf::Vector2f posArma(it["posArma"]["x"], it["posArma"]["y"]);
			bool levandoDano = it["levandoDano"];

			if (ID == IDs::IDs::jogador) {
				bool jogadorUm = it["jogadorUm"];
				criaPersonagem(pos, ID, tam, vel, direcao, jogadorUm, vida, tempoAtaque, posArma, atacando, andando, levandoDano);
			}
			if (ID == IDs::IDs::guerreiraAthena || ID == IDs::IDs::gorgona) {
				criaPersonagem(pos, ID, tam, vel, direcao, false, vida, tempoAtaque, posArma, atacando, andando, levandoDano);
			}
		}

		json = pGS->carregarObstaculo(*this);
		it = json.begin();
		for (auto& it : json) {
			IDs::IDs ID = static_cast<IDs::IDs>(it["ID"]);
			sf::Vector2f pos(it["posicao"]["x"], it["posicao"]["y"]);
			sf::Vector2f tam(it["tamanho"]["x"], it["tamanho"]["y"]);
			if (ID == IDs::IDs::plataforma) {
				criaPlataforma(pos, tam, ID);
			}
		}
	}

	void Fase01::executar() {
		pJogador = getJogador();
		pJogadorDois = getJogadorDois();
		if (pJogadorDois != nullptr) {
			if (pJogador || pJogadorDois) {

				// Atualizar camera
				sf::Vector2f pos;
				if (pJogador) {
					pos = pJogador->getPos();
					if (pJogadorDois) {
						pos = (pJogador->getPos() + pJogadorDois->getPos()) / 2.0f;
						if (pJogador->getPos().x - pJogadorDois->getPos().x > pGG->getTamJanela().x || pJogador->getPos().x - pJogadorDois->getPos().x < -pGG->getTamJanela().x) {
							pos.x = 0.0f;
						}
					}
				}

				if (pos.x != 0.0f) {
					pGG->atualizarCamera(pos, pGG->getTamJanela());
				}

				// Atualizar e desenhar entidades
				pListaPersona->executar();
				pListaObstaculo->executar();
				desenhar();

				gerenciarColisoes();
				atualizaPontuacao();
			}
		}
		else {
			if (pJogador) {
				pGG->atualizarCamera(pJogador->getPos(), pGG->getTamJanela());
				
				pListaPersona->executar();
				pListaObstaculo->executar();
				
				desenhar();
				
				gerenciarColisoes();
				atualizaPontuacao();
			}
		}
	}
}