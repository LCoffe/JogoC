#include "../../include/fases/Fase01.hpp"

namespace Fase {
	Fase01::Fase01() : Fase(IDs::IDs::fase01) {
		mapa = new Mapa(this, MAPA1_PATH, TILESET1_PATH);

		iniciaFundo();
	}

	Fase01::~Fase01() {
		pListaObstaculo->limparLista();
		pListaPersona->limparLista();
	}


	void Fase01::iniciaFase(bool doisJogadres) {
		criarMapa(doisJogadres);
		//executar();
	}

	void Fase01::iniciaFundo() {
		fundo = new Fundo::Parallax();
		fundo->carregarTextura(CAMINHO_TEX_FUNDO);
		if (fundo == nullptr) {
			//cout << "Erro ao criar o fundo" << endl;
			exit(1);
		}
	}

	void Fase01::carregaFase() {
		carregar();
		//executar();
	}

	void Fase01::criarMapa(bool doisJogadores) {
		if (doisJogadores) {
			//Cria Jogadores
			criaPersonagem2Jog(sf::Vector2f(100, 768 - 251), IDs::IDs::jogador, true);
			criaPersonagem2Jog(sf::Vector2f(200, 768 - 251), IDs::IDs::jogador, false);

			// Criar inimigos
			//criaPersonagem2Jog(sf::Vector2f(300, 768 - 251), IDs::IDs::gorgona, false);
			criaPersonagem2Jog(sf::Vector2f(400, 768 - 251), IDs::IDs::minotauro, false);

			criaPlataforma(sf::Vector2f(600, 500), sf::Vector2f(50, 50), IDs::IDs::caixa);
			criaPlataforma(sf::Vector2f(1400, 500), sf::Vector2f(20, 70), IDs::IDs::portao);
		}
		else {
			//Cria Jogador
			criaPersonagem1Jog(sf::Vector2f(100, 768 - 251), IDs::IDs::jogador);
			// Criar inimigos
			//criaPersonagem1Jog(sf::Vector2f(300, 768 - 251), IDs::IDs::gorgona);
			criaPersonagem1Jog(sf::Vector2f(400, 768 - 251), IDs::IDs::minotauro);

			criaPlataforma(sf::Vector2f(700, 500), sf::Vector2f(50, 50), IDs::IDs::caixa);
			criaPlataforma(sf::Vector2f((rand() % 100) + 500, 500), sf::Vector2f(50, 50), IDs::IDs::espinho);
			criaPlataforma(sf::Vector2f(1400, 500), sf::Vector2f(20, 70), IDs::IDs::portao);
		}
	}

	void Fase01::carregar() {
		nlohmann::json json;
		nlohmann::json::iterator it = json.begin();
		Entidade::Entidade* aux = nullptr;

		json = pGS->carregarFase();
		it = json.begin();
		bool doisJogadores = false;
		for (auto& it : json) {
			doisJogadores = it["doisJogadores"];
		}

		json = pGS->carregarObstaculo();
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
			else if (ID == IDs::IDs::caixa) {
				criaPlataforma(pos, tam, ID, arrastado, colisaoParede);
			}
			else if (ID == IDs::IDs::espinho) {
				criaPlataforma(pos, tam, ID);
			}
		}

		json = pGS->carregarPersonagem();
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
			int armaAtual = it["armaAtual"];
			sf::Vector2f posArma(it["posArma"]["x"], it["posArma"]["y"]);
			IDs::IDs IDArma = static_cast<IDs::IDs>(it["IDArma"]);
			sf::Vector2f velArma(it["velocidadeArma"]["x"], it["velocidadeArma"]["y"]);
			bool colidiu = it["colidiu"];
			bool direcaoArma = it["direcaoArma"];
			bool levandoDano = it["levandoDano"];
			float tempoDano = it["tempoDano"];
			bool morrendo = it["morrendo"];
			float tempoMorte = it["tempoMorte"];
			int pontuacao = it["pontuacao"];
			bool colisaoChao = it["colisaoChao"];
			bool ativo = it["ativo"];
			if (doisJogadores) {
				if (ID == IDs::IDs::jogador) {
					bool jogadorUm = it["jogadorUm"];
					carregaPersonagem2Jog(pos, ID, tam, vel, direcao, jogadorUm, vida, tempoAtaque, posArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, pontuacao, colisaoChao);
				}
				if (ID == IDs::IDs::guerreiraAthena || ID == IDs::IDs::gorgona || ID == IDs::IDs::minotauro) {
					carregaPersonagem2Jog(pos, ID, tam, vel, direcao, false, vida, tempoAtaque, posArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, 0, colisaoChao);
				}
			}
			else {
				if (ID == IDs::IDs::jogador) {
					bool jogadorUm = it["jogadorUm"];
					carregaPersonagem1Jog(pos, ID, tam, vel, direcao, jogadorUm, vida, tempoAtaque, armaAtual, posArma, IDArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, pontuacao, colisaoChao);
				}
				if (ID == IDs::IDs::guerreiraAthena || ID == IDs::IDs::gorgona || ID == IDs::IDs::minotauro) {
					carregaPersonagem1Jog(pos, ID, tam, vel, direcao, false, vida, tempoAtaque, armaAtual, posArma, IDArma, velArma, colidiu, direcaoArma, ativo, atacando, petrifica, levandoDano, tempoDano, morrendo, tempoMorte, 0, colisaoChao);
				}
			}

		}
	}
	void Fase01::trocaFase() {
		if (doisJogadores) {
			pGS->salvarTrocaFase(pJogador, pJogadorDois);
		}
		else {
			pGS->salvarTrocaFase(pJogador, nullptr);
		}
	}
}