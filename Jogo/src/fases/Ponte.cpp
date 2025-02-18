#include "../../include/fases/Ponte.hpp"

namespace Fase {
	Ponte::Ponte() : Fase(IDs::IDs::ponte) {
		mapa = new Mapa(this, MAPA1_PATH, TILESET1_PATH);

		iniciaFundo();
	}

	Ponte::~Ponte() {
		pListaObstaculo->limparLista();
		pListaPersona->limparLista();
	}


	void Ponte::iniciaFase(bool doisJogadres) {
		criarMapa(doisJogadres);
	}

	void Ponte::iniciaFundo() {
		fundo = new Fundo::Parallax();
		fundo->carregarTextura(CAMINHO_TEX_FUNDO);
		if (fundo == nullptr) {
			//cout << "Erro ao criar o fundo" << endl;
			exit(1);
		}
	}

	void Ponte::carregaFase() {
		carregar();
		executar();
	}

	void Ponte::criarMapa(bool doisJogadores) {
		if (doisJogadores) {
			//Cria Jogadores
			criaPersonagem2Jog(sf::Vector2f(100, 768 - 251), IDs::IDs::jogador, true);
			criaPersonagem2Jog(sf::Vector2f(150, 768 - 251), IDs::IDs::jogador, false);
			
			// Criar inimigos
			float posX = 300.0f;
			float posY = 0.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPersonagem2Jog(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 200), IDs::IDs::gorgona, false);
				posX *= 2.5f;
			}
			posX = 200.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPersonagem2Jog(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 200), IDs::IDs::guerreiraAthena, false);
				posX += 450.0f;
			}
			posX = 250.0f;
			posY = 500.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPlataforma(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 500), sf::Vector2f(50.0f, 50.0f), IDs::IDs::caixa);
				posX += 400.0f;
				if (i >= 1) {
					posY = 100.0f;
				}
			}
			posX = 300.0f;
			posY = 500.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPlataforma(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 500), sf::Vector2f(50, 50), IDs::IDs::espinho);
				posX += 800.0f;
				if (i >= 1) {
					posY = 100.0f;
				}
			}
			criaPlataforma(sf::Vector2f(1400, 500), sf::Vector2f(20, 300), IDs::IDs::portao);
		}
		else {
			//Cria Jogador
			criaPersonagem1Jog(sf::Vector2f(100, 768 - 251), IDs::IDs::jogador);
			// Criar inimigos
			float posX = 300.0f;
			float posY = 0.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPersonagem1Jog(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 200), IDs::IDs::gorgona);
				posX += 350.0f;
			}
			posX = 200.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPersonagem1Jog(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, 200), IDs::IDs::guerreiraAthena);
				posX += 450.0f;
			}
			posX = 150.0f;
			posY = 500.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPlataforma(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, posY), sf::Vector2f(50, 50), IDs::IDs::caixa);
				posX += 400.0f;
				if (i >= 1) {
					posY = 200.0f;
				}
			}
			posX = 200.0f;
			posY = 500.0f;
			for (int i = 0; i < (rand() % NUM_MAX_INSTANCIA) + NUM_MIN_INSTANCIA; i++) {
				criaPlataforma(sf::Vector2f(static_cast<float>((rand() % 100)) + posX, posY), sf::Vector2f(50, 50), IDs::IDs::espinho);
				posX += 800.0f;
				if (i >= 1) {
					posY = 200.0f;
				}
			}
			criaPlataforma(sf::Vector2f(3400, 200), sf::Vector2f(20, 200), IDs::IDs::portao);
		}
	}

	void Ponte::carregar() {
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
			bool aberto = it["aberto"];
			if (ID == IDs::IDs::plataforma) {
				criaPlataforma(pos, tam, ID);
			}
			else if (ID == IDs::IDs::caixa) {
				criaPlataforma(pos, tam, ID, arrastado, colisaoParede, false);
			}
			else if (ID == IDs::IDs::espinho) {
				criaPlataforma(pos, tam, ID);
			}
			else if (ID == IDs::IDs::portao) {
				criaPlataforma(pos, tam, ID, false, false, it["aberto"]);
			}
			else if (ID == IDs::IDs::maocondenados) {
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
	void Ponte::trocaFase() {
		if (doisJogadores) {
			pGS->salvarTrocaFase(pJogador, pJogadorDois);
		}
		else {
			pGS->salvarTrocaFase(pJogador, nullptr);
		}
	}
}