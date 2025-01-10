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
		criaPersonagem(sf::Vector2f(600, 768 - 101), IDs::IDs::inimigo, false);
		criaPersonagem(sf::Vector2f(400, 768 - 101), IDs::IDs::inimigo, false);

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
			if (ID == IDs::IDs::jogador) {
				bool jogadorUm = it["jogadorUm"];
				criaPersonagem(pos, ID, tam, vel, direcao, jogadorUm);
			}
			if (ID == IDs::IDs::inimigo) {
				criaPersonagem(pos, ID, tam, vel, direcao, false);
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
		if (pJogador || pJogadorDois) {
			
			// Atualizar camera
			sf::Vector2f pos;
			if (pJogador) {
				pos = pJogador->getPos();
				if (pJogadorDois) {
					pos = (pJogador->getPos() + pJogadorDois->getPos()) / 2.0f;
					cout << pJogador->getPos().x - pJogadorDois->getPos().x << endl;
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

			
		}
	}
}