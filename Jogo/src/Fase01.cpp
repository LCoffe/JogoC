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
		criaPersonagem(sf::Vector2f(600, 768 - 101), IDs::IDs::guerreiraAthena, false);
		criaPersonagem(sf::Vector2f(1400, 768 - 101), IDs::IDs::gorgona, false);
		//criaPersonagem(sf::Vector2f(400, 768 - 101), IDs::IDs::guerreiraAthena, false);

		// Criar plataformas
		criaPlataforma(sf::Vector2f(0, 768 - 100), sf::Vector2f(900, 100), IDs::IDs::plataforma);
		criaPlataforma(sf::Vector2f(1366, 768 - 100), sf::Vector2f(1366, 100), IDs::IDs::plataforma);
		criaPlataforma(sf::Vector2f(901, 768 - 238), sf::Vector2f(100, 138), IDs::IDs::plataforma);
		criaPlataforma(sf::Vector2f(1600, 768 - 238), sf::Vector2f(100, 138), IDs::IDs::plataforma);
		criaPlataforma(sf::Vector2f(500, 768-150), sf::Vector2f(50, 50), IDs::IDs::caixa);
	}

	void Fase01::carregar() {
		nlohmann::json json;
		nlohmann::json::iterator it = json.begin();
		Entidade::Entidade* aux = nullptr;

		json = pGS->carregarObstaculo(*this);
		it = json.begin();
		for (auto& it : json) {
			IDs::IDs ID = static_cast<IDs::IDs>(it["ID"]);
			sf::Vector2f pos(it["posicao"]["x"], it["posicao"]["y"]);
			sf::Vector2f tam(it["tamanho"]["x"], it["tamanho"]["y"]);
			bool arrastado = it["arrastado"];
			bool colisaoParede = it["colisaoParede"];
			if (ID == IDs::IDs::plataforma) {
				criaPlataforma(pos, tam, ID);
			}
			if (ID == IDs::IDs::caixa) {
				criaPlataforma(pos, tam, ID, arrastado, colisaoParede);
			}
		}

		json = pGS->carregarPersonagem(*this);
		for (auto& it : json) {
			IDs::IDs ID = static_cast<IDs::IDs>(it["ID"]);
			sf::Vector2f pos(it["posicao"]["x"], it["posicao"]["y"]);
			sf::Vector2f tam(it["tamanho"]["x"], it["tamanho"]["y"]);
			sf::Vector2f vel(it["velocidade"]["x"], it["velocidade"]["y"]);
			bool direcao = it["direcao"];
			bool atacando = it["atacando"];
			bool petrifica = it["petrificado"];
			float vida = it["vida"];
			float tempoAtaque = it["tempoAtaque"];
			sf::Vector2f posArma(it["posArma"]["x"], it["posArma"]["y"]);
			bool levandoDano = it["levandoDano"];
			float tempoDano = it["tempoDano"];
			bool morrendo = it["morrendo"];
			float tempoMorte = it["tempoMorte"];
			int pontuacao = it["pontuacao"];
			bool colisaoChao = it["colisaoChao"];

			if (ID == IDs::IDs::jogador) {
				bool jogadorUm = it["jogadorUm"];
				criaPersonagem(pos, ID, tam, vel, direcao, jogadorUm, vida, tempoAtaque, posArma, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, pontuacao, colisaoChao);
			}
			if (ID == IDs::IDs::guerreiraAthena || ID == IDs::IDs::gorgona) {
				criaPersonagem(pos, ID, tam, vel, direcao, false, vida, tempoAtaque, posArma, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, 0, colisaoChao);
			}
		}
	}
}